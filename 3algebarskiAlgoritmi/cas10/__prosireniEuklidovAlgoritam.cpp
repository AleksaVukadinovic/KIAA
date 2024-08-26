#include <iostream>
#include <vector>
using namespace std;

// vraca nzd(a,b) i racuna x i y takve da je nzd(a, b) = x*a+y*b;
int nzdProsireni(int a, int b, int &x, int &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int x1, y1;
    int nzd = nzdProsireni(b, a%b, x1, y1);

    x=y1;
    y=x1 - (a/b)*y1;
    return nzd;
}

int main(){
    return 0;
}