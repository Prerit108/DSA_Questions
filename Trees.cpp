#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// TRAVERSALS

// PRE ORDER TRAVERSAL
void recursion(TreeNode* root,vector<int>& vec){
    if(root == nullptr){
        return;
    }
    vec.push_back(root->val);
    recursion(root->left,vec);
    recursion(root->right,vec);
}   
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> vec;
    recursion(root,vec);
    return vec;
}
// INORDER TRAVERSAL
void recursion(TreeNode* root,vector<int>& vec){
    if(root == nullptr){
        return;
    }
    recursion(root->left,vec);
    vec.push_back(root->val);
    recursion(root->right,vec);
}   
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> vec;
    recursion(root,vec);
    return vec;
}

// POST ORDER TRAVERSAL

void recursion(TreeNode* root,vector<int>& vec){
        if(root == nullptr){
            return;
        }
        recursion(root->left,vec);
        recursion(root->right,vec);
        vec.push_back(root->val);

    }   
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> vec;
    recursion(root,vec);
    return vec;
}

// LEVEL ORDER TRAVERSAL
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(root == NULL) return ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        vector<int> vec;
        int size = q.size();
        for(int i = 0;i < size;i++){
            TreeNode* node = q.front();
            vec.push_back(node->val);
            if(q.front()->left != NULL) q.push(node->left);
            if(q.front()->right != NULL) q.push(node->right);
            q.pop();
        }
        ans.push_back(vec);
    }
    return ans;
}

// Preorder Traversal Iterative
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> vec;
    stack<TreeNode*> st;
    if(root == NULL) return vec;
    st.push(root);
    while(!st.empty()){
        TreeNode* node = st.top();
        vec.push_back(node->val);
        st.pop();
        if(node->right != NULL)     st.push(node->right);
        if(node->left != NULL)     st.push(node->left);  
    }
    return vec;
}


// Inorder Traversal Iterative
// SC O(N)    (height of the tree)
//  TC O(N)
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> vec;
    stack<TreeNode*> st;
    TreeNode* node = root;
    if(root == NULL) return vec;
    while(true){
        if(node != NULL){
            st.push(node);
            node = node->left;
        }
        else{
            if(st.empty()) break;
            node = st.top();
            st.pop();
            vec.push_back(node->val);
            node = node->right;
        }
    }
    return vec;
}  


// Post order Traversal
// 2 stack
// SC O(2N)
// TC O(N)
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> vec;
    TreeNode* node = root;
    stack<TreeNode*> st1;
    stack<TreeNode*> st2;
    if (node == NULL)
        return vec;
    st1.push(node);
    while (!st1.empty()) {
        node = st1.top();
        st2.push(node);
        st1.pop();
        if (node->left != NULL)
            st1.push(node->left);
        if (node->right != NULL)
            st1.push(node->right);
    }
    while (!st2.empty()) {
        vec.push_back(st2.top()->val);
        st2.pop();
    }
    return vec;
}
     
// Post order Traversal Using 1 stack
// SC O(N)
// TC O(2N)
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> vec;
    TreeNode* curr = root;
    stack<TreeNode *> st;
    while(curr != NULL || !st.empty()){
        if(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }
        else{
            TreeNode* temp = st.top()->right;
            if(temp == NULL){
                temp = st.top();
                st.pop();
                vec.push_back(temp->val);
                while(!st.empty() && temp == st.top() ->right){
                    temp = st.top(),st.pop();
                    vec.push_back(temp->val);
                }
            }
            else curr = temp;
        }
    }
    return vec;
}


