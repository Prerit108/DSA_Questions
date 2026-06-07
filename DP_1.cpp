#include <bits/stdc++.h>
#include <iostream>
using namespace std;


// Fibonaci series via DP

// Memoization
// TC O(N)
// SC O(N) + O(N)  STACK SPACE + dp vector space
int fib(int n, vector<int>& dp) {
    // If base case return n
    if (n <= 1) return n;

    // If already computed, return stored value
    if (dp[n] != -1) return dp[n];

    // Otherwise compute and store
    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}

// Tabulation
// TC O(N)
// SC O(N) 
 int fib(int n) {
        // If n is 0 or 1, return n
        if (n <= 1) return n;

        // Create dp array
        vector<int> dp(n + 1, 0);

        // Initialize base cases
        dp[0] = 0;
        dp[1] = 1;

        // Fill dp array iteratively
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        // Return final answer
        return dp[n];
    }

// Tabulation(Optimized space)
// TC O(N)
// SC O(1) 
int fib(int n) {
    // If n is 0 return 0
    if(n == 0) return 0;
    // If n is 1 return 1
    if(n == 1) return 1;

    // prev2 stores fib(n-2)
    int prev2 = 0;
    // prev stores fib(n-1)
    int prev = 1;
    // curr stores current fib
    int curr;

    // Loop from 2 to n
    for(int i = 2; i <= n; i++) {
        // Calculate current fib
        curr = prev + prev2;
        // Update prev2
        prev2 = prev;
        // Update prev
        prev = curr;
    }
    // Return final answer
    return prev;
}


// Climbing Stairs
// DP approach
// TC O(N)
// SC O(N)
unordered_map<int,int> mp;
int climbStairs(int n) {
    if(n == 0){
        return 1;
    }
    if(n < 0){
        return 0;
    }
    if(mp.find(n) != mp.end()){
        return mp[n];
    }
    return mp[n] = climbStairs(n-1) + climbStairs(n-2);
}

// Tabulation approach same as fibonacci 
int climbStairs(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    vector<int> dp(n+1);
    dp[0] = dp[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int climbStairs(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    int prev = 1, curr = 1;
    for (int i = 2; i <= n; i++) {
        int temp = curr;
        curr = prev + curr;
        prev = temp;
    }
    return curr;
    }


// Q Frog Jump  https://www.geeksforgeeks.org/problems/geek-jump/1

// Method 1 (Using Recursion) 
// TLE
void recursion(vector<int> height,vector<int>& dp,int i,int sum){
    if(i == height.size() -1){
        return dp.push_back(sum);
    }
    if(i == height.size()){
        return;
    }
    recursion(height,dp,i + 1,sum + abs(height[i+1] - height[i]));
    // if(i < height.size() - 2)
    recursion(height,dp,i + 2,sum + abs(height[i+2] - height[i]));
    return;
}
int minCost(vector<int>& height) {
    vector<int> dp;
    recursion(height,dp,0,0);
    int min = INT_MAX;
    for(int i = 0;i < dp.size();i++){
        if(min > dp[i])
            min = dp[i];
    }
    return min;
}

// Method 2 (Using DP)
// Also giving TLE  
int recursion(vector<int> height,vector<int>& dp,int i){
    if(i == 0){
        return 0;
    }
    if(dp[i] != -1){
        return dp[i];
    }
    int left = recursion(height,dp,i-1) + abs(height[i] - height[i-1]);
    int right = INT_MAX;
    if(i > 1)
        right = recursion(height,dp,i - 2) + abs(height[i] - height[i-2]);
    return min(left,right);
}
int minCost(vector<int>& height) {
    int n = height.size();
    vector<int> dp(n,-1);
    return recursion(height,dp,n-1);
}

// Method 3 (Tabulation)
int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n,-1);
        dp[0] = 0;
        for(int i = 1;i < n;i++){
            int first =  dp[i - 1] + abs(height[i] - height[i-1]);
            int second = INT_MAX;
            if(i > 1)
                second = dp[i - 2] + abs(height[i] - height[i-2]);
            
            dp[i] = min(first,second);
    
        }
        return dp[n-1];
        
    }

