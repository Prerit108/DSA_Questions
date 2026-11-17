#include <bits/stdc++.h>
#include <iostream>
using namespace std;


// BFS traversal
// SC O(3N) = O(N)
//  TC O(N + 2*Edges) 
vector<int> bfs(vector<vector<int>> &adj) {
    int n = adj.size();
    int vis[n] = {0};
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    vector<int> bfs;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        
        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}


// DFS traversal
// TC O(N + 2*E)
// SC O(3*N) = O(N)
void dfs(vector<vector<int>>& adj,vector<int>& ans,int vis[],int node){
        vis[node] = 1;
        ans.push_back(node);
        
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(adj,ans,vis,it);
            }
        }
}
vector<int> DFS(vector<vector<int>>& adj) {
    int n = adj.size();
    int start = 0;
    vector<int> ans;
    int vis[n] = {0};
    dfs(adj,ans,vis,start);
    return ans;
}


// Number of Provinces
// TC O(N + 2*EDGES) 
// SC O(N + N) recursion stack space and vis array

void DFS(vector<int> adj[],vector<int> &vis,int node){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            DFS(adj,vis,it);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<int> adj[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (isConnected[i][j] == 1 && i != j) {
                adj[i].push_back(j);
                adj[j].push_back(i);

            }
        }
    }
    vector<int> vis(n,0);
    int cnt = 0;
    for(int i = 0;i<n;i++){
        if(vis[i] == 0){
            cout << i << endl;
            DFS(adj,vis,i);
            cnt++;
        }
    }
    return cnt;  
}


// Rotting Oranges
// TC O(N*M + 4*N*M)
// SC O(N*M)
int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0));

    // {{row,col},time}
    queue <pair<pair<int,int>,int>> q;

    for(int i = 0 ;i < n;i++){
        for(int j = 0 ;j < m;j++){
            if(grid[i][j] == 2){
                vis[i][j] = 2;
                q.push({{i,j},0});
            }
        }
    }

    int mtime = 0;
    int rows[] = {1,-1,0,0};
    int cols[] = {0,0,1,-1};

    while(!q.empty()){
        auto ele = q.front();
        int i = ele.first.first;
        int j = ele.first.second;
        int time = ele.second;
        mtime = max(mtime,time);
        q.pop();

        for(int k = 0 ;k < 4;k++){
            int nrow = i + rows[k];
            int ncol = j + cols[k];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&  vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1 ){
                vis[nrow][ncol] = 2;
                q.push({{nrow,ncol},time + 1});
            }
        }
    }

    for(int i = 0 ;i < n;i++){
        for(int j = 0 ;j < m;j++){
            if(vis[i][j] != 2 && grid[i][j] == 1){
                return -1;
            }
        }
    }
    return mtime;

}


// Flood Fill
// TC O(N*M + 4*M*N)
// SC O(N*M)
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int n = image.size();
    int m = image[0].size();
    vector<vector<int>> vis(n,vector<int>(m,-1));
    queue<pair<int,int>> q;
    q.push({sr,sc});
    vis[sr][sc] = color;
    int rcolor = image[sr][sc];  // color to replace
    
    while(!q.empty()){
        auto ind = q.front();
        q.pop();
        int i = ind.first;
        int j = ind.second;

        int rows[] = {1,-1,0,0};
        int cols[] = {0,0,1,-1};    

        for(int k = 0 ;k < 4;k++){
            int nrow = i + rows[k];
            int ncol = j + cols[k];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m  && image[nrow][ncol] == rcolor &&  vis[nrow][ncol] != color){
                vis[nrow][ncol] = color;
                q.push({nrow,ncol});
            }
        }
    }
    for(int i = 0 ;i < n;i++){
        for(int j = 0 ;j < m;j++){
            if(vis[i][j] != color){
                // cout << vis[i][j] <<  " " ;
                vis[i][j] = image[i][j];
            }
        }
    }
    return vis;
}


