/*
    Problem Statement

You will be given a binary tree as input in level order. You need to tell if the binary tree is perfect or not. A binary tree is called perfect if all leaf nodes are at the maximum depth of the tree, and the tree is completely filled with no gaps.

Here is an example of perfect binary tree:

image

Also there is formula available to tell if a binary tree is perfect or not. The formula is :

Total number of nodes = -1
Note: Here depth is counted from . In the above image maximum depth is , so total number of nodes are . So there should be  nodes to call it a perfect binary tree.

Image Source: OpenGenus Iq

Input Format

Input will contain the binary tree in level order.  means there is no node available.
Constraints

 Maximum number of nodes 
 Node's value 
Output Format

Output  if the tree is perfect,  otherwise.
Sample Input 0

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 0

YES
Sample Input 1

10 20 30 40 -1 60 -1 -1 -1 -1 -1
Sample Output 1

NO
Sample Input 2

10 20 -1 -1 -1
Sample Output 2

NO
Sample Input 3

10 20 30 40 50 60 70 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 3

YES
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

int nodeLevel(Node* root) {
    queue<pair<Node*,int>> q;
    if(root != NULL) {
        q.push({root,1});
    }
    int level = 0;
    
    while(!q.empty()) {
        pair<Node*,int> p = q.front();
        q.pop();
        
        Node* node = p.first;
        level = p.second;
        
        if(node->left != NULL) {
            q.push({node->left,level+1});
        }
        
        if(node->right != NULL) {
            q.push({node->right,level+1});
        }
    }
    return level;
}
int totalNode(Node* root) {
    if (root == NULL) {
        return 0;
    }
    

    int l = totalNode(root->left);
    int r = totalNode(root->right);

    return 1 + l + r;
}


int main() {
    Node* root = inputTree();

    int level = nodeLevel(root);
    int total = totalNode(root);
    if((pow(2,level)) -1 == total)  cout << "YES";
    else cout<<"NO";
   
    

    return 0;
}
