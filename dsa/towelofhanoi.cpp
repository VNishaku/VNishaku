#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// int fib(int n){
//     if(n==0 || n==1){
//         return n;
//     }
//   //  return fib(n-1)+fib(n-2);
//     return fib(n-1)*n;
// }

// void removeDup(string s){
//   if(s.length()==0){
//     return ;
//   }
//   string ans=s.substr(1);
//   removeDup(ans);
//   cout<<s[0]<<"";
// }
void reverse(string s){
  char ans;
  for(int i=11;i>=0;i--){
    char ans=s[i];
    cout<<ans;
  }
}
void ToH(int n,char src,char dest,char helper){
  if(n==0){
    return;
  }
  ToH(n-1,src,helper,dest);
  cout<<"move from "<<src<<" to "<<dest<<endl;
    ToH(n-1,helper,dest,src);
}
int main(){
  // string n;
   //cin>>n;
   //cout<<fib(n);
  // removeDup(n);
  //cout<<n.substr(1)<<endl;
 char src,dest,helper;
 cin>>src>>dest>>helper;
 int n;
 cin>>n;;
   ToH(n,src,dest,helper);
  //reverse(n);
}