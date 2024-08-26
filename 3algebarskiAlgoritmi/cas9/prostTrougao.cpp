#include <iostream>
#include <vector>
using namespace std;

vector<bool> eratosten(const int n){
    vector<bool> jeProst(n+1, true);
    jeProst[0]=false;
    jeProst[1]=false;

    for(int i = 2; i*i<=n; i++){
        if(jeProst[i]){
            for(int j=i*i;j<=n;j+=i)
                jeProst[j]=false;
        }
    }
    return jeProst;
}

vector<pair<int, int>> odrediPreslikavanje(const vector<bool>& jeProst, const int n){
    vector<pair<int, int>> vrstaIKolona(n+1);
    long red = 1, kolona = 1;
    for(int i=2; i<=n; i++){
        if(red<kolona){
            red++;
            kolona=1;
        }
        if(jeProst[i])
            vrstaIKolona[i]={red, kolona++};
    }
    return vrstaIKolona;
}

int main(){
    int n, q, a;
    cin >> n >> q;
    vector<bool> jeProst = eratosten(n);
    vector<pair<int, int>> mapa = odrediPreslikavanje(jeProst, n);

    while(q--){
        cin >> a;
        if(!jeProst[a])
            cout << "-1\n";
        else {
            auto [red, kolona] = mapa[a];
            cout << red << " " << kolona <<  '\n';
        }
    }
    return 0;
}