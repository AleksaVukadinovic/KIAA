#include <iostream>
#include <vector>
using namespace std;

class Graf {
private:
    int brojCvorova;
    int brojac = 0;
    vector<vector<int>> listaSusedstva;
    vector<int> brojCvorovaUPodstablu;
    vector<bool> posecen;

    void dfs1(int cvor, int roditelj){
        brojCvorovaUPodstablu[cvor] = 1;
        for(int sused: listaSusedstva[cvor]){
            if(sused != roditelj){ 
                dfs1(sused, cvor);
                brojCvorovaUPodstablu[cvor] += brojCvorovaUPodstablu[sused];
            }
        }
    }

    void dfs2(int cvor){
        posecen[cvor] = true;
        for(int sused: listaSusedstva[cvor])
            if(!posecen[sused])
                dfs2(sused);
        if(brojCvorovaUPodstablu[cvor] % 2 == 0 && cvor != 0)
            brojac++;
    }

public:
    Graf(const int n){
        brojCvorova = n;
        listaSusedstva.resize(n);
        brojCvorovaUPodstablu.resize(n, 0);
        posecen.resize(n, false);
    }

    void dodajGranu(const int a, const int b){
        listaSusedstva[a].push_back(b);
        listaSusedstva[b].push_back(a);
    }

    int resenje(){
        if(brojCvorova % 2 == 1)
            return 0;
        dfs1(0, -1); 
        dfs2(0);
        return brojac;
    }
};

int main(){
    int n, a, b;
    cin >> n;
    Graf* G = new Graf(n);
    for(int i = 0; i < n - 1; i++){
        cin >> a >> b;
        G->dodajGranu(a - 1, b - 1);
    }
    cout << G->resenje() << '\n';
    delete G;
    return 0;
}
