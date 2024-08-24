#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
using namespace std;

class Graf {
private:
    int brojCvorova;
    vector<vector<pair<int, int>>> listaSusedstva;
    vector<bool> resen;
    vector<int> minRastojanje;
    vector<int> roditelj;

    void dajkstra(int start, int neZeli){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> red;
        minRastojanje[start]=0;
        red.push({0, start});

        while(!red.empty()) {
            pair<int, int> tmp = red.top();
            red.pop();

            int cvor = tmp.second;
            int rastojanje = tmp.first;

            if(resen[cvor])
                continue;

            resen[cvor]=true;
            
            for(pair<int, int>& p: listaSusedstva[cvor]){
                int sused = p.first;
                if(sused == neZeli)
                    continue;
                int udaljenostDoSuseda = p.second;
                
                if (minRastojanje[sused] > minRastojanje[cvor] + udaljenostDoSuseda) {
                    minRastojanje[sused] = minRastojanje[cvor] + udaljenostDoSuseda;
                    red.push({minRastojanje[sused], sused});
                }
            }
        }
    }

public:
    Graf(const int n){
        brojCvorova =n;
        listaSusedstva.resize(n);
        resen.resize(n, false);
        minRastojanje.resize(n, numeric_limits<int>::max());
        roditelj.resize(n, -1);
    }

    void dodajGranu(const int a, const int b, const int tezina){
        listaSusedstva[a].push_back({b, tezina});
        listaSusedstva[b].push_back({a, tezina});
    }

    int obradiUpit(int start, int cilj, int zeli, int neZeli){
        fill(resen.begin(), resen.end(), false);
        fill(minRastojanje.begin(), minRastojanje.end(), numeric_limits<int>::max());
        dajkstra(start, neZeli);
        int a = minRastojanje[zeli];

        fill(resen.begin(), resen.end(), false);
        fill(minRastojanje.begin(), minRastojanje.end(), numeric_limits<int>::max());
        dajkstra(zeli, neZeli);
        int b = minRastojanje[cilj];

        return a+b;
    }
    
};

int main(){
    int n, m, a, b, tezina, q, zeli, neZeli, start, cilj;
    cin >> n >> m;
    Graf* G = new Graf(n);
    while(m--){
        cin >> a >> b >> tezina;
        G->dodajGranu(a, b, tezina);
    }
    cin >> q;
    while(q--){
        cin >> start >> cilj >> zeli >> neZeli;
        cout << G->obradiUpit(start, cilj, zeli, neZeli) << '\n';
    }
    delete G;
    return 0;
}

