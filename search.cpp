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


int search(Node* head,int srch) {
    Node* tmp = head;
    int idx = 0;
    while(tmp != NULL) {
        if(tmp->val ==srch) {
            return idx;
        }
        tmp = tmp->next;
        idx++;
    }

    return -1;
}


int main()
{
    int t;
    cin >> t;
    while(t--) {
        Node* head = NULL;
        Node* tail = NULL;

        int val;

        while (true) {
        
            cin >> val;
            if(val == -1) {
            break;
            }
            input_Value_in_Linked_list(head,tail,val);
        }

        int x;
        cin >> x;
        int idx = search(head,x);
        cout << idx <<endl;

    }

    return 0;
}
