#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> formirajZNiz(const string& s){
    int n = s.size()-1, l=0, d=0;
    vector<int> z(n, 0);

    for(int i=1; i<n; i++){
        if(i<=d)
            z[i] = min(d-i+1, z[i-l]);

        while(z[i]+i<n && s[z[i]]==s[i+z[i]])
            z[i]++;

        if(d<z[i]+i-1){
            l=i;
            d=z[i]+i-1;
        }
    }

    return z;
}

int brojNacina(const string& s, const string& t){
    int k = s.size();
    string novi = s + '#' + t + t;
    vector<int> zNiz = formirajZNiz(novi);
    int b = 0;
    for(int i=k; i<novi.size(); i++)
        if(zNiz[i]==k)
            b++;
    return b;
}

int main(){
    string s, t;
    cin >> s >> t;
    cout << brojNacina(s, t) << '\n';
    return 0;
}