// Pre post and IN order traversal in 1 traversal
// TC O(3N)
// SC O(4N)
vector<vector<int>> preInPostTraversal(Node* root) {
        // Vectors to store traversals
        vector<int> pre, in, post;
        // If the tree is empty,
        // return empty traversals
        if (root == NULL) {
            return {};
        }
        // Stack to maintain nodes
        // and their traversal state
        stack<pair<Node*, int>> st;
        // Start with the root node
        // and state 1 (preorder)
        st.push({root, 1});
        while (!st.empty()) {
            auto it = st.top();
            st.pop();
            // this is part of pre
            if (it.second == 1) {
                // Store the node's data
                // in the preorder traversal
                pre.push_back(it.first->data);
                // Move to state 2
                // (inorder) for this node
                it.second = 2;
                // Push the updated state
                // back onto the stack
                st.push(it); 

                // Push left child onto
                // the stack for processing
                if (it.first->left != NULL) {
                    st.push({it.first->left, 1});
                }
            }
            // this is a part of in
            else if (it.second == 2) {
                // Store the node's data
                // in the inorder traversal
                in.push_back(it.first->data);
                // Move to state 3
                // (postorder) for this node
                it.second = 3;
                // Push the updated state
                // back onto the stack
                st.push(it); 
                // Push right child onto
                // the stack for processing
                if (it.first->right != NULL) {
                    st.push({it.first->right, 1});
                }
            }
            // this is part of post
            else {
                // Store the node's data
                // in the postorder traversal
                post.push_back(it.first->data);
            }
        }
        // Returning the traversals
        vector<vector<int>> result;
        result.push_back(pre);
        result.push_back(in);
        result.push_back(post);
        return result;
    }

// Q Maximum Depth of Binary tree
// TC O(N)
// SC O(N) Height of tree

void recursion(TreeNode * root,int& maxd, int d){
    if(root == NULL){
        return ;
    }
    maxd = max(d,maxd);
    recursion(root->left,maxd,d+1);
    recursion(root->right,maxd,d+1);
}
int maxDepth(TreeNode* root) {
    int maxd = 0;
    if(root == NULL)    return 0;
    recursion(root,maxd,1);
    return maxd;
}


int maxDepth(TreeNode* root) {
    if(root == NULL)    return 0;
    
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);

    return 1 + max(l,r);
}


// Q Check for balanced binary tree
// TC O(N)
// SC O(N)
int recursion(TreeNode* root){
    if(root == NULL)    return 0;
    int l = recursion(root->left);
    int r = recursion(root->right);

    if(l == -1 || r == -1)    return -1;
    if(abs(l-r) > 1){
        return -1;
    }
    return 1+max(l,r);
}
bool isBalanced(TreeNode* root) {
    if(recursion(root) == -1){
        return false;
    }
    return true;
}


// Q Diameter of Binary Tree
// TC O(N)
// SC O(N)
int recursion(TreeNode* root,int& dia){
        if(root == NULL)    return 0;

        int l = recursion(root->left,dia);
        int r = recursion(root->right,dia);
        dia = max(dia,l+r);
        return 1 + max(l,r);
    }
int diameterOfBinaryTree(TreeNode* root) {
    
    int dia = 0;
    recursion(root,dia);
    return dia;

}


// Q Same Tree
// TC AND SC -O(N)
bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL || q == NULL){
            return (p==q);
        }

        if(p->val != q->val){
            return false;
        }
        bool ans = isSameTree(p->left,q->left) && isSameTree(p->right,q->right);

        return ans;

    }


// Q ZIG-ZAG Traversal
// SC O(N)
// TC O(N)
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans ;
    if(root == NULL)    return ans;
    int reverse = 0;
    queue<TreeNode*> q;
    TreeNode*node = root; 
    q.push(node);
    while(!q.empty()){
        vector<int> vec;
        int size = q.size();
        for(int i = 0;i<size;i++){
            if(q.front()->left != NULL) q.push(q.front()->left);
            if(q.front()->right != NULL) q.push(q.front()->right);

            
            if(reverse%2 == 1){
                vec.insert(vec.begin(),q.front()->val);
            }
            else
            vec.push_back(q.front()->val);
            q.pop();
        }
            reverse++;

        ans.push_back(vec);
    }
    return ans;
}


// Q Boundary traversal
// TC O(N + H + H) = O(N)    H is the height of tree
// SC O(N + H + H) = O(N)     Stack space of recursion
void recursion(Node *root, vector<int> &vec) {   // Push the leaf nodes 
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) {
        vec.push_back(root->data);
        return;
    }
    recursion(root->left, vec);
    recursion(root->right, vec);
}

void left(Node* root, vector<int> &vec) {
    if(root == NULL || (root->left == NULL && root->right == NULL)) return;
    vec.push_back(root->data);
    if(root->left) left(root->left, vec);
    else left(root->right, vec);
}

void right(Node* root, vector<int> &vec) {
    if(root == NULL || (root->left == NULL && root->right == NULL)) return;
    if(root->right) right(root->right, vec);
    else right(root->left, vec);
    vec.push_back(root->data); // push after recursion for reverse order
}

