#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

template<typename T>
class graph{
    public:
    unordered_map<T,list<T>> adj;

    void add_edge(T u,T v,bool directed){
        // false: for undirected graph
        // true: for directed graph
        adj[u].push_back(v);
        if(!directed){
            adj[v].push_back(u);
        }

    }
    void print(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<",";
            }
            cout<<endl;
        }
    }
};
int main(){

    graph<int> g;
    int n,e;
    cout<<"Enter the number of nodes and edges: ";
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int u,v;
        cout<<"Enter the edge: ";
        cin>>u>>v;
        g.add_edge(u,v,false);
    }
    g.print();

    return 0;
}