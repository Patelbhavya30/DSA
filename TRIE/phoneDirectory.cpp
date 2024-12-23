// Implement a phone directory
// https://www.naukri.com/code360/problems/implement-a-phone-directory_1062666?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
#include<bits/stdc++.h>
using namespace std; 
class TrieNode{
    public:
    char data;
    bool isEnd;
    TrieNode* children[26];
    TrieNode(char data){
        this->data=data;
        this->isEnd=false;
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

    void insert(string word){
        TrieNode* temp=root;
        while(word.length()>0){
            int index=word[0]-'a';
            TrieNode* child;
            if(temp->children[index]!=NULL){
               child=temp->children[index];
            }else{
                child=new TrieNode(word[0]);
                temp->children[index]=child;
            }
            temp=child;
            word=word.substr(1);
        }
        temp->isEnd=true;
    }

void printSuggestions(vector<string> &temp,TrieNode* curr,string &prefix){
    if(curr->isEnd){
        temp.push_back(prefix);
    }

    for(char ch ='a';ch<='z';ch++){
        TrieNode* next=curr->children[ch-'a'];
        if(next!=NULL){

        prefix.push_back(ch);
        printSuggestions(temp,next,prefix);
        prefix.pop_back();
        }
    }

    
}
    vector<vector<string>> getSuggestions(string query){
        vector<vector<string>> output;
        string prefix="";
        TrieNode* prev=root;
        for(auto i:query){
        vector<string> temp;
            prefix.push_back(i);
            TrieNode* curr=prev->children[i-'a'];
            if(curr==NULL){
                break;
            }
            printSuggestions(temp,curr,prefix);
            output.push_back(temp);
            temp.clear();
            prev=curr;
        }
        return output;

    }

};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //    Write your code here.
    Trie* t=new Trie();
    for(auto i:contactList){
      t->insert(i);
    }
    // Time Complexity:O(n*m^2) space complexity:O(n*m)
    return t->getSuggestions(queryStr);
}