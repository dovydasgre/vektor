#include "Headers/Vector.h"
#include <vector>

int main(){
    /*
    std::vector<int> a;
    a.push_back(1); a.push_back(2); a.push_back(3); a.push_back(4);
    cout << a.size() << endl;

    Vector<int> b;
    b.push_back(1); b.push_back(2); b.push_back(3); b.push_back(4);
    cout << b.size() << endl;

    std::vector<int> c;
    cout << c.max_size() << endl;

    Vector<int> d;
    cout << d.max_size() << endl;

    Vector<int> e;
    e.push_back(1); e.push_back(2); e.push_back(3); e.push_back(4);
    cout << e.size() << " ";
    cout << e.capacity() << " ";
    e.pop_back();
    e.pop_back();
    cout << e.size() << " ";
    cout << e.capacity() << " ";
    e.shrink_to_fit();
    cout << e.size() << " ";
    cout << e.capacity() << " ";

    Vector<int> f;
    f.push_back(1); f.push_back(2); f.push_back(3); f.push_back(4);
    cout << f.at(1) << endl;
    cout << f.at(10) << endl;


    Vector<int> g;
    g.push_back(1); g.push_back(2); g.push_back(3); g.push_back(4);
    cout << g.back() << endl;
    cout << g.size() << endl;
    g.pop_back();
    cout << g.back() << endl;
    cout << g.size() << endl;
    */

    auto start = std::chrono::high_resolution_clock::now(); auto st=start;
    // Pradėti v1 užpildymo laiko matavimą
    unsigned int sz = 10000;  // 100000, 1000000, 10000000, 100000000
    std::vector <int> v1;
    for (int i = 1; i <= sz; ++i)
      v1.push_back(i);
    // Baigti v1 užpildymo laiko matavimą
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "v1 uzpildymo laikas " << diff.count() << endl;

    // Pradėti v2 užpildymo laiko matavimą
    start = std::chrono::high_resolution_clock::now(); st=start;
    Vector <int> v2;
    for (int i = 1; i <= sz; ++i)
      v2.push_back(i);
    // Baigti v2 užpildymo laiko matavimą
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    cout << "v2 uzpildymo laikas " << diff.count() << endl;
}
