#include <iostream>
#include <iterator>
#include <iostream>
#include <memory>
#include <algorithm>
#include <chrono>
#include <exception>

using std::cout;
using std::endl;
using std::size_t;

template <class T> 
class Vector {
    public:
        typedef T* iterator;
        typedef const T* const_iterator;
        typedef ptrdiff_t difference_type;
        typedef size_t size_type;
        typedef T value_type;
        typedef value_type &reference;
        typedef const value_type &const_reference;
        Vector() { create(); }
        explicit Vector(size_type n, const T& value = T{}) { create(n, value); }
        Vector(const Vector& a) { create(a.begin(), a.end()); }
        ~Vector() { uncreate(); }

        //----Operatoriai----

        Vector& operator=(const Vector& a) {
            if (&a == this)  return *this;
            uncreate();
            create(a.begin(), a.end());
            // naudojama copy semantika
            return *this;
        }

        reference operator[](size_type i) {
            try {
                if (i > size() || i < 0) throw std::out_of_range("pasiektas [] operatoriaus limitas");
            }
            catch (const std::out_of_range& e) {
                cout << e.what();
                exit(0);
            }
            return data[i];
        }

        const_reference operator[](size_type i) const {
            try {
                if (i > size() || i < 0) throw std::out_of_range("pasiektas [] operatoriaus limitas");
            }
            catch (const std::out_of_range& e) {
                cout << e.what();
                exit(0);
            }
            return data[i];
        }

        size_type size() const { return avail - data; }
        bool empty() const {
                if (data == nullptr)
                    return true;
                return false;
            }
        size_type max_size() const{
            return std::numeric_limits<difference_type>::max() / sizeof(value_type);
        }

        size_type capacity() const { return limit - data; } 

         // Iteratoriai
        iterator begin() { return data; }
        const_iterator begin() const { return data; }

        iterator rbegin() {
            iterator it = limit;
            return --it;
        }

        const_iterator rbegin() const {
            iterator it = limit;
            return --it;
        }

        iterator end() { return avail; }
        const_iterator end() const { return avail; }

        iterator rend() {
            iterator it = data;
            return ++it;
        }

        const_iterator rend() const {
            iterator it = data;
            return ++it;
        }

        // Elementų pasiekiamumas
        reference front() {
            return *data;
        }
        const_reference front() const {
            return *data;
        }

        reference back() {
            iterator it = avail;
            return *(--it);
        }
        const_reference back() const {
            iterator it = avail;
            return *(--it);
        }

        reference at(size_type pos) {
            try {
                if (size() <= pos || pos < 0) throw std::out_of_range("Ivyko klaida su at - out of range");
            }
            catch (const std::out_of_range& e) {
                cout << e.what();
                exit(0);
            }
            return data[pos];
        }

        const_reference at(size_type pos) const {
            try {
                if (size() <= pos || pos < 0) throw std::out_of_range("Ivyko klaida su at - out of range");
            }
            catch (const std::out_of_range& e) {
                cout << e.what();
                exit(0);
            }
            return data[pos];
        }

        void reserve(size_type new_cap) {
            if (new_cap > capacity()) {
                iterator new_data = alloc.allocate(new_cap);
                iterator new_avail = std::uninitialized_copy(data, avail, new_data);
                uncreate();
                data = new_data;
                avail = new_avail;
                limit = data + new_cap;
            }
        }

        // Modifikatoriai
        
        void push_back(const T& val) {
        if (avail == limit) {
                grow();
            }
            unchecked_append(val);
        }

        void clear() {
            iterator new_data = alloc.allocate(capacity());
            size_type cap = capacity();
            uncreate();
            limit = new_data + cap;
            data = avail = new_data;
        }
        void pop_back() {
            iterator it = avail;
            alloc.destroy(--it);
            avail = it;
        }
        void shrink_to_fit() {
            limit=avail;
        }

        void resize(size_type count, value_type value = T()) {
            if (count < size()) {
                size_type new_size = count;
                iterator new_data = alloc.allocate(new_size);
                iterator new_avail = std::uninitialized_copy(data, data + count, new_data);
                iterator new_limit = new_data + capacity();

                uncreate();

                data = new_data;
                avail = new_avail;
                limit =  new_limit;
            }
            else if (count > size()) {
                size_type new_size = count;
                iterator new_data = alloc.allocate(new_size);
                iterator it = std::uninitialized_copy(data, avail, new_data);
                std::uninitialized_fill(it, new_data + new_size - 1, value);
                iterator new_avail = new_data + new_size;
                iterator new_limit;
                if (capacity() < new_avail - new_data) {
                    new_limit = new_avail;
                }
                else {
                    new_limit = new_data + capacity();
                }
                uncreate();

                data = new_data;
                avail = new_avail;
                limit = new_limit;
            }
        }

    private:
        T* data;
        T* avail;
        T* limit;
        
        std::allocator<T> alloc;

        void create() {
            data = avail = limit = nullptr;
        }

        void create(size_type n, const T& val) {
            try {
                if (n>1215752191) throw std::out_of_range("pasiektas dydzio limitas");
            }
            catch (const std::out_of_range& e) {
                cout << e.what();
                exit(0);
            }

            data = alloc.allocate(n);
            limit = avail = data + n;
            std::uninitialized_fill(data, limit, val);
        }

        void create(const_iterator i, const_iterator j) {
            data = alloc.allocate(j - i);
            limit = avail = std::uninitialized_copy(i, j, data);
        }

        void uncreate() {
            if (data) {
                iterator it = avail;
                while (it != data)
                    alloc.destroy(--it);
                alloc.deallocate(data, limit - data);
            }
            data = limit = avail = nullptr;
        }

        void grow() {
            size_type new_size;
            new_size = std::max(2 * (limit - data), ptrdiff_t(1));

            iterator new_data = alloc.allocate(new_size);
            iterator new_avail = std::uninitialized_copy(data, avail, new_data);
            uncreate();

            data = new_data;
            avail = new_avail;
            limit = data + new_size;
        }

        void unchecked_append(const T& val) {
        alloc.construct(avail++, val);
        }

        friend Vector operator+(const Vector& a, const Vector& b) {
            try {
                if (a.size() != b.size()) throw std::out_of_range("Vektorių dydžio neatitikimas!");
            }
            catch (const std::out_of_range& e) {
                cout << e.what();
                exit(0);
            }

            auto size = a.size();
            Vector c(size);
            for (auto i = 0; i != a.size(); ++i) c[i] = a[i] + b[i];
            return c;
        }
};

