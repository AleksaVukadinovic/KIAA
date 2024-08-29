#include <iostream>
#include <vector>
#include <limits>
#include <string>
using namespace std;

string dopuni(string s){
    string ret = "#";
    for(int i =0; i<s.size(); i++){
        ret+=s[i];
        ret+='#';
    }
    return ret;
}

vector<int> manacer(string& s){
    int n = s.size();
    vector<int> p(n, 1);
    int l = 0, d=0;

    for(int i=1; i<n; i++){
        if(i<=d)
            p[i]=min(d-i+1, p[d+l-i]);
        while(i-p[i]>0 && i + p[i]<n && s[i-p[i]]==s[i+p[i]])
            p[i]++;

        if(i+p[i]-1>d){
            l = i - (p[i]-1);
            d = i + (p[i]-1);
        }
    }

    return p;
}

void resenjeZadatka(string& s, int x){
    string t = dopuni(s);
    vector<int> p = manacer(t);
    pair<int, int> tmp = {numeric_limits<int>::max(), -1};

    for(int i = 0; i<p.size(); i++)
        if(p[i]>=x && p[i]/2<tmp.first/2)
            tmp = {p[i], i};

    if(tmp.first ==  numeric_limits<int>::max()){
        cout << "-1\n";
        return;
    }

    //treba malo popraviti ovde logiku tako sto ce se razlikovati slucaj za parni i neparni palindorm
    int centar = tmp.second;
    int poluprecnik = tmp.first-1;
    for(int i = centar - poluprecnik; i<=centar+poluprecnik; i++){
        if(t[i]!='#')
            cout << t[i];
    }
    cout << '\n';
}

int main(){
    string s; int x;
    cin >> s >> x;
    resenjeZadatka(s, x);
    return 0;
}