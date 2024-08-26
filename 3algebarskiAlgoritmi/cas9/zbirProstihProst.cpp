#include <iostream>
#include <vector>
using namespace std;

vector<bool> eratosten(int n){
    vector<bool> jeProst(n+1, true);
    jeProst[0]=false;
    jeProst[1]=false;
    for(int i=2; i*i<=n; i++){
        if(jeProst[i]){
            for(int j=i*i; j<=n; j+=i)
                jeProst[j]=false;
        }
    }
    return jeProst;

}

int resiZadatak(int n){
    vector<bool> jeProst = eratosten(n);
    int b = 0;
    int p = 2;
    for(int q = p+1; p+q <=n; q++)
        if(jeProst[q] && jeProst[p+q])
            b++;
    return b;
}

int main(){
    int n; cin >> n;
    cout << resiZadatak(n) << '\n';
    return 0;
}