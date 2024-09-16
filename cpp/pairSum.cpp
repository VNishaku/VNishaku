#include<iostream>
#include<vector>
using namespace std;
vector<int>pairSum(vector<int> nums,int target){
    vector<int> ans;
    int n=nums.size();
    int i=0,j=n-1;
    while (i<j)
    { int pairSum=nums[i]+nums[j];
      if(pairSum<target){
        i++;
      }
      else if(pairSum>target){
        j--;
      }else{
        ans.push_back(i);
        ans.push_back(j);
        return ans;
      }
    }
    
    return ans;
}
int main(){
    vector<int> nums={1,3,4,5,8};
    int target=8;
    vector<int>ans = pairSum(nums,target);
    cout<<ans[0]<<"and"<<ans[1];
  
    return 0;
}