#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int petya,vasya,tonya;
    int ans=0;
    while(n--){
        cin>>petya>>vasya>>tonya;
        if(petya+vasya+tonya >= 2)
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}
