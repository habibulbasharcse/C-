#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> s;
    queue<int> q;
    queue<int>q1;
    
    int n;
    cin >> n;
    
    while(n--) {
        int val;
        cin >> val;
        q.push(val);
    }
    
    while(!q.empty()) {
        s.push(q.front());
        q.pop();
    }
    
    while(!s.empty()) {
        q1.push(s.top());
        s.pop();
    }
    
    while(!q1.empty()) {
        cout << q1.front() << " ";
        q1.pop();
    }
}
