// Is Binary Tree Heap
// https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
class Solution2 {
  public:
  bool isMax(struct Node* tree,int i,int &cnt){
      if(tree==NULL)
        return true;
      if(i>=++cnt)
        return false;
      bool left = isMax(tree->left,2*i+1,cnt);
      bool right = isMax(tree->right,2*i+2,cnt);
      return (left && right);
      
  }
  bool isOrder(struct Node* tree){
      if(tree==NULL){
          return true;
      }
      if(tree->left==NULL && tree->right==NULL)
        return true;
      if(tree->right==NULL){
          return tree->data>tree->left->data;
      }
      bool left=isOrder(tree->left);
      bool right=isOrder(tree->right);
      return ( left && right && tree->data>tree->left->data && tree->data>tree->right->data);
  }
    bool isHeap(struct Node* tree) {
        // code here
        int count=0;
        if(isMax(tree,0,count) && isOrder(tree)){
            return true;
        }
        return false;
    }
};
class Solution1 {
  public:
  int countNodes(struct Node* tree){
      if(tree==NULL)
        return 0;
      return 1+countNodes(tree->left)+countNodes(tree->right);
  }
  bool isMax(struct Node* tree,int i,int cnt){
      if(tree==NULL)
        return true;
      if(i>=cnt)
        return false;
      bool left = isMax(tree->left,2*i+1,cnt);
      bool right = isMax(tree->right,2*i+2,cnt);
      return (left && right);
      
  }
  bool isOrder(struct Node* tree){
      if(tree==NULL){
          return true;
      }
      if(tree->left==NULL && tree->right==NULL)
        return true;
      if(tree->right==NULL){
          return tree->data>tree->left->data;
      }
      bool left=isOrder(tree->left);
      bool right=isOrder(tree->right);
      return ( left && right && tree->data>tree->left->data && tree->data>tree->right->data);
  }
    bool isHeap(struct Node* tree) {
        // code here
        int nodesCnt= countNodes(tree);
        if(isMax(tree,0,nodesCnt) && isOrder(tree)){
            return true;
        }
        return false;
    }
};