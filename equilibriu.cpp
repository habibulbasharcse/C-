#include<bits/stdc++.h>
using namespace std;
int main () {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n;i++) {
        cin >> v[i];
    }
    vector<int> prefix(n);
    prefix[0] =  v[0];
    for(int i = 1; i < n;i++) {
        prefix[i] = prefix[i - 1] + v[i];
    }
    
    int total_sum = prefix[n - 1];
    int left_sum = 0;
    for(int i = 0; i < n;i++ ) {
        if(left_sum == total_sum - left_sum - v[i]){
            cout << i << endl; 
            return 0;
        }
        left_sum += v[i];
        
    }
    cout << -1 << endl;
}