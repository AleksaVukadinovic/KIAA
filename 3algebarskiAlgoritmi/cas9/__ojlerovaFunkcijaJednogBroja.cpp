#include <iostream>
#include <vector>
using namespace std;

int ojlerovaFunkcija(int n){
    int fi = n;
    for(int p=2; p*p<=n; p++){
        if(n%p==0){
            while(n%p==0)
                n/=p;
            fi = fi * (p-1)/p;
        }
    }
    if(n>1)
        fi = fi * (n-1)/n;
    return fi;
}

int main(){
    return 0;
}