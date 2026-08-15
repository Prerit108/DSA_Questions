#include<bits/stdc++.h>



// Best Time to Buy and Sell Stock 

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int buy = INT_MAX;
    int profit = 0;
    for(int i = 0;i<n;i++){
        buy = min(prices[i],buy);
        profit = max(prices[i] - buy,profit);
    }
    return profit;
}


// Best Time to Buy and Sell Stock II
// Iterative approach
int maxProfit(vector<int>& arr) {
    int  n = arr.size();

    int buy = -1;
    int sell = -1;
    int t_profit = 0;

    for(int i = 0;i < n-1;i++){
        int profit = arr[i+1] - arr[i];
        if(profit > 0){
            t_profit += profit; 
        }
    }
    return t_profit;

}
// DP approach (memoization)
// SC O(N*2 + N)
// TC O(N*2)
int recursion(vector<int>& arr, int i, int buy, vector<vector<int>>& dp) {
    if (i == arr.size())
        return 0;

    if (dp[i][buy] != -1)
        return dp[i][buy];

    int profit = 0;
    if (buy == 0) {
        // Option to buy
        int buyStock = recursion(arr, i + 1, 1, dp) - arr[i];
        int skip = recursion(arr, i + 1, 0, dp);
        profit = max(buyStock, skip);
    } else {
        // Option to sell
        int sellStock = recursion(arr, i + 1, 0, dp) + arr[i];
        int hold = recursion(arr, i + 1, 1, dp);
        profit = max(sellStock, hold);
    }

    return dp[i][buy] = profit;
}

int maxProfit(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(2,-1));   // for 2 states of buy (bought or not bought)
    return recursion(arr, 0, 0, dp);
}

// Tabulation (Dp array will have 1 based indexing)
// SC O(N*2)
// TC O(N*2)
int maxProfit(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(
        n + 1,
        vector<int>(2, -1)); // for 2 states of buy (bought or not bought)

    dp[n][0] = 0;
    dp[n][1] = 0;

    for (int i = n-1; i >= 0; i--) {
        for (int buy = 0; buy < 2; buy++) {
            int profit = 0;
            if (buy == 0) {
                // Option to buy
                int buyStock = dp[i+1][1] - arr[i];
                int skip = dp[i+1][0];
                profit = max(buyStock, skip);
            } else {
                // Option to sell
                int sellStock = dp[i+1][0] + arr[i];
                int hold = dp[i+1][1];
                profit = max(sellStock, hold);
            }
            dp[i][buy] = profit;

        }
    }
    return dp[0][0];
}

// Space Optimized
int maxProfit(vector<int>& arr) {
    int n = arr.size();
    vector<int> ahead(2,0) , curr(2,0);
    ahead[0] = 0;
    ahead[1] = 0;

    for (int i = n-1; i >= 0; i--) {
        for (int buy = 0; buy < 2; buy++) {
            int profit = 0;
            if (buy == 0) {
                // Option to buy
                int buyStock = ahead[1] - arr[i];
                int skip =  ahead[0];
                profit = max(buyStock, skip);
            } else {
                // Option to sell
                int sellStock =  ahead[0] + arr[i];
                int hold =  ahead[1];
                profit = max(sellStock, hold);
            }
            curr[buy] = profit;

        }
        ahead = curr;
    }
    return curr[0];
}


// Best Time to Buy and Sell Stock III

// Memoization
// TC O(N * 3 * 2)
// SC O(N * 3 * 2 + N)
int recursion(vector<int> &arr,int i,int buy,int cnt,vector<vector<vector<int>>>& dp){
    if(cnt == 0) return 0;
    if(i == arr.size()) return 0;

    if(dp[i][buy][cnt] != -1) return dp[i][buy][cnt]; 

    if(buy == 0){
        int buying = recursion(arr,i+1,1,cnt,dp) - arr[i]; 
        int leave = recursion(arr,i+1,0,cnt,dp);
        return dp[i][buy][cnt] = max(buying,leave);
    }
    else {
        int sell = recursion(arr,i+1,0,cnt - 1,dp) + arr[i];
        int hold = recursion(arr,i+1,1,cnt,dp);
        return dp[i][buy][cnt] = max(sell,hold);
    }
}
int maxProfit(vector<int>& arr) {
    int n = arr.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    return recursion(arr,0,0,2,dp);
}

