// Implement Trie
// https://www.naukri.com/code360/problems/implement-trie_631356?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar
#include<bits/stdc++.h>
using namespace std;
/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
class TrieNode
{
    public:
    // char data;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode()
    {
        // this->data = data;
        isTerminal = false;
        for(int i=0;i<26;i++)
        {
            children[i] = NULL;
        }
    }
};


class Trie {

public:

        TrieNode* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    void insertUtil(TrieNode* root, string word)
        {
            if(word.size()==0)
            {
                root->isTerminal = true;
                return;
            }
            // assuming all characters are capital letters
            int index = word[0]-'a';
            TrieNode* child;
            if(root->children[index]!=NULL)
            {
                child = root->children[index];
            }
            else
            {
                child = new TrieNode();
                root->children[index] = child;
            }
            insertUtil(child, word.substr(1));
        }

    /** Inserts a word into the trie. */
    void insert(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word)
        {
            if(word.size()==0)
            {
                return root->isTerminal;
            }
            int index = word[0]-'a';
            if(root->children[index]==NULL)
            {
                return false;
            }
            return searchUtil(root->children[index], word.substr(1));
        }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchUtil(root, word);
    }

    bool startsWithUtil(TrieNode* root, string word)
        {
            if(word.size()==0)
            {
                return true;
            }
            int index = word[0]-'a';
            if(root->children[index]==NULL)
            {
                return false;
            }
            return startsWithUtil(root->children[index], word.substr(1));
        }
    

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return startsWithUtil(root, prefix);

    }
};