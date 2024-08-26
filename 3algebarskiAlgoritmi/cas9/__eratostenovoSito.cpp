#include <iostream>
#include <vector>
using namespace std;

vector<bool> eratosten(const int n){
    vector<bool> jeProst(n+1, true);
    jeProst[0]=false;
    jeProst[1]=false;

    for(int i=2; i*i<=n; i++){
        if(jeProst[i]){
            for(int j = i*i; j<=n; j+=i)
                jeProst[j]=false;
        }
    }
    return jeProst;
}

int main(){
    return 0;
}