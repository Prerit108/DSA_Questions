#include<bits/stdc++.h>

//  Matrix Chain Multiplication

// Recursion
int recursion(vector<int> &arr,int i,int j){
    if(i == j){
        return 0;
    }
    int mini = 1e9;
    for(int k = i;k < j;k++){
        int steps = arr[i-1]*arr[k]*arr[j] + recursion(arr,i,k) + recursion(arr,k+1,j);
        mini = min(steps,mini);
    }
    return mini;
    
}
int matrixMultiplication(vector<int> &arr) {
    int n = arr.size();
    return recursion(arr,1,n-1);
}

// Memoization
// TC O(N^3) 
// SC O(N^2 + N)

int recursion(vector<int> &arr,int i,int j,vector<vector<int>> &dp){
    if(i == j){
        return 0;
    }
    if(dp[i-1][j-1] != -1) return dp[i-1][j-1];
    
    int mini = 1e9;
    for(int k = i;k < j;k++){
        int steps = arr[i-1]*arr[k]*arr[j] + recursion(arr,i,k,dp) + recursion(arr,k+1,j,dp);
        mini = min(steps,mini);
    }
    return dp[i-1][j-1] = mini;
    
}
int matrixMultiplication(vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> dp(n-1,vector<int>(n-1,-1));   // Since the zero index of he array was not required so shrink the dp to n-1 elements.
     
    return recursion(arr,1,n-1,dp);
}


// Tabulation
// TC O(N^3) 
// SC O(N^2)
int matrixMultiplication(vector<int> &arr) {
    int n = arr.size();
    
    vector<vector<int>> dp(n,vector<int>(n,-1));
        
    for(int i = 0;i < n;i++){
        dp[i][i] = 0;
    }
    
    for(int i = n-1;i >= 1;i--){
        for(int j = i+1;j < n;j++){
            int mini = 1e9;
            for(int k = i;k < j;k++){
                int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];
                mini = min(steps,mini);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][n-1];
}

// Minimum Cost to Cut the Stick
// Recursion solution
int recursion(vector<int>& cuts,int i,int j){
    if(i > j){
        return 0;
    }
    int mini = 1e9;
    for(int k = i;k <= j;k++){

        int cut = (cuts[j+1] - cuts[i-1]) + recursion(cuts,i,k-1) + recursion(cuts,k+1,j);
        mini = min(cut,mini);
    }
    return mini;

}
int minCost(int n, vector<int>& cuts) {
    
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end());
    int len = cuts.size();

    return recursion(cuts,1,len-2);
}

// Memoization 
// TC O(N^3)
// SC O(N^2 + N)
int recursion(vector<int>& cuts,int i,int j,vector<vector<int>> &dp){
    if(i > j){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }

    int mini = 1e9;
    for(int k = i;k <= j;k++){
        int cut = (cuts[j+1] - cuts[i-1]) + recursion(cuts,i,k-1,dp) + recursion(cuts,k+1,j,dp);
        mini = min(cut,mini);
    }
    return dp[i][j] = mini;

}
int minCost(int n, vector<int>& cuts) {
    
    cuts.push_back(n);
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end());
    int len = cuts.size();
    vector<vector<int>> dp(len,vector<int>(len,-1));

    return recursion(cuts,1,len-2,dp);
}



// Tabulation
// TC O(N^3)
// SC O(N^2  )
int minCost(int n, vector<int>& cuts) {
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    int len = cuts.size();
    vector<vector<int>> dp(len+1, vector<int>(len+1, 0));

    for (int i = len - 2; i >= 1; i--) {
        for (int j = 1; j <= len-2; j++) {
            if(i > j)   continue;
            int mini = 1e9; 
            for (int k = i; k <= j; k++) {
                int cut = (cuts[j + 1] - cuts[i - 1]) + dp[i][k-1] + dp[k+1][j];
                mini = min(cut, mini);
            }
            dp[i][j] = mini;
        }
    }

    return dp[1][len-2];
}



int main(){


    return 0;
}