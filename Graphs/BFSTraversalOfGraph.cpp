#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> bfsofgraph(int V,vector<int>adj[]){
   queue<int>q;
   vector<int>vis(V,0);
   vis[0]=1;
   q.push(0);// queue will have starting node
   vector<int>bfs;
   while(!q.empty()){
    int node=q.front();
    q.pop();
    bfs.push_back(node);
    for(auto it:adj[node]){
        if(!vis[it]){
            vis[it]=1;
            q.push(it);
        }
    }
   }
   return bfs;
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
    ans= bfsofgraph(n,adj);
    for(auto it : ans) {
    cout << it << " ";
}
    return 0;

}