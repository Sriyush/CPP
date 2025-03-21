
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool isSafe(int x,int y,int n,vector<vector<int>> visited,vector<vector<int>> &m){
        
        if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y] == 0 && m[x][y] == 1){
            return true;
        }
        else{
            return false;
    }
    }
    void solve(vector<vector<int>> &m, int n,int x,int y,vector<vector<int>> visited,string path,vector<string> &ans){
        
        
        if(x==n-1 && y ==n-1){
            ans.push_back(path);
            return ;
        }
        
        visited[x][y]=1;
        if(isSafe(x+1,y,n,visited,m)){
            path.push_back('D');
            solve(m,n,x+1,y,visited,path,ans);
            path.pop_back();
        }
        if(isSafe(x,y-1,n,visited,m)){
            path.push_back('L');
            solve(m,n,x,y-1,visited,path,ans);
            path.pop_back();
        }
        if(isSafe(x,y+1,n,visited,m)){
            path.push_back('R');
            solve(m,n,x,y+1,visited,path,ans);
            path.pop_back();
        }
        if(isSafe(x-1,y,n,visited,m)){
            path.push_back('U');
            solve(m,n,x-1,y,visited,path,ans);
            path.pop_back();
        }
        
        visited[x][y] = 0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        if(m[0][0]==0){
            return ans;
        }
        int srcx =0;
        int srcy=0;
        
        vector<vector<int>> visited = m;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                visited[i][j] = 0;
            }
        }
        string path = "";
        solve(m,n,srcx,srcy,visited,path,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}