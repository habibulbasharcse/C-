#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long int> A(n);

    for(int i = 0; i < n;i++) {
        cin >> A[i];
    }

    vector<long int> prefix(n);
    prefix[0] = A[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + A[i];
    }

    for(int i = n-1 ; i >= 0; i--) {
        cout << prefix[i] << " ";
    }
    
} 