#include <iostream>
#include <vector>
using namespace std;

int nzdProsireni(int a, int b, int&x, int&y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }

    int x1, y1;
    int nzd = nzdProsireni(b, a%b, x1, y1);

    x=y1;
    y=x1-(a/b)*y1;
    return nzd;
}

int modInverz(int a, int n){
    int x, y;
    int d = nzdProsireni(a, n, x, y);
    if(d!=1)
        return -1;
    else {
        int inverz = (x%n+n)%n;
        return inverz;
    }
    
}

int main(){
    return 0; 
}