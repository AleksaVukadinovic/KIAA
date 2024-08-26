#include <iostream>
#include <vector>
using namespace std;

int ojlerovaFunkcija(int n){
    int rez = n;
    for(int p = 2; p*p<n; p++){
        if(n%p==0){
            while(n%p==0)
                n/=p;
            rez=rez*(p-1)/p;
        }
    }
    if(n>1)
        rez = rez*(n-1)/n;
    return rez;
}

int main(){
    int n; cin >> n;
    cout << ojlerovaFunkcija(n) << '\n';
    return 0;
}