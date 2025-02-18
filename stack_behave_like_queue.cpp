// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int>s1;
    stack<int>s2;
    
    int n;
    cin >> n;
    while(n--) {
        int val;
        cin >> val;
        s1.push(val);
    }
    
    while(!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }
    
    while(!s2.empty()) {
        cout << s2.top() << " ";
        s2.pop();
    }
    return 0;
}
