#include<bits/stdc++.h>
using namespace std;
class Node1 {
    public:
    int val;
    Node1* next;

    Node1(int val) {
        this->val = val;
        this->next = NULL; 
    }
};

int main () {
    Node1 a(20),b(34),c(32),d(1);

    a.next = &b;
    b.next = &c;
    c.next = &d;

    cout << a.val << endl;
    cout << a.next->val << endl;
    cout << a.next->next->val << endl;
    cout << a.next->next->next->val << endl;
}