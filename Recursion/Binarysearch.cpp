#include<iostream>
using namespace std;

bool binsear(int arr[],int s,int e,int key){
    
    if(s>e){
        return false;
    }
    int mid = s+(e-s)/2;
    if(arr[mid]==key){
        return true;
    }
    if(arr[mid]< key){
        return binsear(arr,mid+1,e,key);
    }
    else{
        return binsear(arr,s,mid-1,key);
    }

}
int main(){

    int arr[6] = {1,2,3,5,6,7};
    int size = 6;
    int key = 12;

    cout<<"Is it present? "<<(binsear(arr,0,size-1,key) == 1?"true":"false");
    return 0;
}