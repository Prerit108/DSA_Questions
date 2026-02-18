#include <bits/stdc++.h>
#include <iostream>
using namespace std;


// Pow(x,n)
// divide power by 2 and square the base
// TC O(LOG(N))
// SC O(1)
double myPow(double x, int m) {
        double extra = 1;
        long long n = m;
        if(n == 0) return 1;
        while(abs(n) > 1){
            if(n%2 == 0){
                n = n/2;
                x = x*x;
            }
            else {
                n = n/2;
                extra *= x;
                x = x*x;
            }
            cout << x << " ";
        }
        if(n < 0) return 1/(x*extra);
        return x*extra;
    }

// Q Reverse a stack using recursion
// TC O(N^2)
// SC O(N)
void bottompusher(stack<int> & st,int x){       // Traverse to the bottom then push latest element at bottom
        if(st.empty()){
            st.push(x);
            return ;
        }
        int y = st.top();
        st.pop();
        bottompusher(st,x);      
        st.push(y);
        
    }
void reverseStack(stack<int> &st) {
    if(st.empty()){
        return ;
    }
    int x = st.top();
    st.pop();
    reverseStack(st);
    bottompusher(st,x);
}

// Q Sort a Stack
// TC O(N^2)
// SC O(N)
void sorter(stack<int> & st,int x){
    if(st.empty() || st.top() <= x){
        st.push(x);
        return;
    }
    int y = st.top();
    st.pop();
    sorter(st,x);
    st.push(y);
}
void sortStack(stack<int> &st) {
    if(st.empty()){
        return ;
    }
    int x = st.top();
    st.pop();
    sortStack(st);
    sorter(st,x);
}

// Q Generate all binary strings
// TC O(N * 2^N)   N for concatenation of each string and 2^N strings
// SC O(N)
void recursion(int n,vector<string> &vec,string s) {
    if(n <= 0){
        vec.push_back(s);
        return ;
    }
    recursion(n-1,vec,s + "0");
    
    recursion(n-1,vec,s + "1");
    
    return ;
    
}
 
vector<string> binstr(int n) {
    vector<string> vec ;
    recursion(n,vec,"");
    return vec;
    
}


// Q Subsets
// TC O(N*2^N) 
// SC O(N*2^N) (including output), O(N) auxiliary

void recursion(vector<int> nums,vector<vector<int>>& ans,vector<int>& vec,int n){
    if(n == nums.size()){
        ans.push_back(vec);
        return;
    }
    recursion(nums,ans,vec,n+1);   // Not taken
    vec.push_back(nums[n]);
    recursion(nums,ans,vec,n+1);   // taken
    vec.pop_back();
    return ;
    
} 

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> vec;
    recursion(nums,ans,vec,0);
    return ans;
}


// Q Count all subsequences with sum K
// TC O(2^N)
// SC O(N)

void recursion(vector<int> nums,int k,int sum,int n,int &ans){
    if(n == nums.size()){
        if(sum == k){
            ans++;
        }
        return;
    }
    if(sum >= k){
        return;
    }
    recursion(nums,k,sum,n+1,ans);

    recursion(nums,k,sum + nums[n],n+1,ans);
    
} 	
int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    int ans = 0;
    recursion(nums,k,0,0,ans);
    return ans;

}

// Check if there exists a subsequence with sum K
// TC O(2^N)
// SC O(N)
bool checkSubsequenceSum(int n, vector<int>& arr, int k,int sum = 0) {
    if(n < 0){
        if(sum  == k){
            return true;
        }
        return false;
    }
    if(sum > k){
        return false;
    }
    if(checkSubsequenceSum(n-1,arr,k,sum) == true)
    return true;
    
    if(checkSubsequenceSum(n-1,arr,k,sum + arr[n-1]) == true)
    return true;
    
    return false;
}

// Q Generate Parentheses
// 
// 
void recursion(int n,vector<string> &ans,string s,int i,int sum){
    if(sum < 0){
        return;
    }
    if(sum > n){
        return;
    }
    if(i == 2*n){
        if( sum == 0){
            ans.push_back(s);
            return;
        }
        else {
            return;
        }
    }
    recursion(n,ans,s+"(",i+1,sum+1);
    recursion(n,ans,s+")",i+1,sum-1);
    return ;
}        
vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string s = "(";
    recursion(n,ans,s,1,1);
    return ans;
}


// Combination Sum
// TC O(2^t * k)   t is the depth of tree, k is the avg length of combination
// SC O(x * k)    x is no. of combination

