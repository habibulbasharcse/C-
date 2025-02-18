#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,q;
    cin >> n >> q;
    vector<long long int> A(n+1);
    vector<long long int> B(n+1);

    int x = 0;
    B[0] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];

    }

    for (int i = 1; i <= n; i++) {
        
        B[i] = B[x] + A[i];
        x++;
    }

    while (q--) {
        int l , r;
        cin>> l >> r;
        if(l == 1) {
            cout << B[r] << endl;
        }else {
            cout <<B[r] - B[l-1] << endl;
        }
    }
    
    
    return 0;
}
