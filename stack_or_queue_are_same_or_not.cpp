
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

class Node{
    public:
    Node* next;
    int val;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class Queue{
    public:
    Node* head = NULL;
    Node* tail = NULL;
    
    int sz = 0;
     
    void push(int val) {
        sz++;
        Node* newNode = new Node(val);
        if(head == NULL) {
             head = newNode;
             tail = newNode;
             return;
        }
        tail->next = newNode;
        tail = newNode;
         
    }
    
    void pop() {
        sz--;
        if(head == NULL)
            return;
        Node* deleteNode = head;
        head = head->next;
        delete deleteNode;
    }
    
    int front() {
        return head->val;
    }
    
    int size() {
        return sz;
    }
    
    bool empty() {
        return head == NULL;
    }
    
};

int main() {
    Stack s1;
    Queue q1;
    
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
