#include <iostream>
#include <vector>
using namespace std;

vector<int> eratosten(int n){
    vector<int> najmanjiCinilac(n+1);
    
    for(int i=0; i<=n; i++)
        najmanjiCinilac[i]=i;

    for(int i=2; i*i<=n; i++){
        if(najmanjiCinilac[i]==i){
            for(int j=i*i; j*j<=n; j+=i)
                if(najmanjiCinilac[j]==j)
                    najmanjiCinilac[j]=i;
        }
    }

    return najmanjiCinilac;
}

void ispisiProsteCinionce(int n, vector<int>& najmanjiCinilac){
    while(n!=1){
        cout << najmanjiCinilac[n] << " ";
        n/=najmanjiCinilac[n];
    }
    cout << '\n';
}

int main(){
    return 0;
}