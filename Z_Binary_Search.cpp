#include<bits/stdc++.h>
using namespace std;

int main() {
    int n , q;
    cin >> n >> q;
    int v[n];

    for(int i = 0; i < n ;i++) {
        cin >> v[i];
    }
    sort(v,v+n);
    while(q--) {
        int flag = 0;
        int val;
        cin >> val;

        int l = 0;
        int r =(n - 1);

        while(l <= r) {
            int mid = (l + r) / 2;

            if(v[mid] == val) {
                flag = 1;
                break;
            }else if(v[mid] > val) {
                r = mid - 1;
            }else {
                l = mid + 1;
            }
        }
        if(flag == 1) {
            cout << "found" << endl;
        }else {
           cout << "not found" << endl; 
        }
    }
    
}