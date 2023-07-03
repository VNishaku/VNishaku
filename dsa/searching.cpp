#include<iostream>
using namespace std;
template <class T>
T linearsearch(T*arr,T n,T el){
    for(int i=0;i<n;i++){
        if(arr[i]==el)
        return 1;
    }
    return -1;
}
template <class T>
T binarysearch(T *arr,int left,int right,T el){
    if(right>=left){
        int mid=(right+left)/2;
        if(arr[mid]==el){
              return mid;
        }
        if(arr[mid]>el){
            return binarysearch(arr,left,mid-1,el);
        }
        else
        return binarysearch(arr,mid+1,right,el);
    }
}
int main(){
    int n,el;
    cout<<"enter size of array\n";
    cin>>n;
    int arr[n];
     for (int i = 0; i < n; i++)
     {
        cin>>arr[i];
     }
       cout<<"Array:\n";
    for (int i = 0; i < n; i++)
    {   
         cout<<arr[i]<<" ";
     }
    cout<<"Enter element\n";
    cin>>el;
     cout<<linearsearch(arr,n,el)<<endl;
     int b=binarysearch(arr,0,n-1,el);
     if(b!=-1)
     cout<<"element found\n";
     else
     cout<<"element not fount\n";
     return 0;

}