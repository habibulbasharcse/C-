/*
Problem Statement

You will be given a binary tree as input in level order. Also you will be given a level . You need to print all the node's values in that level from left to right. Assume that level starts from .

For example:

image

If , then the output for the above tree will be: 40 50 60

Note: If the level  is not a valid level, the print "Invalid".

Input Format

Input will contain the binary tree in level order.  means there is no node available.
Constraints

 Maximum number of nodes 
 Node's value 
Output Format

Output all the node's values in level .
Sample Input 0

10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
0
Sample Output 0

10
Sample Input 1

10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
1
Sample Output 1

20 30
Sample Input 2

10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
2
Sample Output 2

40 50 60
Sample Input 3

10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
3
Sample Output 3

Invalid
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

int countLevel(Node* root) {
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

vector<int> nodeLevel(Node* root,int val) {
    vector<int> v;
    queue<pair<Node*,int>> q;
    if(root != NULL) {
        q.push({root,0});
    }
    
    
    while(!q.empty()) {
        pair<Node*,int> p = q.front();
        q.pop();
        
        Node* node = p.first;
        int level = p.second;
        
        if(level == val) {
            v.push_back(node->val);
        }
        
        if(node->left != NULL) {
            q.push({node->left,level+1});
        }
        
        if(node->right != NULL) {
            q.push({node->right,level+1});
        }
    }
    return v;
}


int main() {
    Node* root = inputTree();
    int val;
    cin >> val;

    vector<int> v = nodeLevel(root,val);
    int level = countLevel(root);
    
    if(level > val) {
        for(int n : v) {
        cout << n<<" ";
        }
    }else {
        cout << "Invalid";
    }

    return 0;
}
