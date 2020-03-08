// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 
  
class Node { 
public: 
    int data; 
    Node *left, *right; 
}; 
  
// A utility function to create 
// a new Binary Tree Node 
Node* newNode(int item) 
{ 
    Node* temp = new Node(); 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
// Recursive function to find the sum of nodes 
// of the left view of the given binary tree 
void sumLeftViewUtil(Node* root, int level, int* max_level, int* sum) 
{ 
    // Base Case 
    if (root == NULL) 
        return; 
  
    // If this is the first Node of its level 
    if (*max_level < level) { 
        *sum += root->data; 
        *max_level = level; 
    } 
  
    // Recur for left and right subtrees 
    sumLeftViewUtil(root->left, level + 1, max_level, sum); 
    sumLeftViewUtil(root->right, level + 1, max_level, sum); 
} 
  
// A wrapper over sumLeftViewUtil() 
void sumLeftView(Node* root) 
{ 
    int max_level = 0; 
    int sum = 0; 
    sumLeftViewUtil(root, 1, &max_level, &sum); 
    cout << sum; 
} 
  
// Driver code 
int main() 
{ 
    Node* root = newNode(12); 
    root->left = newNode(10); 
    root->right = newNode(30); 
    root->right->left = newNode(25); 
    root->right->right = newNode(40); 
  
    sumLeftView(root); 
  
    return 0; 
} 
