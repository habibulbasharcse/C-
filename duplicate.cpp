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
    int i = 0;

    while (tmp != NULL) 
    {
        if(tmp->val != -1) {
            arr[tmp->val] += 1;
        }
        tmp = tmp->next;
        i++;
    }
    int bol = 0;
    for(int i = 0; i < 100;i++) {
        if(arr[i] >= 2) {
            bol = 1;
            break;
        }
    }

    if(bol) {
        cout << "YES";
    }else {
        cout << "NO";
    }

     
    
    
} 
