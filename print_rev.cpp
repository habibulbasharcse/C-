#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void addValue(Node* &head, Node* &tail, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = tail->next;
    }
}

void print_riv(Node* &head) {
    if(head == NULL) {
        return;
    }

    print_riv(head->next);
    cout <<head->val << " "; 
    
}


   
int main() {
    Node* head = NULL;
    Node* tail = NULL;

    
    while (true) {
        int val;
        cin >> val;
        if (val == -1) {
            break;
        }
        addValue(head, tail, val);
        
    }
    print_riv(head);

}
