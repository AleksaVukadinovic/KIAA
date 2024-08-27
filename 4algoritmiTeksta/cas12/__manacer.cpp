#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string dopuni(string& s){
    string t = "#";
    for(char c:s)
        t+=(c+"#");
    return t;
}

vector<int> manacer(string& s){
    int n=s.size();
    vector<int> p(n, 1);

    int l=0, d=0;

    for(int i = 1;i<n; i++){
        if(i<=d)
            p[i]=min(d-i+1, p[l+d-i]);

        while(i-p[i]>0 && i+p[i]<n && s[i-p[i]]==s[i+p[i]])
            p[i]++;
        
        if(i+p[i]-1>d)
        l=i-(p[i]-1);
        d=i+(p[i]-1);
    }

    return p;
}

int main(){


    return 0;
}