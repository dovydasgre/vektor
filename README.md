### Vektor Class

## std::vector ir Vector
| Tipas       |std::vector | Vektor      |
|-------------|------------|-------------|
| 1000        | 4.477      | 3.64        |
| 10000       | 2.15       | 39.04       |
| 100000      | 1.8        | 3.15        |
| 1000000     | 40.23      | 39.39       |
| 10000000    | 40.23      | 39.39       |

## Vektorių funkcijų palyginimas

### size()
---
std::vector<int> a;
a.push_back(1); a.push_back(2); a.push_back(3); a.push_back(4);
cout << a.size() << endl;
---
  
Vector<int> b;
b.push_back(1); b.push_back(2); b.push_back(3); b.push_back(4);
cout << b.size() << endl;
---
  
### max_size()
---
std::vector<int> c;
cout << c.max_size() << endl;
---
  
---  
Vector<int> d;
cout << d.max_size() << endl;
---
  
---
### shrink_to_fit()
---
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
---
  
### at()
---
Vector<int> f;
f.push_back(1); f.push_back(2); f.push_back(3); f.push_back(4);
cout << f.at(1) << endl;
cout << f.at(10) << endl;
---
 
### pop_back()
---  
Vector<int> g;
g.push_back(1); g.push_back(2); g.push_back(3); g.push_back(4);
cout << g.back() << endl;
cout << g.size() << endl;
g.pop_back();
cout << g.back() << endl;
cout << g.size() << endl;
---
