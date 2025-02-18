/*
  Problem Statement

You will be given a binary tree as input in level order. You need to print the values of leaf nodes in descending order.

For example:
                                       10
                                      /  \
                                    20    30
                                   /  \     \
                                 40    50    60


image

The output for the above tree will be: 60 50 40

Input Format

Input will contain the binary tree in level order.  means there is no node available.
Constraints

 Maximum number of nodes 
 Node's value 
Output Format

Output the values of leaf nodes in descending order.
Sample Input 0

10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
Sample Output 0

60 50 40
*/

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

void countLeafNode(Node* root, vector<int>& l) {
    if (root == NULL) {
        return;
    }
    
    if (root->left == NULL && root->right == NULL) {
        l.push_back(root->val);
    }

    countLeafNode(root->left, l);
    countLeafNode(root->right, l);
}

int main() {
    Node* root = inputTree();

    vector<int> l;
    countLeafNode(root, l);

    sort(l.begin(), l.end());
    for(int i = l.size() - 1; i >= 0 ;i--) {
        cout << l[i] << " ";
    }

    return 0;
}
