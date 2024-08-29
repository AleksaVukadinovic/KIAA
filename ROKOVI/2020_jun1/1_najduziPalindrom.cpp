#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string dopuni(const string& s) {
    string ret = "#";
    for(char c : s) 
        ret += c + string("#");
    return ret;
}

vector<int> manacher(const string& s) {
    int n = s.size();
    vector<int> p(n, 1);

    int l = 0, d = 0;
    for(int i = 1; i < n; i++) {
        if(i <= d)
            p[i] = min(d - i + 1, p[l + d - i]);

        while(i - p[i] >= 0 && i + p[i] < n && s[i - p[i]] == s[i + p[i]])
            p[i]++;

        if(i + p[i] - 1 > d) {
            l = i - (p[i] - 1);
            d = i + (p[i] - 1);
        }
    }
    return p;
}

pair<int, string> resiZadatak(const string& s, int x) {
    string s2 = dopuni(s);
    vector<int> m = manacher(s2);

    int maxDuzina = 0;
    string najduziPalindrom = "";
    
    for(int i = 0; i < m.size(); i++) {
        int trenutnaDuzina = m[i] - 1;
        if (trenutnaDuzina > maxDuzina && trenutnaDuzina > x) {
            maxDuzina = trenutnaDuzina;
            int start = (i - trenutnaDuzina) / 2;
            najduziPalindrom = s.substr(start, trenutnaDuzina);
        }
    }
    
    return {maxDuzina, najduziPalindrom};
}

int main() {
    string s; int x;
    cin >> s >> x;
    auto [duzina, p] = resiZadatak(s, x);
    cout << duzina << " " << p << '\n';
    return 0;
}
