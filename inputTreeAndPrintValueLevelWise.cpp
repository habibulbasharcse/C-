
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int val;
    Node* left;
    Node* right;
    
    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
 Node* inputTree() {
     int val;
     cin >> val;
     
     Node* root;
     if(val == -1) root = NULL;
     else root = new Node(val);
     queue<Node*> q;
     if(root != NULL) q.push(root);
     else return NULL;
     
     while(!q.empty()) {
         Node* f = q.front();
         q.pop();
         int l,r;
         cin>> l >> r;
         Node* myL,*myR;
         
         if(l == -1) {
             myL = NULL;
         }else {
             myL = new Node(l);
         }
         
         if(r == -1) {
             myR = NULL;
         }else {
             myR = new Node(r);
         }
         
         f->left = myL;
         f->right = myR;
         
         if(f->left != NULL) {
             q.push(f->left);
         }
         
         if(f->right != NULL) {
             q.push(f->right);
         }
     }
     return root;
 }
 
 void levelOrder(Node* root) {
     
     if(root == NULL) {
         cout << "NO TREE";
         return;
     }
     queue<Node*> q;
     q.push(root);
     
     while(!q.empty()) {
         Node* f = q.front();
         q.pop();
         
         cout << f->val << " ";
         
         if(f->left != NULL) {
             q.push(f->left);
         }
         
         if(f->right != NULL) {
             q.push(f->right);
         }
     }
 }


int main() {
    Node* root = inputTree();
    levelOrder(root);
    return 0;
}