// Detecting Cycels in a undirected graph (BFS)
// TC O(N + 2*Edges + N)
// SC O(N)
bool detect(vector<int> adj[],vector<int> &vis,int src){
    // {curr node,parent}
    queue <pair<int,int>> q;
    
    q.push({src,-1});
    vis[src] = 1;
    while(!q.empty()){
        auto ele = q.front();
        q.pop();
        for(auto it : adj[ele.first]){
            if(!vis[it]){
                q.push({it,ele.first});
                vis[it] = 1;
            }
            else if(ele.second != it){   // if the node is visited but it is not it's parent , it means there is a cycle
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<vector<int>>& edges) {
    vector<int> adj[V];
    for(int i = 0;i < edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> vis(V,0);
    
    for(int i = 0;i < V;i++){
        if(!vis[i]){
            if (detect(adj,vis,i)) return true;
        }
    }
    
    return false;
    
}


// Detecting Cycels in a undirected graph (DFS)
// TC O(N + 2*Edges + N)
// SC O(N)
bool detect(vector<int> adj[],vector<int> &vis,int src,int parent){   // return true if cycle detected
    // {curr node}
    vis[src] = 1;
    bool cycle = false;
    for(auto it : adj[src]){
        if(!vis[it]){
            cycle = detect(adj,vis,it,src);
        }
        else if(it != parent) {        // if the node is visited but it is not it's parent , it means there is a cycle     
            cycle = true;      
            return cycle;
        }
    }
    return cycle;
}

bool isCycle(int V, vector<vector<int>>& edges) {
    vector<int> adj[V];
    for(int i = 0;i < edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> vis(V,0);
    
    for(int i = 0;i < V;i++){
        if(!vis[i]){
            if (detect(adj,vis,i,-1)) return true;
        }
    }
    
    return false;
    
}


// 01 Matrix
// SC O(N*M)
// TC O(N*M*4)

// Start by taking all 0s in the queue and then apply the bfs.
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> vis(n,vector<int>(m,0)) ;
    vector<vector<int>> ans(n,vector<int>(m,0)) ;

    // {{row,col},dist}
    queue<pair<pair<int,int>,int>> q;

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(mat[i][j] == 0){
                q.push({{i,j},0});
                vis[i][j] = 1;
            }
        }
    }

    while(!q.empty()){
        auto ele = q.front();
        q.pop();
        int x = ele.first.first;
        int y = ele.first.second;
        int dis = ele.second;

        int rows[] = {1,-1,0,0};
        int cols[] = {0,0,1,-1};    

        for(int k = 0 ;k < 4;k++){
            int nrow = x + rows[k];
            int ncol = y + cols[k];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0){   
                q.push({{nrow,ncol},dis + 1});
                vis[nrow][ncol] = 1;
                ans[nrow][ncol] = dis+1;
                
            }
        }
    }
    return ans;
}


// Surrounded Regions
// SC O(N*M*4)
// TC O(N*M*4 )

// Do a boundary reaversal of the matrix and store all 'O' in the queue.
// Then do BFS traversal on all those O's one by one and marked them 'O' in visited array.
// Return the visited array, as all O's not connected woth the edge elements will be X.
void solve(vector<vector<char>>& board) {
    int n = board.size();
    int m = board[0].size();

    vector<vector<char>> vis(n,vector<char>(m,'X'));
    queue<pair<int,int>> q;

    for(int i = 0;i < n;i++){
        if(board[i][0] == 'O'){
            vis[i][0] = 'O';
            q.push({i,0});
        }
        if(board[i][m-1] == 'O'){
            vis[i][m-1] = 'O';
            q.push({i,m-1});
        }        
    }
    for(int j = 0;j < m;j++){
        if(board[0][j] == 'O'){
            vis[0][j] = 'O';
            q.push({0,j});
        }
        if(board[n-1][j] == 'O'){
            vis[n-1][j] = 'O';
            q.push({n-1,j});
        }
    }

    while(!q.empty()){
        auto ele = q.front();
        int x = ele.first;
        int y = ele.second;
        q.pop();
        int rows[] = {0,0,1,-1};
        int cols[] = {1,-1,0,0};

        for(int i = 0;i<4;i++){
            int drow = x + rows[i];
            int dcol = y + cols[i];
            if(drow >=0 && drow < n && dcol >= 0 && dcol < m && vis[drow][dcol] == 'X' && board[drow][dcol] == 'O'){
                    q.push({drow,dcol});
                    vis[drow][dcol] = 'O';
                
            }

        }
        
    }
    board = vis;
}


// Number of Enclaves
// SC O(N*M)
// TC O(N*M*4)
int numEnclaves(vector<vector<int>>& board) {
    int n = board.size();
    int m = board[0].size();
    int cnt = 0;

    vector<vector<int>> vis(n,vector<int>(m,0));
    queue<pair<int,int>> q;


    for(int i = 0;i < n;i++){
        if(board[i][0] == 1){
            vis[i][0] = 1;
            q.push({i,0});
        }
        if(board[i][m-1] == 1){
            vis[i][m-1] = 1;
            q.push({i,m-1});
        }        
    }
    for(int j = 0;j < m;j++){
        if(board[0][j] == 1){
            vis[0][j] = 1;
            q.push({0,j});
        }
        if(board[n-1][j] == 1){
            vis[n-1][j] = 1;
            q.push({n-1,j});
        }
    }

    while(!q.empty()){
        auto ele = q.front();
        int x = ele.first;
        int y = ele.second;
        q.pop();
        int rows[] = {0,0,1,-1};
        int cols[] = {1,-1,0,0};

        for(int i = 0;i<4;i++){
            int drow = x + rows[i];
            int dcol = y + cols[i];
            if(drow >=0 && drow < n && dcol >= 0 && dcol < m && vis[drow][dcol] == 0 && board[drow][dcol] == 1){
                q.push({drow,dcol});
                vis[drow][dcol] = 1;
                    
            }

        }
        
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(vis[i][j] == 0 && board[i][j] == 1)
                cnt++;
        }
    }
    return cnt;

}


