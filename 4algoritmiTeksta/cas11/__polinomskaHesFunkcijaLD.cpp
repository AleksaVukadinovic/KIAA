#include <iostream>
#include <vector>
#include <string>
using namespace std;

int kod(char a){
    return a-'a'+1;
}

long long hesiraj(const string& s){
    int p = 31;
    int m = 1e9+9;

    long long h = 0;
    for(int i=0; i<s.size(); i++)
        h = (h*p+kod(s[i]))%m;
    return h;
}

int main(){
    return 0;
}