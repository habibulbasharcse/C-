#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    int i = 0;
    while(true) {
        if(i == n) {
            break;
        }
        cin >> v[i].first >> v[i].second;
        i++;
    }
    
    int j = 0;
    while(true) {
        if(j == n) {
            break;
        }
        cout << v[j].first << " " << v[j].second << endl;
        j++;
    }
    
    

    return 0;
}
