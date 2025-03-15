//n and m will be givern where n will be number of nodes and m wil be number of edges
//next will b eset of lines 
// 2 ways to store matrix and list
//matrix is coslty
//but lets use it
#include <bits/stdc++.h>
using namespace std;
//this is using matrix
//for weightes graph instead of writing 1 use the weight to fill the matrix

int main(){
    int n,m;
    cin>>n>>m;
    int adj[n+1][m+1];
    for(int i=-0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;

    }
}

//this is using list
//for weightd use the pair of edge and weight
int main(){
    int n,m;
    cin>>n>>m;
    vector <int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return 0;
}
