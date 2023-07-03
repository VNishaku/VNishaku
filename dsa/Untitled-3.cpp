#include<iostream>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;
void subsets(int arr[],int n){
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(i & (1<<j)){
                cout<<arr[j]<<" ";
            }
        }
        cout<<endl;
    }
}
int main(){
    int n=4x;
    int arr[n]={1,2,3,4};
    subsets(arr,n);
    //  int n,m;
    // cin>>n;
    // cin>>m;
    // int a[n][m];
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //     cin>>a[i][j];
    //     }
    //     cout<<endl;
    // }
  /*  int row_start =  0 , row_end = n-1 , col_start = 0 , col_end = m-1;
    while(row_start<=row_end && col_start<=col_end){
        for(int col=col_start;col<=col_end;col++)
            cout<<a[row_start][col]<<" ";
        
        row_start++;
        for(int row=row_start;row<=row_end;row++)
            cout<<a[row][col_end]<<" ";
        
        col_end--;
        for(int col=col_end;col>=col_start;col--)
            cout<<a[row_end][col]<<" ";
        
        row_end--;
        for(int row=row_end;row>=row_start;row--)
            cout<<a[row][col_start]<<" ";
        
        col_start++;
    }*/
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //     cout<<a[j][i]<<" ";
    //     }
    //     cout<<endl;
    // }

    // string str="fam";
    // string st1="ilyie";
    // str.append(st1);
    // cout<<str<<endl;
    // transform(str.begin(),str.end(),str.begin(),::toupper);
    // cout<<str<<endl;

    // int st=0;
    // int en=1;
    // int len=1;
    // int mxLen=INT_MIN;
    // sort(str.begin(),str.end());
    // cout << str << endl ;
    // while(en<str.size())
    // {
    //     if(str[st] == str[en]){
    //         len++;
    //     }
    //     else{
    //         len=1;
    //     }
    //     mxLen = max(mxLen, len);
    //     st+=1;
    //     en+=1;
    // }
    return 0;
}