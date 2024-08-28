#include <iostream>
#include <vector>
using namespace std;

int KTO_grubaSila(const vector<int>& m, const vector<int>& r){
    int n = m.size();
    int x=1;
    while(true){
        int i;
        for(i=0; i<n; i++)
            if(x%m[i] != r[i])
                break;
        
        if(i==n)
            return x;
        x++;
    }
    return x;
}

int KTO_prosejavanje(const vector<int>& m, const vector<int>& r){
    int n = m.size();
    int x = r[0];
    while(true){
        int i;
        for(i=0;i<n;i++)
            if(x%m[i] != r[i])
                break;
        if(i==n)
            return x;
        
        x+=m[0];
    }
    return x;
}

int main(){
    return 0;
}