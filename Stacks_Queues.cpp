#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Q Stack using Queue
class MyStack {
public:
    queue<int> q;
    MyStack() {
    }
    

    // TC O(N)
    void push(int x) {
        int s = q.size();
        q.push(x);
        for(int i = 0;i<s;i++){
            q.push(q.front());
            q.pop();
        }        
    }
    
    // TC O(1)
    int pop() {
        int p = q.front();
        q.pop();
        return p;
    }

    // TC O(1)
    int top() {
        return q.front();
    }

    // TC O(1)
    bool empty() {
        return q.empty();
        
    }
};

// Q Queue using Stack
class MyQueue {
public:
    stack<int> s1,s2;
    MyQueue() {
        
    }
    // TC O(2N)
    void push(int x) {
        int s = s1.size();
        for(int i = 0;i < s;i++){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        for(int i = 0;i < s;i++){
            s1.push(s2.top());
            s2.pop();
        }
    }

    // TC O(1)
    int pop() {
        int s = s1.top();
        s1.pop();
        return s;
    }

    // TC O(1)
    int peek() {
        return s1.top();
    }

    // TC O(1)
    bool empty() {
        return s1.empty();
    }
};

// Q Check for balanced paranthesis
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int size = s.size();
        for(int i = 0;i<size;i++){
            if(st.size() == 0){
                st.push(s[i]);
                continue;
            }
            if(st.top() == '(' && s[i] ==')' || st.top() == '[' && s[i] == ']' || st.top() == '{' && s[i] == '}'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        if(st.size() == 0){
            return true;
        }
        return false;
    }
};

// Q Implement Min Stack

// Using Stack which stores pair of int (value , min)
// SC O(2N)
// TC O(1)
class minStack {
public:
    MinStack() {
    }
    stack<pair<int,int>> st;
    void push(int val) {
        if(st.size() == 0){
            st.push({val,val});
        }
        else{
            st.push({val,min(val,st.top().second)});
        }
    }
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

// Using 2 stacks 
class MinStack {
public:
    MinStack() {
        
    }
    vector<int> st,mini;

    void push(int val) {
        st.emplace_back(val);
        if(mini.size() == 0){
            mini.emplace_back(val);
        }    
        else{
            if(val <= mini.back()){
                mini.emplace_back(val);
            }
        }
    }

    void pop() {
        if(st.back() == mini.back()){
            mini.pop_back();
        }
        st.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return mini.back();
    }
};

// Conversion

class conversion {
  public:
    int priority(char c){
        if(c == '^'){
            return 3;
        }
        else if(c == '*' || c == '/'){
            return 2;
        }
        else if(c == '+' || c == '-'){
            return 1;
        }
        else
            return -1;
    }
    string rev(string s){
        int sz = s.size();
        for(int i = 0;i < sz/2;i++){
            swap(s[i],s[sz-i-1]);
        }
        return s;
    }

