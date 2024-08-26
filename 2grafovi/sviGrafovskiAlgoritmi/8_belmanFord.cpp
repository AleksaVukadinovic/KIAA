#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
using namespace std;

const int INF = numeric_limits<int>::max();

class Graf {
private:
    int brojCvorova;
    vector<vector<pair<int, int>>> listaSusedstva;
    vector<int> minRastojanje;
    vector<int> roditelj;

public:
    Graf(const int n){
        brojCvorova = n;
        listaSusedstva.resize(n);
        minRastojanje.resize(n, INF);
        roditelj.resize(n, -1);
    }

    void dodajGranu(const int a, const int b, const int t){
        listaSusedstva[a].push_back({b, t});
    }

    void belmanFord(int start){
        minRastojanje[start]=0;

        for(int k=0; k<brojCvorova-1; k++){
            bool biloRelaksacija = false;

            for(int cvor=0; cvor<brojCvorova; cvor++){
                for(const auto& [sused, udaljenostDoSuseda]: listaSusedstva[cvor]){
                    if(minRastojanje[cvor]+udaljenostDoSuseda<minRastojanje[sused]){
                        minRastojanje[sused]=minRastojanje[cvor]+udaljenostDoSuseda;
                        roditelj[sused]=cvor;
                        biloRelaksacija=true;
                    }
                }
            }

            if(!biloRelaksacija)
                break;
        }

        for(int cvor = 0; cvor<brojCvorova; cvor++)
            for(const auto& [sused, udaljenostDoSuseda]: listaSusedstva[cvor])
                if(minRastojanje[cvor]+udaljenostDoSuseda<minRastojanje[sused]){
                    cout<<"Graf sadrzi negativan ciklus\n";
                    return;
                }
    }

};

int main(){
    return 0;
}