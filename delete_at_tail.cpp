#include<bits/stdc++.h>
using namespace std;

class Node {
    public :
    int val;
    Node* next;
    Node* prev;
    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
        
    }
};    

void print_forword(Node* head) {
    Node* tmp = head;
    while(tmp != NULL) {
        cout << tmp->val <<" ";
        tmp = tmp->next;
    }
    cout << endl;
}

void print_backword(Node* tail) {
    Node* tmp = tail;
    while(tmp != NULL) {
        cout << tmp->val <<" ";
        tmp = tmp->prev;
    }
    cout << endl;
}

void deleteAtTail(Node* &head,Node* &tail) {
    Node* deleteTail = tail;
    tail = tail->prev;
    delete deleteTail;
    if(tail == NULL) {
        head = NULL;
        return;
    }
    tail->next = NULL;
}

int main() {
    Node* head = new Node(10);
    Node* a = new Node(20);
    Node* tail = new Node(30);

    head->next = a;
    a->prev = head;
    a->next = tail;
    tail->prev = a;
    
    
    deleteAtTail(head,tail);
    deleteAtTail(head,tail);
    deleteAtTail(head,tail);



    print_forword(head);
    print_backword(tail);

}