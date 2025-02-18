/*
Problem Statement

You will be given a binary tree as input in level order. You need to output the sum of all node's values in that tree except the leaf nodes.

For example:                           10
                                      /  \
                                    20    30
                                   /  \     \
                                 40    50    60




image

The output for the above tree will be: 60

Input Format

Input will contain the binary tree in level order.  means there is no node available.
Constraints

 Maximum number of nodes 
 Node's value 
Output Format

Output the total sum of that tree except the leaf nodes.
Sample Input 0

10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
Sample Output 0

60
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

int sumWithOutLeafNode(Node* root) {
    if(root == NULL) {
        return 0;
    }
    
    int count = 0;
    if (root->left != NULL || root->right != NULL) {
        count += root->val;
    }

    count += sumWithOutLeafNode(root->left);
    count += sumWithOutLeafNode(root->right);
    
    return count;
    
}


int main() {
    
    Node* root =inputTree();
    int r = sumWithOutLeafNode(root);
    cout << r;
    
    return 0;
}
