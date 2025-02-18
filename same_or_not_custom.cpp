/*
Problem Statement

There is a list of  values that were inserted into a stack and a list of  values that were inserted into a queue. You need to determine whether the stack and queue are the same or not based on the order in which the elements are removed.

Note: You cannot use any  here. You need to implement the stack and queue by yourself. You can use linked list or array as you want.

Input Format

First line will contain  and .
Second line will contain stack  with  values.
Third line will contain queue  with  values.
Constraints

Output Format

Output YES if they were same, otherwise NO.
Sample Input 0

5 5
10 20 30 40 50
50 40 30 20 10
Sample Output 0

YES
Sample Input 1

4 4
10 20 30 40
10 20 30 40
Sample Output 1

NO
Sample Input 2

5 4
1 2 3 4 5
5 4 3 2
Sample Output 2

NO
*/



#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    Node* next;
    Node* prev;
    int val;
    
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class Queue {
    public:
    Node* head = NULL;
    Node* tail = NULL;
    
    int sz = 0;
    
    void push(int val) {
        sz++;
        Node* newNode =new Node(val);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }
        
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    
    void pop() {
        sz--;
        Node* deleteNode = head;
        head = head->next;
        
        delete deleteNode;
        if(head == NULL) {
            tail == NULL;
            return;
        }
        
        head->prev = NULL;
        
    }
    
    int front() {
        return head->val;
    }
    int back() {
        return tail->val;
    }
    
    int size() {
        return sz;
    }
    
    bool empty() {
        return head == NULL;
    }
};

class Stack {
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
    Stack a;
    Queue b;
    
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        a.push(val);
    }
    
    for (int i = 0; i < m; i++) {
        int val;
        cin >> val;
        b.push(val);
    }
    
    bool isSame = true;
    
    if (a.size() != b.size()) {
        isSame = false;
    } else {
        while (!a.empty() && !b.empty()) {
            if (a.top() != b.front()) {
                isSame = false;
                break;
            }
            a.pop();
            b.pop();
        }
    }
    
    if (isSame) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}



