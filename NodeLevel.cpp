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

int nodeLevel(Node* root,int findNum) {
    queue<pair<Node*,int>> q;
    if(root != NULL) {
        q.push({root,1});
    }
    
    while(!q.empty()) {
        pair<Node*,int> p = q.front();
        q.pop();
        
        Node* node = p.first;
        int level = p.second;
        
        if(node->val == findNum) {
            return level;
        }
        
        if(node->left != NULL) {
            q.push({node->left,level+1});
        }
        
        if(node->right != NULL) {
            q.push({node->right,level+1});
        }
    }
    return -1;
}


int main() {
    
    Node* root =inputTree();
    
    int findNum;
    cin >> findNum;
    
    int r = nodeLevel(root,findNum);
    
    cout << r;
    return 0;
}
