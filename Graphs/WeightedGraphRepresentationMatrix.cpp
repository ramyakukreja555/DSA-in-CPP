#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int adj[n+1][n+1];
    
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        int wt;
        cin>>wt;
        adj[u][v]=wt;
        adj[v][u]=wt;
       
    }
    return 0;

}