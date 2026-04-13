#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// Search in a BST
// TC O(log N)
// SC O(1)
TreeNode* searchBST(TreeNode* root, int val) {
    // while(root != NULL && root->val != val){
    //     (root->val > val) ? root = root->left:root = root->right;
    // }
    // return root;
    
    // Using recursion
    if(root == NULL || root->val == val){
        return root;
    }
    TreeNode* l = NULL;
    TreeNode* r = NULL;
    if(root->val > val){
        l = searchBST(root->left,val);
    }
    if(root->val < val){
        r = searchBST(root->right,val);        
    }
    return (l==NULL) ? r:l ;

}

// Min element in BST
// TC O(log N)
// SC O(1)
int minValue(Node* root) {
    if(root == NULL){
        return -1;
    }
    if(root->left == NULL){
        return root->data;
    }    
    return minValue(root->left);
}

// Floor in a BST
// TC O(log N)
// SC O(1)
int findFloor(Node* root, int x) {
    int maxx = -1;
    while(root != NULL){
        if(root->data <= x){
            maxx = max(maxx,root->data);
        }
        root = (x > root->data) ? root->right : root->left;
        
    }
    return maxx;
}


// Ceil in a BST
// TC O(log N)
// SC O(1)
int findCeil(Node* root, int x) {
    // code here
    int minn = INT_MAX;
    while(root != NULL){
        if(root->data >= x)  minn = min(minn,root->data);
        root = (root->data > x) ? root->left : root->right;
    }
    return minn == INT_MAX ? -1 : minn;
}

// Insert a given Node in Binary Search Tree
// TC O(log N)
// SC O(1)
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root == NULL){
        TreeNode* node = new TreeNode(val);
        return node;
    }
    if(val < root->val && root->left == NULL){      
        root->left = new TreeNode(val);
        return root;
    };
    if(val > root->val && root->right == NULL){ 
        root->right = new TreeNode(val);
        return root;
    }
    TreeNode* l = NULL;
    TreeNode* r = NULL;
    (val > root->val)? r = insertIntoBST(root->right,val) :l = insertIntoBST(root->left,val);
    
    return root;
}

// Q Validate Binary Search Tree 
// SC O(N)
// TC O(1)
bool isValidBST(TreeNode* root) {
    return isValidBST(root, LLONG_MIN, LLONG_MAX);
}
bool isValidBST(TreeNode* root,long long intmin, long long intmax){
    if(root == NULL)    return true;
    if(root->val <= intmin || root->val >= intmax)    return false;
    return (isValidBST(root->left,intmin,root->val) && isValidBST(root->right,root->val,intmax));
}

// Q LCA in a BST
// SC O(1)
// TC O(H)

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        if(root == p || root == q)    return root;
        if(p->val < root->val && q->val < root->val) return lowestCommonAncestor(root->left,p,q);
        if(p->val > root->val && q->val > root->val) return lowestCommonAncestor(root->right,p,q);

        return root;
    }

// Kth smallest element in a BSTw
// SC O(1)
// TC O(N)
int helper(TreeNode*root,int k,int& cnt){
    if(root == NULL){
        return -1;
    }
    int l = helper(root->left,k,cnt);
    cnt++;
    if(cnt == k)    return root->val;
    int r = helper(root->right,k,cnt);

    return (l == -1)? r:l;
}
int kthSmallest(TreeNode* root, int k) {
    int cnt = 0;   
    return helper(root,k,cnt);
}

// Two Sum In BST | Check if there exists a pair with Sum K
// SC O(N)
// TC O(N)

// Method 1 (Using hashmap)
bool helper(TreeNode* root, int k,unordered_map<int,TreeNode*>& mp){
    if(root == NULL)    return false;

    if(mp.find(k - root->val) == mp.end()){
        mp[root->val] = root;
    }
    else    return true;
    return helper(root->left,k,mp) || helper(root->right,k,mp);

}

bool findTarget(TreeNode* root, int k) {
    // TreeNode* temp = root;
    unordered_map<int,TreeNode*> mp;
    return helper(root,k,mp);
}

// Method 2 (Using vector and 2 pointers)
// Inorder of a BST is always sorted
// SC O(N)
// TC O(2*N)     2 time traversal of array(filling and retrieving)

void helper(TreeNode* root, int k,vector<int>& vec){
    if(root == NULL)    return ;
    vec.push_back(root->val);
    helper(root->left,k,vec);
    helper(root->right,k,vec);
}

bool findTarget(TreeNode* root, int k) {
    // TreeNode* temp = root;
    vector<int> vec;
    helper(root,k,vec);
    int i = 0,j = vec.size()- 1;
    while(i<j){
        if(vec[i] + vec[j] == k){
            return true;
        }
        else if(vec[i] + vec[j] > k){
            j--;
        }
        else i++;
    }
    return false;
}

// Q Construct Binary Search Tree from Preorder Traversal
// SC O(N)
// TC O(N)
TreeNode* helper(vector<int>& preorder,int maxx,int& ind){
        
        if(ind == preorder.size() || preorder[ind] > maxx)  return NULL;
        TreeNode* temp = new TreeNode(preorder[ind]);
        ind++;

        temp->left = helper(preorder,temp->val,ind);
        temp->right = helper(preorder,maxx,ind);
        return temp;

    } 
     
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        int ind = 0;  
        return helper(preorder,INT_MAX,ind);
    }


// Inorder Successor/Predecessor in BST
// Method 1
// TC O(2 * log(N))   (for skewed trees O(N))
// SC O(1)
vector<Node*> findPreSuc(Node* root, int key) {
    int sus = INT_MAX; Node* sus_node = NULL;
    int pre = -1;   Node* pre_node = NULL;
    Node* temp = root;
    vector<Node*> vec;
    
    while(temp != NULL){
        if(key < temp->data){
            // if(sus > temp->data){
                sus_node = temp;
                // cout << sus_node->data << " ";
            // }
            
            temp = temp->left;
        }
        else temp = temp->right;
    }
    temp = root;
    while(temp != NULL){
        if(key > temp->data){
            // if(pre < temp->data){
                pre_node = temp;
            // }
            temp = temp->right;
        }
        else temp = temp->left;
    }
    vec.push_back(pre_node);
    vec.push_back(sus_node);
    return vec;
}

// Method 2
// Combined in 1 traversal 
// TC O(log(N))   (for skewed trees O(N))
// SC O(1)
Node* rightMost(Node* node) {
    while (node->right)
        node = node->right;
    return node;
}

Node* leftMost(Node* node) {
    while (node->left)
        node = node->left;
    return node;
}

// return vector with predecessor at index 0 
// and successor at index 1

vector<Node*> findPreSuc(Node* root, int key) {
    Node* pre = NULL;
    Node* suc = NULL;
    Node* curr = root;

    while (curr) {
        if (curr->data < key) {
            pre = curr;
            
            // look for predecessor with greater value
            curr = curr->right;
        } else if (curr->data > key) {
            suc = curr;
            
            // look for successor with smaller value
            curr = curr->left;
        } else {
            if (curr->left)
                pre = rightMost(curr->left);
            if (curr->right)
                suc = leftMost(curr->right);
            break;
        }
    }

    return {pre, suc};
}










