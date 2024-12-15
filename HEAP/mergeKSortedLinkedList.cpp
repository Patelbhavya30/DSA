// Merge k sorted linked lists
// https://www.naukri.com/code360/problems/merge-k-sorted-lists_992772?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SOLUTION
#include <bits/stdc++.h> 
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

class compare{
    public:
    bool operator()(Node* a,Node* b){
        return a->data>b->data;

    }

};
// Time Complexity: O(Nlog(K)) Space Complexity: O(K)
Node* mergeKLists(vector<Node*> &listArray){
    // Write your code here.
    priority_queue<Node*,vector<Node*>,compare> minHeap;
    for(int i=0;i<listArray.size();i++){
        minHeap.push(listArray[i]);
    }
      Node* head=minHeap.top();
      Node* temp=head;
      minHeap.pop();
      if(temp->next){
          minHeap.push(temp->next);
      }
    while(!minHeap.empty()){
      Node* topNode=minHeap.top();
      minHeap.pop();
      temp->next=topNode;
      if(topNode->next){
        minHeap.push(topNode->next);
      }
      temp=topNode;
    }

    return head;

}
