#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
    int val;
    Node *left;
    Node *right;
    
    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* inputTree() {
    queue<Node*>q;
    int val;
    cin >> val;
    if(val == -1) {
        return NULL;
    }
    
    Node* root = new Node(val);
    q.push(root);
    
    
    while(!q.empty()) {
        Node* f = q.front();
        q.pop();
        
        int l,r;
        Node*myL,*myR;
        cin >> l>>r;
        
        if(l == -1) myL = NULL;
        else myL = new Node(l);
        
        if(r == -1) myR = NULL;
        else myR = new Node(r);
        
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

bool search(Node* root, int v) {
    if (root == NULL) {
        return false;
    }
    
    if (root->val == v) {
        return true;
    }
    if(root ->val > v) {
        return search(root->left, v);
    }else {
        return  search(root->right, v);
    }
    
    //return search(root->left, v) || search(root->right, v);
}


int main() {
    Node* root = inputTree();
    
    bool operation = search(root,15);
    
    if(operation) cout << "Found";
    else cout << "Not Found";

    return 0;
}
