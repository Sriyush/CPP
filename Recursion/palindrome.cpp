#include<bits/stdc++.h>
using namespace std;


bool palin(string str,int s,int e){
    if(s>=e){
        return true;
    }
    if(str[s] == str[e]){
        s++;
        e--;
        return palin(str,s,e);
    }
    return false;
}
int main(){
    string s1 ="kooik";
    cout<<"Is it palindrome: "<<(palin(s1,0,s1.size()-1)==1?"oh yeah nigga":"suck it nigga");
    return 0;
}