void recursion(vector<int> candidates,vector<int> vec,int target,vector<vector<int>>& ans, int i,int sum){
        if(sum == target){
            ans.push_back(vec);   // require linear time (cause of k in TC)
            return;
        }
        if(sum > target){
            return;
        }
        if(i == candidates.size()){
            return;
        }
        recursion(candidates,vec,target,ans,i+1,sum);    // If we leave it and move to next element
        vec.push_back(candidates[i]);
        recursion(candidates,vec,target,ans,i,sum + candidates[i]);      // If we take it , we can retake it
        
    }
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> vec;
    recursion(candidates,vec,target,ans,0,0);
    return ans;
}

// Combination Sum 2

// Method 1
// TC O(2^t * k * log(K))   t is the depth of tree, k is the avg length of combination  , log(k) inserion in stack
// SC O(x * k)    x is no. of combination
void recursion(vector<int> candidates,vector<int> vec,int target,set<vector<int>>& ans, int i,int sum){
    if(sum == target){
        ans.insert(vec);
        return;
    }
    if(sum > target){
        return;
    }
    if(i == candidates.size()){
        return;
    }
    
    vec.push_back(candidates[i]);
    recursion(candidates,vec,target,ans,i+1,sum + candidates[i]);
    
    vec.pop_back();
    recursion(candidates,vec,target,ans,i+1,sum);
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    set<vector<int>> ans;
    vector<vector<int>> fans;
    vector<int> vec;
    recursion(candidates,vec,target,ans,0,0);
    fans.assign(ans.begin(),ans.end());
    return fans;
}

// Method 2 (approach in notes)
// TC O(2^N * k)    t is the depth of tree, k is the avg length of combination 
// SCC O(x * k)     x is no. of combination

void recursion(vector<int> candidates,vector<int> vec,int target,vector<vector<int>>& ans, int i,int sum){
    if(sum == target){
        ans.push_back(vec);
        return;
    }
    if(sum > target){
        return;
    }
    if(i == candidates.size()){
        return;
    }
    for(int j = i;j < candidates.size();j++){
        if(j > i && candidates[j] == candidates[j-1])   continue;
        if(candidates[j] > target - sum)   continue;
        vec.push_back(candidates[j]);
        recursion(candidates,vec,target,ans,j+1,sum + candidates[j]);
        vec.pop_back();
    }
    
    
    
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    vector<vector<int>> ans;
    vector<int> vec;
    recursion(candidates,vec,target,ans,0,0);
    return ans;
}


// Q Subset Sum
// TC O(2^N)
// SC O(2^N)
void recursion(vector<int> arr,int i,int sum,vector<int> &ans){
    if(i == arr.size()){
        ans.push_back(sum);
        return;
    }
    recursion(arr,i+1,sum,ans);
    sum += arr[i];
    recursion(arr,i+1,sum,ans);
    
}
vector<int> subsetSums(vector<int>& arr) {
    vector<int> ans;
    recursion(arr,0,0,ans);
    return ans;
    }


// Q Subset Sum 2

// Method 1
// TC O(2^N*LOG(2^N))   log(N) for putting elements in stack
// 
void recursion(vector<int> nums,int i,vector<int> vec,set<vector<int>>& ans){
    if(i <= nums.size()){
        ans.insert(vec);
        if(i==nums.size())
        return;
    }
    recursion(nums,i+1,vec,ans);
        vec.push_back(nums[i]);
        recursion(nums,i+1,vec,ans);
    
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    set<vector<int>> ans;
    vector<vector<int>> fans;
    vector<int> vec;
    recursion(nums,0,vec,ans);
    fans.assign(ans.begin(),ans.end());
    return fans;
}


