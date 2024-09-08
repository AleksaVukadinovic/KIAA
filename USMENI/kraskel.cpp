#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> roditelj;
vector<int> rang;

void inicijalizujUF(const int n){
    rang.resize(n, 0);
    roditelj.resize(n);
    for(int i=0;i<n;i++)
        roditelj[i]=i;
}

int pronadjiPredstavnika(int x){
    while(x!=roditelj[x]){
        roditelj[x]=roditelj[roditelj[x]];
        x=roditelj[x];
    }
    return x;
}

void unija(int x, int y){
    int fx = pronadjiPredstavnika(x);
    int fy = pronadjiPredstavnika(y);

    if(fx==fy) return;

    if(rang[fx]>rang[fy])
        roditelj[fy]=fx;
    else if(rang[fx]<rang[fy])
        roditelj[fx]=fy;
    else {
        roditelj[fx]=fy;
        rang[fy]++;
    }
}

class Graf{
    private:
        int brojCvorova;
        vector<vector<pair<int, int>>> listaSusedstva;

    public:
        Graf(const int n){
            brojCvorova = n;
            listaSusedstva.resize(n);
        }

        void dodajGranu(const int a, const int b, const int t){
            listaSusedstva[a].push_back({b, t});
        }

    void kraskel(){
        inicijalizujUF(brojCvorova);
        vector<pair<int, pair<int, int>>> grane;
        for(int cvor = 0; cvor<brojCvorova; cvor++)
            for(const auto& [sused, tezina]: listaSusedstva[cvor])
                grane.push_back({tezina, {cvor, sused}});

        sort(grane.begin(), grane.end());

        vector<pair<pair<int, int>, int>> drvo(brojCvorova-1);

        for(const auto& [tezina, grana]: grane){
            auto [u, v] = grana;
            int fu = pronadjiPredstavnika(u);
            int fv = pronadjiPredstavnika(v);

            if(fu!=fv){
                unija(fu, fv);
                drvo.push_back({grana, tezina});

                if(drvo.size()==brojCvorova-1)
                    break;
            }
        }
            
        for(const auto& [grana, tezina]: drvo)
            cout << "(" << grana.first <<", " << grana.second << ")" << tezina << '\n';
    }
};

int main(){
    return 0;
}