// Tabulation
int maxProfit(vector<int>& arr) {
    int n = arr.size();
    // if made dp with 0 as default value then no need of base cases.
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));  

    // Base cases
    for(int i = 0;i <= n;i++){
        for(int j = 0;j <= 1;j++){
            dp[i][j][0] = 0;
        }
    }
    for(int i = 0;i <= 1;i++){
        for(int j = 0;j <= 2;j++){
            dp[n][i][j] = 0;
        }
    }

    for(int i = n-1;i >= 0;i--){
        for(int buy = 0;buy <= 1;buy++){
            for(int cnt = 2;cnt >=1; cnt--){
                if(buy == 0){
                    int buying = dp[i+1][1][cnt] - arr[i]; 
                    int leave = dp[i+1][0][cnt];
                    dp[i][buy][cnt] = max(buying,leave);
                }
                else {
                    int sell = dp[i+1][0][cnt-1] + arr[i];
                    int hold = dp[i+1][1][cnt];
                    dp[i][buy][cnt] = max(sell,hold);
                }
            }  
        }
    }
    return dp[0][0][2];
}

// Space Optimization
// TC O(N*2*3)
// SC O(1)
int maxProfit(vector<int>& arr) {
    int n = arr.size();
    
    vector<vector<int>> ahead (2,vector<int>(3,0));
    vector<vector<int>> curr (2,vector<int>(3,0));

    for(int i = n-1;i >= 0;i--){
        for(int buy = 0;buy <= 1;buy++){
            for(int cnt = 2;cnt >=1; cnt--){
                if(buy == 0){
                    int buying = ahead[1][cnt] - arr[i]; 
                    int leave = ahead[0][cnt];
                    curr[buy][cnt] = max(buying,leave);
                }
                else {
                    int sell = ahead[0][cnt-1] + arr[i];
                    int hold = ahead[1][cnt];
                    curr[buy][cnt] = max(sell,hold);
                }
            }  
        }
        ahead = curr;
    }
    return curr[0][2];
}

// Best Time to Buy and Sell Stock IV

// Memoization
// TC O(N*2*K)
// SC O(N*2*K + N)
int recursion(vector<int>& arr, int i, int buy, int cnt,
                vector<vector<vector<int>>>& dp) {
    if (cnt == 0)
        return 0;
    if (i == arr.size())
        return 0;

    if (dp[i][buy][cnt] != -1)
        return dp[i][buy][cnt];

    if (buy == 0) {
        int buying = recursion(arr, i + 1, 1, cnt, dp) - arr[i];
        int leave = recursion(arr, i + 1, 0, cnt, dp);
        return dp[i][buy][cnt] = max(buying, leave);
    } else {
        int sell = recursion(arr, i + 1, 0, cnt - 1, dp) + arr[i];
        int hold = recursion(arr, i + 1, 1, cnt, dp);
        return dp[i][buy][cnt] = max(sell, hold);
    }
}

int maxProfit(int k, vector<int>& arr) {
    int n = arr.size();
    vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(2, vector<int>(k+1, -1)));
    return recursion(arr, 0, 0, k, dp);
}

// Other way is that create a vector of size 2k {0,1,2,3,4,5,...}  where odd index represent buy and even index represent sell.
// In this way we can represent bought or not bought and no. of times bought in 1 array.
// 3D Dp will be reduced to 2D dp 

// Tabulation
int maxProfit(int k, vector<int>& arr) {
    int n = arr.size();
    vector<vector<vector<int>>> dp(
        n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

    for (int i = n - 1; i >= 0; i--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cnt = k; cnt >= 1; cnt--) {
                if (buy == 0) {
                    int buying = dp[i+1][1][cnt] - arr[i];
                    int leave = dp[i+1][0][cnt];
                    dp[i][buy][cnt] = max(buying, leave);
                } else {
                    int sell = dp[i+1][0][cnt-1] + arr[i];
                    int hold = dp[i+1][1][cnt];
                    dp[i][buy][cnt] = max(sell, hold);
                }
            }
        }
    }
    return dp[0][0][k];
}


// Space Optimization
int maxProfit(int k, vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> ahead (2, vector<int>(k + 1, 0));
    vector<vector<int>> curr (2, vector<int>(k + 1, 0));
    
    for (int i = n - 1; i >= 0; i--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cnt = k; cnt >= 1; cnt--) {
                if (buy == 0) {
                    int buying = ahead[1][cnt] - arr[i];
                    int leave = ahead[0][cnt];
                    curr[buy][cnt] = max(buying, leave);
                } else {
                    int sell = ahead[0][cnt-1] + arr[i];
                    int hold = ahead[1][cnt];
                    curr[buy][cnt] = max(sell, hold);
                }
            }
        }
        ahead = curr;
    }

    return curr[0][k];
}


// Best Time to Buy and Sell Stock with Cooldown

