#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graf {
private:
    int brojCvorova;
    vector<vector<int>> listaSusedstva;
    vector<bool> posecen;
    vector<pair<int, int>> usmerenja;

    void usmeriGrane2(int koren){
        posecen[koren]=true;
        for(int sused: listaSusedstva[koren]){
            if(!posecen[sused]){
                usmerenja.push_back({koren, sused});
                usmeriGrane2(sused);
            }
        }
    }
public:
    Graf(const int n){
        brojCvorova=n;
        listaSusedstva.resize(n);
        posecen.resize(n, false);
    }
    void dodajGranu(const int a, const int b){
        listaSusedstva[a].push_back(b);
        listaSusedstva[b].push_back(a);
        
    }
    void usmeriGrane(int koren){
        usmeriGrane2(koren);
        sort(usmerenja.begin(), usmerenja.end());
        for(pair<int, int> p: usmerenja)
            cout << p.first << " " << p.second << '\n';
    }
    
};

int main(){
    int n, a, b, koren;
    cin >> n;
    Graf* G = new Graf(n);
    for(int i=0; i<n-1; i++){
        cin >> a >> b;
        G->dodajGranu(a, b);
    }
    cin >> koren;
    G->usmeriGrane(koren);
    delete G;
    return 0;
}