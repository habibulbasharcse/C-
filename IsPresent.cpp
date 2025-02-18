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
    if (val == -1) {
        // If the root is -1, return NULL (empty tree).
        return NULL;
    }
    Node*root = new Node(val);
    queue<Node*>q;
    
    q.push(root);
    while(!q.empty()) {
        Node* f = q.front();
        q.pop();
        
        int l,r;
        cin >> l >> r;
        Node*myL,*myR;
        
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

bool findNumber(Node* root,int findNum) {
    if(root == NULL) {
        return false;
    }
    if(root->val == findNum) {
        return true;
    }
    return findNumber(root->left,findNum) || findNumber(root->right,findNum);
}


int main() {
    Node * root = inputTree();
    if(findNumber(root,7)) cout <<"True" ;
    else cout << "False";

    return 0;
}