// Space optimized Tabulation
int minCost(vector<int>& height) {
    int n = height.size();
    int prev = 0;
    int prev2 = 0;   // previous of prev
    for(int i = 1;i < n;i++){
        int first =  prev + abs(height[i] - height[i-1]);
        int second = INT_MAX;
        if(i > 1)
            second = prev2 + abs(height[i] - height[i-2]);
        int curr = min(first,second);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}


// 	Frog jump with K distances

// Recursion
int recursion(vector<int> height,int i,int k){
    if(i == 0){
        return 0;
    }
    int mini = INT_MAX;
    for(int j = 1;j <= k;j++){
        if(i >= j)      int step = recursion(height,i - j,k) +  abs(height[i] - height[i-j]);
        mini = min(mini,step);
    }
    return mini;
}

// DP
// TC O(N*K)
// SC O(N + N)  stack space and dp array
int recursion(vector<int> height,vector<int>& dp,int i,int k){
    if(i == 0){
        return 0;
    }
    if(dp[i] != -1){
        return dp[i];
    }
    for(int j = 1;j <= k;j++){
        if(i >= j)      int step = recursion(height,i - j,k) + abs(height[i] - height[i-j]);
        dp[i] = min(dp[i],step);
    }
    return dp[i]; 
}


// Maximum sum of non adjacent elements or House Robber

// Method 1 DP 
// TC O(N)
// SC O(2N)
int recursion(vector<int> & arr,vector<int> &dp,int i){
    if(i < 0) return 0;
    if(i == 0)      return arr[0];
    if(dp[i] != -1)     return dp[i];

    int sum = recursion(arr,dp,i-2) + arr[i];
    
    int prevsum = recursion(arr,dp,i-1);
    // cout << prevsum << " ";
    return dp[i] = max(prevsum,sum);;
    
}
int findMaxSum(vector<int>& arr) {
    vector<int> dp(arr.size(),-1);
    if(arr.size() == 2){
        return max(arr[0],arr[1]);
    }
    return recursion(arr,dp,arr.size()-1);
    
}

// Method 2 Tabulation
// TC O(N)
// SC O(N)
int findMaxSum(vector<int>& arr) {
    vector<int> dp(arr.size(),-1);
    // base case
    dp[0] = arr[0]; 
    int neg = 0;
    
    for(int i = 1;i < arr.size();i++){
        int take = arr[i];
        if(i > 1)   take += dp[i-2];
        int nottake = dp[i-1];
        dp[i] = max(take,nottake);
    }
    return dp[arr.size() - 1];

}

// Method 3 Tabulation
// TC O(N)
// SC O(1)
int rob(vector<int>& arr) {
    // base case        
    int prev = arr[0];
    int prev2 = 0; // previous of prev

    for(int i = 1;i < arr.size();i++){
        int take = arr[i];
        if(i > 1)   take += prev2;
        int nottake = prev;
        // cout << nottake << " ";
        int current = max(take,nottake);
        prev2 = prev;
        prev = current;
    }
    return prev;
}


// House Robber 2 
// Method 1 DP  (Rest approaches same as House Robber)
// TC O(N)
// SC O(2N + N)
int recursion(vector<int>& nums,int start,int end,vector<int> & dp){
    if(end < start){
        return 0;
    }
    if(end == start){
        return nums[end];
    }
    if(dp[end] != -1)     return dp[end];
    
    int taken = recursion(nums,start,end-2,dp) + nums[end];

    int not_taken = recursion(nums,start,end-1,dp);
    
    return dp[end] = max(taken,not_taken);

}

int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 1)  return nums[0];
    
    vector<int> dp1(n-1,-1);
    vector<int> dp2(n,-1);

    return max(recursion(nums,0,n-2,dp1),recursion(nums,1,n-1,dp2));
    
}

// Ninja's Training
// Since we require to store task to be done today and the task done yesterday there 2 things to be stored therefore 2D DP array is required.

// Recursive Solution
int recursion(vector<vector<int>>& mat, int day, int last) {
    // Base case: first day
    if (day == 0) {
        int maxi = 0;
        for (int task = 0; task < 3; task++) {
            if (task != last) {
                maxi = max(maxi, mat[0][task]);
            }
        }
        return maxi;
    }

    int maxi = 0;
    for (int task = 0; task < 3; task++) {
        if (task != last) {
            int points = recursion(mat, day - 1, task) + mat[day][task];
            maxi = max(maxi, points);
        }
    }

    return maxi;
    }

int maximumPoints(vector<vector<int>>& mat) {
    int n = mat.size();
    return recursion(mat, n - 1, 3); // start from last day, with "no task" restriction
}


