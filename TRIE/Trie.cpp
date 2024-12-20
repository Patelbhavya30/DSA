#include<iostream>
using namespace std;

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

class Trie{
    public:
    TrieNode* root;

    Trie()
    {
        root = new TrieNode();
    }
    void insertUtil(TrieNode* root, string word)
    {
        if(word.size()==0)
        {
            root->isTerminal = true;
            return;
        }
        // Assuming all characters are capital letters
        int index = word[0]-'A';
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

    void insert(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word)
    {
        if(word.size()==0)
        {
            return root->isTerminal;
        }
        int index = word[0]-'A';
        if(root->children[index]==NULL)
        {
            return false;
        }
        return searchUtil(root->children[index], word.substr(1));
    }
 
    bool search(string word)
    {
        return searchUtil(root, word);
    }
};
int main()
{
    Trie* t=new Trie();
    t->insert("HELLO");
    t->insert("TIME");
    t->insert("BHAVYA");
    t->insert("PATEL");
    cout<<"Present or not HELLO "<<t->search("HELL")<<endl;
    cout<<"Present or not BHAVYA "<<t->search("BHAVYA")<<endl;
    cout<<"Present or not TIMEA "<<t->search("TIMEA")<<endl;
    return 0;
}