// Number of Islands
// SC O(N*M)
// TC O(N*M*4)

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<char>> vis(n,vector<char>(m,'0'));
    queue<pair<int,int>> q;
    int ans = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(grid[i][j] == '1' && vis[i][j] == '0'){
                q.push({i,j});
                vis[i][j] = '1';
                ans++;
                while(!q.empty()){
                    auto ele = q.front();
                    int x = ele.first;
                    int y = ele.second;
                    q.pop();
                    int rows[] = {0,0,1,-1};
                    int cols[] = {1,-1,0,0};

                    for(int i = 0;i < 4;i++){
                        int drow = x + rows[i];
                        int dcol = y + cols[i];
                        if(drow >= 0 && drow < n && dcol >= 0 && dcol < m && vis[drow][dcol] == '0' && grid[drow][dcol] == '1'){
                            vis[drow][dcol] = '1';
                            q.push({drow, dcol});
                        }
                    }
                }
            }
        }
    }

    return ans;
}


// Bipartite Graph
bool dfs(vector<vector<int>>& graph,vector<int> &vis,int start,int color){
    vis[start] = color;
    for(auto it : graph[start]){
        if(vis[it] == -1){
            if(dfs(graph,vis,it,(color == 0 ? 1 : 0)) == false){
                return false;
            }
        }
        else if(vis[it] == color){
            return false;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    int nodes = graph.size();
    vector<int> vis(nodes,-1);
    bool ans = true;
    for(int i = 0;i < nodes;i++){
        if(vis[i] == -1){
            ans = dfs(graph,vis,i,0) && ans;
        }
    }
    return ans;
}


// Topological Sort (DFS)
// TC O(V + E)
// SC O(N)
void dfs(vector<vector<int>>& adj,vector<int> & vis,stack<int> &s,int node){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(adj,vis,s,it);
        }
    }
    s.push(node);
    return;
}

vector<int> topoSort(int V, vector<vector<int>>& edges) {
    vector<int> vis(V,0);
    stack<int> s;
    vector<vector<int>> adj(V);
    
    for(auto e : edges){
        adj[e[0]].push_back(e[1]);
    }
    
    for(int i = 0;i < V;i++){
        if(vis[i] == 0){
            dfs(adj,vis,s,i);
        }
    }
    
    vector<int> ans;
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    
    return ans;
}



