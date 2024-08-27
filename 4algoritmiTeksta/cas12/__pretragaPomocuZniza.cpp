#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> izracunajZNiz(const string& s){
    int n = s.size(), l=0, d=0;
    vector<int> z(n, 0);
    for(int i=1; i<n; i++){
        if(i<=d)
            z[i]=min(d-l+1, z[i-l]);

        while(i+z[i]<n && s[z[i]]==s[z[i]+i])
            z[i]++;

        if(i+z[i]-1>d){
            l=i;
            d=i+z[i]-1;
        }
    }
    return z;
}

vector<int> traziNiz(const string& niska, const string& tekst){
    vector<int> pojavljivanja;
    string zajedno = niska + "#" + tekst;
    int n = zajedno.size(), m=niska.size();
    vector<int> z = izracunajZNiz(zajedno);
    for(int i=0; i<n; i++)
        if(z[i]==m)
            pojavljivanja.push_back(i-m-1);
    return pojavljivanja;
}

int main(){    
    return 0;
}