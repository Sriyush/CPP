//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Disjoint{
    //pehle rank aur parent ke liye vector banaya
    vector<int> rank,parent;
public:
    Disjoint(int n){
        //usko resize karenege to overcome 1 absed indexing
        rank.resize(n+1,0);
        parent.resize(n+1);
        //sabko khud ka parent banado
        for(int i=0;i<=n;i++){ 
            parent[i]=i;
        }
    }

    int findpar(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findpar(parent[node]);
    }

    void unionbyrank(int u, int v){
        int ulpu=findpar(u);
        int ulpv=findpar(v);
        if(ulpu == ulpv)    return ;
        if(rank[ulpu]<rank[ulpv]){
            parent[ulpu]=ulpv;
        }
        else if(rank[ulpu]>rank[ulpv]){
            parent[ulpv]=ulpu;
        }
        else{
            parent[ulpv]=ulpu;
            rank[ulpu]++;
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++){
            for(auto j:adj[i]){
                int u=i;
                int v=j[0];
                int wt=j[1];
                edges.push_back({wt,{u,v}});
            }
        }
        Disjoint ds(V);
        sort(edges.begin(),edges.end());
        int mst=0;
        for(auto i:edges){
            int wt=i.first;
            int u=i.second.first;
            int v=i.second.second;
            if(ds.findpar(u)!=ds.findpar(v)){
                mst+=wt;
                ds.unionbyrank(u,v);
            }
        }
        return mst;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends