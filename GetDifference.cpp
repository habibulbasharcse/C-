#include <bits/stdc++.h>

using namespace std;
class Node {
    public :
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};


void input_Value_in_Linked_list(Node* &head,Node* &tail,int val) {
    Node* newNode = new Node(val);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
    }else {
        tail->next = newNode;
        tail = newNode;
    }
}

int find_max(Node* head) {
    
    Node* tmp = head;
    int mx = tmp->val;
    while(tmp != NULL) {
        if(tmp->val > mx) {
            mx = tmp->val;
        }
        tmp = tmp->next;
    }
    return mx;
}

int find_min(Node* head) {
    
    Node* tmp = head;
    int mn = tmp->val;
    while(tmp != NULL) {
        if(tmp->val < mn) {
            mn = tmp->val;
        }
        tmp = tmp->next;
    }

    return mn;

}


int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    int val;
    int count = 0;

    while (true) {
        
        cin >> val;
        if(val == -1) {
            break;
        }
        count++;
        input_Value_in_Linked_list(head,tail,val);
    }
    

    int min = find_min(head);
    int max = find_max(head);

    cout << max - min;


    return 0;
}
