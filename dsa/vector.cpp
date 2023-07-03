#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;
bool myCompare(pair<int,int> p1,pair<int,int> p2){
    return p1.first<p2.first;
}
int main(){
    // vector<int>v;
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);
    // int n=2;
    // int m=3;
    // vector<vector<int>> grid(n,vector<int>(m,-1));
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i];
    // }
    // cout<<endl;
    // for(auto element:v){
    //     cout<<element;
    // }
    // cout<<endl;
    // vector<int>::iterator it;
    // for(it=v.begin();it!=v.end();it++){
    //     cout<<*it;
    // }
    // cout<<endl;
    vector<pair<int,int>>v;
    int arr[]={1,3,5,2,6};
    for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++){
      v.push_back(make_pair(arr[i],i));
    }
    sort(v.begin(), v.end(), myCompare);
    for(int i=0;i<v.size();i++){
        arr[v[i].second]=i;
    }
     for(int i=0;i<v.size();i++){
       cout<<arr[i]<<" ";
    }
}