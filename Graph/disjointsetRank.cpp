//disjoint set- 2 fucn - findpar and union
#include <bits/stdc++.h>
using namespace std;

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

int main(){
    Disjoint ds(7);
    ds.unionbyrank(1,2);
    ds.unionbyrank(2,3);
    ds.unionbyrank(4,5);
    ds.unionbyrank(6,7);
    ds.unionbyrank(5,6);

    if(ds.findpar(3) == ds.findpar(7)){
        cout<<"Same\n";
    }
    else cout<<"NotSure\n";
    ds.unionbyrank(3,7);
    if(ds.findpar(3) == ds.findpar(7)){
        cout<<"Same\n";
    }
    else cout<<"NotSure\n";
    return 0;
}