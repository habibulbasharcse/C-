
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
    int arr[100] ={0};

    int val;

    while (true)
    {
        cin >> val;
        if(val == -1) {
            break;
        }
        insertLinkedList(head,tail,val);

    }


    Node* tmp = head;
    int count = 0;

    while (tmp->next != NULL) 
    {
        tmp = tmp->next;
        count++;

    }
    int len = count / 2;
    Node* tmp1 = head;
    for(int i = 0; i < len;i++) {
        tmp1 = tmp1->next;
    }
    if(count % 2 == 0) {
        cout << tmp1->val;
    } else {
        cout << tmp1->val<<" ";
        tmp1 = tmp1->next;
        cout << tmp1->val << endl;


    }


    

} 
