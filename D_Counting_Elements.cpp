#include<bits/stdc++.h>
using namespace std;
int main () {
    int n;
    cin >> n;
    vector<int> v(n);

    for(int i = 0; i < n;i++) {
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    int count = 0;
    for(int i = 0; i < n;i++) {
        int l = 0;
        int r =(n - 1);
        int val = v[i] + 1;

        while(l <= r) {
            int mid = (l + r) / 2;

            if(v[mid] == val) {
                count += 1;
                break;
            }else if(v[mid] > val) {
                r = mid - 1;
            }else {
                l = mid + 1;
            }
        }

        
    }
    cout << count << endl;

    
}