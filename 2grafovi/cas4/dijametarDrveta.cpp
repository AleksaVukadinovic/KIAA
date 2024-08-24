#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Graf {
private:
    int brojCvorova;
    vector<vector<int>> listaSusedstva;

private:
    pair<int, int> bfs(int pocetak){
        vector<int> udaljenost(brojCvorova, -1);
        queue<int> red;
        red.push(pocetak);
        udaljenost[pocetak]=0;
        int posledjni = pocetak;

        while(!red.empty()){
            int trenutni = red.front(); red.pop();

            for(int sused: listaSusedstva[trenutni]){
                if(udaljenost[sused]==-1){
                    udaljenost[sused]=udaljenost[trenutni]+1;
                    red.push(sused);
                    posledjni = sused;
                }
            }
        }
        return {posledjni, udaljenost[posledjni]};

    }
public:
    Graf(const int n){
        brojCvorova = n;
        listaSusedstva.resize(n);
    }

    void dodajGranu(const int a, const int b){
        listaSusedstva[a].push_back(b);
        listaSusedstva[b].push_back(a);
    }

    int dijametar(){
        pair<int, int> t1 = bfs(0);
        return bfs(t1.first).second;
    }
};

int main(){
    int n, a, b;
    cin >> n;
    Graf* G = new Graf(n);
    for(int i=0; i<n-1; i++){
        cin >> a >> b;
        G->dodajGranu(a, b);
    }
    cout<< G->dijametar() << '\n';
    delete G;
    return 0;
}