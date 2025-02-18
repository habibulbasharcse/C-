
#include <bits/stdc++.h>
using namespace std;

void arr(int a[],int b[],int n) {
    vector<int> v;
    for(int i = 0; i < n ; i++) {
        v.push_back(b[i]);
    }
    for(int i = 0; i < n ; i++) {
        v.push_back(a[i]);
    }
    
    for(int i = 0; i < n+n ; i++) {
        cout <<v[i] << " ";
    }
}

int main() {
    
    int n;
    
    cin >> n;
    int a[n];
    int b[n];
    
    for(int i = 0; i < n ; i++) {
        cin >> a[i];
    }
    
    for(int i = 0; i < n ; i++) {
        cin >> b[i];
    }
    
    arr(a,b,n);

    return 0;
}