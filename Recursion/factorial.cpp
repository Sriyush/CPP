// 5! = 5*4*3*2*1

#include<bits/stdc++.h>

using namespace std;

int fact(int n){
    if (n==0){//base case
        return 1;
    }
    
    return n*fact(n-1);
}
int main(){
    cout<<"Enter a number: ";
    int n;
    cin>>n;
    cout<<"Factorial is: "<<fact(n);
    return 0;
}