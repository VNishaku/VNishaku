#include<iostream>
using namespace std;
int main(){
    int a[4]={1,1,0,1};
    int b[4]={1,0,1,1};
    int c[5];
    int carry=0;
    for(int i=0;i<3;i++){
        int sum=a[i]+b[i]+carry;
        if(sum>1){
            sum=sum%1;
            carry=1;
        }
        else{
            carry=0;
        }
        c[i+1]=sum;
    }
    c[0]=carry;
    for(int i=0;i<4;i++){
        cout<<c[i]<<" ";
    }
}