#include <iostream>
#include <vector>
using namespace std;

class Graf {
private:
    int brojCvorova, dolazna;
    vector<vector<int>> listaSusedstva;
    vector<bool> posecen;
    vector<int> roditelj;
    vector<int> lowlink;
    vector<int> dolaznaEnumeracija;
    vector<pair<int, int>> mostovi;

    void pronadjiMostove(int trenutni){
        posecen[trenutni]=true;
        dolaznaEnumeracija[trenutni]=lowlink[trenutni]=dolazna++;

        for(int sused: listaSusedstva[trenutni]){
            if(posecen[sused]){
                if(sused!=roditelj[trenutni])
                    lowlink[trenutni] = min(lowlink[trenutni], lowlink[sused]);
            } else {
                roditelj[sused]=trenutni;
                pronadjiMostove(sused);

                lowlink[trenutni] = min(lowlink[trenutni], lowlink[sused]);

                if(dolaznaEnumeracija[trenutni]<lowlink[sused])
                    mostovi.push_back({trenutni, sused});
            }
        }
        
    }

public:
    Graf(const int n){
        brojCvorova=n;
        dolazna=0;
        listaSusedstva.resize(n);
        posecen.resize(n, false);
        roditelj.resize(n);
        lowlink.resize(n);
        dolaznaEnumeracija.resize(n);
    }

    void dodajGranu(const int a, const int b){
        listaSusedstva[a-1].push_back(b-1);
        listaSusedstva[b-1].push_back(a-1);
    }

    bool moguSeUsmeriti(){
        pronadjiMostove(0);
        return mostovi.size()==0;
    }

    void usmeriGrane(){
        for(int trenutni = 0;trenutni<brojCvorova;trenutni++){
            for(int sused: listaSusedstva[trenutni]){
                if(trenutni > sused) continue;
                if(dolaznaEnumeracija[trenutni]>dolaznaEnumeracija[sused])
                    swap(trenutni,sused);

                if(roditelj[sused]==trenutni)
                    cout << trenutni+1 << " " << sused+1 <<'\n';
                else
                    cout << sused+1 << " " << trenutni+1 << '\n';
            }
        }
    }
};

int main(){
    int n, m, a, b;
    cin >> n >> m;
    Graf* G = new Graf(n);
    while(m--){
        cin >> a >> b;
        G->dodajGranu(a, b);
    }
    if(G->moguSeUsmeriti()){
        G->usmeriGrane();
    } else cout << "0\n";
    delete G;
    return 0;
}