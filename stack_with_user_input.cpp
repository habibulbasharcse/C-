#include <bits/stdc++.h>
using namespace std;

class MyStack {
    public :
    std::vector<int> v ;
    
    void push(int val) {
        v.push_back(val);
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        return v.back();
    } 
    
    bool empty() {
        return v.empty();
    }
    
    int size() {
        return v.size();
    }
    
};

int main() {
    MyStack ms;
    
    int n;
    cin >> n;
    
    for(int i = 0; i < n;i++) {
        int val;
        cin >> val;
        
        ms.push(val);
    }
    
     while(!ms.empty()){
        cout << ms.top()<< " ";
        ms.pop();
    }
          
  
     
     

}
