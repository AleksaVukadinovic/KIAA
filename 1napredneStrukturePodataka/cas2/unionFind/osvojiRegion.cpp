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

int kod(int i, int j, int m){
    return i*m+j;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrica(n, vector<int>(m));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> matrica[i][j];
    
    const int dummy = n*m;

    inicijalizujUF(n*m+1);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrica[i][j]==0){
                if(i==0 || i==n-1 || j==0 || j==m-1)
                    unija(dummy, kod(i, j, m));
                else {
                    if(i>0 && matrica[i-1][j]==0)
                        unija(kod(i, j, m), kod(i-1, j, m));
                    if(i<n-1 && matrica[i+1][j]==0)
                        unija(kod(i, j, m), kod(i+1, j, m));
                    if(j>0 && matrica[i][j-1]==0)
                        unija(kod(i, j, m), kod(i, j-1, m));
                    if(j<m-1 && matrica[i][j+1]==0)
                        unija(kod(i, j, m), kod(i, j+1, m));
                }
            }
        }
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(matrica[i][j] == 0 && pronadjiPredstavnika(dummy) != pronadjiPredstavnika(kod(i, j, m)))
                matrica[i][j]=1;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout << matrica[i][j] << " ";
        cout << '\n';
    }
    
    return 0;
}