vector<int> boundaryTraversal(Node *root) {
    vector<int> vec;
    if(root == NULL) return vec;
    if(root->left == NULL && root->right == NULL) {
        vec.push_back(root->data);
        return vec;
    }

    vec.push_back(root->data); // root added
    left(root->left, vec);     // Push the left boundary
    recursion(root, vec);      
    right(root->right, vec);   // Push the right boundary

    return vec;
}

// Iterative Approach
// TC O(N + H + H) = O(N)    H is the height of tree
// SC O(N)     

void addLeftBoundary(Node* root, vector<int> &res) {
    Node* cur = root->left;
    while (cur) {
        if (!isLeaf(cur)) res.push_back(cur->data);
        if (cur->left) cur = cur->left;
        else cur = cur->right;
    }
}

void addRightBoundary(Node* root, vector<int> &res) {
    Node* cur = root->right;
    vector<int> tmp;
    while (cur) {
        if (!isLeaf(cur)) tmp.push_back(cur->data);
        if (cur->right) cur = cur->right;
        else cur = cur->left;
    }
    for (int i = tmp.size()-1; i >= 0; --i) {
        res.push_back(tmp[i]);
    }
}

void addLeaves(Node* root, vector<int>& res) {
    if (isLeaf(root)) {
        res.push_back(root->data);
        return;
    }
    if (root->left) addLeaves(root->left, res);
    if (root->right) addLeaves(root->right, res);
}

vector<int> printBoundary(Node *root)
{
    vector<int> res;
    if (!root) return res;
    if (!isLeaf(root)) res.push_back(root->data);
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);
    return res;
}


// Q Vertical Traversal
// TC O(Nlogn)
// SC O(3N) + O(3N)   Map and queue 
vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int,map<int,multiset<int>>> mp;
    queue<pair<TreeNode*,pair<int,int>>> q;
    TreeNode* node = root;
    q.push({node,{0,0}});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        node = it.first;
        int x = it.second.first;
        int y = it.second.second;
        mp[x][y].insert(node->val);
        if(node->left != NULL){
            q.push({node->left,{x-1,y+1}});
        }
        if(node->right != NULL){
            q.push({node->right,{x+1,y+1}});
        }
    }
    vector<vector<int>> ans;
    for(auto x : mp){
        vector<int> col;
        for(auto y : x.second){
            col.insert(col.end(),y.second.begin(),y.second.end());  // Inserting whole multiset inside the col.
        }
        ans.push_back(col);
    }
    return ans;
}

// Q Top view
// SC O(N)
// TC O(N)
vector<int> topView(Node *root) {
    vector<int> ans;
    queue<pair<Node*,int>> q;
    map<int,int> mp;
    Node* temp = root;
    int line = 0;
    q.push({root,line});
    while(!q.empty()){
        temp = q.front().first;
        int x = q.front().second;
        q.pop();
        if(temp->left)  q.push({temp->left,x-1});
        if(temp->right)  q.push({temp->right,x+1});
        if(mp.find(x) == mp.end())  mp[x] = temp->data;
    }
    for(auto it : mp){
        ans.push_back(it.second);
    }
    return ans;
}


// Q Bottom view
// SC O(N)
// TC O(N)
vector<int> bottomView(Node *root) {
    vector<int> ans;
    queue<pair<Node*,int>> q;
    map<int,int> mp;
    q.push({root,0});
    while(!q.empty()){
        auto it = q.front();
        Node* node = it.first;
        int x = it.second;
        q.pop();
        if(node->left)  q.push({node->left,x-1});
        if(node->right)  q.push({node->right,x+1});
        mp[x] = node->data;
    }
    for(auto it : mp){
        ans.push_back(it.second);
    }
    return ans;
}

// Q Binary tree Right side view  (Reverse tree traversal order for the left view)

// Using Map ds 
// SC O(N + H)
// TC O(N)
void recursion(TreeNode* root,map<int,int>& mp,int level){   
        if(root == NULL){
            return;
        }
        recursion(root->left,mp,level+1);
        mp[level] = root->val; 
        recursion(root->right,mp,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        map<int,int> mp;
        recursion(root,mp,0);
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }

// Using a vector only
// SC O(H)
// TC O(N)
void recursion(TreeNode* root,vector<int>& ans,int level){   
    if(root == NULL){
        return;
    }
    if(level == ans.size()){     // if reached a new level insert the elemnt (rightmost element since traversing right subtree first)
        ans.push_back(root->val);
    }
    recursion(root->right,ans,level+1);    
    recursion(root->left,ans,level+1); 
}
vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    recursion(root,ans,0);
    return ans;
}