    // Q Infix to Postfix
    // TC O(2N)
    // SC O(2N)
    string infixToPostfix(string& s) {  
        stack<char> st;
        string ans;
        int i = 0;
        int n = s.size();
        while(i < n){
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || s[i] >= '0' && s[i] <= '9'){
                ans += s[i];
            }
            else if(s[i] == '('){
                st.push(s[i]);
            }
            else if(s[i] == ')'){
                while(!st.empty() && st.top() != '('){
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            else {
                while(!st.empty()) {
                    int p1 = priority(st.top());
                    int p2 = priority(s[i]);
                    
                    // If current is '^' (Right Associative), strictly greater needed (^^ allowed)
                    if (s[i] == '^' && p1 > p2) {
                         ans += st.top();
                         st.pop();
                    }
                    // If current is normal operator (Left Associative), greater or equal needed(++,--,//,**) not allowed
                    else if (s[i] != '^' && p1 >= p2) {
                         ans += st.top();
                         st.pop();
                    }
                    else {
                        break; 
                    }
                }
                st.push(s[i]);
            }
            i++;
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }

    // Infix to prefix
    // TC O(2N) + O(N)(reverse 2 times)
    // SC O(2N)

    string infixToPrefix(string& s) {  
        s = rev(s);
        stack<char> st;
        string ans;
        int i = 0;
        int n = s.size();
        while(i < n){
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || s[i] >= '0' && s[i] <= '9'){
                ans += s[i];
            }
            else if(s[i] == ')'){
                st.push('(');
            }
            else if(s[i] == '('){
                while(!st.empty() && st.top() != '('){
                    ans += st.top();
                    st.pop();
                }
                st.pop();
            }
            else {
                while(!st.empty()) {
                    int p1 = priority(st.top());
                    int p2 = priority(s[i]);
                    // Reverse of postfix condition
                    if (s[i] == '^' && p1 >= p2) {
                         ans += st.top();
                         st.pop();
                    }
                    else if (s[i] != '^' && p1 > p2) {
                         ans += st.top();
                         st.pop();
                    }
                    else {
                        break; 
                    }
                }
                st.push(s[i]);
            }
            i++;
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        ans = rev(ans);
        return ans;
    }

    // postfix to infix
    // TC O(N) + O(N)(string concat operation taken time in some languages)
    // SC (N)  stack storage

    string postToInfix(string exp) {
        int i = 0;
        stack<string> st;
        int n = exp.size();
        while(i<n){
            if(isalnum(exp[i])) {
                string t(1,exp[i]);
                st.push(t);
            }
            else {
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();
                string t = "(" +t2 +exp[i] + t1+ ")";
                st.push(t);
                
            }
            i++;
        }
        return st.top();
    }

    // Prefix to infix
    // TC O(N) + O(N)(string concat operation taken time in some languages)
    // SC (N)  stack storage

    string preToInfix(string pre_exp) {
        int i = 0;
        stack<string> st;
        int n = pre_exp.size();
        for(int i = n-1;i >= 0;i--){
            if(isalnum(pre_exp[i])) {
                string t(1,pre_exp[i]);
                st.push(t);
            }
            else {
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();
                string t = "(" + t1 +pre_exp[i] + t2 + ")";
                st.push(t);
            }
        }
        return st.top();
    }

    // Postfix to Prefix 
    // TC O(N) + O(N)(string concat operation taken time in some languages)
    // SC (N)  stack storage
    string postToPre(string post_exp) {
        stack<string> st;
        int n = post_exp.size();
        int i = 0;
        while(i < n){
            if(isalnum(post_exp[i])){
                string t(1,post_exp[i]);
                st.push(t);
            }
            else{
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();
                string val = post_exp[i]+t2 + t1;
                st.push(val);
            }
            i++;
        }
        return st.top();
    }

    // Prefix to Postfix  
    // TC O(N) + O(N)(string concat operation taken time in some languages)
    // SC (N)  stack storage
    string preToPost(string pre_exp) {
        int i = 0;
        stack<string> st;
        int n = pre_exp.size();
        for(int i = n-1;i >= 0;i--){
            if(isalnum(pre_exp[i])) {
                string t(1,pre_exp[i]);
                st.push(t);
            }
            else {
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();
                string t = t1 + t2 +pre_exp[i];
                st.push(t);
            }
        }
        return st.top();
    }

};

// Q Next greater element

// taking all elements on the right
// TC O(N^2)
// SC O(N)
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> vec;
    int s1 = nums1.size();
    int s2 = nums2.size();
    for (int i = 0; i < s1; i++) {
        int nextGreater = -1;  // default if none found
        // find nums1[i] in nums2
        for (int j = 0; j < s2; j++) {
            if (nums1[i] == nums2[j]) {
                // look to the right of nums2[j]
                for (int k = j + 1; k < s2; k++) {
                    if (nums2[k] > nums2[j]) {
                        nextGreater = nums2[k];
                        break;
                    }
                }
                break; // stop once we found nums1[i] in nums2
            }
        }
        vec.emplace_back(nextGreater);
    }
    return vec;
}

// Monotonic stack
// TC O(N+M)
// SC O(3N)

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vec;
        stack<int> st;
        int s1 = nums1.size();
        int s2 = nums2.size();
        vector<int> arr(s2);
        for(int i = s2-1;i >= 0;i--){
            while(!st.empty() && st.top() < nums2[i]){
                st.pop();
            }
            if(st.empty()){
                arr[i] = -1;
            }
            else{   
                arr[i] = st.top();
            }     
            st.push(nums2[i]);
        }
        unordered_map<int,int> pos;
        for (int i = 0; i < s2; i++) {
            pos[nums2[i]] = i;
        }
        
        vec.reserve(s1);
        for (int x : nums1) {
            int j = pos[x];          // index in nums2
            vec.push_back(arr[j]);   // its next greater
        }

    return vec;
}

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> m1;

        for (int i = 0; i < nums1.size(); i++) {
            m1[nums1[i]]++;
        }

        // for (auto it = m1.begin(); it != m1.end(); it++) {
        //     cout << it->first << " " << it->second << endl;
        // }
        int n = nums2.size();
        stack<int> s;
        unordered_map<int, int> m2;
        for (int i = n - 1; i >= 0; i--) {
            if (m1.find(nums2[i]) != m1.end()) {
                if (s.empty()) {
                    m2[nums2[i]] = -1;
                    s.push(nums2[i]);
                } else {
                    while (!s.empty()) {

                        int ele = s.top();
                        if (nums2[i] > ele) {
                            s.pop();
                        } else {
                            m2[nums2[i]] = ele;
                            s.push(nums2[i]);
                            break;
                        }
                    }
                    if (s.empty()) {
                        m2[nums2[i]] = -1;
                        s.push(nums2[i]);
                    }
                }
            } else {
                if (s.empty()) {
                    s.push(nums2[i]);
                } else {
                    if (nums2[i] < s.top()) {
                        s.push(nums2[i]);
                    }
                }
            }
        }
        vector<int>ans;

