#include <bits/stdc++.h>
#include <iostream>
using namespace std;


// Subset Sum Equals to Target 
// Method 1 DP

// TC O(N*target)
// SC O(N + (N+1)*(target + 1))

bool recursion(vector<int>& arr, int sum, int ind,vector<vector<int>>& dp){
    
    if(sum == 0)   return 1;
    if(ind < 0){
        return 0;
    }
    // if(ind == 0){
    //     return arr[0] == sum;
    // }
    if(dp[ind][sum] != -1)  return dp[ind][sum];
    
    bool take = 0;
    if(sum >= arr[ind]) take = recursion(arr,sum-arr[ind],ind-1,dp);
    
    bool not_take = recursion(arr,sum,ind-1,dp);
    
    return dp[ind][sum] = (take || not_take);
}

bool isSubsetSum(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<vector<int>> dp (n+1,vector<int>(sum+1,-1));
    
    return recursion(arr,sum,n-1,dp);
}

// Tabulation code
//  TC O(N*target)
//  SC O((N+1)*(target + 1))
bool isSubsetSum(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<vector<bool>> dp (n+1,vector<bool>(sum+1,false));
    
    for(int i = 0;i < n;i++) dp[i][0] = true;
    dp[0][arr[0]] = true;
    
    for(int i = 1;i < n;i++){
        for(int target = 1;target <= sum;target++){
            bool take = false;
            if(target >= arr[i]) take = dp[i-1][target- arr[i]];
            
            bool not_take = dp[i-1][target];
            
            dp[i][target] = (take || not_take);
        }
    }
    
    
    return dp[n-1][sum];
}

// Space Optimised
//  TC O(N*target)
//  SC O(target)
bool isSubsetSum(vector<int>& arr, int sum) {
    int n = arr.size();
    // vector<vector<bool>> dp (n+1,vector<bool>(sum+1,false));
    vector<bool> prev(sum+1,false);
    
    prev[0] = true;
    prev[arr[0]] = true;
    for(int i = 1;i < n;i++){
        vector<bool> curr(sum+1,false);
        curr[0] = true;
        for(int target = 1;target <= sum;target++){
            bool take = false;
            if(target >= arr[i]) take = prev[target- arr[i]];
            
            bool not_take = prev[target];
            
            curr[target] = (take || not_take);
        }
        prev = curr;
    }
    return prev[sum];
}



//  Partition Equal Subset Sum
// Memoization
// TC O(N*Target)
// SC O(N + (N*Target))

bool recursion(vector<int>& nums,int sum1, int & sum,int ind, vector<vector<int>> &dp){
    if(ind < 0){
        if(sum1*2 == sum)    return 1;
        else    return 0;
    }
    if(sum1 > sum/2)    return 0;
    
    if(dp[ind][sum1] != -1)    return dp[ind][sum1];

    bool not_take = recursion(nums , sum1 , sum,ind - 1,dp);
    bool take = recursion(nums,sum1 + nums[ind], sum ,ind - 1,dp); 

    return dp[ind][sum1] = (not_take || take);

}
bool canPartition(vector<int>& nums) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    vector<vector<int>> dp(n,vector<int>(sum/2 + 1,-1));
    cout << sum;
    return recursion(nums,0,sum,n-1,dp); 
}

// Count Subsets with Sum
// TC O(N*Target)
// SC O(N + (N*Target))
int recursion(vector<int>& arr,int& target,int ind,int sum,vector<vector<int>> &dp){
    if(sum > target)    return  0;
    if(ind < 0){
        return sum == target;
    }
    if(dp[ind][sum] != -1)  return dp[ind][sum];


    int take  = recursion(arr,target,ind -1 ,sum + arr[ind],dp);
    int not_take  = recursion(arr,target,ind - 1,sum,dp);
    
    return dp[ind][sum] = take + not_take;
}


// Partitions with Given Difference
// TC O(N*Target)
// SC O(N + (N*Target))
int perfectSum(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(target + 1,-1));
    return recursion(arr,target,n-1,0,dp);

    }


