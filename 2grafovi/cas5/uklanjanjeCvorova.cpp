#include <iostream>
#include <vector>
using namespace std;

class Graf {
private:
    int brojCvorova, brojacDolazna;
    vector<vector<int>> listaSusedstva;
    vector<bool> artikulacioneTacke;
    vector<int> roditelj;
    vector<int> dolaznaEnumeracija;
    vector<int> lowlink;
    vector<bool> posecen;

public:
    Graf(const int n){
        brojCvorova=n;
        brojacDolazna = 0;
        listaSusedstva.resize(n);
        dolaznaEnumeracija.resize(n);
        roditelj.resize(n, -1);
        lowlink.resize(n);
        posecen.resize(n, false);
        artikulacioneTacke.resize(n, false);
    }

    void dodajGranu(const int a, const int b){
        listaSusedstva[a].push_back(b);
        listaSusedstva[b].push_back(a);
    }

    void pronadjiArtikulacioneTacke(int trenutni){
        posecen[trenutni]=true;
        lowlink[trenutni] = dolaznaEnumeracija[trenutni] = brojacDolazna++;
        int brojDece = 0;

        for(int sused: listaSusedstva[trenutni]){
            if(posecen[sused]){
                if(roditelj[trenutni]!=sused)
                    lowlink[trenutni]=min(lowlink[trenutni], dolaznaEnumeracija[sused]);
            } else {
                brojDece++;
                roditelj[sused]=trenutni;
                pronadjiArtikulacioneTacke(sused);

                lowlink[trenutni]=min(lowlink[trenutni], lowlink[sused]);

                if(roditelj[trenutni]!=-1 && dolaznaEnumeracija[trenutni]<=lowlink[sused])
                    artikulacioneTacke[trenutni]=true;

            }

            if(brojDece>1 && roditelj[trenutni]==-1)
                artikulacioneTacke[trenutni]=true;
        }
    }

    pair<bool, int> upit(int n){
        if(artikulacioneTacke[n]) return {true, listaSusedstva[n].size()};
        return {false, -1};
    }
};

int main(){
    int n, m, a, b, q;
    cin >> n >> m;
    Graf* G = new Graf(n);
    while(m--){
        cin >> a >> b;
        G->dodajGranu(a, b);
    }
    cin >> q;
    G->pronadjiArtikulacioneTacke(0);
    while(q--){
        cin >> a;
        pair<bool, int> tmp = G->upit(a);
        if(tmp.first) cout << "Da "<<tmp.second<<'\n';
        else cout << "Ne\n";
    }
    return 0;
}