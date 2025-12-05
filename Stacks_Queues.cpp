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

// 


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






int main(){
    string s = "ab*c+";
    string o = postToInfix(s);
    

    return 0;
}





