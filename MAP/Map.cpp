#include<unordered_map>
#include<map>
#include<iostream>
using namespace std;

// Time Complexity unordered_map insertion, deletion, access: O(1)
// Time Complexity map insertion, deletion, access: O(logn) it is based on bst
int main(){
    unordered_map<string, int> umap;
    map<string, int> map;
    // Insert
    umap["bhavya"] = 1;
    pair<string, int> p("patel", 2);
    umap.insert(p);
    pair<string,int> p1 = make_pair("hello", 3);
    umap.insert(p1);

    // Access
    cout<<umap["bhavya"]<<endl; 
    cout<<umap.at("patel")<<endl;
    // cout<<umap.at("unknown")<<endl; // This will throw an exception
    cout<<umap["unknown"]<<endl; // This will insert the key with value 0 and return 0

    // Size
    cout<<umap.size()<<endl;

    // Check if key exists
    umap.count("bhavya"); // It will return 1 if key exists else 0

    // Erase
    umap.erase("bhavya");
    umap.erase("bhavya"); // It will not throw an exception if key does not exist
    cout<<umap.size()<<endl;

    // Iterate
    for(auto i:umap){
        cout<<i.first<<" "<<i.second<<endl;
    }
    for(auto i=umap.begin();i!=umap.end();i++){
        cout<<i->first<<" "<<i->second<<endl;
    }
    unordered_map<string, int>::iterator it = umap.begin();
    while(it!=umap.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
    return 0;
}