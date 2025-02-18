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

bool isCycle(Node* slow,Node* fast) {
    bool flag = false;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            flag = true;
            break;
        }
    }

    return flag;
}

void insert_at_tail(Node* &head,Node* &tail,int val) {
    Node* newNode = new Node(val);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
    }
    tail->next = newNode;
    newNode->prev = tail ;
    tail = newNode;
    newNode->next = NULL;
}

void print(Node* head) {
    Node* tmp = head;
    while (tmp != NULL) {
        cout << tmp->val << " " ;
        tmp = tmp->next;
    }
    cout << endl;


}

void rev_linked_list(Node* &head,Node* &tail,Node* tmp) {
    if(tmp->next == NULL) {
        head = tmp;
        return;
    }
    rev_linked_list(head,tail,tmp->next);
    tmp->next->next = tmp;
    tmp->next = NULL;
    tail =tmp;


}


int main() {
    Node* head = NULL;
    
    Node* tail = NULL;

    int val;

    while (true)
    {
        cin >> val;
        if(val == -1) {
            break;
        }
        insert_at_tail(head,tail,val);
    }
    
   
    rev_linked_list(head,tail,head);
    print(head);


    bool operation = isCycle(head,head);

    if(operation) {
        cout <<"Cycle Ditect" << endl;
    }else {
        cout <<"No Cycle Ditect" << endl;
    }

}