#include<bits/stdc++.h>
using namespace std;
int solve(int ind,int k , vector<int> &s,vector<int>& dp){
    if(ind ==0){
        return 0;
    }
    if(dp[ind] != -1){
        return dp[ind];
    }
    int minsteps =INT_MAX;
    for(int j=1;j<=k;j++){
        if(ind-j>=0){
            int jump = solve(ind-j,k,s,dp)+abs(s[ind-j]-s[ind]);
            minsteps =min(jump ,minsteps);
        }
    }
    return dp[ind]=minsteps;
}
int main(){

    int n,k;
    cin>>n>>k;
    vector<int> stones(n);
    for(int i=0;i<n;i++){
        cin>>stones[i];
    }
    vector<int> dp(n+1,-1);
    cout<<solve(n-1,k,stones,dp);
}