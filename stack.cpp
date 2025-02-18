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
    
    ms.push(10);
    ms.push(20);
    ms.push(30);
    ms.push(40);
    
    if(!ms.empty())
        ms.pop();
        
    if(!ms.empty())
        ms.pop();
    
    if(!ms.empty())
        ms.pop();
    
    /*if(!ms.empty())
        ms.pop();
        */
        
    if(!ms.empty())
        cout << ms.top();
          
  
     
     

}
