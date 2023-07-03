#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void swap(int arr[], int i, int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}
void wave(int A[], int n1) {
    for(int i=1;i<n1;i+=2 ){
        if(A[i]>A[i-1]){
        swap(A,i,i-1);
        }
        if(A[i]>A[i+1] && i<=n1-2){
        swap(A,i,i+1);
        }
    }
}
int main(){
    int A[]={1,3,4,7,5,6,2};
    wave(A,7);
    for(int i=0;i<7;i++){
    cout<<A[i]<<" ";
    }
}