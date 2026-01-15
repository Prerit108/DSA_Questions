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


// Q Celebrity problem (Diagonal elements are 1)

// Method 1
// TC O(N^2 + N)
// SC O(2N)
int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int> iknow(n,0);   // knows someone  eg -> if [0][2] == 1 them iknow[0]++ and knowme[2]++
        vector<int> knowme(n,0);  // known by someone 
        for(int i = 0;i < n;i++){
            for(int j = 0;j<n;j++){
                if(mat[i][j] == 1){
                    iknow[i]++;
                    knowme[j]++;
                }
            }
        }
        for(int i = 0;i<n;i++){
            if(iknow[i] == 1 && knowme[i] == n){
                return i;
            }
        }
        return -1;
    }

// Method 2
// TC O(2N)
// SC O(1)
int celebrity(vector<vector<int>>& mat) {
    int n = mat.size();
    int top = 0;
    int down = n-1;
    while(top < down){
        if(mat[down][top] == 1){    // this person knows someone , therefore not celebrity
            down--;
        }
        else if(mat[top][down] == 1){    // this person knows someone , therefore not celebrity
            top++;
        }
        else{        
            top++;
            down--;
        }
    }
    if(top > down){
        return -1;
    }
    // Rechecking if the person is celebrity
    else{
        for(int i = 0;i<n;i++){
            if(i == top){
                continue;
            }
            if(mat[i][top] == 1 && mat[top][i] == 0){
                continue;
            }
            
            else{
                return -1;
            }
        }
    }
    return top;
}

// Q LFU cache



// Q length Of Longest Substring
// take low and high pointer (marking ends of non repeating substring)
// TC O(N)
// SC O(256)  Max no. of character
int lengthOfLongestSubstring(string s) {
    int mlength = 0;
    unordered_map<char,int> m;
    int n = s.size();
    int low = 0;
    int high = 0;
    for(int i = 0;i < n;i++){
        if(m.find(s[i]) != m.end()){
            while(low <= m[s[i]]){
                m.erase(s[low]);
                low++;
            }
            m[s[i]] = i;
            high++; 
        }
        else if(m.find(s[i]) == m.end()){
            m[s[i]] = i;
            high++;
        }
        mlength = max(mlength,high - low);
        cout << high << ' ';
        cout << low << ' ' << endl;
    }
    return mlength;
}


// Maximize Number of 1's

//  Method 1
// Finding all valid sub arrays
// TC O(N^2)
// SC O(1)
int longestOnes(vector<int>& nums, int k) {
    int n = nums.size();
    int mlength = 0;
    for(int i = 0;i<n;i++){
        int zeros = 0;
        for(int j = i;j<n;j++){
            if(nums[j] == 0){
                zeros++;
            }
            if(zeros > k){
                break;
            }
            mlength = max(mlength,j-i+1);
        }
    }
    return mlength;
}

// Method 2
// take 2 pointer left and right
// SC O(1)
// TC O(2N)  NEACH FOR BOTH Left AND Right
int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int zeros = 0;
        int mlength = 0;
        int right = 0;
        while(right < n){
            if(nums[right] == 0)  zeros++;
            while(zeros > k){
                if(nums[left] == 0){
                    zeros--;
                }
                left++;
            }
            mlength = max(mlength,right-left+1);
            right++;

        }
        return mlength;
    }

// Method 3 
// 2 pointer but both pointer moves only by one place
//  Update mlength only if found a bigger window if not maintain the largest window
// TC O(N)
// SC O(1)
int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int zeros = 0;
        int mlength = 0;
        for(int right = 0;right < n;right++){
            if(nums[right] == 0) zeros++;
            if(zeros > k){
                if(nums[left] == 0){
                    zeros--;
                }
                left++;
            }
            if(zeros<=k)
            mlength = max(mlength,right-left+1);
        }
        return mlength;
    }

// Q Fruits in Basket

// Method 1 


// Method 2
// 2 pointer approach
// TC O(N)
// SC O()
int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int mlength = 0;
        int left = 0;
        unordered_map<int,int> m;
        for(int right = 0;right< n;right++){
            m[fruits[right]]++; 
            if(m.size() > 2){
                    m[fruits[left]]--;
                    if(m[fruits[left]] == 0){
                        m.erase(fruits[left]);
                    }
                    left++;
            }
            if(m.size() <= 2){
                mlength = max(mlength,right - left + 1);   
            }     
        }

        return mlength;
    }


// Q Longest repeating character replacement
 
// Method 1 
// Find all possible subarrays and k = length - maxfrequency OF ELEMENT
// TC O(N^2)
// SC O(26)
int characterReplacement(string s, int k) {
    int n = s.size();
    int mfreq = 0;
    int mlength = 0;
    
    for(int i = 0;i < n;i++){
        vector<int> arr(26,0);    // Hash array
        int mfreq = 0;
        for(int j = i;j < n;j++){
            arr[s[j] - 'A']++;
            mfreq = max(mfreq,arr[s[j] - 'A']);
            int changes = j-i+1-mfreq;
            if(changes <= k)   mlength = max(mlength,j-i+1);
            else break;
        }
    }
    return mlength;
}