// Q Symmetric Tree
// SC O(N)         // Recursive stack space
// TC O(N)
bool recursion(TreeNode* Left,TreeNode* Right){
    if(Left == NULL || Right  == NULL){
        return (Left == Right);
    }
    if(Left->val != Right->val){ 
        return false;
    }
    bool ans = recursion(Left->left,Right->right) && recursion(Left->right,Right->left);
    return ans;
}
bool isSymmetric(TreeNode* root) {
    TreeNode* Left = root->left;
    TreeNode* Right = root->right;
    return recursion(Left,Right);
}

// Q Print root to leaf path in BT
// TC O(N)
//  SC O(N)
void recursion(Node* root,vector<int> vec,vector<vector<int>>& ans){
    if(root == NULL)    return;
    if(root->left == NULL && root->right == NULL){
        vec.push_back(root->data);
        ans.push_back(vec);
        return;
    }
    vec.push_back(root->data);
    recursion(root->left,vec,ans);
    // if(vec.size()>0)    vec.pop_back();
    recursion(root->right,vec,ans);
}
vector<vector<int>> Paths(Node* root) {
    vector<vector<int>> ans;
    recursion(root,{},ans);
    return ans;
    
}

void recursion(Node* root, vector<int>& vec, vector<vector<int>>& ans) {
    if (root == NULL) return;

    // include current node
    vec.push_back(root->data);

    // if leaf, store path
    if (root->left == NULL && root->right == NULL) {
        ans.push_back(vec);
    } else {
        // recurse left and right
        recursion(root->left, vec, ans);
        recursion(root->right, vec, ans);
    }

    // backtrack
    vec.pop_back();
}
vector<vector<int>> Paths(Node* root) {
    vector<vector<int>> ans;
    vector<int> vec;
    recursion(root, vec, ans);
    return ans;
}

// Q Count total nodes in a complete BT
// TC O(N)
//  SC O(1)
int countNodes(TreeNode* root) {
        TreeNode* node = root;
        if(root == NULL)    return 0;
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            node = q.front();
            q.pop();
            if(node->left != NULL)  q.push(node->left);
            if(node->right != NULL)  q.push(node->right);
            ans++;
        }
        return ans;
    }

// Q Width of a Binary tree
// TC SC O(N)
int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q; // node , index
        TreeNode* node = root;
        int ans = 0;
        q.push({node , 0});
        while (!q.empty()) {
            int size = q.size();
            long long min = q.front().second;
            int first,last;
            for(int i = 0;i < size;i++){
                node = q.front().first;
                long long cur_ind = q.front().second - min;
                q.pop();
                if(i == 0) first = cur_ind;
                if(i == size-1) last = cur_ind;
                if (node->left != NULL)
                    q.push({node->left,cur_ind*2+ 1});
                if (node->right != NULL)
                    q.push({node->right, cur_ind*2 + 2});
            }
            ans = max(ans,last-first+1);
        }
        return ans;
    }


// Q Flaten a Binary tree to Linked List

// Method 1
// SC O(N + N) Stack space + vector space
// TC O(2N)
void recursion(TreeNode* root, vector<TreeNode*>& vec){
    if(root == NULL){
        return;
    }
    vec.push_back(root);
    recursion(root->left,vec);
    recursion(root->right,vec);
    return;
}
void flatten(TreeNode* root) {
    if(root == NULL) return;
    TreeNode* temp = new TreeNode ;
    vector<TreeNode*> vec;
    recursion(root,vec);
    for(int i = 0;i < vec.size()- 1;i++){
        vec[i]->left = NULL;
        vec[i]->right = vec[i+1];
    }
    vec.back()->left = NULL;
    vec.back()->right = NULL;
    root = vec[0];
    return ;
}

// Method 2
// SC O(N) stack apace
// TC O(N)
TreeNode* prev = NULL;
void flatten(TreeNode* root) {
    if(root == NULL){
        return;
    }
    flatten(root->right);
    flatten(root->left);

    root->right = prev;
    root->left = NULL;
    prev = root;

    return;
}

    

// Q  Lowest Common Ancestor of a Binary Tree

