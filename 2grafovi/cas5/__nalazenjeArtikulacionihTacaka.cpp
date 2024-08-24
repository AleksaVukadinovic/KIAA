#include <iostream>
#include <vector>
using namespace std;

class Graf {
private:
    int brojCvorova, dolazniBrojac;
    vector<vector<int>> listaSusedstva;
    vector<bool> posecen;
    vector<int> roditelj;
    vector<int> dolaznaEnumeracija;
    vector<int> lowlink;
    vector<bool> artikulacioneTacke;

public:
    Graf(const int n){
        brojCvorova=n;
        listaSusedstva.resize(n);
        dolaznaEnumeracija.resize(n);
        posecen.resize(n, false);
        roditelj.resize(n, -1);
        lowlink.resize(n);
        artikulacioneTacke.resize(n, false);
        dolazniBrojac=0;
    }

    void dodajGranu(const int a, const int b){
        listaSusedstva[a].push_back(b);
        listaSusedstva[b].push_back(a);
    }

    void pronadjiArtikulacioneTacke(int trenutni){
        posecen[trenutni]=true;
        lowlink[trenutni] = dolaznaEnumeracija[trenutni] = dolazniBrojac++;
        int brojDece = 0;

        for(int sused: listaSusedstva[trenutni]){
            if(posecen[sused]){
                if(roditelj[trenutni]!=sused)
                    lowlink[trenutni]=min(lowlink[trenutni], dolaznaEnumeracija[sused]);
            } else {
                brojDece++;
                roditelj[sused]=trenutni;
                pronadjiArtikulacioneTacke(sused);

                lowlink[trenutni]=min(lowlink[trenutni], lowlink[sused]);

                if(roditelj[trenutni]!=-1 && lowlink[sused]>=dolaznaEnumeracija[trenutni])
                    artikulacioneTacke[trenutni]=true;
            }
        }

        if(roditelj[trenutni]==-1 && brojDece>1)
            artikulacioneTacke[trenutni]=true;
    }
};

int main(){
    return 0;
}