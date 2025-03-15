#include<bits/stdc++.h>
using namespace std;

void rev(string &str,int s,int e){
    if (s>e){
        return ;
    }
    swap(str[s],str[e]);
    s++;
    e--;
    rev(str,s,e);
}
int main(){
    string s = "abcde";
    rev(s,0,s.size()-1);
    cout<<"Rev str: "<<s;
    return 0;
}