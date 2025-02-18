#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> A(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }

        bool isSorted = true;
        for (int i = 0; i < n - 1; i++) {
            if (A[i] > A[i + 1]) { 
                isSorted = false;
                break;
            }
        }

        if (isSorted) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
