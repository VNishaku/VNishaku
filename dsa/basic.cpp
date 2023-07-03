#include<bits/stdc++.h>
#include<climits>
using namespace std;
int sum(int n){
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=n;
    }
    return ans;
}
int binaryToDecimal(int n){
    int ans=0;
    int x=1;
    while(n>0){
       int y=n%10;
       ans+=x*y;
       x*=2;
       n/=10;
    }
    return ans;
}
int DecimalToBinary(int n){
    int x=1;
    int ans=0;
    while(x<=n){
        x*=2;
    }
    x/=2;
    while(x>0){
        int ld=n/x;
        n-=ld*x;
        x/=2;
        ans=ans*10+ld;
    }
    return ans;
}
int linearsearch(int arr[],int n,int k){
    for(int i=0;i<n;i++){
        if(k==arr[i]){
            return i;
        }
    }
    return -1;
}
int binarySearch(int arr[], int l, int r, int x){
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    //cout<<sum(n);
    //cout<<binaryToDecimal(n);
    int arr[n];
   // int key;
   // cin>>key;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // for(int i=0;i<n;i++){
    //     int c=0;
    //     for(int j=i;j<n;j++){
    //         c+=arr[i];
    //         cout<<c<<endl;
    //     }
    // }

    // int ans=2;
    // int pd=arr[1]-arr[0];
    // int curr=2;
    // int j=2;
    // while(j<n){
    //     if(pd==arr[j]-arr[j-1]){
    //         curr++;
    //     }
    //     else{
    //         pd=arr[j]-arr[j-1];
    //         curr=2;
    //     }
    //     ans=max(ans,curr);
    //     j++;
    // }
    // cout<<ans<<endl;

    //subarray
  int maxSum=INT16_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            for(int k=i;k<j;k++){
                //cout<<arr[k]<<" ";
                sum+=arr[k];
            }
            maxSum=max(maxSum,sum);
        } 
    }
    cout<<maxSum<<endl;
   // cout<<linearsearch(arr,n,key);
   // cout<<binarySearch(arr,0,n-1,key);
}