#include <bits/stdc++.h>
#include <iostream>
using namespace std;


void merge(vector<int>& arr ,int low,int mid ,int high){
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while(left <= mid && right <= high){
        if(arr[left] >= arr[right]){
            temp.push_back(arr[right]);
            right++;
        } 
        else{
            temp.push_back(arr[left]);
            left++;
        }
    }  
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i = low; i <= high;i++){  // IMPORTANT
        arr[i] = temp[i-low];
    }
}

void mergesort(vector<int>& arr,int low,int high){
    if(low >= high){
        return;
    }
    int mid = (low + high)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
} 


// Q Assign Cookies

// Sort both arrays and distribute  according to greed factor
// TC O(N*logN + M*logM + N)
// SC O(1)
int findContentChildren(vector<int>& g, vector<int>& s) {
    int n = g.size();
    int m = s.size();
    mergesort(g,0,n-1);
    mergesort(s,0,m-1);
    int l = 0;
    int r = 0;
    while(l < n && r < m){
        if(g[l] <= s[r]){
            l++;
        }
        r++;
    }
    return l;
}


// Q Greedy algorithm to find minimum number of coins

// TC O(N)
// SC O(1)

int findMin(int n) {
    int n_coins = 0;
    int N = n;
    vector<int> vec =  {1, 2, 5, 10};
    int len = vec.size();
    for(int i = len-1;i >= 0;i--){    
        if(vec[i] <= N){
            n_coins += N/vec[i];
            N = N%vec[i];
        }
        if(N == 0)  break;
    }
    return n_coins;
}

// Q Lemonade Change

// TC O(N)
// SC O(1)

bool lemonadeChange(vector<int>& bills) {
    unordered_map<int, int> m;
    int n = bills.size();
    for (int i = 0; i < n; i++) {
        m[bills[i]]++;
        if(bills[i] > 10){
            if(m[10] > 0 && m[5] > 0){
                m[5]--;
                m[10]--;
            }
            else if(m[10] == 0 && m[5] >= 3)   m[5] -= 3;
            else return false;
        }
        else if(bills[i] > 5){
            if(m[5] > 0) m[5]--;
            else return false;
        }
        cout << m[5] << " " << m[10] << endl;
    }
    return true;
}

// Q Fractional Knapsack

// TC O(N*log(N) + 2*N)
// SC O(1)

static bool comp(pair<double,double> p1 ,pair<double,double> p2){
    if(p1.first < p2.first){
        return true;
    }
    if(p1.first > p2.first){
        return false;
    }
    return true;
    
}
double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
    int n = val.size();
    double value = 0;
    int weight = capacity;
    
    vector<pair<double,double>> vec;
    for(int i = 0;i<n;i++){
        double x = (double)val[i]/wt[i];
        vec.emplace_back(x,wt[i]);
    }
    sort(vec.begin(),vec.end(),comp);
    
    for(int i = n-1;i >= 0;i--){
        if(vec[i].second <= weight){
            value += vec[i].first * vec[i].second;
            weight -= vec[i].second;
        }
        else if(vec[i].second > weight){
            value += vec[i].first*weight;
            weight = 0;
        }
        if(weight == 0){
            return value;
        }
        
    }
    return value;
}

// Q N meetings in one room
// Look for meeting which ends earliest
// TC O(2N + N*log(N))
// SC O(2*N )
// Use structures if order of meeting is also required.
static bool comp(pair<int,int> p1,pair<int,int> p2){ 
    if(p1.second < p2.second) {
        return true; }
    return false; 
    
}
int maxMeetings(vector<int>& start, vector<int>& end) {
    int n = start.size();
    int meetings = 0;
    vector<pair<int,int>> vec;
    for(int i = 0;i < n;i++){
        vec.emplace_back(start[i],end[i]);
    }
    
    sort(vec.begin(),vec.end(),comp);
    int endtime = -1;
    for(int i = 0;i < n;i++){
        if(vec[i].first > endtime){
            endtime = vec[i].second;   
            meetings++;
        }   
        else{
            continue;
        }
    }
    return meetings;
}