// Method 1 
// Storing and comparing paths upto both nodes
// SC O(N + N)  stack spcae + array space
// TC O(N)
void recursion(TreeNode* root,vector<TreeNode*>& vec,TreeNode* p, TreeNode* q,vector<vector<TreeNode*>>& seq){
    if(root == NULL){
        return;
    }
    vec.push_back(root);
    if(root == p || root == q){
        seq.push_back(vec);
    }
    
    recursion(root->left,vec,p,q,seq);
    recursion(root->right,vec,p,q,seq);
    
    vec.pop_back();
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> vec;
    vector<vector<TreeNode*>> seq;
    recursion(root,vec,p,q,seq);
    int i = 0;int n = seq[0].size();
    int j = 0;int m = seq[1].size();
    TreeNode* ans = new TreeNode;
    while(i < n && j < m){
        if(seq[0][i] == seq[1][j]){
            ans = seq[0][i];
        }
        else break;
        i++;
        j++;
    }
    return ans;
}

// Method 2
// SC O(N ) 
// TC O(N)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL || root == p || root == q){           // If one of required node is found return and check the other other subtree
                                                          // If node not in the other subtree then this root wil be returned automatically(means this is the anscestor to the reuired node 2)  
        return root;
    }
    TreeNode * l = lowestCommonAncestor(root->left,p,q);
    TreeNode* r = lowestCommonAncestor(root->right,p,q);
    // if(root == p || root == q){                       // can also check the nodes  while backtracking also
    //     return root;
    // }
    if(l == NULL){
        return r;
    }
    else if(r == NULL){
        return l;
    }
    else return root;
}

// Children Sum Property in Binary Tree
// SC O(1)
// TC O(N)
int recursion(Node* root){
    if(root == NULL)
        return 0;
    
    if(root->left == NULL && root->right == NULL){
        return root->data;
    }
    
    int l = recursion(root->left);
    int r = recursion(root->right);
    // cout << l << " " << r << endl;
    if(l == -1 || r == -1)
        return -1;
    
    if(l + r == root->data){
        return root->data;
    }
    else return -1;
}
bool isSumProperty(Node *root) {
    
    int ans = recursion(root);
    if(ans == -1){
        return false;
    }
    return true;
}


// Q All Nodes Distance K in Binary Tree
// SC O(3*N)
// TC O(2*N)

void parentmapper(TreeNode* root,unordered_map<TreeNode*, TreeNode*> &parentmap){
    if(root == NULL){
        return;
    }
    parentmapper(root->left,parentmap);
    parentmapper(root->right,parentmap);
    if(root->left != NULL)  parentmap.insert({root->left,root});
    if(root->right != NULL)  parentmap.insert({root->right,root});
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode* , TreeNode*> parentmap;    // {node,parent}
    parentmapper(root,parentmap);

    queue<TreeNode *> q;
    unordered_map<TreeNode* , bool> visited;
    q.push(target);
    int curr_level = 0;
    visited[target] = true;
    while(!q.empty()){
        int size = q.size();
        if(curr_level++ == k)   break;
        for(int i = 0;i < size;i++){
            auto it = q.front();
            q.pop();
            if(it->left != NULL && !visited[it->left]){
                q.push(it->left);
                visited[it->left] = true;
            }     
            if(it->right != NULL && !visited[it->right]){
                q.push(it->right);
                visited[it->right] = true;
            }  
            if(parentmap[it] && !visited[parentmap[it]]){
                q.push(parentmap[it]);
                visited[parentmap[it]] = true;
            }
        }
    }
    vector<int> ans;
    while(!q.empty()){
        ans.push_back(q.front()->val);
        q.pop();
    }
    return ans;

    }




// Q Burning Tree
// SC O(3*N)
// TC O(2*N)

void parentmapper(Node* root,unordered_map<Node*, Node*> &parentmap,int target,Node* &target_node){
    if(root == NULL){
        return;
    }
    if(target == root->data)    target_node = root;
    
    parentmapper(root->left,parentmap,target,target_node);
    parentmapper(root->right,parentmap,target,target_node);
    if(root->left != NULL)  parentmap.insert({root->left,root});
    if(root->right != NULL)  parentmap.insert({root->right,root});
}
int minTime(Node* root, int target) {
    Node* target_node(0) ;
    unordered_map<Node*, Node*> parentmap;
    parentmapper(root,parentmap,target,target_node);

    queue<Node*> q;
    unordered_map<Node*,bool> visited;
    q.push(target_node);
    int curr_level = -1;
    visited[target_node] = true;
    while(!q.empty()){
        int size = q.size();
        curr_level++;
        for(int i = 0;i < size;i++){
            auto it = q.front();
            q.pop();
            if(it->left != NULL && !visited[it->left]){
                q.push(it->left);
                visited[it->left] = true;
            }     
            if(it->right != NULL && !visited[it->right]){
                q.push(it->right);
                visited[it->right] = true;
            }  
            if(parentmap[it] && !visited[parentmap[it]]){
                q.push(parentmap[it]);
                visited[parentmap[it]] = true;
            }
        }
        
    }
    return curr_level;
    
}

