#include<bits/stdc++.h>
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

void insertLinkedList(Node* &head,Node* &tail,int val) {
    Node* newNode = new Node(val);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
    }
    tail->next = newNode;
    tail = tail->next;
}

int  print(Node* head) {
    int count = 0;
    Node* tmp = head;
    while (tmp != NULL) {
        tmp = tmp->next;
        count++;
    }

    return count;
    
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;

    int val;

    while (true)
    {
        cin >> val;
        if(val == -1) {
            break;
        }
        insertLinkedList(head,tail,val);

    }

    cout << print(head) << endl;
    
} 