// Kahn's Algorithm (BFS)
// SC O(N)
// TC O(V + E)
vector<int> topoSort(int V, vector<vector<int>>& edges) {
    vector<int> vis(V,0);
    queue<int> q;
    vector<vector<int>> adj(V);
    vector<int> indegree(V,0);
    
    for(auto e : edges){
        adj[e[0]].push_back(e[1]);
        indegree[e[1]]++;
    }
    
    for(int i = 0;i < V;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    
    vector<int> ans;
    while(!q.empty()){
        auto ele = q.front();
        q.pop();
        ans.push_back(ele);
        for(auto it : adj[ele]){
            indegree[it]--;
            if(indegree[it] == 0)
                q.push(it);
            
        }
    }
    return ans;
}


// Directed Graph Cycle (DFS)
// SC O(N)
// TC O(V + E)
bool dfs( vector<vector<int>> &adj, vector<int>& vis,vector<int>& path_vis,int node){
    vis[node] = 1;
    path_vis[node] = 1;
    
    for(auto ele : adj[node]){
        if(!vis[ele]){
            if(dfs(adj,vis,path_vis,ele) == true)
                return true;
            
        }
        else if(path_vis[ele] == 1){
            return true;
        }
    }
    path_vis[node] = 0;
    return false;
    
}

bool isCyclic(int V, vector<vector<int>> &edges) {
    vector<int> vis(V,0);
    vector<int> path_vis(V,0);
    vector<vector<int>> adj(V); 
    

    for(auto e : edges){
        adj[e[0]].push_back(e[1]);
    }
    
    for(int i = 0;i < V;i++){
        if(!vis[i]){
            if(dfs(adj,vis,path_vis,i) == true)
                return true;
        }
    }
    
    return false;
    
}


// Directed Graph Cycle (BFS)
// Apply Topo sort on the graph if the whole graph gets covered by the sort then it has no cycle else it has cycle.
// SC O(N)
// TC O(V + E)
bool isCyclic(int V, vector<vector<int>> &edges) {
    vector<int> vis(V,0);
    queue<int> q;
    vector<vector<int>> adj(V);
    vector<int> indegree(V,0);

    for(auto e : edges){
        adj[e[0]].push_back(e[1]);
        indegree[e[1]]++;
    }

    for(int i = 0;i < V;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    vector<int> ans;
    while(!q.empty()){
        auto ele = q.front();
        q.pop();
        ans.push_back(ele);
        for(auto it : adj[ele]){
            indegree[it]--;
            if(indegree[it] == 0)
                q.push(it);

        }
    }
    
    if(ans.size() == V) return false;
    return true;

}


// Course Schedule
// SC O(N)
// TC O(V + E)
bool dfs(vector<vector<int>>& adj, vector<int>& vis, vector<int>& path_vis,int node) {
    vis[node] = 1;
    path_vis[node] = 1;

    for (auto ele : adj[node]) {
        if (!vis[ele]) {
            if (dfs(adj, vis, path_vis, ele) == true)
                return true;

        } else if (path_vis[ele] == 1) {
            return true;
        }
    }
    path_vis[node] = 0;
    return false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> vis(numCourses, 0);
    vector<int> path_vis(numCourses, 0);
    vector<vector<int>> adj(numCourses);

    for (auto e : prerequisites) {
        adj[e[0]].push_back(e[1]);
    }

    for (int i = 0; i < numCourses; i++) {
        if (!vis[i]) {
            if (dfs(adj, vis, path_vis, i) == true)
                return false;
        }
    }

    return true;
}


// Course Schedule II
// Apply Kahn's algo with cycle check
// SC O(N)
// TC O(V + E)
vector<int> findOrder(int V, vector<vector<int>>& edges) {
    vector<int> vis(V,0);
    queue<int> q;
    vector<vector<int>> adj(V);
    vector<int> indegree(V,0);
    
    for(auto e : edges){
        adj[e[1]].push_back(e[0]);
        indegree[e[0]]++;
    }
    
    for(int i = 0;i < V;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    
    vector<int> ans;
    while(!q.empty()){
        auto ele = q.front();
        q.pop();
        ans.push_back(ele);
        for(auto it : adj[ele]){
            indegree[it]--;
            if(indegree[it] == 0)
                q.push(it);
            
        }
    }

    if(ans.size() != V){
        return {};
    }
    cout << ans.size();
    return ans;
}


// Find Eventual Safe States (DFS cycle detection)
// SC O(N)
// TC O(E + V)
// If there is a cycle then all possible paths do not lead to the terminal nodes therefore not a safe node
bool safe(vector<vector<int>>& graph,vector<int> &terminal,vector<int>&vis,vector<int> & pathvis,int node){
    vis[node] = 1;
    pathvis[node] = 1;
    for(auto it : graph[node]){
        if(!vis[it]){
            if(safe(graph,terminal,vis,pathvis,it) == false)  return false;
        }
        else if(pathvis[it] == 1){
            return false;
        }
    }
    pathvis[node] = 0;
    terminal[node] = 1;
    return true;
}
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<int> terminal(V,0);
    vector<int> vis(V,0);
    vector<int> pathvis(V,0);

    for(int i = 0;i < V;i++){
        safe(graph,terminal,vis,pathvis,i);
    }

    vector<int> ans;
    for(int i = 0;i < V;i++){
        if(terminal[i]) ans.push_back(i);
    }

    return ans;
}

// BFS 
// TC O(N log N)
// SC O(N)

// Reverse all the graph connections and apply TOPO sort on it.
// Elements appearing in the Linear ordering will be the safe nodes.
// Nodes not appearing in the topo sort will be the ones with cycle there not safe nodes.
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int V = graph.size();
    queue<int> q;
    vector<int> vis(V,0);
    vector<int> indegree(V,0); 
    vector<vector<int>> graphrev(V);

    for(int i = 0;i < V; i ++){
        for(auto j : graph[i]){
            graphrev[j].push_back(i);
            indegree[i]++;

        }
    }
    vector<int> safe;
    for(int i = 0;i < V; i ++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int ele = q.front();
        q.pop();
        safe.push_back(ele);
        for(auto it : graphrev[ele]){
            indegree[it]--;
            if(indegree[it] == 0)   q.push(it);
        }
    }

    sort(safe.begin(),safe.end());

    return safe;
}

// Alien Dictionary
// TC O(V + E +  L) L = total number of characters across all words
// SC O(L)
bool dfs(vector<vector<int>> &graph,vector<int> &vis,stack<int> &s,int node){
    vis[node] = 1;
    for(auto nxt : graph[node]){
        if(vis[nxt] == 1)
            return true;     // cycle detected means ordering is wrong in the question
        if(vis[nxt] == 0){
            if(dfs(graph,vis,s,nxt))
                return true;
        }
    }
    vis[node] = 2;
    s.push(node);
    return false;
}

string findOrder(vector<string> &words) {
    int n = words.size();
    vector<vector<int>> graph(26);
    vector<int> vis(26,-1);
    for(auto &word : words){
        for(char ch : word){
            vis[ch-'a'] = 0;   // mark character as present
        }
    }
    for(int i = 0;i < n-1;i++){
        int mini_str = min(words[i].size(),words[i+1].size());
        bool found = false;                   // found a relation
        for(int j = 0;j < mini_str;j++){
            if(words[i][j] != words[i+1][j]){
                graph[words[i][j] - 97].push_back(words[i+1][j] - 97);
                found = true;
                break;
            }
        }
        
        if(found == false && words[i].size() > words[i+1].size()){   // no relation found and first string is greater than second then order is wrong
            return "";
        }
    }

    // topo sort
    stack<int> s;
    for(int i = 0;i < 26;i++){
        if(vis[i] == 0){
            if(dfs(graph,vis,s,i) == true){
                return "";
            }
        }
    }
    
    string ans;
    while(!s.empty()){
        auto it = s.top();
        s.pop();
        ans = ans + char(it + 'a');

    }
    // cout << ans << endl;
    return ans;
}


// Shortest Path in Directed Acyclic Graph
// TC O(V + E)
// SC O(N)

// my code
// topo sort
void dfs(vector<vector<pair<int,int>>>& adj,vector<int> & vis,stack<int> &s,int node){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it.first]){
            dfs(adj,vis,s,it.first);
        }
    }
    s.push(node);
    return;
}
vector<int> shortestPath(int V, vector<vector<int>>& edges) {
    vector<vector<pair<int,int>>> adj(V);
    for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
    }
    
    vector<int> vis(V,0);
    stack<int> s;
    
    for(int i = 0;i < V;i++){
        if(vis[i] == 0){
            dfs(adj,vis,s,i);
        }
    }
    vector<int> ans(V,INT_MAX);
    int src = 0;
    int src_found = 0;

    while(!s.empty()){
        int ele = s.top();
        s.pop();
        if(ele == src){
            ans[src] = 0;
            src_found = 1;
        }
        // skip all elements until the source/starting element is found 
        if(src_found == 1){
            for(int i = 0;i < adj[ele].size();i++){
                ans[adj[ele][i].first] = min(ans[adj[ele][i].first],ans[ele] + adj[ele][i].second);
            }
        }
    }
    for(int i = 0;i < V;i++){
        if(ans[i] == INT_MAX){
            ans[i] = -1;
        }
    }
    return ans;
}

