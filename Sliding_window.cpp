#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Q Sliding windows maximum

// Method 1
// Traversing each window to find max element
// TC O((N-K+1)*K)
// SC O(N-K+1)
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    // int i = 0;
    vector<int> vec;
    for(int j = k-1;j<n;j++){
        int i = j-k+1;
        int maxx = nums[i];
        while(i<=j){
            if(nums[i] > maxx) maxx = nums[i];
            i++;
        }
        vec.emplace_back(maxx);
    }
    return vec;
}

// Method 2
// Using deque  (create a deque with element in decresing order larger element pops all , smaller element push at back)
// TC O(N + N) traversal and pop push
// SC O(N-K + K) vector and deque
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> ans;
        for(int i = 0;i<n;i++){
            if(!dq.empty() && i - dq.front() >= k){       
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] <= nums[i]){
                dq.pop_back();
            }
            if(dq.empty() || nums[i] < nums[dq.back()]){
                dq.push_back(i);
            }
            // cout << nums[dq.front()] << ' ';
            if(i >= k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }

// Q Stock span

// Method 1 
// Store price in a vector and iterate in reverse to find a greater element
// TC O(N^2)

// Mehtod 2
// find previous greater element in stack
// TC O(2N)  N push N pop
// SC O(N)
class StockSpanner {
public:
    StockSpanner() {

    }
    deque<pair<int,int>> dq;
    int i = 0;
    int next(int price) {
        while(!dq.empty() && dq.back().first <= price){
            dq.pop_back();
        }
        if(dq.empty()){
            i++;
            dq.push_back({price,i});
            return i;
        }
        int j = dq.back().second;
        i++;
        dq.push_back({price,i});

        return i-j;
    }
};



int main(){
    return 0;
}