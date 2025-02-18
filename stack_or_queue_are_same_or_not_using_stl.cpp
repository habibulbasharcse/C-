
#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> s1;
    queue<int> q1;
    
    int n,m;
    
    cin >> n;
    while(n --) {
        int val;
        cin >> val;
        s1.push(val);
    }
    cin >> m;
    
    while(m--) {
        int val;
        cin >> val;
        q1.push(val);
    }
    
    int flag = 0;
    
    if(s1.size() == q1.size()) {
        while(!s1.empty() && !q1.empty()) {
            if(s1.top() != q1.front()) {
                flag = 1;
                break;
            }
            s1.pop();
            q1.pop();
            
        }
    }else {
        flag = 1;
    }
    
    if(flag == 0) {
        cout << "YES";
    }else{
        cout << "NO";
    }
    

    return 0;
}