// Striver's code
void dfs(vector<vector<pair<int,int>>>& adj,vector<int> & vis,stack<int> &s,int node){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it.first]){
            dfs(adj,vis,s,it.first);
        }
    }
    s.push(node);
    return;
}
vector<int> shortestPath(int V, vector<vector<int>>& edges) {
    vector<vector<pair<int,int>>> adj(V);
    for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
    }
    
    vector<int> vis(V,0);
    stack<int> s;
    
    for(int i = 0;i < V;i++){
        if(vis[i] == 0){
            dfs(adj,vis,s,i);
        }
    }
    vector<int> ans(V,INT_MAX);
    ans[0] = 0;
    while(!s.empty()){
        int ele = s.top();
        s.pop();
        if (ans[ele] != INT_MAX) {
            for(auto it : adj[ele]){
                int w = it.second;   // weight
                int v = it.first;    // value
                if(ans[ele] + w < ans[v]){
                    ans[v] = ans[ele] + w;
                }
            }
        }
    }
    for(int i = 0;i < V;i++){
        if(ans[i] == INT_MAX){
            ans[i] = -1;
        }
    }
    return ans;
}


// Shortest Path in Undirected Graph with Unit Weights
// TC O(V + 2E)
// SC O(N)
int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
    vector<vector<int>> adj(V);
    for(auto it : edges){
        adj[it[0]].push_back(it[1]); 
        adj[it[1]].push_back(it[0]);
    }
    
    queue<pair<int,int>> q;
    vector<int> ans(V,INT_MAX);
    ans[src] = 0;

    q.push({src,0});
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        int ele = node.first;
        int dis = node.second;
        
        
        for(auto it : adj[ele]){

            if(ans[it] > ans[ele]  + 1){
                q.push({it,dis + 1});
                ans[it] = ans[ele] + 1;
            }
            if(it == dest){
                return ans[it];
            }
        }
        
    }
    return -1;

}

// Word Ladder
// TC O(Wordlength * 26 * number of words)
// SC O(N)

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    queue<pair<string,int>> q; 
    unordered_set<string> s(wordList.begin(),wordList.end());
    q.push({beginWord,0});
    s.erase(beginWord);

    while(!q.empty()){
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        if(word == endWord){
            return steps + 1;
        }
        for(int i = 0;i < word.size();i++){
            char original = word[i];
            for(char ch = 'a';ch  <= 'z';ch++){
                word[i] = ch;
                if(s.find(word)  != s.end()){
                    s.erase(word);
                    q.push({word,steps + 1});
                }
            }
            word[i] = original;

        }
    }
    return 0;
}    



