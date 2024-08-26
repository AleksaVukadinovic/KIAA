#include <iostream>
using namespace std;

void faktorisi(int n){
    while(n%2==0){
        cout << "2 ";
        n/=2;
    }

    for(int i = 3;i*i<=n;i+=2){
        if(n%i==0){
            cout << i << " ";
            n/=i;
        }
    }

    if(n>2)
        cout << n << '\n';
}

int main(){
    int n;
    cin >> n;
    faktorisi(n);
    return 0;
}