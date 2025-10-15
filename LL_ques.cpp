#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct ListNode{        
    public:
    int val;
    ListNode* next;
    ListNode(int data1, ListNode* next1){
        val = data1;
        next = next1;
    }
    ListNode(int data1){
        val = data1;
        next = nullptr;
    }
};

ListNode* convertArr2LL(vector<int> arr){
    ListNode* head = new ListNode(arr[0]);
    ListNode* temp = head;
    for(int i = 1;i < arr.size();i++){
        ListNode* newnode = new ListNode(arr[i]);
        temp->next = newnode;
        temp = newnode;
    }
    return head; 
}

void traversal(ListNode* head){
    ListNode* temp = head;
    while(temp != nullptr){
        cout << temp->val << "  ";
        temp = temp->next;
    }
    cout << endl;
    return;
}

// Middle of a LinkedList 

// Method 1 (traverse LL to count elements then find the the middle one)
// SC O(1)
// TC O(3N/2)
ListNode* middleNode(ListNode* head) {
    ListNode* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        temp = temp->next;
    }
    temp = head;
    for(int i = 0;i < cnt/2;i++){
        temp = temp->next;
    }
    return temp;
}

// Method 2 ([TortoiseHare Method]) 
// Create 2 pointers fast(2 steps) and  slow(1 step)
// SC O(1)
// TC O(N/2)
ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

// Reverse a LinkedList 

// Method 1 (Using stack/vectors)
// TC O(2N)
// SC O(N)
ListNode* reverseList(ListNode* head) {
    vector<int> vec;
    ListNode* temp = head;
    while(temp != NULL){
        vec.emplace_back(temp->val);
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL){
        temp->val = vec.back();
        vec.pop_back();
        temp = temp->next;
    }
    return head;

}

// Method 2  (swapping the links between nodes)
// TC O(N)
// SC O(1)
ListNode* reverseList(ListNode* head) {
    vector<int> vec;

    ListNode* prev = nullptr;
    ListNode* temp = head;

    while(temp != NULL){
        ListNode* ahead = temp->next;
        temp->next = prev;
        prev = temp;
        temp = ahead;
    }

    return prev;

}

// Method 3 (recursion)
// SC O(N)
// TC O(N)
ListNode* reverseList(ListNode* head) {
    if(head == NULL || head->next == NULL){
    return head;
}
ListNode* newhead = reverseList(head->next);
ListNode* front = head->next;
front->next = head;
head->next = NULL;
return newhead;


}


// LinkedList cycle

// Method 1 (Hashing to stored viewed element)
// SC O(N)
// TC O(N*2*log(n))  // can use unordered_set for better TC
bool hasCycle(ListNode *head) {
    map<ListNode*,int> hash;
    ListNode* temp = head;
    while(temp != NULL){
        if(hash.find(temp) != hash.end()){
            return true;
        }
        hash.emplace(temp,temp->val);
        temp = temp->next;
    }
    return false;
}

// Method 2 (Slow and Fast pointer)
// SC O(1)
// TC(N)
// The pointers will surely collide at some point in a cycle, beacuse the fast pointer is moving by 2 and slow is moving by 1 step,
// therefore after each iteration the gap b/w fast and slow will be reduced by 1.So they will collide.
bool hasCycle(ListNode *head) {

    ListNode* slow = head;
    ListNode* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            return true;
        }
    }
    return false;
}


int  main(){
    return 0;
} 