// Unique Binary Tree Requirements
// SC O(1)
// TC O(1)
bool isPossible(int a, int b) {
    if((a != 2 && b != 2) || a == b){
        return 0;
    }
    else return 1;
}


// Q Creating a BT from Inorder and preorder 
// SC O(N *log(N))
// TC O(N)
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    map<int,int> mp;
    for(int i = 0;i < inorder.size();i++){
        mp[inorder[i]] = i;
    }
    TreeNode* root = buildTree(inorder,0,inorder.size() - 1,preorder,0,preorder.size() - 1,mp);
    return root;
}
TreeNode* buildTree( vector<int>& inorder,int instart,int inend,vector<int>& preorder,int prestart,int preend,map<int,int>& mp){
    if(instart > inend || prestart > preend ){
        return NULL;
    }

    TreeNode* root = new TreeNode(preorder[prestart]);
    
    int inroot = mp[root->val];
    int numsleft = inroot - instart;     // nums on left of root in inorder 
    root->left = buildTree(inorder,instart,inroot - 1,preorder,prestart + 1,prestart + numsleft,mp);
    root->right = buildTree(inorder,inroot+ 1,inend,preorder,prestart + numsleft + 1,preend,mp);
    return root;
}

// Q Creating a BT from Inorder and postorder 
// SC O(N *log(N))
// TC O(N)
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    map<int,int> mp;
    for (int i = 0; i < inorder.size(); i++) {
        mp[inorder[i]] = i;
    }
    return buildTree(inorder, 0, inorder.size() - 1,
                     postorder, 0, postorder.size() - 1, mp);
}

TreeNode* buildTree(vector<int>& inorder, int instart, int inend,
                    vector<int>& postorder, int poststart, int postend,
                    map<int,int>& mp) {
    if (instart > inend || poststart > postend) {
        return NULL;
    }

    TreeNode* root = new TreeNode(postorder[postend]);

    int inroot = mp[root->val];
    int numsleft = inroot - instart;

    // Left subtree
    root->left = buildTree(inorder, instart, inroot - 1,
                           postorder, poststart, poststart + numsleft - 1, mp);

    // Right subtree
    root->right = buildTree(inorder, inroot + 1, inend,
                            postorder, poststart + numsleft, postend - 1, mp);

    return root;
    }



// Q Serialize and Deserialize Binary Tree
// SC O(N)
// TC O(N)
// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    string str = "";
    if (root == NULL) {
        return str;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            auto it = q.front();
            q.pop();
            if (it != NULL) {
                string num = to_string(it->val);
                str.append(num + " ");
                if (it->left != NULL)
                    q.push(it->left);
                else
                    q.push(NULL);
                if (it->right != NULL)
                    q.push(it->right);
                else
                    q.push(NULL);
            } else {
                str.append("n ");
            }
        }
    }
    // for(auto it : str){
    //     cout << it;
    // }
    return str;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
        if (data.empty())
            return NULL;

        // Split the string by spaces
        vector<string> tokens;
        stringstream ss(data);
        string temp;
        while (ss >> temp) {
            tokens.push_back(temp);
        }

        // First token is the root
        TreeNode* root = new TreeNode(stoi(tokens[0]));
        queue<TreeNode*> q;
        q.push(root);

        int i = 1; // index for tokens
        while (!q.empty() && i < tokens.size()) {
            TreeNode* node = q.front();
            q.pop();

            // Left child
            if (tokens[i] != "n") {
                node->left = new TreeNode(stoi(tokens[i]));
                q.push(node->left);
            }
            i++;

            // Right child
            if (i < tokens.size() && tokens[i] != "n") {
                node->right = new TreeNode(stoi(tokens[i]));
                q.push(node->right);
            }
            i++;
        }

        return root;
    }



