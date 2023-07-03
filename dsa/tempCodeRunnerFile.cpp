#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ans=0;
    int i=0;
    while(n!=0){
        int bit=n&1;
        ans=(bit<<i)+ans;
        n=n>>1;
        i++;
    }
    cout<<ans;
}


// #include <bitset>
// using namespace std;
// int main() {
//     int n;
//     cout << "Enter an integer: ";
//     cin >> n;
//     bitset<32> binary(n); // Assuming 32-bit integers
//     cout << "Binary representation: " << binary << std::endl;
//     return 0;
// }
