### Vektor Class

## std::vector ir Vector (s)
| Tipas       |std::vector | Vektor      |
|-------------|------------|-------------|
| 10.000      | 0.0002549  | 0.0001854   |
| 100.000     | 0.0037629  | 0.0027389   |
| 1.000.000   | 0.0244307  | 0.0206536   |
| 10.000.000  | 0.241042   | 0.23914     |
| 100.000.000 | 2.38423    | 2.17712     |

## Vektorių funkcijų palyginimas

### size()
```
std::vector<int> a;
a.push_back(1); a.push_back(2); a.push_back(3); a.push_back(4);
cout << a.size() << endl;
```
```
Vector<int> b;
b.push_back(1); b.push_back(2); b.push_back(3); b.push_back(4);
cout << b.size() << endl;
```
  
### max_size()
```
std::vector<int> c;
cout << c.max_size() << endl;
```
  
``` 
Vector<int> d;
cout << d.max_size() << endl;
```
  
### shrink_to_fit()
```
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
```
  
### at()
```
Vector<int> f;
f.push_back(1); f.push_back(2); f.push_back(3); f.push_back(4);
cout << f.at(1) << endl;
cout << f.at(10) << endl;
```
 
### pop_back()
``` 
Vector<int> g;
g.push_back(1); g.push_back(2); g.push_back(3); g.push_back(4);
cout << g.back() << endl;
cout << g.size() << endl;
g.pop_back();
cout << g.back() << endl;
cout << g.size() << endl;
```

## Atminties perskirstymai Vector ir std::vector

### std::vector perskirstymas: 31
### Vector perskirstymas: 31

## Class ir struktūros palyginimas su 10M -O3
| Tipas       | std::vector| Vector      |
|-------------|------------|-------------|
| Nuskaitymas | 0.04       | 0.05        |
| Rūšiavimas  | 0.32       | 0.62        |
| Išskirstymas| 0.04       | 0.03        |
| Išvedimas   | 0.48       | 0.54        |
