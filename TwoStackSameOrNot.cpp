
#include <bits/stdc++.h>
using namespace std;

class Stack {
    public:
    vector<int> v;
    
    void push(int val) {
        v.push_back(val);
    }
    
    void pop() {
        v.pop_back();
    }
    
    int size() {
        return v.size();
    }
    
    int top() {
        return v.back();
    }
    
    bool empty() {
        return v.empty();
    }
};

int main() {
    Stack s1;
    Stack s2;
    
    int n,n2;
    
    cin >> n;
    while(n --) {
        int val;
        cin >> val;
        s1.push(val);
    }
    cin >> n2;
    
    while(n2--) {
        int val;
        cin >> val;
        s2.push(val);
    }
    
    int flag = 0;
    
    if(s1.size() == s2.size()) {
        while(!s1.empty() && !s2.empty()) {
            if(s1.top() != s2.top()) {
                flag = 1;
                break;
            }
            s1.pop();
            s2.pop();
            
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
