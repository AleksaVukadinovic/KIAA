#include <iostream>
#include <vector>
using namespace std;

class Graf {
private:
    int brojCvorova, cenaServera, cenaKabla, bk;
    vector<vector<int>> listaSusedstva;
    vector<bool> posecen;

    void dfs(int pocetak){
        posecen[pocetak]=true;
        for(int sused: listaSusedstva[pocetak])
            if(!posecen[sused])
                dfs(sused);
    }

    int brojKomponentiPovezanosti(){
        int b = 0;
        for(int i = 0; i<brojCvorova; i++){
            if(!posecen[i]){
                b++;
                dfs(i);
            }
        }
        return b;
    }

public:
    Graf(const int n, const int cs, const int ck){
        brojCvorova=n;
        listaSusedstva.resize(n);
        posecen.resize(n, false);
        cenaServera = cs;
        cenaKabla = ck;
    }

    void dodajGranu(const int a, const int b){
        listaSusedstva[a].push_back(b);
        listaSusedstva[b].push_back(a);
    }
    
    int minimalnaCena(){
        if(cenaServera<=cenaKabla) return brojCvorova*cenaServera;
        bk = brojKomponentiPovezanosti();
        return bk*cenaServera + (brojCvorova-bk)*cenaKabla;
    }
};

int main(){
    int cs, ck, n, m, a, b;
    cin >> cs >> ck >> n >> m;
    Graf* G = new Graf(n, cs, ck);
    while(m--){
        cin >> a >> b;
        G->dodajGranu(a, b);
    }
    cout << G->minimalnaCena() << '\n';
    delete G;
    return 0;
}