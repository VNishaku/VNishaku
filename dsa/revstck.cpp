// #include<iostream>
// #include<stack>
// #include<bits/stdc++.h>
// using namespace std;
// void reverssStack(string s){
//     stack<string> st;
//     for(int i=0;i<s.length();i++){
//         string word=" ";
//         while(s[i]=" " && i<s.length()){
//             word+=s[i];
//             i++;
//         }
//     }
//       while(!st.empty()){
//         cout << st.top()<<" ";
//         st.pop();
//     }cout<<endl;
// }
// int main(){
    
//     string s="hello what are you doing";
//     reverssStack(s);
// }
#include <bits/stdc++.h>
using namespace std;
void solve(string s)
{
    stack<string>st;
    string words="";
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!=' ')
        words=words+s[i];
        else
        {
        st.push(words);
        words="";
        }
    }
    st.push(words);
    while(!st.empty()){

        cout<<st.top()<<" ";
        st.pop();
    }
}
int main() {
    string s="hello what are you doing";
    solve(s);
}