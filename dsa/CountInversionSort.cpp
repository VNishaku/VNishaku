#include<bits/stdc++.h>
using namespace std;
int merge(int arr[],int l,int mid,int r){
    int n1= mid-l+1;
    int n2= r-mid; 
    int inv=0;   
    //temp arrays
    int a[n1];
    int b[n2];
    //array ke elements ko 2 temp arrays mein bhar rhe hai
    for (int i = 0; i < n1; i++){
        a[i]=arr[l+i];

    }
    for (int i = 0; i < n2; i++){
        b[i]=arr[mid+1+i];
        
    }
    //checing when putting the values backing in the k array
    int i=0;
    int j=0;
    int k=l;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k++]=a[i++];
            // k++;
            // i++;
        }
        else{
            arr[k++]=b[j++];
            inv+=n1-i;
            // k++;
            // j++;
        }
    }
    // for the last one
    while(i<n1){
        arr[k++]=a[i++];
        // k++;
        // i++;
    }
    while(j<n2){
        arr[k++]=b[j++];
        // k++;
        // j++;
    }
    return inv;    
}
int countInv(int arr[],int l,int r){
    int inv = 0;   
    if(l<r){
        int mid=(l+r)/2;
     inv =+  countInv(arr,l,mid);
     inv =+  countInv(arr,mid+1,r);
     inv =+  merge(arr,l,mid+1,r);
    }
    return inv;   
}
int getInvCount(int arr[], int n)
{
    int inv_count = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                inv_count++;
  
    return inv_count;
}
int main(){
    int arr[]={5,3,2,4,1};
    cout<<countInv(arr,0,4);
   cout<<getInvCount(arr,5);
    // for (int i = 0; i < 5; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
    cout<<endl;
    return 0;
}