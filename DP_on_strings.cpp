#include<bits/stdc++.h>





	
// Longest common subsequence
// TC O(N*M)
// SC O(N * M + N + M)
int recursion(string &text1, string &text2,int ind1,int ind2,vector<vector<int>>& dp){
    if(ind1 < 0 || ind2 < 0){
        return 0;
    }

    if(dp[ind1][ind2] != -1)    return dp[ind1][ind2];

    if(text1[ind1] == text2[ind2]){
        return dp[ind1][ind2] = 1 + recursion(text1,text2,ind1-1,ind2-1,dp);
    }

    return dp[ind1][ind2] = max(recursion(text1,text2,ind1,ind2-1,dp),recursion(text1,text2,ind1-1,ind2,dp));

}
int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size();
    int m = text2.size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    int len = recursion(text1,text2,n-1,m-1,dp)

    // To print the LCS also.
    string ans = "";
    for(int i = 0;i < len;i++){
        ans[i] = '$';
    }

    int i = n,j = m;
    int index = len - 1;
    while(i > 0 && j > 0){
        if(text1[i] == text2[j]){
            ans[index] = text1[i];
            index--;
            i--;j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else {
            j--;
        }
    }
    cout << ans;
    return len;
}


// Longest palindromic subsequence
// TC O(N*N)
// SC O(N * N + N)
int recursion(string &s,int front,int back,vector<vector<int>> &dp){
    if(front > back){
        return 0;
    }
    if(front == back){
        return 1;
    }
    if(dp[front][back] != -1) return dp[front][back];

    if(s[front] == s[back]){
        return 2 + recursion(s,front +1 ,back - 1,dp);
    }
    return dp[front][back] = max(recursion(s,front,back - 1,dp),recursion(s,front +1 ,back,dp));
}
int longestPalindromeSubseq(string s) {
    int n = s.size();
    // if(n == 1)  return -1
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return recursion(s,0,n-1,dp);
    
}


int main(){



    return 0;
}