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

int size(Node* &head) {
    Node* tmp = head;
    int count = 0;
    while (tmp != NULL) {
        tmp = tmp->next;
        count++;
    }
    return count;
}


   
int main() {
    Node* head = NULL;
    Node* tail = NULL;

    Node* head1 = NULL;
    Node* tail1 = NULL;


    int index = 0;
    int index1 = 0;

    
    while (true) {
        int val;
        cin >> val;
        if (val == -1) {
            break;
        }
        addValue(head, tail, val);
        index++;
    }
    while (true) {
        int val;
        cin >> val;
        if (val == -1) {
            break;
        }
        addValue(head1, tail1, val);
        index1++;
    }
    int x,y;
    x = size(head);
    y = size(head1);

    // if(index1 == index) {
    //     cout <<"YES";
    // }else {
    //     cout <<"NO";
    // }

    if(x == y) {
        cout <<"YES";
    }else {
        cout <<"NO";
    }

    return 0;
}
