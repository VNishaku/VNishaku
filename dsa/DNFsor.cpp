#include<iostream>
using namespace std;
void dnf(int nums[],int n){
   int low=0;
        int mid=0;
        int high=n-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            //      cout<<"0array";
            // for(int i=0;i<n;i++){
            //    cout<<nums[i]<<" ";
            //  }
            //  cout<<endl;
            }
              if(nums[mid]==1){
                mid++;
              //   cout<<"1array";
            // for(int i=0;i<n;i++){
            //    cout<<nums[i]<<" ";
            //  }
            //  cout<<endl;
             }
            else{
                swap(nums[mid],nums[high]);
                high--;
              //   cout<<"2array";
            // for(int i=0;i<n;i++){
            //    cout<<nums[i]<<" ";
            //  }
            //  cout<<endl;
            }
        }
    }
int main(){
 int nums[]={0,1,2,0,2,1,2};
 dnf(nums,7);
 for(int i=0;i<7;i++){
    cout<<nums[i]<<" ";
 }
}