int recursion(vector<int>& arr,int& diff,int ind,int &total_sum,int sum,vector<vector<int>> &dp){
    if(ind < 0) return (((total_sum-sum)-sum) == diff);
    
    if(dp[ind][sum] != -1) return dp[ind][sum];
    
    int take = recursion(arr,diff,ind-1,total_sum,sum + arr[ind],dp);
    int not_take = recursion(arr,diff,ind-1,total_sum,sum,dp);
    
    return dp[ind][sum] = take + not_take;
}
int countPartitions(vector<int>& arr, int diff) {
    int n = arr.size();
    int total_sum = accumulate(arr.begin(),arr.end(),0);
    vector<vector<int>> dp(n,vector<int>(total_sum + 1,-1));
    
    return recursion(arr,diff,n-1,total_sum,0,dp);
}


// Coin Change
// TC O(N*Target)
// SC O(Target + (N*Target))


int recursion(vector<int>& coins,int amount,int ind,vector<vector<int>> &dp){

    if(ind == 0){
        if(amount%coins[ind] == 0) return amount/coins[ind];
        return 1e9;
    }
    
    if(dp[ind][amount] != -1) return dp[ind][amount];

    int not_take = recursion(coins,amount,ind-1,dp);

    int take = INT_MAX;
    if(coins[ind] <= amount)
        take = 1 + recursion(coins,amount-coins[ind],ind,dp);

    return dp[ind][amount] = min(take,not_take);

}
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n,vector<int>(amount + 1,-1));
    int cnt = recursion(coins,amount,n-1,dp);
    return (cnt >= 1e9 )? -1 : cnt;

    }


// Target Sum
// TC O(N * 2*total_sum)
// SC O(N * 2*total_sum + N)
int recursion(vector<int>& arr, int target,int ind,int &total_sum,vector<vector<int>> &dp){
    if(ind < 0){
        if(target == 0)     return 1;
        return 0;
    }
    if(target < -total_sum || target > total_sum)   return 0;

    if(dp[ind][target + total_sum] != -1)   return dp[ind][target + total_sum];

    int minus = recursion(arr,target - arr[ind],ind - 1,total_sum,dp);
    int plus = recursion(arr,target + arr[ind],ind - 1,total_sum,dp);

    return  dp[ind][target + total_sum] = minus + plus;

}
int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    int total_sum = accumulate(nums.begin(),nums.end(),0);
    vector<vector<int>> dp(n,vector<int>(2*total_sum+1 , -1));
    return recursion(nums,target,n-1,total_sum,dp);
}


// 
// TC O(N * amount)
// SC O(N * amount + amount)
int recursion(vector<int>& arr,int amount,int ind, vector<vector<int>> &dp){
    if(ind < 0){
        return (amount == 0);
    }
    if(amount < 0)  return 0;
    if(dp[ind][amount] != -1)   return dp[ind][amount];

    int not_take = recursion(arr,amount,ind - 1,dp);
    int take = 0; 
    if(amount >= arr[ind]){
        take = recursion(arr,amount - arr[ind],ind,dp);
    }

    return dp[ind][amount] = take+not_take;

}
int change(int amount, vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(amount+1,-1));
    return recursion(arr,amount,n-1,dp);
}


// Knapsack with Duplicate Items
// TC O(N * capacity)
// SC O(N * capacity + capacity)
int recursion(vector<pair<int,int>>& vec,int ind,int capacity,vector<vector<int>> &dp){
    if(ind < 0){
        return 0;
    }
    
    if(dp[ind][capacity] != -1)     return dp[ind][capacity];
    
    int not_take = recursion(vec,ind-1,capacity,dp);
    int take = INT_MIN;
    if(capacity >= vec[ind].first)  
        take = vec[ind].second + recursion(vec,ind, capacity - vec[ind].first,dp);  
    
    return dp[ind][capacity] = max(take,not_take) ;

}
int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
    vector<pair<int,int>> vec;
    int n = val.size();
    for(int i = 0; i < n;i++){
        vec.push_back({wt[i],val[i]});
    }
    vector<vector<int>> dp(n,vector<int>(capacity + 1 , -1));
    
    return recursion(vec,n-1,capacity,dp);
    
}


int main(){


    return 0;
}