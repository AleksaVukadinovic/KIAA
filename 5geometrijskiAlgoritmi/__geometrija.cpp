#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef pair<int, int> Tacka;
typedef pair<int, int> Vektor;

int skalarniProizvod(Vektor a, Vektor b){
    return a.first*b.first + a.second*b.second;
}

int vektorskiProizvod(Vektor a, Vektor b){
    return a.first*b.second - a.second*b.first;
}

int orijentacija(Tacka a, Tacka b, Tacka c){
    return vektorskiProizvod(napraviVektorOdTacaka(a,b), napraviVektorOdTacaka(a,c));
}

string tackaPripadaTrouglu(Tacka t, Tacka a, Tacka b, Tacka  c){
    int o1 = orijentacija(a, b, t);
    int o2 = orijentacija(b, c, t);
    int o3 = orijentacija(c, a, t);
    
    if(o1 == 0 && o2 == 0 && o3 == 0)
        return "NA_STRANICI";
    else if((o1 == 0 && o2 * o3 >= 0) || (o2 == 0 && o1 * o3 >= 0) || (o3 == 0 && o1 * o2 >= 0))
        return "NA_STRANICI";
    else if((o1 > 0 && o2 > 0 && o3 > 0) || (o1 < 0 && o2 < 0 && o3 < 0))
        return "U_TROUGLU";
    else
        return "NE_PRIPADA";
}

Vektor napraviVektorOdTacaka(const Tacka t1, const Tacka t2){
    return {t2.first-t1.first, t2.second-t1.second};
}

bool jeKonveksan(vector<Tacka>& tacke){
    bool pos = false, neg = false;
    int n = tacke.size();
    for(int i=0;i<n;i++){
        int j=(i+1)%n;
        int k=(i+2)%n;
        int smer = orijentacija(tacke[i], tacke[j], tacke[k]);
        if(smer<0)
            neg=true;
        if(smer>0)
            pos=true;
    }
    return !(pos && neg);
}

void napraviProstoMonougao(vector<Tacka>& tacke){
    swap(tacke[0], *min_element(tacke.begin(), tacke.end()));
    sort(tacke.begin()+1, tacke.end(),[&](Tacka a, Tacka b){
        return orijentacija(tacke[0], a, b)>0;
    });
}

void grahamovAlgoritam(vector<Tacka>& tacke){
    napraviProstoMonougao(tacke);
    vector<int> omotac = {0};
    for(int i = 1; i<tacke.size(); i++){
        while(omotac.size()>0 && orijentacija(tacke[omotac[omotac.size()-2]], tacke[omotac.back()], tacke[i]) < 0)
            omotac.pop_back();
        omotac.push_back(i);
    }
}

int main(){

}