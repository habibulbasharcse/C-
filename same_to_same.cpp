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


void isSame(Node* head,Node* head1,int idx,int idx1) {
    
    Node* tmp = head;
    Node* tmp1 = head1;
    int check = 0;
    if(idx != idx1) {
        cout <<"NO";
        return;
    }else {
        while(tmp != NULL && tmp1 != NULL) {
            if(tmp->val != tmp1->val) {
                cout <<"NO";
                return;
            }
            tmp = tmp->next;
            tmp1 = tmp1->next;
        }
    }
      cout << "YES" << endl;
    
}


int main()
{
    int t;
    int count = 0;
    int count1 = 0;
    
    Node* head = NULL;
    Node* tail = NULL;
    Node* head1 = NULL;
    Node* tail1 = NULL;
    
    while (true) {
        int val;
        cin >> val;
        if(val == -1) {
            break;
        }
        count++;
        input_Value_in_Linked_list(head,tail,val);
    }

    while (true) {
        int val;
        cin >> val;
        if(val == -1) {
            break;
        }
        count1++;
        input_Value_in_Linked_list(head1,tail1,val);
    }
    isSame(head,head1,count,count1);

    return 0;
}
