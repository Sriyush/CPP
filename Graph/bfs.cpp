// will take a queue, level by level karenge
#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(int n, vector<int> adj[]){
    int vis[n]={0};
    vis[0]=1;
    queue<int> q;
    q.push(0);
    vector<int> ans;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto i :adj[node]){
            if(!vis[i]){
                vis[i]=1;
                q.push(i);
            }
        }
    }
    return ans;
}
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
    vector<int> ans =bfs(n,adj);
    cout<<"BFS of graph is: " ;
    for(int i:ans){
        cout<<i<< " ";
    }
    return 0;
}