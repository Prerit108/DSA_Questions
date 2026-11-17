#include<bits/stdc++.h>

// Longest Increasing Subsequence

// Memoization 
// TC O(N * N)
// SC O(N * N + N)

int recursion(vector<int>& nums, int i, int prev_ind,vector<vector<int>>& dp) {
    if (i >= nums.size()) {
        return 0;
    }

    if(dp[i][prev_ind + 1] != -1) return dp[i][prev_ind + 1];

    int take = 0,not_take = 0;
    if (prev_ind == -1 || nums[i] > nums[prev_ind]) {    
        take = recursion(nums, i + 1, i,dp) + 1;
    }
    not_take = recursion(nums, i + 1, prev_ind,dp);
    return dp[i][prev_ind + 1] = max(take, not_take);
}
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    return recursion(nums, 0, -1,dp);
}


// LIS USING BINARY SEARCH
// TC O(N* log(N))
// SC O(N)
int lengthOfLIS(vector<int>& nums){
    int n = nums.size();
    vector<int> temp;
    temp.push_back(nums[0]);
    int len = 1;
    for(int i = 1;i < n;i++){
        if(nums[i] > temp.back()){
            temp.push_back(nums[i]);
            len++;
        }
        else{
            int ind = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();  
            // Find the index of next greater element or equal element from the vector using binary search.
            temp[ind] = nums[i];
        }
    }
    return len;
}


// DIfferent kind of tabulation apprach (required for printing the LIS sequence)
vector<int> getLIS(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n,1);
    int maxi = 1;
    for(int i = 0;i < n;i++){
        for(int prev = 0;prev < i;prev++){
            if(arr[prev] < arr[i]){
                dp[i] = max(dp[i],1 + dp[prev]);
            }
        }
        maxi = max(dp[i],maxi);
    }
    return maxi;
}


// Printing Longest Increasing Subsequence 
// TC O(N^2)
// SC O(N)
vector<int> getLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n,1),hash(n);
        int lastind = 0;
        int maxi = 1;
        
        for (int i = 0; i < n; i++)
            hash[i] = i;
        
        for(int i = 0;i < n;i++){
            for(int prev = 0;prev < i;prev++){
                if(arr[prev] < arr[i] && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                lastind = i;
            }
        }
        
        vector<int> temp;
        temp.push_back(arr[lastind]);
        while(hash[lastind] != lastind){
            lastind = hash[lastind];
            temp.push_back(arr[lastind]);
        }
        
        reverse(temp.begin(),temp.end());
        
        return temp;
    }


// Largest Divisible Subset
// TC O(N^2)
// SC O(N)
vector<int> largestDivisibleSubset(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n,1),hash(n);
    int lastind = 0;
    int maxi = 1;
    sort(arr.begin(),arr.end());
    
    for (int i = 0; i < n; i++)
        hash[i] = i;
    
    for(int i = 0;i < n;i++){
        for(int prev = 0;prev < i;prev++){
            if(arr[i] % arr[prev] == 0 && 1 + dp[prev] > dp[i]){
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if(dp[i] > maxi){
            maxi = dp[i];
            lastind = i;
        }
    }
    
    vector<int> temp;
    temp.push_back(arr[lastind]);
    while(hash[lastind] != lastind){
        lastind = hash[lastind];
        temp.push_back(arr[lastind]);
    }
    
    reverse(temp.begin(),temp.end());
    
    return temp;
}


// Longest String Chain
// TC O(N*log(N) + N^2 * L) L is the length of the word
// SC O( N )
bool string_compare(string &a, string &b) {
    int extra = 0;
    int x = 0, y = 0;
    if(a.size() + 1 != b.size())    return false;
    while (x < a.size() && y < b.size()) {
        if (a[x] == b[y]) {
            x++;
            y++;
        } else {
            y++;
            extra++;
        }
    }
    if (extra == 1 || x == y) {
        return true;
    }
    
    return false;
}
int longestStrChain(vector<string>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);
    int maxi = 1;

    sort(arr.begin(), arr.end(), [](const string& a, const string& b) {
        return a.length() < b.length();
    });

    for (int i = 0; i < n; i++) {
        for (int prev = 0; prev < i; prev++) {
            if (string_compare(arr[prev], arr[i])) {
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }
        maxi = max(dp[i], maxi);
    }
    return maxi;
}


// Longest Biotonic Subsequence (Strictly increasing and decreasing subsequences are not allowed)
// TC O(N*LOG(N))
// SC O(2N)

int longestBitonicSequence(int n, vector<int> &nums) {
    
    vector<int> dp1(n,1);
    vector<int> dp2(n,1);
    
    for(int i = 0;i < n;i++){
        for(int prev = 0;prev < i;prev++){
            if(nums[i] > nums[prev] && dp1[prev] + 1 > dp1[i]){
                dp1[i] = dp1[prev] + 1;
            }
        }
    }
    
    for(int i = n - 1;i >= 0;i--){
        for(int prev = n-1; prev > i;prev--){
            if(nums[i] > nums[prev]){
                dp2[i] = max(dp2[i],dp2[prev] + 1);
            }
        }
    }
    
    int ans = 0;
    for(int i = 0;i < n;i++){
        if(dp1[i] > 1 && dp2[i] > 1){
            ans = max(ans,dp1[i] + dp2[i] -1);
        }
    }
    return ans;
}



// Number of Longest Increasing Subsequence
// SC O(N)
// TC O(N*log(N))
int findNumberOfLIS(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);
    vector<int> cnt(n, 1);

    int maxi = 1;
    for (int i = 0; i < n; i++) {
        for (int prev = 0; prev < i; prev++) {
            // if the length 
            if (arr[prev] < arr[i] && dp[i] < 1 + dp[prev]) {
                dp[i] = 1 + dp[prev];
                cnt[i] = cnt[prev];
            }
            else if(arr[prev] < arr[i] && dp[i] == dp[prev] + 1){
                cnt[i] += cnt[prev];
            }
        } 
        maxi = max(maxi,dp[i]);
        
    }

    int ans  = 0;
    for (int i = 0; i < n; i++) {
        if(dp[i] == maxi) ans += cnt[i];
    } 
    return ans;
}



int main(){

    return 0;
}

