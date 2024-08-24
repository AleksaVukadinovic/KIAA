#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>
using namespace std;

class Graf{
private:
    int brojCvorova;
    vector<vector<pair<int, int>>> listaSusedstva;
    vector<int> minRastojanje;
    vector<int> roditelj;
    vector<bool> resen;
public:
    Graf(const int n){
        brojCvorova =n;
        listaSusedstva.resize(n);
        minRastojanje.resize(n, numeric_limits<int>::max());
        roditelj.resize(n, -1);
        resen.resize(n, false);
    }
    
    void dodajGranu(const int a, const int b, const int tezina){
        listaSusedstva[a].push_back({b, tezina});
    }

    void dajkstra(int start){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> red;
        minRastojanje[start]=0;
        red.push({0, start});

        while(!red.empty()){
            pair<int, int> p = red.top();
            red.pop();

            int rastojanje = p.first;
            int cvor = p.second;

            if(resen[cvor])
                continue;
            
            resen[cvor]=true;

            for(pair<int, int> tmp: listaSusedstva[cvor]){
                int sused = tmp.first;
                int udaljenostDoSuseda = tmp.second;

                if(!resen[sused]){
                    minRastojanje[sused] =  min(minRastojanje[sused], minRastojanje[cvor]+udaljenostDoSuseda);
                    roditelj[sused]=cvor;
                    red.push({minRastojanje[sused], sused});
                }
            }
        }
    }
};

int main(){
    return 0;
}