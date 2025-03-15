#include<iostream>
using namespace std;

int part(int arr[],int s,int e){
    int pivot =arr[s];

    int count=0;
    for(int i = s+1;i<=e;i++){
        if(arr[i]<pivot){
            count++;
        }
    }
    int ind = s+count;
    swap(arr[s],arr[s+count]);
    int i=s,j=e;

    while(i<ind && j>ind){
        while(arr[i]<pivot){
            i++;
        }
        while(arr[i]>pivot){
            j--;
        }
        if(i<ind && j>ind){
            swap(arr[i++],arr[j--]);
        }
    }
    return ind;
}
void quicksort(int arr[],int s,int e){
    if(s>=e){
        return ;
    }
    int p = part(arr,s,e);

    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);
}
int main(){
    int n=5;
    int arr[n]={3,2,1,7,4};

    quicksort(arr,0,n-1);
    for(int i:arr){
        cout<<i<<" ";
    }
    return 0;
}