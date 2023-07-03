#include<bits/stdc++.h>
#include<climits>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    // int maxn=INT_MAX;
    // int minn=INT_MIN;
    // for(int i=0;i<n;i++){
    //     maxn=min(maxn,a[i]);
    //     minn=max(minn,a[i]);
    // }
    // cout<<maxn<<" "<<minn<<endl;
//Selection sort
//  for(int i=0;i<n;i++){
//     for(int j=i+1;j<n;j++){
//         if(a[j]<a[i]){
//             int temp=a[j];
//             a[j]=a[i];
//             a[i]=temp;
//         }
//     }
//  }
//Bubble sort
/*int c=1;
while(c<n){
    for(int i=0;i<n-c;i++){
        if(a[i+1]<a[i]){
            int temp=a[i+1];
               a[i+1]=a[i];
               a[i]=temp;
        }
    }
    c++;
}*/
//Insertion sort
for(int i=1;i<n;i++){
    int c=a[i];
    int j=i-1;
    while(a[j]>c && j>=0){
        a[j+1]=a[j];
        j--;
       // cout<<j;
    }
    a[j+1]=c;
}
cout<<"sort array";
 for(int i=0;i<n;i++){
    cout<<a[i] <<" ";
 }
 cout<<endl;
}
