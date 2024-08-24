#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graf {
private:
    int brojCvorova;
    vector<vector<int>> listaSusedstva;
    vector<int> ulazniStepen;
    vector<int> pozicijaNakonSortiranja;
    vector<pair<int, int>> neusmereneGrane;

    void topoloskiSortiraj(){
        queue<int> red;
        for(int i=0;i<brojCvorova;i++)
            if(ulazniStepen[i]==0)
                red.push(i);
        int b = 0;
        while(!red.empty()){
            int trenutni = red.front(); red.pop();
            pozicijaNakonSortiranja[trenutni]=b++;

            for(int sused: listaSusedstva[trenutni]){
                ulazniStepen[sused]--;
                if(ulazniStepen[sused]==0)
                    red.push(sused);
            }
        }
    }

public:
    Graf(const int n){
        brojCvorova=n;
        listaSusedstva.resize(n);
        ulazniStepen.resize(n, 0);
        pozicijaNakonSortiranja.resize(n);
    }

    void dodajUsmerenuGranu(const int a, const int b){
        listaSusedstva[a].push_back(b);
        ulazniStepen[b]++;
    }

    void dodajNeusmerenuGranu(const int a, const int b){
        neusmereneGrane.push_back({a, b});
    }

    void usmeriGrane(){
        topoloskiSortiraj();
        vector<pair<int, int>> tmp;
        
        for(auto p: neusmereneGrane){
            if(pozicijaNakonSortiranja[p.first]<pozicijaNakonSortiranja[p.second])
                tmp.push_back({p.first, p.second});
            else 
                tmp.push_back({p.second, p.first});
        }

        for(auto p: tmp)
            cout << p.first << " " << p.second << '\n';
    }
};

int main(){
    int n, m, p, a, b;
    cin >> n >> m >> p;
    Graf* G = new Graf(n);
    while(m--){
        cin >> a >> b;
        G->dodajUsmerenuGranu(a, b);
    }
    while(p--){
        cin >> a >> b;
        G->dodajNeusmerenuGranu(a, b);
    }
    G->usmeriGrane();
    delete G;
    return 0;
}