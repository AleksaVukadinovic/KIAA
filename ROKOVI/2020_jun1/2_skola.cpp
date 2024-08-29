#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>
using namespace std;

class Graf {
private:
    int brojCvorova;
    vector<vector<pair<int, int>>> listaSusedstva;
    vector<int> minRastojanje;
    vector<bool> resen;

    void dajkstra(int pocetak){
        minRastojanje[pocetak]=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> red;
        red.push({0, pocetak});

        while(!red.empty()){
            auto [rastojanje, cvor] = red.top();
            red.pop();

            if(resen[cvor])
                continue;

            resen[cvor]=true;

            for(auto [sused, udaljenostDoSuseda]: listaSusedstva[cvor]){
                if(!resen[sused]){
                    if(minRastojanje[sused]>minRastojanje[cvor]+udaljenostDoSuseda){
                        minRastojanje[sused] = minRastojanje[cvor]+udaljenostDoSuseda;
                        red.push({minRastojanje[sused], sused});
                    }
                }
            }
        }


    }

public:
    Graf(const int n){
        brojCvorova = n;
        listaSusedstva.resize(n);
        minRastojanje.resize(n, numeric_limits<int>::max());
        resen.resize(n, false);
    }

    void dodajGranu(const int a, const int b, const int t){
        listaSusedstva[b].push_back({a, t});
    }

    pair<int, int> najudaljenijaKuca(){
        dajkstra(0);
        pair<int, int> ret = {-1, numeric_limits<int>::min()};
        for(int i =0; i<brojCvorova; i++)
            if(minRastojanje[i]!=numeric_limits<int>::max() && minRastojanje[i]>ret.second)
                ret = {i, minRastojanje[i]};
        return ret;
    }
};

int main(){
    int n, m, a, b, t;
    cin >> n >> m;
    Graf* G = new Graf(n);
    while(m--){
        cin >> a >> b >> t;
        G->dodajGranu(a, b, t);
    }
    auto [kuca, udaljenost] = G->najudaljenijaKuca();
    cout << kuca << " " << udaljenost << '\n';
    delete G;
    return 0;
}