        for(int i=0;i<nums1.size();i++)
        {
            ans.push_back(m2[nums1[i]]);
        }

        return ans;
    }

// Q Next greater element part 2

// TC O(4N) 2N push and 2N pop
// SC O(2N)
vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> vec(n, -1);
        for (int j = 2 * n - 1; j >= 0; j--) {      //Travesing the array twice
            while (!st.empty() && st.top() <= nums[j % n]) {
                st.pop();                   // Can pop at max 2N elements in the stack
            }
            if (j < n) {                  // Adding elements in the vec only once
                if(!st.empty()){
                    vec[j] = st.top();   
                }
            } 
            
            st.push(nums[j%n]);              // Can push at max 2N elements in the stack
        }
        return vec;
    }

// Q Next Smaller element
// TC O(N)
// SC O(N)

vector<int> nextSmallerEle(vector<int>& arr) {
    stack<int> st;
    int n = arr.size();
    vector<int> vec(n,-1);
    for(int i = n-1 ; i >= 0;i--){
        while(!st.empty() && st.top() >= arr[i]){
            st.pop();
        }
        if(!st.empty()){
            vec[i] = st.top();
        }
        st.push(arr[i]);
    }
    
    return vec;
}

// Q Number of Next greater elements for a given index

// Method 1
// TC O(N * (M))  M is the number of elements in the index array(whose nge is to be found)
// SC O(M)
vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
    stack<int> st;
    int n = arr.size();
    int m = indices.size();
    vector<int> vec(m,-1);
    for(int j = 0;j < m;j++){
        int nnge = 0;
        for(int i = n-1;i >= indices[j] ;i--){
            if(arr[i] > arr[indices[j]]){
                nnge++;
            }
        }
        vec[j] = nnge;
    }
    return vec;
}

// Method 2
// #####################################################################################################

// Q Asteroid Collision
// TC O(2N + M)
// SC O(N)

vector<int> asteroidCollision(vector<int>& ast) {
    stack<int> st;      // Can directly use vector also
    int n = ast.size();
    int eq = 0; // equal not found
    for (int i = 0; i < n; i++) {
        if (st.empty()) {
            st.push(ast[i]);
            continue;
        }
        if (!st.empty() && st.top() * ast[i] < 0) {
            if (ast[i] > 0) {
                st.push(ast[i]);
                continue;
            } else {
                while (!st.empty() && st.top() > 0) {
                    if (abs(ast[i]) > st.top()) {
                        while (!st.empty() && abs(ast[i]) > st.top()) {
                            if (st.top() < 0) {
                                break;
                            }
                            st.pop();
                        }
                    } else if (!st.empty() && st.top() == abs(ast[i])) {
                        st.pop();
                        eq = 1;
                        break;
                    } else if (!st.empty() && abs(ast[i]) < st.top()) {
                        eq = 1;
                        break;
                    }
                }
            }
        }
        if (eq == 0) {
            st.push(ast[i]);
        }
        eq = 0;
    }
    vector<int> vec(st.size());
    int m = st.size();
    for (int i = m - 1; i >= 0; i--) {
        vec[i] = st.top();
        st.pop();
    }
    return vec;
}

// Q Sum of Subarray Minimum

// Method 1
// Find all contiguous subarray and add min to sum 
// TC O(N^2)
int sumSubarrayMins(vector<int>& arr) {
    int sum = 0;
    int n = arr.size();
    int mod = 1e9 + 7;
    for(int i = 0;i < n;i++){
        int mini = arr[i];
        for(int j = i;j < n;j++){
            mini = min(arr[j],mini);
            sum = (sum + mini)%mod;
        }
    }
    return sum;
}

// Method 2
// Finding in how many subarray the current element will be min by using next smaller and prev smaller element
// To counter edge case(similar elements) use >= in either next smallest or prev greatest
// TC O(5N)
// SC O(5N)
vector<int> nextsmallest(vector<int>& arr){     //TC O(2N)
        int n = arr.size();
        vector<int> nse(n,-1);
        stack<int> st;
        for(int i = n - 1;i >= 0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                nse[i] = st.top();
            }
            
            st.push(i);
        }
        return nse;

    }

