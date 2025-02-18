// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class Node {
    public :
    int val;
    Node* left;
    Node* right;
    
    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* input_tree() {
    int val;
    cin >> val;
    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* f = q.front();
        q.pop();
        Node *myL,*myR;
        int l,r;
        cin >> l >> r;
        
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

int count_leaf_node(Node* root) {
    if(root == NULL) {
        return 0;
    }
    if(root->left == NULL & root->right == NULL) {
        return 1;
    }
    
    int l = count_leaf_node(root->left);
    int r = count_leaf_node(root->right);
    
    return l+r;
}



int main() {
    Node* root = input_tree();
    int totalNode = count_leaf_node(root);
    
    cout<<"total leaf node:" <<totalNode;
    

    return 0;
}
