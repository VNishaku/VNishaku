#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int main(){
    int n, k;
    cin >> n;
    cin >> k;
    vector<int> a(n);
    for (auto &i : a){
        cin >> i;
    }
    deque<int> q;
    vector<int> ans;
    // Pushing the first 3 inputs
    for (int i = 0; i < k; i++){
        // Checking if the deque is empty or if the current value in hand is greater then the element on back of dqueue
        while (!q.empty() && a[q.back()] < a[i]){
            // If elements on left is small then pop it
            q.pop_back();
        }
        // Pushing inputs in left side
        q.push_back(i);
    }
    // Pushing the first highest value present on right
    ans.push_back(a[q.front()]);
    // Checking for rest of the array
    for (int i = k; i < n; i++){
        // If the right value is passed and no longer in the given window then pop it
        if (q.front() == i - k){
            q.pop_front();
        }
        // Now like previously pop the elements in left if it is smaller than the element in hand
        while (!q.empty() && a[q.back()] < a[i]){
            q.pop_back();
        }
        // Pushing the value to right
        q.push_back(i);
        // Sending the right most element to answer
        ans.push_back(a[q.front()]);
    }
    for (auto i : ans){
        cout << i << " ";
    }
    return 0;
}