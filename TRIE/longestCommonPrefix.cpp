// Longest common prefix
// https://www.naukri.com/code360/problems/longest-common-prefix_2090383?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
#include <bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
    char data;
    bool isTerminal;
    int childCount;
    TrieNode* children[26];
    TrieNode(char data){
        this->data=data;
        this->childCount=0;
       this->isTerminal=false;
       for(int i=0;i<26;i++){
           children[i]=NULL;
       }
   }

};
class Trie{
   public:
   TrieNode* root;
   Trie(){
       root=new TrieNode('\0');
   }
   string ans="";
   void insertUtil(TrieNode* top,string word){
       if(word.length()==0){
           top->isTerminal=true;
           return;
       }
       int index = word[0]-'a';
       TrieNode* child;
       if(top->children[index]!=NULL){
           child=top->children[index];
           if(top->childCount==1){
           ans.push_back(child->data);
           }
           else{
               return;
           }
       }
       else{
           child=new TrieNode(word[0]);
           top->children[index]=child;
           ++top->childCount;
       }
       insertUtil(child,word.substr(1));
   }
   void insert(string word){
       ans="";
       insertUtil(root,word);
   }
};

// Time Complexity: O(N*M) space complexity: O(N*M)
// second solution is check for each character of the first string with all the strings time complexity: O(N*M) space complexity: O(1)
string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    Trie* trie= new Trie();
    for(auto i:arr){
       trie->insert(i);
    }
    string ans=arr[0];
    return trie->ans;
}


