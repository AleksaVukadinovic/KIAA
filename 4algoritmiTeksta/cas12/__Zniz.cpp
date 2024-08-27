#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> izracunajZNiz(const string& s){
    int n = s.size(), l=0, d=0;
    vector<int> z(n, 0);

    for(int i=1; i<n; i++){
        if(i<=d) 
            z[i]=min(d-i+1, z[i-l]);
        
        while(i+z[i]<n && s[z[i]] == s[i+z[i]])
            z[i]++;

        if(i+z[i]-1 > d){
            l=i;
            d=i+z[i]-1;
        }
    }
    return z;
}

int main(){    
    return 0;
}