// Dijkstra's Algorithm - Using Priority Queue 
// TC O(E*log(V))
// SC O(N)
vector<int> dijkstra(vector<vector<vector<int>>> &adj, int src) {
    int V = adj.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;   //{distance,vertex}
    vector<int> dis(V,INT_MAX);
    q.push({0,src});
    dis[src] = 0;
    
    while(!q.empty()){
        auto node = q.top();
        int dist = node.first;
        int ver = node.second;
        q.pop();
        
        for(auto it : adj[ver]){
            int next_node = it[0];
            if(dis[next_node] > it[1] + dist){
                dis[next_node] = it[1] + dist;
                q.push({dis[next_node],next_node});
            }
        }
    }
    
    return dis;
}

// Dijkstra's Algorithm - Using Set
// TC O(E*log(V))
// SC O(N)
vector<int> dijkstra(vector<vector<vector<int>>> &adj, int src) {
    int V = adj.size();
    set<pair<int,int>> st;
    vector<int> dis(V,INT_MAX);
    
    st.insert({0,src});
    dis[src] = 0;
    
    while(!st.empty()){
        auto node = *(st.begin());
        int dist = node.first;
        int ver = node.second;
        st.erase(node);
        
        for(auto it : adj[ver]){
            int next_node = it[0];
            if(dis[next_node] > it[1] + dist){
                // erase if it existed 
                // if the next node has been visited but with a greater distance then remove it from the set.
                if(dis[next_node] != INT_MAX)
                    st.erase({dis[next_node],next_node});
                
                dis[next_node] = it[1] + dist;
                st.insert({dis[next_node],next_node});
            }
        }
    }
    
    return dis;
}


// Print Shortest Path 
// TC O(Elog(V))
// SC O(2*Edges)
vector<int> shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
    vector<vector<pair<int,int>>> adj(V + 1);
    for(auto it : edges){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;        vector<int> dis(V+1,INT_MAX);
    vector<int> ans;
    
    q.push({0,src});
    dis[src] = 0;
    vector<int> prev(V+1);
    for(int i = 0;i < V+1;i++){
        prev[i] = i;
    }

    while(!q.empty()){
        auto node = q.top();
        int dist = node.first;
        int ver = node.second;
        q.pop();
        
        
        for(auto it : adj[ver]){
            int next_node = it.first;
            if(dis[next_node] > it.second + dist){
                dis[next_node] = it.second + dist;
                q.push({dis[next_node],next_node});
                prev[next_node] = ver; 
            }
        }
    }
    if(dis[dest] == INT_MAX)    return {-1};
    int i = dest;
    while(i != src){
        ans.push_back(i);
        i = prev[i];
    }
    ans.push_back(src);
    reverse(ans.begin(),ans.end());
    return ans;
}

// Shortest Path in Binary Matrix
// TC O()
// using BFS
// Can use A simple queue instead of a Priority queue since distance between all the nodes are same(1).
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<int,pair<int,int>>> q;

        if (grid[0][0] != 0)
            return -1;
        q.push({1, {0, 0}});
        
        if(m == 1 && n == 1)  return 1;
        vis[0][0] = 1;

        while (!q.empty()) {
            int x = q.front().second.first;
            int y = q.front().second.second;
            int dis = q.front().first; // distance
            q.pop();

            int rows[] = {1, -1, 1, -1, 0,  0, 1,-1};
            int cols[] = {1, -1, 0,  0, 1, -1,-1, 1};
            for (int i = 0; i < 8; i++) {
                int drow = rows[i];
                int dcol = cols[i];
                if (x + drow < n && y + dcol < m && x + drow >= 0 &&
                    y + dcol >= 0 && grid[drow + x][y + dcol] == 0 && vis[x + drow][y + dcol] == 0) {
                    if (x + drow == n - 1 && y + dcol == m - 1) {
                        return dis + 1;
                    }
                    q.push({dis + 1, {x + drow,y + dcol}});
                    vis[x + drow][y + dcol] = 1;
                }
            }
        }
        return -1;
    }


// Using Dijkstra 
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

    queue<pair<int,pair<int,int>>> q;

    if (grid[0][0] != 0)
        return -1;
    q.push({1, {0, 0}});
    
    if(m == 1 && n == 1)  return 1;
    dist[0][0] = 0;

    while (!q.empty()) {
        int x = q.front().second.first;
        int y = q.front().second.second;
        int dis = q.front().first; // distance
        q.pop();

        int rows[] = {1, -1, 1, -1, 0,  0, 1,-1};
        int cols[] = {1, -1, 0,  0, 1, -1,-1, 1};
        for (int i = 0; i < 8; i++) {
            int drow = rows[i];
            int dcol = cols[i];
            if (x + drow < n && y + dcol < m && x + drow >= 0 &&
                y + dcol >= 0 && grid[drow + x][y + dcol] == 0 && 1 + dis < dist[drow + x][y + dcol]) {
                if (x + drow == n - 1 && y + dcol == m - 1) {
                    return dis + 1;
                }
                q.push({dis + 1, {x + drow,y + dcol}});
                dist[x + drow][y + dcol]  = dis + 1;
            }
        }
    }
    return -1;
}


