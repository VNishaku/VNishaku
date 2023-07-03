// #include<iostream>
// using namespace std;
// int main(){
//    /* for(int i=5;i>0;i--){
//         for(int j=i;j>0;j--){
//            // if(i==0||i==4||j==0||j==4)
//             cout<<"*";
//             // else
//             // cout<<" ";
//         }
//         cout<<endl;
//     }*/
//     char a[100]="KimTaeHyung";
//     int i=NULL;
//     while(a[i]!=NULL){
//         cout<<a[i]<<endl;
//         i++;
//     }
//     //return 0;
//     char arr[100];
//     cin>>arr;
//     cout<<arr<<endl;
// }
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    cin.ignore();
    char arr[n+1];

    cin.getline(arr, n+1);
    cin.ignore();
    int maxLen = 0, currLen = 0;
    int st = 0;
    for(int i = 0; arr[i] != '\0'; i++){
        if(arr[i] == ' '){
            if(currLen > maxLen){
                maxLen = currLen;
                st = i - maxLen;
            }
            currLen = 0;
            continue;
        }
        currLen++;
    }
    if(currLen > maxLen){
        maxLen = currLen;
        st = n - maxLen;
    }
    cout<<maxLen<<endl;
    for(int i=0; i<maxLen; i++){
        cout<<arr[i+st];
    }
    return 0;
}