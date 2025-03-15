//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool detect(int start,vector<int> adj[],int vis[]){
        vis[start]=1;
        queue<pair<int,int>> q;
        q.push({start,-1});
        while(!q.empty()){
            int node = q.front().first;
            int parent =q.front().second;
            q.pop();
            
            for(auto i:adj[node]){
                if(!vis[i]){
                    q.push({i,node});
                    vis[i]=1;
                }
                else if(parent != i){
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect(i,adj,vis)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