// Path With Minimum Effort
// TC O(E log V) - (n*m *4 * log(n*m))
// SC O(n*m)

int minimumEffortPath(vector<vector<int>>& heights) {
        // Define the pair structure: pair<int, pair<int, int>>  
        using Element = pair<int, pair<int, int>>;         
        // Create a clean min-heap priority queue 
        priority_queue<Element,vector<Element>, greater<Element>> pq;

        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n,(vector<int>(m,INT_MAX)));

        pq.push({0,{0,0}});
        if(n == 1 && m == 1)    return 0;
        dist[0][0] = heights[0][0];


        while(!pq.empty()){
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            int gaps = pq.top().first;
            pq.pop();

            if(x == n-1 && y == m-1 ){
                return gaps;
            }

            int rows[] = {1,-1,0,0};
            int cols[] = {0,0,-1,1};

            for(int i = 0;i < 4; i++){
                int nrow = rows[i] + x;
                int ncol = cols[i] + y;
                if(nrow < n && ncol < m && nrow >= 0 && ncol >= 0){
                    int diff = max(abs(heights[nrow][ncol] - heights[x][y]),gaps);
                    if(dist[nrow][ncol] > diff){
                        dist[nrow][ncol] = diff;
                        pq.push({diff,{nrow,ncol}});
                    }
                }
            }
        }
        return 0;
    }


// Cheapest Flights Within K Stops
// create the queue based on the stops no the distance.
// TC O(E) E = number of flighs
// SC O(N)
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int,int>>> adj(n);
    for(int i = 0;i < flights.size();i++){
        adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
    }

    // {stops ,{next node , distance}}
    queue<pair<int, pair<int, int>>> pq;         

    vector<int> dist(n,INT_MAX);

    pq.push({0,{src,0}});
    dist[src] = 0;

    while(!pq.empty()){
        int stop = pq.front().first;    // stops taken
        int next = pq.front().second.first; 
        int dis = pq.front().second.second;    
        pq.pop();
        for(auto it : adj[next]){
            if(dist[it.first] > dis + it.second && stop <= k){
                dist[it.first] = dis + it.second;
                pq.push({stop + 1,{it.first,dist[it.first]}});
            }
        } 
    }

    return (dist[dst] == INT_MAX)? -1 :  dist[dst];

}


// Minimum Multiplications to Reach End
// TC O(N * M)   M = no.of numbers actually generated

int minSteps(vector<int>& nums, int start, int end) {
    int n = nums.size();
    
    vector<int> arr;
    for(int i = 0;i<n;i++){
        if(end%2 == 1 && nums[i]%2 == 0){
            continue;
        }
        arr.push_back(nums[i]);
    }
    n = arr.size();
    if(n == 0)  return -1;
    vector<int> dist(1000,INT_MAX);
    // {steps,number}
    queue<pair<int, int>> q;       
    q.push({0,start});
    dist[start] = 0;
    
    while(!q.empty()){
        int num = q.front().second;
        int step = q.front().first;
        q.pop();
        
        if(num == end){
            return step;
        }   
        for(int i = 0; i < n;i++){
            int next_num = (num * arr[i])%1000;
            if(dist[next_num] > step + 1){
                dist[next_num] = step + 1;
                q.push({step + 1,next_num});
            }
        }
    }
    
    return -1;
}


// Number of Ways to Arrive at Destination
// Store the number of ways to reach that node also
// TC O(E log(V))
int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int,int>>> adj(n);
    for(int i = 0;i < roads.size();i++){
        adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
        adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
    }
    // stores {shortest time, distance}
    vector<pair<long long,int>> dist(n, {LLONG_MAX, 0});;
    // {time,node}
    priority_queue<pair<long long, int>,vector<pair<long long, int>>,greater<pair<long long, int>>> pq;
    int mod = 1e9 + 7;
    pq.push({0,0});
    dist[0] = {0,1};
    while(!pq.empty()){
        long long time = pq.top().first;
        long long node = pq.top().second;
        pq.pop();
        
        for(auto it : adj[node]){
            // First time finding the shortest path
            if(dist[it.first].first > time + it.second){
                dist[it.first].first = time + it.second;
                pq.push({dist[it.first].first,it.first});
                dist[it.first].second = dist[node].second;
            }
            // finding shortest path after first time
            else if(dist[it.first].first == time + it.second){
                dist[it.first].second = (dist[it.first].second + dist[node].second) % mod;
            }
            
        }
    }
    return int((dist[n-1].second)%mod);
}


// Bellman Ford
// TC O(E*V)
// SC O(V)
vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    vector<int> dist(V,1e8);
    dist[src] = 0;
    
    for(int i = 0;i < V-1;i++){
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    }
    for(auto it : edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
            return {-1};
        }
    }
    return dist;
}

