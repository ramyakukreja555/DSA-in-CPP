#include<iostream>
using namespace std;
bool dfs(int node,int parent,vector<int>&vis,vector<int>adj[]){
        vis[node]=1;
        for(auto adjacentnode:adj[node]){
            if(!vis[adjacentnode]){
               if (dfs(adjacentnode,node,vis,adj)==true) return true;
            }
            else if(adjacentnode!=parent) return true; 
        } 
        return false;
}
bool isCycle(int V,vector<int>adj[]){
    vector<int>vis(V,0);
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(dfs(i,-1,vis,adj)==true) return true;
        }
    }
    return false;
}
int main(){
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<int> adj[V];

    cout << "Enter edges:\n";
    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(isCycle(V, adj)) {
        cout << "Cycle detected";
    }
    else {
        cout << "No cycle detected";
    }

    return 0;
}

