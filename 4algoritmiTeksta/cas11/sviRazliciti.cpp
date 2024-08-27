#include <iostream>
#include <vector>
#include <string>
using namespace std;

void resiZadatak(const string& tekst, const string& niska){
    const int n = tekst.size();
    const int m = niska.size();

    int s = 0;
    while(s < n-m+1){
        for(int i=0; i<m; i++){
            if(niska[i] != tekst[s]){
                if(i==0)
                    s+=1;
                break;
            } else if (i==m-1)
                cout << s-m+1 << " ";
            s++;
        }
    }
    cout << '\n';
}

int main(){
    string tekst, niska;
    cin >> tekst >> niska;
    resiZadatak(tekst, niska);
    return 0;
}