// DP
// TC O(N*4) * 3
// SC O(N + N*4)
int recursion(vector<vector<int>>& mat,int day,int last,vector<vector<int>> & dp){
    if(day == 0){
        int maxi = 0;
        for(int i = 0;i <= 2;i++){
            if(i != last)
            maxi = max(maxi,mat[day][i]);
        }
        return maxi;
    }
        
    int maxi = 0;
    if(dp[day][last] != -1)     return dp[day][last];
    
    for(int i = 0;i <= 2;i++){
        if(i != last){
            int points = recursion(mat,day-1,i,dp) + mat[day][i];
            maxi = max(points,maxi);
        }
        
    }

    return dp[day][last] = maxi;
}
int maximumPoints(vector<vector<int>>& mat) {
    int n = mat.size();
     // DP array will have n rows and 4 cols (3 tasks) and 4th one shows none of the task has been done (1st day)
    vector<vector<int>> dp(n, vector<int>(4, -1));
    
    return recursion(mat,n-1,3,dp);
    
}

// Tabulation
// TC O(N*4) * 3
// SC O(N*4)
 int maximumPoints(vector<vector<int>>& mat) {
        int n = mat.size();
        // DP array will have n rows and 4 cols (3 tasks) and 4th one shows none of the task has been done (1st day)
        vector<vector<int>> dp(n, vector<int>(4, -1));
        
        
        dp[0][0] = max(mat[0][1],mat[0][2]);
        dp[0][1] = max(mat[0][2],mat[0][0]);
        dp[0][2] = max(mat[0][0],mat[0][1]);
        dp[0][3] = max(mat[0][1],max(mat[0][2],mat[0][0]));
  
        for(int day = 1;day < n;day++){
            for(int last = 0;last <= 3; last++){
                // dp[day][last] = 0;
                for(int task = 0;task <= 2;task++){
                    if(task != last){
                        int points = dp[day-1][task] + mat[day][task];
                        dp[day][last] = max(points,dp[day][last]);
                    }
                }
            }
        }
        return dp[n-1][3];  // Initial parameters given in DP or recursion code.
        
    }

// Space optimization
// TC O(N*4) * 3
// SC O(1)
int maximumPoints(vector<vector<int>>& mat) {
    int n = mat.size();
    // DP array will have n rows and 4 cols (3 tasks) and 4th one shows none of the task has been done (1st day)
    vector<int> prev(4, -1);
    
    
    prev[0] = max(mat[0][1],mat[0][2]);
    prev[1] = max(mat[0][2],mat[0][0]);
    prev[2] = max(mat[0][0],mat[0][1]);
    prev[3] = max(mat[0][1],max(mat[0][2],mat[0][0]));

    for(int day = 1;day < n;day++){
        vector<int> curr(4,-1);
        for(int last = 0;last <= 3; last++){
            for(int task = 0;task <= 2;task++){
                if(task != last){
                    int points = prev[task] + mat[day][task];
                    curr[last] = max(points,curr[last]);
                }
            }
        }
        prev = curr;   // before moving to the next day update prev with the current
    }
    return prev[3];
    
}


// Unique Paths

// Recursion
// TC O(2^(M*N))
// SC O(Path length = M + N)
int recursion(int m,int n){
    if(m==0 && n == 0){
        return 1;
    }
    int top = 0;
    int left = 0;
    if(m > 0){
        top = recursion(m-1,n,sum) ;
    }
    if(n > 0){
        left = recursion(m,n-1,sum) ;
    }
    return top + left;
    
}
int uniquePaths(int m, int n) {
    recursion(m-1,n-1);
    return sum;
} 

// DP
// TC O(M*N)
// SC O(Path length = M + N) + (M*N)
int recursion(int m,int n,vector<vector<int>> &dp){
    if(m==0 && n == 0){
        return 1;
    }
    if(dp[m][n]  != 0)     return dp[m][n];
    int top = 0;
    int left = 0;
    if(m > 0){
        top = recursion(m-1,n,dp) ;
        dp[m][n] += top;
    }
    if(n > 0){
        left = recursion(m,n-1,dp);
        dp[m][n] += left;
    }
    return  dp[m][n];
}
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m,vector<int>(n,0));
    return recursion(m-1,n-1,dp);
}

