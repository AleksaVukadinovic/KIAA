#include <iostream>
#include <vector>
using namespace std;

int brojDelioca(int n){
    int b = 0;
    for(int i=1; i*i<=n; i++){
        if(n%i==0){
            if(i*i!=n)
                b+=2;
            else
                b++;
        }
    }
    return b;
}

int brojDeliocaPomocuFaktorizacije(int n){
    
}

int main(){
    return 0;
}