// Q Jump Gain
// TC O (N)
// SC O(1)
bool canJump(vector<int>& nums) {
    int n = nums.size();
    // vector<pair<int,int>> vec;
    int pos = 0;
    for(int i = 0;i<n-1;i++){
        // vec.emplace_back(nums[i];i+nums[i]);
        pos = max(pos,nums[i] + i);
        if(pos > n-1){
            return true;
        }
        else if(pos == i){
            return false;
        }
    }
    return true;

}


// Jump Game 2 (Minimum jumps)
// Make a jump and find next lonest jump within the current jump.
// TC O(N)
// SC O(1)

int jump(vector<int>& nums) {
    int n = nums.size();
    if(n == 1) return 0;
    int final_ind = 0;
    int jumps = 0;
    int i = 0;
    while(i < n-1){
        final_ind = nums[i] + i;
        jumps++;
        if(final_ind >= n-1) return jumps;
        int j = final_ind;
        int max_jump_ind = i;
        i++;
        while(i <= j){
            if(final_ind < nums[i] + i){
                final_ind = max(final_ind,nums[i] + i);
                max_jump_ind = i;
            }
            if(final_ind >= n-1) return jumps+1;
            i++;
        }
        i = max_jump_ind;
    }
    return jumps;
}

// Same approach less complicated.
int jump(vector<int>& nums) {
    int n = nums.size();
    int jumps = 0, curEnd = 0, curFarthest = 0;
    for (int i = 0; i < n - 1; i++) {
        curFarthest = max(curFarthest, i + nums[i]);
        if (i == curEnd) {
            jumps++;
            curEnd = curFarthest;
        }
    }
    return jumps;
}

// Q Minimum number of platforms required for a railway
// 2 pointer approach 
// TC O((N*LOG(N) + N)*2)
// SC O(1)
int minPlatform(vector<int>& arr, vector<int>& dep) {
    sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
    
    int m = dep.size();
    int n = arr.size();
    
    int ans = 0;
    int maxans = 0; 
    int i = 0;
    int j = 0;
    while(i < n && j < m){
        if(arr[i] <= dep[j]){
            i++;
            ans++;
            maxans = max(ans,maxans);
        }
        else{
            ans--;
            j++;
        }  
    }
    return maxans;
}

// Q Job Sequencing Problem
// TC O(N*N + N*log(N))
// SC O(N)
// Best solution is by using Disjoint set union 
static bool comp(pair<int,int> p1,pair<int,int> p2){
    return p1.second > p2.second ;
}
vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
    int n = profit.size();
    vector<int> ans ={0,0};
    vector<pair<int,int>> vec;
    for(int i = 0;i < n;i++){
        vec.emplace_back(deadline[i],profit[i]);
    }
    vector<int> days(n+1,0);

    sort(vec.begin(),vec.end(),comp);
    
    for(int i = 0;i < n;i++){
        for(int j = vec[i].first ;j > 0;j--){
            if(days[j] == 0){
                ans[0]++;
                ans[1] += vec[i].second;
                days[j]++;
                break;
            }
        }
        
        if(ans[0] == n){
            return ans;
        }
    }
    return ans;
}

// Q Candy Problem

// Method 1
// Making two arrays in estroring candies required only on basis of left other on basis of right
// Then find max corresponding elements of both arrays and add to the sum
// TC O(3N)
// SC O(2N)
int candy(vector<int>& ratings) {
    int n = ratings.size();
    int ans = 0;
    vector<int> left ;
    left.emplace_back(1);
    vector<int> right;
    right.emplace_back(1);
    // if(n == 1)  return 1;
    int prev = 1;
    for(int i = 1;i < n;i++){
        if(ratings[i] > ratings[i-1]){
            prev++;
            left.emplace_back(prev);
        }
        // else if (ratings[i] == ratings[i-1]) left.emplace_back(prev);
        else {
            left.emplace_back(1);
            prev = 1;
        }
    }
    prev = 1;
    for(int i = n-2;i >= 0;i--){
        if(ratings[i] > ratings[i+1]){
            prev++;
            right.insert(right.begin(),prev);
        }
        // else if (ratings[i] == ratings[i+1]) right.insert(right.begin(),prev);
        else {
            right.insert(right.begin(),1);
            prev = 1;
        }
    }
    for(int i = 0;i<n;i++){
        ans = ans + max(left[i],right[i]);
    }
    return ans;
    
}