// Method 2
// TC O(2^N * K)    2^N total subsets generated , N for creating and adding subset to the vec<vec>
// SC O(2^N * K) + O(N) auxilliary space of recursion ,   K is the average length of each subset
void recursion(vector<int> nums,int i,vector<int> vec,vector<vector<int>>& ans){
    ans.push_back(vec);

    for(int j = i;j < nums.size();j++){
        if(j > i && nums[j-1] == nums[j]){
            continue;
        } 
        vec.push_back(nums[j]);
        recursion(nums,j+1,vec,ans);
        vec.pop_back();    // to remove the element pushed earlier in the same loop.
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    vector<int> vec;
    recursion(nums,0,vec,ans);
    return ans;
}


// Q Combination sum 3
// TC O(2^N * K)
// SC O(2^N * K) + O(N)    K is the average length of each subset
void recursion(int k, int n,vector<vector<int>>& ans,vector<int> vec,int i){
    if(n < 0){
        return;
    }
    if(k == 0 && n == 0){
        ans.push_back(vec);
        return;
    }
    for(int j = i;j < 10;j++){
        vec.push_back(j);
        recursion(k-1,n-j,ans,vec,j+1);
        vec.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> vec;
    recursion(k,n,ans,vec,1);
    return ans;
}

// Palindrome Partitioning
void recursion(string s,vector<string> vec,vector<vector<string>>& ans,int i){
    if(i == s.size()){
        ans.push_back(vec);
        return;
    }
    for(int j = i;j < s.size();j++){
        string sub = s.substr(i,j-i+1);
        string rev = sub ;
        reverse(rev.begin(), rev.end());
        if(rev == sub){
            vec.push_back(sub);
            recursion(s,vec,ans,j+1);
            vec.pop_back();
        }
    }

}
vector<vector<string>> partition(string s) {
    vector<string> vec;
    vector<vector<string>> ans; 
    recursion(s,vec,ans,0);
    return ans;
}


// Q Word Search
// TC O(4^K * N * M)  N*M possible starting points and K is avg length of the work or depth of recursion
// SC O(M*N)
bool recursion(vector<vector<char>>& board, string& word, int row, int col,int words, vector<vector<bool>>& rep) {
    if (words == word.size())
        return true;
    if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size())
        return false;
    if (rep[row][col] == true)
        return false;
    if(word[words] != board[row][col])
    return false;

    rep[row][col] = true;
    bool found = recursion(board, word, row + 1, col, words+1, rep) ||
                    recursion(board, word, row, col + 1, words+1, rep) ||
                    recursion(board, word, row - 1, col, words+1, rep) ||
                    recursion(board, word, row, col - 1, words+1, rep);
    rep[row][col] = false;
    return found;
}
bool exist(vector<vector<char>>& board, string word) {
    int words = 0;
    int row = 0;int col = 0;
    vector<vector<bool>> rep(board.size(),vector<bool>(board[0].size(),false));
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == word[words]) {
                if(recursion(board, word, i, j, words, rep)) return true;
            }
        }
    }
    return false;
}


// Q N Queens
// TC O()
    void recursion(int n,vector<vector<string>> &ans,vector<string>& vec,int col,vector<int>& upperdiag,vector<int>& lowerdiag,vector<int>& left){
        if(col == n){
            ans.push_back(vec);
            return;
        }

        for(int row = 0;row < n;row++){
            if(left[row] == 0 && lowerdiag[row+col] == 0 && upperdiag[n - 1 + col - row] == 0){
                
                left[row] = 1;
                lowerdiag[row+col] = 1;
                upperdiag[n - 1 + col - row] = 1;
                vec[row][col] = 'Q';
                recursion(n,ans,vec,col+1,upperdiag,lowerdiag,left);
                left[row] = 0;
                lowerdiag[row+col] = 0;
                upperdiag[n - 1 + col - row] = 0;
                vec[row][col] ='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n,'.');
        vector<string> vec(n,s);
        vector<int> upperdiag(2*n-1);
        vector<int> lowerdiag(2*n-1);
        vector<int> left(n);
        recursion(n,ans,vec,0,upperdiag,lowerdiag,left);
        return ans;
    }


// Q Rat in a Maze
// TC O(4^(N*N))
// SC O(N*N)
void recursion(vector<vector<int>> & maze, vector<string> &ans,vector<vector<bool>> &visited, string s,int row,int col){
        int n = maze.size();
        if(row == n-1 && col == n-1){
            ans.push_back(s);
            return ;
        }
        if(row > n-1 || row < 0 || col < 0 || col > n-1){
            return ;
        }
        if(maze[row][col] == 0 || visited[row][col] == true){
            return ;
        }
    
        visited[row][col] = true;
        recursion(maze, ans, visited, s+"D", row+1, col);
        recursion(maze, ans, visited, s+"L", row, col-1);
        recursion(maze, ans, visited, s+"R", row, col+1);
        recursion(maze, ans, visited, s+"U", row-1, col);

        
        visited[row][col] = false;
        

    }
vector<string> ratInMaze(vector<vector<int>>& maze) {
    int n = maze.size();
    vector<string> ans;
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    recursion(maze,ans,visited,"",0,0);
    return ans;
}




int main(){


    return 0;
} 


