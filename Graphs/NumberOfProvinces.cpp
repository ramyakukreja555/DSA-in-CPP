#include<iostream>
#include<vector>
using namespace std;
void dfs(int node,vector<int>adj[],vector<int>&vis){
     vis[node]=1;
     for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis);
        }
     } 
}
int numProvinces(vector<vector<int>>adj,int V){
      vector<int>adjLs[V];
      // to change adjacency matrix to list
      for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(adj[i][j]==1&&i!=j){
                adjLs[i].push_back(j);
                
            }
        }
      }
     vector<int>vis(V,0);
     int count=0;
     for(int i=0;i<V;i++){
        if(!vis[i]){
            count++;
            dfs(i,adjLs,vis);
        }
     }
     return count;
}
int main(){
    int n ;
    cin>>n;
    vector<vector<int>>adj(n,vector<int>(n));
     for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }
    int numberofprovinces;
    numberofprovinces=numProvinces(adj,n);
    cout<<numberofprovinces;
}