// Method 2
// move left pointer until changes less than k
// TC O(26*(N+N))
//  SC O(26)
int characterReplacement(string s, int k) {
    int n = s.size();
    int mlength = 0;
    int left = 0;
    vector<int> arr(26,0);
    int mfreq = 0;
    for(int right =  0;right < n;right++){
        arr[s[right] - 'A']++;
        mfreq = max(mfreq,arr[s[right] - 'A']);
        int changes = right - left + 1 - mfreq;
        while(right - left + 1 - mfreq > k){
            arr[s[left] - 'A']--;
            mfreq = 0;
            left++;
            for(int i = 0;i<26;i++){
                mfreq = max(mfreq,arr[i]);
            }
            
        }
            mlength = max(mlength,right - left +1);
        
    }
    return mlength;
}

// Method 3
// k = length - maxfrequency(OF ELEMENT) and move the window by one step only 
// Update mlength only if found a bigger window ,if not maintain the largest window
// Do not decrease mfreq
// TC O(N)
//  SC O(26)
int characterReplacement(string s, int k) {
    int n = s.size();
    int mlength = 0;
    int left = 0;
    vector<int> arr(26,0);
    int mfreq = 0;
    for(int right =  0;right < n;right++){
        arr[s[right] - 'A']++;
        mfreq = max(mfreq,arr[s[right] - 'A']);
        int changes = right - left +1-mfreq;         // right - left +1 = length of subarray
        if(changes > k){ 
            arr[s[left] - 'A']--;
            // for(int i = 0;i<26;i++){
            //     mfreq = max(mfreq,arr[i]);
            // }
            left++;
        }
        if(changes <= k)   mlength = max(mlength,right - left +1);
        
    }
    return mlength;
}


// Q Binary Subarray with sum ( same as Count Subarray sum Equals K)

// Method 1
// Finding all the subarrays
// TC O(N^2)
// SC O(1)
int numSubarraysWithSum(vector<int>& nums, int goal) {
    int n = nums.size();
    int left = 0;
    int nsubarray = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = i; j < n; j++) {
            if(nums[j] == 1){
                cnt++;
            }
            if(cnt == goal){
                nsubarray++;
            }
        }
        cout << right << " ";
        cout << left << " ";
        cout << nsubarray << endl;
    }
    return nsubarray;
}

// Method 2 
// same as Count Subarray sum Equals K
// TC O(N)
// SC O(N)
int numSubarraysWithSum(vector<int>& nums, int k) {
    int n = nums.size();
    int sum = 0;
    int nsubarray = 0;
    int count = 0;
    unordered_map<int,int> m = {{0,1}};
    for (int i = 0; i < n; i++) {
        sum = sum+nums[i];
        count = count + m[sum - k];
        m[sum]++;
    }
    return count;
}

// Method 3
// Find number subarrays with sum <= goal and sum <= goal-1, then subtract both numbers
// TC O(2N * 2)
// SC O (1)
int numSubarraysWithSumlessthan(vector<int>& nums, int goal) {
    if(goal < 0) {return 0;}
    int n = nums.size();
    int sum = 0;
    int nsubarray = 0;
    int count = 0;
    int left = 0;
    for (int r = 0; r < n; r++){
        if(nums[r] == 1)  sum++;
        while(sum > goal){
            if(nums[left] == 1)    sum--;
            left++;
        }
        count = count + r - left + 1;
    }
    return count;
}
int numSubarraysWithSum(vector<int>& nums, int goal) {
    int x = numSubarraysWithSumlessthan(nums,goal);
    int y = numSubarraysWithSumlessthan(nums,goal-1);
    return x-y;
}

// Q Count number of nice arrays

// Method 1 
// create all subarrays

// Method 2
// Find number subarrays with oddnumber <= k and oddnumber <= k-1, then subtract both numbers
// TC O(2N * 2)
// SC O (1)
int numberOfSubarrayslessthanequal(vector<int>& nums, int k) {
    int n = nums.size();
    int changes = 0;
    int nsubarray = 0;
    int left = 0;
    for(int r = 0;r < n;r++){
        if(nums[r]%2 == 1) changes++;
        while(changes > k){
            if(nums[left]%2 == 1){
                changes--;
            }
            left++;
        }
        nsubarray = nsubarray + r-left+1;  
    }
    return nsubarray;
}

int numberOfSubarrays(vector<int>& nums, int k){
    int x = numberOfSubarrayslessthanequal(nums,k);
    int y = numberOfSubarrayslessthanequal(nums,k-1);
    return x - y;
}


// Q Number of substring containing all three characters
// TC O(N)
// SC O(1)
// Find the subarray where all three character are present
// Store lastseen appereance of each character, cnt = cnt+min(a,b,c)
int numberOfSubstrings(string s) {
    int n = s.size();
    int cnt = 0;
    int hash[3] = {-1,-1,-1};
    for(int i = 0;i < n;i++){
        hash[s[i] - 'a'] = i;
        if(hash[0] != -1 && hash[1] != -1 && hash[2] != -1){
            cnt = cnt + 1 + min(hash[0],min(hash[1],hash[2]));
        }
    }
    return cnt;
}


int main(){
    return 0;
}