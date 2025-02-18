#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,q;
    cin >> n >> q;
    vector<long long int> A(n+1);
    vector<long long int> B(n+1);
    B[0] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> A[i];

    }

    B[1 ] = A[1];

    for (int i = 2; i <= n; i++) {
        
        B[i] = B[i -1] + A[i];
        
    }

    while (q--) {
        int l , r;
        cin>> l >> r;
        long long int sum = 0;
        if(l == 1) {
            sum = B[r];
        }else {
            sum = B[r] - B[l-1];
        }

        cout << sum << endl;
    }
    
    
    return 0;
}
