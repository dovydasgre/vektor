#include "../Headers/Vec.h"

double mediana (Vector <int> temp) {
    std::sort(temp.begin(), temp.end());

    if (temp.size() % 2 == 0) {
      int nr = temp.size() / 2;
      double b = (temp.at(nr) + temp.at(nr-1)) / 2;
      return b;
    } else {
      int nr = temp.size() / 2;
      return temp.at(nr);
    }
}

double galutinis(string med, Vector <int> temp, int egz) {
  double v=0;
  if (temp.size() > 0) {
    if (med == "0") {
      v = std::accumulate(temp.begin(), temp.end(), v) * 1.0 / temp.size();
    }
    else v = mediana(temp);
  }
  
  return v*0.4 + 0.6*egz;
}

void studentas::setPazymys(int mpaz) {
  paz.reserve(paz.size() + 1);
  paz.push_back(mpaz);
};

void studentas::setGalBal(string med) {
  bendr = galutinis(med, paz, egz);
};

void skaitymas (studentas &temp, Vector <studentas> &mas, double &skaitym, string failodydis) {
    Vector <string> splited;
    string eil, df=failodydis;

    skaitym=0;

    std::ifstream open_f(df);
    auto start = std::chrono::high_resolution_clock::now(); auto st=start;
    //----------------------------------------------------------------------
    while (open_f){ 
    if (!open_f.eof()) {
        std::getline(open_f, eil);
        splited.push_back(eil);}
    else break;
    }
    open_f.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    failodydis.erase(std::remove(failodydis.begin(), failodydis.end(), '.'), failodydis.end());
    failodydis.erase(std::remove(failodydis.begin(), failodydis.end(), 't'), failodydis.end());
    failodydis.erase(std::remove(failodydis.begin(), failodydis.end(), 'x'), failodydis.end());


    std::cout << failodydis << " elementu failo nuskaitymas uztruko: "<< fixed << setprecision(2)<< diff.count() << " s\n";

    skaitym=diff.count();

    stringstream ss(splited[0]);
    string word;
    int count = 0;
    int sk;

    while (ss >> word)
        count++;
    int pazymys;
    for (int i=1;i<splited.size();i++){
        stringstream ss(splited[i]);
        ss >> word;
        temp.setVardas(word);

        ss >> word;
        temp.setPavarde(word);

        for (int i=0;i<count-3;i++){
            ss >> pazymys;
            temp.setPazymys(pazymys);
        }
        ss >> sk;
        temp.setEgzas(sk);
        temp.setGalBal("1");
        mas.push_back(temp);
        temp.clearPaz();
        }
}

void generavimas (string filename, int studKiek, int kiek) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist (0, 10);

    std::ofstream rf (filename);

    rf << setw(25) << left << "Vardas" << setw(25) << left << "Pavarde";
    for (int i=0 ; i<kiek ; i++){
        rf << setw(5) << left << "ND"+to_string(i+1);
    }

    rf << "Egz." << endl;

    char eil[1000];
    string laikeilute;

    for (int i=0; i<studKiek ; i++) {
        //rf << setw(25) << left << "Vardas"+to_string(i+1) << setw(25) << left << "Pavarde"+to_string(i+1);
        sprintf_s (eil, "%-s%-19d%-s%-18d", "Vardas", i+1, "Pavarde", i+1);
        laikeilute=eil;
        for (int j=0 ; j<kiek+1 ; j++) {
            //rf << setw(5) << left << dist(mt);
            laikeilute+="   "+to_string(dist(mt));
        }
        rf << laikeilute << endl;
        laikeilute.clear();
    }
}

void rusiavimas (Vector <studentas> &temp, Vector <studentas> &kietas, string failodydis, double &rusiavim) {

    rusiavim=0;

    failodydis.erase(std::remove(failodydis.begin(), failodydis.end(), '.'), failodydis.end());
    failodydis.erase(std::remove(failodydis.begin(), failodydis.end(), 't'), failodydis.end());
    failodydis.erase(std::remove(failodydis.begin(), failodydis.end(), 'x'), failodydis.end());

    auto start = std::chrono::high_resolution_clock::now();
    sort(temp.begin(), temp.end(), [](studentas a, studentas b){
       if (a.galBalas() == b.galBalas()) return a.getVardas() < b.getVardas();
       return a.galBalas() < b.galBalas();
    });

    cout<<"XXXXXXXXXXXXX"<<endl;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << failodydis << " elementu failo rusiavimas uztruko: "<< fixed << setprecision(2)<< diff.count() << " s\n";

    rusiavim=diff.count();

    start = std::chrono::high_resolution_clock::now();

    for (int i=temp.size()-1; i>=0; i--) {
        if (temp.at(i).galBalas() >= 5) {
            kietas.push_back(temp.at(i));
            temp.pop_back();
        }
    }
    kietas.shrink_to_fit();
    temp.shrink_to_fit();

    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << failodydis << " elementu failo priskirimas prie vargsu ir istrinimas is kietu: "<< fixed << setprecision(2) << diff.count() << " s\n";

    rusiavim+=diff.count();

}

void isvedimas2 (Vector <studentas> &temp, string failodydis, string tipas, double &isved) {
    
    std::ofstream out(tipas);

    isved=0;

    auto start = std::chrono::high_resolution_clock::now();

    char eil[100];
    string laikeilute;

    out<<setw(15)<<left<<"Vardas"<<setw(15)<<left<<"Pavarde"<<"Galutinis (Vid.)" <<endl;
    out << setfill('-') << setw(50) << '-' << setfill(' ') << endl;
    for(auto &i: temp) {
        sprintf_s(eil, "%-15s%-15s", i.getVardas().c_str(), i.getPavarde().c_str());
        laikeilute=eil;
        laikeilute+="   "+to_string(i.galBalas());
        out << laikeilute << endl;
    }
    out.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    failodydis.erase(std::remove(failodydis.begin(), failodydis.end(), '.'), failodydis.end());
    failodydis.erase(std::remove(failodydis.begin(), failodydis.end(), 't'), failodydis.end());
    failodydis.erase(std::remove(failodydis.begin(), failodydis.end(), 'x'), failodydis.end());

    std::cout << failodydis << " failu elemento " << tipas << " isvedimas uztruko: " << fixed << setprecision(2)<< diff.count() << " s\n";

    isved=diff.count();
}