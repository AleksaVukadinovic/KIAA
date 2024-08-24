#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> roditelj;
vector<int> rang;

void inicijalizujUF(const int n){
    rang.resize(n, 0);
    roditelj.resize(n);
    for(int i=0;i<n;i++)
        roditelj[i]=i;
}

int pronadjiPredstavnika(int x){
    while(x!=roditelj[x]){
        roditelj[x]=roditelj[roditelj[x]];
        x=roditelj[x];
    }
    return x;
}

void unija(int x, int y){
    int fx = pronadjiPredstavnika(x);
    int fy = pronadjiPredstavnika(y);

    if(fx==fy) return;

    if(rang[fx]>rang[fy])
        roditelj[fy]=fx;
    else if(rang[fx]<rang[fy])
        roditelj[fx]=fy;
    else {
        roditelj[fx]=fy;
        rang[fy]++;
    }
}

int main(){
    return 0;
}