#include<bits/stdc++.h>
using namespace std;

bool linsear(int arr[],int size,int key){
    if(size == 0){
        return false;
    }

    if(arr[0] == key){
        return true;
    }
    else{
        bool check = linsear(arr+1,size-1,key);
        return check;
    }
    
}

int main(){
    int arr[5]={3,5,6,3,2};
    int size =5;
    int key =2;
    bool ans = linsear(arr,size,key);
    cout<<"Is it present? "<<(ans==1?"ohh yeah nigga":"false");
}