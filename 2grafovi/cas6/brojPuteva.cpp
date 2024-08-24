#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Graf {
private:
    int brojCvorova, pocetak, cilj;
    vector<vector<int>> listaSusedstva;
    vector<int> ulazniStepen;
    vector<int> poredakNakonSortiranja;
    vector<bool> posecen;

    int brojac = 0;

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

    void dfs(int cvor){
        if(cvor==cilj){
            brojac++;
            return;
        }
        posecen[cvor]=true;
        for(int sused: listaSusedstva[cvor])
            if(!posecen[sused])
                dfs(sused);
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

    void postaviPocetakIKraj(const int p, const int k){
        pocetak = p;
        cilj = k;
    }

    int brojPuteva(){
        topoloskoSortiranje();
        dfs(pocetak);
        return brojac;
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
    cin >> a >> b;
    G->postaviPocetakIKraj(a, b);
    cout << G->brojPuteva() << '\n';
    delete G;
    return 0;
}
