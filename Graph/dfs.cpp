
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(int node,vector<int>  adj[],int vis[],vector<int> &ls){
        vis[node]=1;
        ls.push_back(node);
        for(auto i:adj[node]){
            if(!vis[i]){
                dfs(i,adj,vis,ls);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] ={0};
        int start=0;
        vector<int> ans;
        dfs(start,adj,vis,ans);
        return ans;
    }
};
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
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}