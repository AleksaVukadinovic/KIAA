#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <limits>
using namespace std;

class Graf {
private:
    int brojCvorova, budzet;
    vector<vector<tuple<int, int, int>>> listaSusedstva;
    vector<int> minRastojanje;
    vector<int> minCena;

    void dajkstra(int start, int cilj){
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> red;
        minRastojanje[start]=0;

        red.push({0, 0, start});

        while(!red.empty()){
            auto [udaljenost, cena, cvor] = red.top();
            red.pop();

            if(cvor==cilj){
                cout << udaljenost << " " << cena << '\n';
                return;
            }

            if(udaljenost > minRastojanje[cvor] || cena > minCena[cvor])
                continue;

            for(auto [sused, cenaDoSuseda, udaljenostDoSuseda]: listaSusedstva[cvor]){
                int sledeceRastojanje = udaljenost + udaljenostDoSuseda;
                int sledecaCena = cena + cenaDoSuseda;

                if(sledecaCena <=budzet && (sledeceRastojanje < minRastojanje[sused] || sledecaCena < minCena[sused])){
                    minRastojanje[sused]=sledeceRastojanje;
                    minCena[sused] = sledecaCena;
                    red.push({sledeceRastojanje, sledecaCena, sused});
                }
            }
        }
        cout << "-\n";
    }

public:
    Graf(const int n){
        brojCvorova=n;
        listaSusedstva.resize(n);
        minRastojanje.resize(n, numeric_limits<int>::max());
        minCena.resize(n, numeric_limits<int>::max());
    }

    void setBudzet(int budzet){
        this->budzet=budzet;
    }

    void dodajGranu(const int a, const int b, const int duzina, const int cena){
        listaSusedstva[a].push_back({b, cena, duzina});
        listaSusedstva[b].push_back({a, cena, duzina});
    }

    void resiZadatak(int start, int cilj){
        dajkstra(start, cilj);
    }
};

int main(){
    int n, m;

    cin >> n >> m;

    Graf *G = new Graf(n);

    int u, v, d, c;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> d >> c;
        G->dodajGranu(u, v, d, c);
    }

    int src, dest, budget;
    cin >> src >> dest >> budget;

    G->setBudzet(budget);
    G->resiZadatak(src, dest);

    delete G;
    return 0;
}