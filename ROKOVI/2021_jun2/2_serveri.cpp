#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graf {
private:
    int brojCvorova, brojac = 0, server;
    vector<vector<int>> listaSusedstva;
    vector<int> dolazna;
    vector<int> lowlink;
    vector<int> roditelj;
    vector<bool> posecen;
    vector<bool> jesteArtikulacionaTacka;

    void nadjiArtikulacioneTacke(int cvor){
        lowlink[cvor]=dolazna[cvor]=brojac++;
        posecen[cvor]=true;
        int brojDece = 0;

        for(int sused: listaSusedstva[cvor]){
            if(posecen[sused]){
                if(roditelj[cvor]!=sused)
                    if(dolazna[sused]<lowlink[cvor])
                        lowlink[cvor]=dolazna[sused];
            } else {
                roditelj[sused]=cvor;
                brojDece++;
                nadjiArtikulacioneTacke(sused);

                lowlink[cvor]=min(lowlink[cvor], lowlink[sused]);

                if(roditelj[cvor]!=-1 && dolazna[cvor]<=lowlink[sused])
                    jesteArtikulacionaTacka[cvor]=true;
            }
        }

        if(brojDece>1 && roditelj[cvor]==-1)
            jesteArtikulacionaTacka[cvor]=true;
    }

public:
    Graf(const int n){
        brojCvorova = n;
        listaSusedstva.resize(n);
        dolazna.resize(n);
        lowlink.resize(n);
        roditelj.resize(n, -1);
        posecen.resize(n, false);
        jesteArtikulacionaTacka.resize(n, false);
    }

    void dodajGranu(const int a, const int b){
        listaSusedstva[a].push_back(b);
        listaSusedstva[b].push_back(a);
    }

    int cenaPopravke(int server, vector<int>& cenePopravke){
        this->server = server;
        nadjiArtikulacioneTacke(server);
        int cena = 0;
        for(int i=0; i<brojCvorova; i++)
            if(i!=server && jesteArtikulacionaTacka[i])
                cena+=cenePopravke[i];
        
        return cena;
    }
    
};

int main(){
    int n, m, a, b, srv;
    cin >> n >> m;
    Graf* G = new Graf(n);
    while(m--){
        cin >> a >> b;
        G->dodajGranu(a, b);
    }
    vector<int> cene(n);
    for(int i=0; i<n-1; i++)
        cin >> cene[i];
    cin >> srv;
    cout << G->cenaPopravke(srv, cene) << '\n';
    delete G;
}