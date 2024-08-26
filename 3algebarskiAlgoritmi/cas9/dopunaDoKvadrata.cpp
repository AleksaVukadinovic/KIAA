#include <iostream>
#include <vector>
using namespace std;

long dopunaDoPunogKvadrata(long n){
    long m = 1, p = 2;
    while(p*p<=n){
        int k = 0;
        while(n%p==0){
            n/=p;
            k++;
        }

        if(k%2==1)
            m*=p;
        
        p++;;
    }

    if(n>1) 
        m*=n;
    
    return m;

}

int main(){
    long n; cin >> n;
    cout << dopunaDoPunogKvadrata(n) << '\n';
    return 0;
}