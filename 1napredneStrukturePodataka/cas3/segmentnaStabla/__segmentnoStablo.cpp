#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int zaokruziNaStepenDvojke(int n){
    if(n==0) return 1;
    return (int) pow(2, ceil(log2(n)));
}

vector<int> formirajStablo(vector<int>& originalniNiz){
    int n = zaokruziNaStepenDvojke(originalniNiz.size());
    originalniNiz.resize(n);
    vector<int> stablo(2*n, 0);
    copy(originalniNiz.begin(), originalniNiz.end(), stablo.begin()+n);
    for(int i=n-1;i>0;i--)
        stablo[i]=stablo[2*i]+stablo[2*i+1];
    return stablo;
}

void promeniVrednost(vector<int>& stablo, int indeks, int novaVrednost){
    int n = stablo.size()/2;
    stablo[indeks+=n]=novaVrednost;
    for(indeks/=2;indeks>0;indeks/=2)
        stablo[indeks]=stablo[2*indeks]+stablo[2*indeks+1];
}

int zbirSegmenta(vector<int>& stablo, int levaGranica, int desnaGranica){
    int n = stablo.size()/2, zbir=0;
    levaGranica+=n; desnaGranica+=n;
    while( levaGranica<=desnaGranica){
        if(levaGranica%2==1)
            zbir+=stablo[levaGranica++];
        if(desnaGranica%2==0)
            zbir+=stablo[desnaGranica--];
        levaGranica/=2;
        desnaGranica/=2;
    }
    return zbir;
}

int main(){
    return 0;
}