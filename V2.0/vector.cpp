#include "funkcijos.cpp"

int main (){
    Vector <studentas> mas;
    studentas tempas;
    Vector <studentas> vargsas;
    Vector <studentas> kietas;

    int x;
    cout << "Iveskite 1 jeigu norite generuoti failus, o jeigu norite nuskaityti 0: ";
    cin >> x;

    /*
    unsigned int sz = 1000000000;
    Vector <int> v1;
    int v1_add = 0, szs = 0;
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= sz; ++i) {
      if (v1.capacity() != szs) {
        szs = v1.capacity();
        v1_add++;
      }
      v1.push_back(i);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Vector laikas: " << diff.count() << endl;
    cout << "Vector perskirstymas: " << v1_add << endl;

    Vector<int> v2;
    v1_add = 0; szs = 0;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 1; i <= sz; ++i) {
      if (v2.capacity() != szs) {
        szs = v2.capacity();
        v1_add++;
      }
      v2.push_back(i);
    }
    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    cout << "Mano Vector laikas: " << diff.count() << endl;
    cout << "Mano Vector perskirstymas: " << v1_add << endl;

    */

    if (x == 0){
        string failodydis;

        cout << "Iveskite failo pav is kurio nuskaityti duomenis: "; cin >>failodydis;

        double skaitym, rusiavim, isved, bendras;

        skaitymas (tempas, mas, skaitym, failodydis);
        rusiavimas(mas, kietas, failodydis, rusiavim);
        isvedimas2(kietas, failodydis, "kietas.txt", isved);
        bendras=skaitym+rusiavim+isved;
        isvedimas2(mas, failodydis, "vargsai.txt", isved);
        bendras+=isved;
        cout << failodydis << " Elementu failo visas laikas: " << fixed << setprecision(2)<< bendras << endl;
        cout << setfill('-') << setw(50) << '-' << setfill(' ') << endl;

        mas.clear();
        vargsas.clear();
        kietas.clear();

        }   else {
        auto start = std::chrono::high_resolution_clock::now();

        remove("1000.txt");  
        remove("10000.txt"); 
        remove("100000.txt");  
        remove("1000000.txt");
        remove("10000000.txt"); 

        generavimas("1000.txt", 1000, 15);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        std::cout << "1000" << " failu elemento generavimas uztruko: " << diff.count() << " s\n";

        cout << setfill('-') << setw(50) << '-' << setfill(' ') << endl;

        start = std::chrono::high_resolution_clock::now();

        generavimas("10000.txt", 10000, 15);

        end = std::chrono::high_resolution_clock::now();
        diff = end - start;
        std::cout << "10000" << " failu elemento generavimas uztruko: " << diff.count() << " s\n";

        cout << setfill('-') << setw(50) << '-' << setfill(' ') << endl;

        start = std::chrono::high_resolution_clock::now();

        generavimas("100000.txt", 100000, 15);

        end = std::chrono::high_resolution_clock::now();
        diff = end - start;
        std::cout << "100000" << " failu elemento generavimas uztruko: " << diff.count() << " s\n";

        cout << setfill('-') << setw(50) << '-' << setfill(' ') << endl;

        start = std::chrono::high_resolution_clock::now();

        generavimas("1000000.txt", 1000000, 15);

        end = std::chrono::high_resolution_clock::now();
        diff = end - start;
        std::cout << "1000000" << " failu elemento generavimas uztruko: " << diff.count() << " s\n";

        cout << setfill('-') << setw(50) << '-' << setfill(' ') << endl;

        start = std::chrono::high_resolution_clock::now();

        generavimas("10000000.txt", 10000000, 15);

        end = std::chrono::high_resolution_clock::now();
        diff = end - start;
        std::cout << "10000000" << " failu elemento generavimas uztruko: " << diff.count() << " s\n";

        cout << setfill('-') << setw(50) << '-' << setfill(' ') << endl;
    }
    int y;
    if (x == 0) {
        cout << "Ar istrinti sugeneruotus failus? Jeigu taip spauskite 1. "; cin >> y;
        if (y == 1) {
            remove("vargsai.txt");
            remove("kietas.txt");
        }
    }  
}