vector<int> prevsmaller(vector<int>& arr){       // TC O(2N)
    int n = arr.size();
    vector<int> pse(n,-1);
    stack<int> st;
    for(int i = 0;i < n;i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }
        if(!st.empty()){
            pse[i] = st.top();
        }
        st.push(i);

    }
    return pse;

}

int sumSubarrayMins(vector<int>& arr) {
    long long sum = 0;
    int n = arr.size();
    int mod = 1e9 + 7;
    vector<int> nse = nextsmallest(arr);
    vector<int> pse = prevsmaller(arr);
    for(int i = 0;i < n;i++){
        int nnse = 0,npse = 0;    // Number of subarrays on left and right before min is reached.
        if(nse[i] == -1){
            nnse = (n - i)%mod;
        }
        else{
            nnse = (nse[i] - i)%mod;
        }
        if(pse[i] == -1){
            npse =  (i+1)%mod;
        }
        else{
            npse =  (i - pse[i])%mod;
        }
        sum = (sum + (1LL*nnse*npse%mod)*arr[i])%mod;

    }
    return (int)sum;
}

// Q Sum of subarray ranges(largest - smallest)

// Method 1
// Finding max min in every array
// TC O(N^2)
// SC O(1)
long long subArrayRanges(vector<int>& nums) {
    long long ans = 0;
    int n = nums.size();
    for(int i=0;i<n;i++)
    {
        long long mn = nums[i];
        long long mx = nums[i];
        for(int j=i;j<n;j++) 
        {
            if(nums[j] > mx) mx = nums[j];
            if(nums[j] < mn) mn = nums[j];
            ans += (mx - mn);
        }
    }
    return ans;
}

// Method 2
// (Find the subarray min and subarray max and subtract them)
// TC O(10*N)
// SC O(10*N)
class Solution {
public:
    vector<int> nextsmallest(vector<int>& arr) { // TC O(2N)
        int n = arr.size();
        vector<int> nse(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nse[i] = st.top();
            }

            st.push(i);
        }
        return nse;
    }

    vector<int> prevsmaller(vector<int>& arr) { // TC O(2N)
        int n = arr.size();
        vector<int> pse(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                pse[i] = st.top();
            }
            st.push(i);
        }
        return pse;
    }

    vector<int> nextgreatest(vector<int>& arr) { // TC O(2N)
        int n = arr.size();
        vector<int> nge(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nge[i] = st.top();
            }

            st.push(i);
        }
        return nge;
    }

    vector<int> prevgreatest(vector<int>& arr) { // TC O(2N)
        int n = arr.size();
        vector<int> pge(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                pge[i] = st.top();
            }
            st.push(i);
        }
        return pge;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        long long sum = 0;
        int n = arr.size();
        int mod = 1e9 + 7;
        vector<int> nse = nextsmallest(arr);
        vector<int> pse = prevsmaller(arr);
        for (int i = 0; i < n; i++) {
            int nnse = 0, npse = 0; // Number of subarrays on left and right
                                    // before min is reached.
            if (nse[i] == -1) {
                nnse = (n - i) ;
            } else {
                nnse = (nse[i] - i) ;
            }
            if (pse[i] == -1) {
                npse = (i + 1) ;
            } else {
                npse = (i - pse[i]) ;
            }
            sum = (sum + (1LL * nnse * npse) * arr[i]);
        }
        return sum;
    }
    long long sumSubarrayMax(vector<int>& arr) {
        long long sum = 0;
        int n = arr.size();
        int mod = 1e9 + 7;
        vector<int> nge = nextgreatest(arr);
        vector<int> pge = prevgreatest(arr);
        for (int i = 0; i < n; i++) {
            int nnge = 0, npge = 0; // Number of subarrays on left and right
                                    // before min is reached.
            if (nge[i] == -1) {
                nnge = (n - i) ;
            } else {
                nnge = (nge[i] - i);
            }
            if (pge[i] == -1) {
                npge = (i + 1) ;
            } else {
                npge = (i - pge[i]) ;
            }
            sum = (sum + (1LL * nnge * npge ) * arr[i]) ;
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMax(nums) - sumSubarrayMins(nums);
    }
};


// Q Tapping rainwater
// Using the left and right pointer approach
// TC O(N)
// SC O(1)
int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;
    int l = 0;
    int r = n-1;
    int sum = 0;int leftmax = 0; int rightmax = 0;
    
    while(l < r){
        if(height[l] <= height[r]){
            if(height[l] <= leftmax){
                sum = sum + leftmax - height[l]; 
            }
            else{
                leftmax = height[l];
            }
            l++;
        }
        else{
            if(height[r] <= rightmax){
                sum = sum + rightmax - height[r]; 
            }
            else{
                rightmax = height[r];
            }
            r--;
        }
    } 
    return sum;
}



int main(){
    string s = "ab*c+";
    string o = postToInfix(s);


    return 0;
}