// Floyd Warshall
// TC O(n^3)
// SC O(n^2)
void floydWarshall(vector<vector<int>> &dist) {
    int n = dist.size();
    
    for(int k = 0;k<n;k++){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if (dist[i][k] == 1e8 || dist[k][j] == 1e8)
                                    continue;
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }    
    }

    // for checking negative cycles 
    // for(int i = 0;i<n;i++){
    //     if(dist[i][i] < 0){
    //         return -1;
    //     }
    // }

    
}


// Find the City With the Smallest Number of Neighbors at a Threshold Distance
// Floyd Warshall
// TC O(V^3)
int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

    vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
    for(auto it : edges){
        dist[it[0]][it[1]] = it[2];
        dist[it[1]][it[0]] = it[2];
    }
    for(int k = 0;k<n;k++){
        dist[k][k] = 0;
    }

    for(int k = 0;k<n;k++){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                    continue;
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }    
    }

    int cnt_max = 1e8;
    int city = 0;
    for(int i = 0;i < n;i++){
        int cnt = 0;
        for(int j = 0;j < n;j++){
            if(dist[i][j] <= distanceThreshold)
                cnt++;
        }
        if(cnt <= cnt_max){
            cnt_max = cnt;
            city = i;
        }
    }
    return city;

}


// Dijkstra method
// TC O(V * Vlog(E))
int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<pair<int,int>>> adj(n);
    for(int i = 0;i < edges.size();i++){
        adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
    }
    vector<vector<int>> matrix(n,vector<int>(n,INT_MAX));
    for(int i = 0;i < n ; i++){

        vector<pair<int,int>> dist(n, {INT_MAX, 0});  // {distane , pathlen}
        // {distance ,node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0,i});
        dist[i] = {0,0};

        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                if(dis + it.second < dist[it.first].first && dist[node].first < distanceThreshold){
                    dist[it.first].first = dis + it.second;
                    dist[it.first].second = dist[node].second + 1;
                    pq.push({dist[it.first].first,it.first});
                    matrix[i][it.first] = dis + it.second;
                }
            }
        }
    }

    int cnt_max = 1e8;
    int city = 0;
    for(int i = 0;i < n;i++){
        int cnt = 0;
        for(int j = 0;j < n;j++){
            if(matrix[i][j] <= distanceThreshold)
                cnt++;
        }
        if(cnt <= cnt_max){
            cnt_max = cnt;
            city = i;
        }
    }
    return city;

}




// Network Delay Time
// TC O(E log(V))
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i = 0;i < times.size();i++){
        adj[times[i][0]].push_back({times[i][1],times[i][2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;   //{distance,vertex}
    vector<int> dist(n+1,INT_MAX);
    pq.push({0,k});
    dist[k] = 0;
    while(!pq.empty()){
        int time = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for(auto it : adj[node]){
            if(it.second + time < dist[it.first]){
                dist[it.first] = time + it.second;
                pq.push({dist[it.first],it.first});
            }
        }
            
    }
    int maxx = 0;
    for(int i = 1;i < n+1;i++){
        maxx = max(maxx,dist[i]);
    }
    if(maxx == INT_MAX) return -1; 
    
    return maxx;
}

// Prims Algo MST
// TC O(E log(E))
// SC O(E)

// Storing parent in PQ is only required when you want the edges of the MST also .
// Parent can be remove from the PQ in this question.
int primMST(vector<vector<vector<int>>> &adj) {
    int n = adj.size();
    // Define the pair structure: pair<int, pair<int, int>>
    using Element = pair<int, pair<int, int>> ;
    // Create a clean min-heap priority queue
    //  {weight,{node,parent}}
    priority_queue<Element, vector<Element>, greater<Element>> pq;
    
    vector<int> vis(n,0);
    pq.push({0,{0,-1}});
    int sum = 0;
    // E
    while(!pq.empty()){

        // Log E
        int node = pq.top().second.first;
        int parent = pq.top().second.second;
        int weight = pq.top().first;
        pq.pop();

        // Adding it to the MST
        if(vis[node] == 0){     
            vis[node] = 1;
            sum += weight;
        }
        else continue;
        // E log E
        for(auto it : adj[node]){
            int next = it[0];
            if(vis[next] == 0){
                pq.push({it[1],{next,node}});
            }
        }
    }
    return sum;	
}





int main(){
    int n, m;
    cin >> n >> m;
    // adjacency matrix for undirected graph
    // time complexity: O(n)
    // SC O(N*N)
    int adj[n+1][n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;  // this statement will be removed in case of directed graph
    }


    // adjacency list for undirected graph
    // time complexity: O(2E)
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    // adjacency list for directed graph
    // time complexity: O(E)
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        // u —> v
        cin >> u >> v;
        adj[u].push_back(v);
    }



    return 0;
}