// Tabulation 
// TC O(N*M)
// 1 Declare Base case
// 2 Express all states in for loops
// 3 Copy the recurrence and write
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m,vector<int>(n,0));
    dp[0][0] = 1;
    for(int rows = 0;rows < m;rows++){
        for(int cols = 0;cols < n;cols++){
            if(rows == 0 && cols == 0)  dp[0][0] = 1;   // for base case
            else{    
                int bottom = 0;
                int right = 0;
                if(rows > 0)
                    bottom = dp[rows - 1][cols];
                if(cols > 0)
                    right = dp[rows][cols - 1];
                dp[rows][cols] = bottom + right;
            }
        }
    }
    return dp[m-1][n-1];   // Initial parameters given in DP or recursion code.
    
}

// Space optimize
// TC O(N*M)
int uniquePaths(int m, int n) {
    vector<int> dp(n,0);   // prev row
    

    for(int rows = 0;rows < m;rows++){
        vector<int> temp(n,0);   // current row
        for(int cols = 0;cols < n;cols++){
            if(rows == 0 && cols == 0)  temp[0] = 1;
            else{  
                int bottom = 0;
                int right = 0;  
                if(rows > 0)
                    bottom = dp[cols];
                if(cols > 0)
                    right = temp[cols - 1];
                temp[cols] = bottom + right;
            }
        }
        dp = temp;
    }
    return dp[n-1];   // Initial parameters given in DP or recursion code.
    
}


// Unique Paths II

// Recursion 
// TC O(2^N)
int recursion(vector<vector<int>>& obstacleGrid,int rows,int cols){
    if(obstacleGrid[rows][cols] == 1){
        return 0;
    }
    if(rows == 0 && cols == 0){
        return 1;
    }   
    int num = 0;
    if(rows > 0){
        num += recursion(obstacleGrid,rows-1,cols);
    }
    if(cols > 0){
        num += recursion(obstacleGrid,rows,cols - 1);
    }
    return num;
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int rows = obstacleGrid.size();
    int cols = obstacleGrid[0].size();
    return recursion(obstacleGrid,rows-1,cols-1);
}

// DP
int recursion(vector<vector<int>>& obstacleGrid,int rows,int cols,vector<vector<int>> &dp){
    if(obstacleGrid[rows][cols] == 1){
        return dp[rows][cols] = 0;
    }
    if(rows == 0 && cols == 0){
        return dp[rows][cols] = 1;
    }   
    if(dp[rows][cols] != -1) return dp[rows][cols];
    int num = 0;
    if(rows > 0){
        num += recursion(obstacleGrid,rows-1,cols,dp);
    }
    if(cols > 0){
        num += recursion(obstacleGrid,rows,cols - 1,dp);
    }
    return dp[rows][cols] = num;
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int rows = obstacleGrid.size();
    int cols = obstacleGrid[0].size();
    vector<vector<int>> dp(rows,vector<int>(cols,-1));
    return recursion(obstacleGrid,rows-1,cols-1,dp);
}

// Tabulation
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        vector<vector<int>> dp(rows,vector<int>(cols,0));

        dp[0][0] = 1;
        for(int r = 0;r < rows;r++){
            for(int c = 0;c < cols;c++){
                int num = 0;
                if(obstacleGrid[r][c] == 1){
                    dp[r][c] = 0;
                    continue;
                }
                if(r == 0 && c == 0){
                    dp[0][0] = 1;
                }
                else{
                    if(r > 0) num += dp[r-1][c];
                    if(c > 0) num += dp[r][c-1];
                    dp[r][c] = num;
                }   
            }
        }
        return dp[rows - 1][cols - 1];
    }

// Space optimize
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int rows = obstacleGrid.size();
    int cols = obstacleGrid[0].size();
    vector<int> prev(cols,0);

    for(int r = 0;r < rows;r++){
        vector<int> curr(cols,0);
        for(int c = 0;c < cols;c++){
            int num = 0;
            if(obstacleGrid[r][c] == 1){
                curr[c] = 0;
                continue;
            }
            if(r == 0 && c == 0){
                curr[0] = 1;
            }
            else{
                if(r > 0) num += prev[c];
                if(c > 0) num += curr[c-1];
                curr[c] = num;
            }   
        }
        prev = curr;
    }
    return prev[cols - 1];
}

int main() {
    int n = 10;
    vector<int> dp(n + 1, -1);
    cout << fib(n, dp);
    return 0;
}
