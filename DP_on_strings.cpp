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



// Maximum Length of Repeated Subarray || Longest common substring
// TC O(N*N)
// SC O(N * N + N)

// Dp array will be filled diagonally only

int recursion(vector<int>& a, vector<int>& b, int i, int j,
                  vector<vector<int>>& dp, int& maxi) {

    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    recursion(a, b, i - 1, j, dp, maxi);
    recursion(a, b, i, j - 1, dp, maxi);

    if (a[i] == b[j])
        dp[i][j] = 1 + recursion(a, b, i - 1, j - 1, dp, maxi);
    else
        dp[i][j] = 0;

    maxi = max(maxi, dp[i][j]);
    return dp[i][j];
}

int findLength(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int maxx = 0;
    recursion(nums1, nums2, n - 1, m - 1, dp,maxx);

    return maxx;
}



// Delete Operation for Two Strings
// TC O(N*M)
// SC O(N * M + N + M)
// length of both string - LCS
int recursion(string &word1, string &word2,int i,int j,vector<vector<int>> & dp){
    if(i < 0 || j < 0){
        return 0;
    }

    if(dp[i][j] != -1)  return dp[i][j];

    if(word1[i] == word2[j]) return dp[i][j] = 2 + recursion(word1,word2,i-1,j-1,dp);

    return dp[i][j] = max(recursion(word1,word2,i-1,j,dp),recursion(word1,word2,i,j-1,dp));

}
int minDistance(string word1, string word2) {
    int i = word1.size();
    int j = word2.size();
    vector<vector<int>> dp(i,vector<int>(j,-1));
    int len = recursion(word1,word2,i-1,j-1,dp);
    return i + j - len;
}

// Minimum Insertion Steps to Make a String Palindrome
// TC O(N*N)
// SC O(N * N + N)
// N - length of the longest palindrome sequence
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
int minInsertions(string s) {
    int n = s.size();
    vector<vector<int>> dp(n,vector<int>(n,-1));
    int len =  recursion(s,0,n-1,dp);
    return n - len;
}


// Distinct Subsequences
// TC O(N*M)
// SC O(N * M + N + M)
int recursion(string &s, string &t,int i , int j,vector<vector<int>> &dp){
    if (j < 0) return 1;
    if (i < 0) return 0;
    
    if(dp[i][j] != -1)  return dp[i][j];

    
    if(s[i] == t[j])   return dp[i][j] = recursion(s,t,i-1,j-1,dp) + recursion(s,t,i-1,j,dp);

    return dp[i][j] = recursion(s,t,i-1,j,dp);
}

int numDistinct(string s, string t) {
    int i = s.size();
    int j = t.size();

    vector<vector<int>> dp(i,vector<int>(j,-1));

    return recursion(s,t,i-1,j-1,dp); 

}


// Wildcard Matching

// Imp test cases
// "adceb" "*a*b"
// "adceb" "*a?b"
// "adceb" "?a*b"
// "adceb" "?a?b"
// "" "***"
// "" "*?*"
// "a" ""
// "a" "***"
// "a" "*?*"
// "a" "?**"
// "a" "**?"
// "" ""
// "aa" "*aaa*"

// TC O(N*M)
// SC O(N * M + N + M)
int recursion(string &s,string &p,int i , int j,vector<vector<int>> &dp){
    if(i < 0 && j < 0)  return 1;
    if(i < 0){
        int match = 0;
        for(int n = j;n >=0 ;n--){
            if(p[n] == '*'){
                match = 1;
            }
            else {
                match = 0;
                break;
            }
        }
        return match;
    } 
    if(i < 0 || j < 0) return 0;
    
    if(dp[i][j] != -1)  return dp[i][j];
    
    if(p[j] == s[i] || p[j] == '?') return dp[i][j] = recursion(s,p,i-1,j-1,dp);

    else if(p[j] == '*') return dp[i][j] = (recursion(s,p,i-1,j-1,dp) || recursion(s,p,i-1,j,dp)) || recursion(s,p,i,j-1,dp);
    // works without recursion(s,p,i-1,j-1,dp) this also. but take few extra recursion steps.

    return dp[i][j] =  0;
    

}
bool isMatch(string s, string p) {
    int i = s.size();
    int j = p.size();
    vector<vector<int>> dp(i,vector<int>(j,-1));
    return recursion(s,p,i-1,j-1,dp);
}


// Edit Distance
// TC O(N*M)
// SC O(N * M + N + M)
int recursion(string &word1, string &word2,int i,int j,vector<vector<int>> &dp){
    if(j < 0){   
        return i + 1;
    }
    if(i < 0) return j + 1;


    // Also fine for 0 based indexing
    // if(j < 0) return abs(i-j);
    //     if(i < 0) return abs(i-j);


    if(dp[i][j] != -1)  return dp[i][j];

    if(word1[i] == word2[j])    return dp[i][j] = recursion(word1,word2,i-1,j-1,dp);

    // Use all 3 possibilities inertion,replace and deletion respectively
    return dp[i][j] = min(recursion(word1,word2,i,j-1,dp),min(recursion(word1,word2,i-1,j-1,dp),recursion(word1,word2,i-1,j,dp))) + 1;
}

int minDistance(string word1, string word2) {
    int i = word1.size();
    int j = word2.size();

    // TO ensure that word1 is the longer string.
    if(j > i) { 
        vector<vector<int>> dp(j,vector<int>(i,-1));
        return recursion(word2,word1,j-1,i-1,dp);
    }
    vector<vector<int>> dp(i,vector<int>(j,-1));
    return recursion(word1,word2,i-1,j-1,dp);
}





int main(){



    return 0;
}