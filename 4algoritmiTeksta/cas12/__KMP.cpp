#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> pretprocesiranje(const string& s){
    int n = s.size();
    vector<int> p(n);

    for(int i=1;i<n;i++){
        int j = p[i-1]; 
        while(j>0 && s[i] != s[j])
            j = p[j-1];
        if(s[i]==s[j])
            j++;
        p[i]=j;
    }

    return p;
}

vector<int> kmpPojavljivanja(const string& tekst, const string& niska){
    string pomocna = niska + "#" +tekst;
    vector<int> pojavljivanja;
    vector<int> prefiksSufiksi = pretprocesiranje(pomocna);
    for(int i=niska.size(); i<tekst.size(); i++)
        if(prefiksSufiksi[i]==niska.size())
            pojavljivanja.push_back(i);

    return pojavljivanja;
}

int main(){
    return 0;
}