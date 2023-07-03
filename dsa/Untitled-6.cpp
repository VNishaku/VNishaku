#include<iostream>
#include<stack>
using namespace std;
// bool isvalid(string s){
//     int n=s.size();
//     stack<char>st;
//     bool ans=true;
//     for(int i=0;i<n;i++){
//         if(s[i]=='(' || s[i]=='{' || s[i]=='['){
//             st.push(s[i]);
//         }
//         else if(s[i]==')'){
//             if(!st.empty() && s[i]=='('){
//                 st.pop();
//             }
//             else{
//                 ans=false;
//                 break;
//             }
//         }
//          else if(s[i]=='}'){
//             if(!st.empty() && s[i]=='{'){
//                 st.pop();
//             }
//             else{
//                 ans=false;
//                 break;
//             }
//         }
//          else if(s[i]==']'){
//             if(!st.empty() && s[i]=='['){
//                 st.pop();
//             }
//             else{
//                 ans=false;
//                 break;
//             }
//         }
//     }
//     if(!st.empty())
//         return false;
    
//     return ans;
// }
// int main(){
//     string s = "{([()])}";
//     if(isvalid(s))
//     {
//         cout<<"\nBrackets are Balanced..";
//     }
//     else
//     {
//         cout<<"\nBrackets are not Balanced..";
//     }
//     return 0;
// }
bool check(string s){
    if(s.length()%2!=0){
        return false;
    }
    stack<char>a;
    for(int i=0;i<s.length()/2;i++){
        a.push(s[i]);
    }
    for(int i=s.length()/2;i<s.length();i++){
        if((a.top()=='[' and s[i]==']') or (a.top()=='{' and s[i]=='}') or (a.top()=='(' and s[i]==')')){
            a.pop();
        }
    }
    if(a.empty()){
        return true;
    }
    else{
        return false;
    }
    
}
int main(){
    string s="{[()]}";
    if(check(s)){
        cout<<"It is balanced";
    }else{
        cout<<"It is not balanced";
    }    
    return 0;
}