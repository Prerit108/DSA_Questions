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

int main() {
    int n = 10;
    vector<int> dp(n + 1, -1);
    cout << fib(n, dp);
    return 0;
}