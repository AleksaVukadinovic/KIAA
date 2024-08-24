#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Graf {
private:
    int brojCvorova;
    vector<vector<int>> listaSusedstva;
    vector<int> ulazniStepen;
    vector<int> poredakNakonSortiranja;
    vector<bool> posecen;

    void topoloskoSortiranje(){
        queue<int> red;
        for(int i = 0; i < brojCvorova; i++)
            if(ulazniStepen[i] == 0)
                red.push(i);

        while(!red.empty()){
            int trenutni = red.front();
            red.pop();
            poredakNakonSortiranja.push_back(trenutni);

            for(int sused: listaSusedstva[trenutni]){
                ulazniStepen[sused]--;
                if(ulazniStepen[sused] == 0)
                    red.push(sused);
            }
        }
    }

public:
    Graf(const int n){
        brojCvorova = n;
        listaSusedstva.resize(n);
        ulazniStepen.resize(n, 0);
        posecen.resize(n, false);
    }

    void dodajGranu(const int a, const int b){
        listaSusedstva[a].push_back(b);
        ulazniStepen[b]++;
    }

    void dodajGrane(){
        topoloskoSortiranje();
        for(int i = 0; i < brojCvorova; i++){
            int trenutni = poredakNakonSortiranja[i];
            fill(posecen.begin(), posecen.end(), false);

            for(int sused: listaSusedstva[trenutni])
                posecen[sused] = true;

            for(int j = i + 1; j < brojCvorova; j++){
                int sused = poredakNakonSortiranja[j];
                if(!posecen[sused]){
                    cout << trenutni << " " << sused << '\n';
                }
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
    cout << '\n';
    G->dodajGrane();
    delete G;
    return 0;
}