// Memoization 
// SC O(N*2 + N)
// TC O(N*2)
int recursion(vector<int>& arr, int i, int buy, vector<vector<int>>& dp) {
    if (i >= arr.size())
        return 0;

    if (dp[i][buy] != -1)
        return dp[i][buy];

    int profit = 0;
    if (buy == 0) {
        // Option to buy
        int buyStock = recursion(arr, i + 1, 1, dp) - arr[i];
        int skip = recursion(arr, i + 1, 0, dp);
        profit = max(buyStock, skip);
    } else {
        // Option to sell
        int sellStock = recursion(arr, i + 2, 0, dp) + arr[i];
        int hold = recursion(arr, i + 1, 1, dp);
        profit = max(sellStock, hold);
    }

    return dp[i][buy] = profit;
}


// Tabulation
int maxProfit(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));

    dp[n][0] = 0;
    dp[n][1] = 0;

    for (int i = n-1; i >= 0; i--) {
        for (int buy = 0; buy <= 1; buy++) {
            int profit = 0;
            if (buy == 0) {
                // Option to buy
                int buyStock = dp[i+1][1] - arr[i];
                int skip = dp[i+1][0];
                profit = max(buyStock, skip);
            } else {
                // Option to sell
                int sellStock = 0;
                if(i <= n - 2)
                    sellStock = dp[i+2][0] + arr[i];
                int hold = dp[i+1][1];
                profit = max(sellStock, hold);
            }
            dp[i][buy] = profit;
        }
    }

    return dp[0][1];
}



// Best Time to Buy and Sell Stock with Transaction Fee

// Memoization
// TC O(N*2)
// SC O(N*2 + n)
int recursion(vector<int>& arr,int &fee, int i, int buy, vector<vector<int>>& dp) {
    if (i >= arr.size())
        return 0;

    if (dp[i][buy] != -1)
        return dp[i][buy];

    int profit = 0;
    if (buy == 0) {
        // Option to buy
        int buyStock = recursion(arr,fee, i + 1, 1, dp) - arr[i];
        int skip = recursion(arr,fee, i + 1, 0, dp);
        profit = max(buyStock, skip);
    } else {
        // Option to sell
        int sellStock = recursion(arr,fee, i + 1, 0, dp) + arr[i]-fee;
        int hold = recursion(arr,fee, i + 1, 1, dp);
        profit = max(sellStock, hold);
    }
    cout << profit<< endl;

    return dp[i][buy] = profit;
}
int maxProfit(vector<int>& arr, int fee) {
    vector<vector<int>> dp(arr.size(),vector<int>(2,-1));
    return recursion(arr,fee,0,0,dp);
}

// Tabulation
// TC O(N*2)
// SC O(N*2)
int maxProfit(vector<int>& arr, int fee) {
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));

    dp[n][0] = 0;
    dp[n][1] = 0;

    for (int i = n - 1; i >= 0; i--) {
        for (int buy = 0; buy <= 1; buy++) {
            int profit = 0;
            if (buy == 0) {
                // Option to buy
                int buyStock = dp[i+1][1] - arr[i];
                int skip = dp[i+1][0];
                profit = max(buyStock, skip);
            } else {
                // Option to sell
                int sellStock = dp[i+1][0] + arr[i] - fee;
                int hold = dp[i+1][1];
                profit = max(sellStock, hold);
            }
            dp[i][buy] = profit;
        }
    }

    return dp[0][0];
}


// Space Optimization
// SC O(1)
// TC O(N*2)
int maxProfit(vector<int>& arr, int fee) {
    int n = arr.size();
    
    vector<int> ahead(2,0) , curr(2,0);

    

    for (int i = n - 1; i >= 0; i--) {
        for (int buy = 0; buy <= 1; buy++) {
            int profit = 0;
            if (buy == 0) {
                // Option to buy
                int buyStock = ahead[1] - arr[i];
                int skip = ahead[0];
                profit = max(buyStock, skip);
            } else {
                // Option to sell
                int sellStock = ahead[0] + arr[i] - fee;
                int hold = ahead[1];
                profit = max(sellStock, hold);
            }
            curr[buy] = profit;
        }
        ahead = curr;
    }
    return curr[0];
}



// Longest Increasing Subsequence

// Memoization
// TC O()
int recursion(vector<int>& nums, int i, int prev,vector<vector<int>>& dp) {
    if (i >= nums.size()) {
        return 0;
    }

    int take = 0,not_take = 0;
    if(dp[i][prev + 1e4+1] != -1)  return dp[i][prev + 1e4+1];


    if (nums[i] > prev)
        take = recursion(nums, i + 1, nums[i],dp) + 1;
    not_take = recursion(nums, i + 1, prev,dp);
    

    return dp[i][prev + 1e4+1] = max(take, not_take);
}
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(2*1e4+2, -1));
    return recursion(nums, 0, -1e4-1,dp);
}


int main(){




    return 0;
}









