#include <iostream>
#include <vector>
using namespace std;

vector<int> ojlerovaFunkcijaSvihBrojevaDoN(int n){
    vector<int> fi(n+1);

    for(int i=1; i<=n; i++)
        fi[i]=i;

    for(int p=2; p<=n; p++){
        if(fi[p]==p){
            fi[p]=p-1;
            for(int i=2*p; i<=n; i+=p)
                fi[i]=(fi[i]/p)*(p-1);
        }
    }

    return fi;
}

int main(){
    return 0;
}