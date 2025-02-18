#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore(); 

    for (int i = 0; i < t; i++) {
        string s, x;
        cin >> s >> x;

        
        while (s.find(' ') != -1) {
            s.erase(s.find(' '));
        }

       
        while (s.find(x) != -1) {
            s.replace(s.find(x), 4, "#");
        }

        
        while (s.find(x) != -1) {
            s.replace(s.find(x), 3, "#");
        }

        cout << s << endl; 
    }

    return 0;
}
