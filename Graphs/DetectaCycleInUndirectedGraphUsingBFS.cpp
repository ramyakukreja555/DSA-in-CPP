#include<iostream>
#include<queue>
#include<vector>
using namespace std;
bool detect(int src,vector<int>adj[],vector<int>&vis){
    vis[src] = 1;
    queue<pair<int,int>>q;
    q.push({src,-1});
    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second; 
        q.pop();
        for(auto adjacentnode:adj[node]){
              if(!vis[adjacentnode]){
                vis[adjacentnode]=1;
                q.push({adjacentnode,node});
              } 
              else if(parent!=adjacentnode){
                return true;
              } 
        }
    }
    return false;


}

bool isCycle(int V,vector<int>adj[]){
         vector<int>vis(V,0);
         for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect(i,adj,vis)) return true;
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