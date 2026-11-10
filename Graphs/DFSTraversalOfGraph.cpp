#include<iostream>
#include<queue>
#include<vector>
using namespace std;
void dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&ls){
    vis[node]=1;
    ls.push_back(node);
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,ls);
        }
    }
}
vector<int>dfsofgraph(int V , vector<int>adj[]){
    // 0 based indexing graph
    vector<int>vis(V,0);
    int start=0;
    vector<int>ls;
    dfs(start,adj,vis,ls);
    return ls;

}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>adj[n];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>ans;
    ans= dfsofgraph(n,adj);
    for(auto it : ans) {
    cout << it << " ";
}
    return 0;

}