// Method 2
// Slope  Method
// TC O(N)
// SC O(1)
int candy(vector<int>& ratings) {
    int n = ratings.size();
    int ans = 1;
    int peak = 0;
    int bottom = 0;
    int i = 1;
    while(i < n){
        if(ratings[i] == ratings[i-1]){
            ans += 1;
            i++;
            continue;
        }
        peak = 1;
        while(i < n && ratings[i] > ratings[i-1]){
            peak++;
            ans += peak;
            i++;
        }
        bottom = 1;
        while(i < n && ratings[i] < ratings[i-1]){
            ans += bottom;
            bottom++;
            i++;
        }
        if(bottom > peak){
            ans += bottom - peak;
        }
    }
    return ans;
}

// Q Insert Intervals
// TC O(N)
// SC O(N)
// Find intervals which are smaller ,equal, and larger than the given newinterval 
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> ans;
    int n = intervals.size();
    int i = 0;
    while(i < n && newInterval[0] > intervals[i][1]){
        ans.push_back(intervals[i]);
        i++;
    }
    while(i < n && newInterval[1] >= intervals[i][0]){
        newInterval[0] = min(intervals[i][0],newInterval[0]);
        newInterval[1] = max(intervals[i][1],newInterval[1]);
        i++;
    }
    ans.push_back(newInterval);
    while(i < n){
        ans.push_back(intervals[i]);
        i++;
    }
    return ans;
}

// Q Non-overlapping Intervals

// TC O(N*LOG(N))
// SC O (1)
static bool comp(const vector<int>& p1, const vector<int>& p2){
        return p1[1] < p2[1];   // sort by end time
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int n = intervals.size();
    int ans = 0;
    int i = 1;
    sort(intervals.begin(),intervals.end(),comp);
    int end_interval = intervals[0][1];
    while(i < n){
        if(end_interval <= intervals[i][0]){
            end_interval = intervals[i][1];
            // i++;
            // continue;
        }
        else if(intervals[i][0] < end_interval){
            ans++;
            // end_interval = intervals[i][1];
            cout << intervals[i][0] << " "<<intervals[i][1] << endl;
        }
        i++;
        
    }
    return ans;
}

// Q Merge Intervals

// TC O(N*LOG(N))
// SC O(1)
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int j = 0;
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> vec = {intervals[0]};
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= vec[j][1]) {
            vec[j][1] = max(intervals[i][1], vec[j][1]);
        } else {
            vec.push_back(intervals[i]);
            j++;
        }
    }
    return vec;
}

// Q Valid Parenthesis

// Method 1
// Forward pass to by taking * as ( as 1 to check is it valid 
// Backward pass takinf ) and * as -1 to check is it valid , if both valid return true
// TC O(2N)
// SC O(1)
bool checkValidString(string s) {
    int n = s.size();
    int sum = 0;
    for(auto it:s){
        if(it == '(' || it == '*')      sum++;
        else    sum--;
        if(sum < 0)     return false;
    }

    sum = 0;
    for(int i = n-1;i >= 0;i--){
        if(s[i] == ')' || s[i] == '*')      sum--;
        else sum++;
        if(sum > 0) return false;
    }
    return true;
}


// Method 2
// TC O(N)
// SC O(1)

bool checkValidString(string s) {
    int n = s.size();
    int min = 0;
    int max = 0;
    for(auto it : s){
        if(it == '('){
            min++;
            max++;
        }
        else if(it == ')'){
            min--;
            max--;
        }
        else{
            min--;
            max++;
        }
        if(min < 0)     min = 0;
        if(max < 0)     return false;
    }
    if(min == 0){
        return true;
    }
    return false;
}

int main(){
    
    
    
    return 0;
}