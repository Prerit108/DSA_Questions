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

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
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

// Method 1 
// (traverse LL to count elements then find the the middle one)
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

// Method 2 
// ([TortoiseHare Method]) 
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

// Method 1 
// (Using stack/vectors)
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

// Method 2  
// (swapping the links between nodes)
// TC O(N)
// SC O(1)
ListNode* reverseList(ListNode* head) {
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

// Method 3
//  (recursion)
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

// Method 1 
// (Hashing to stored viewed element)
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

// Method 2 
// (Slow and Fast pointer)
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


// Find the starting point in LL

// Method 1 
// (Hashmap)
// TC O(N*2)
// SC O(N)
ListNode *detectCycle(ListNode *head) {
    ListNode* temp = head;
    unordered_map<ListNode*,int> hash;
    int cnt = 0;
    while(temp != NULL){
        if(hash.find(temp) != hash.end()){
            return temp;
        }
        hash.emplace(temp,cnt);
        temp = temp->next;
        cnt++;
    }
    return NULL;
}

// Method 2 
// (Slow and fast pointers)
// SC O(1)
// TC O(N)
ListNode *detectCycle(ListNode *head) {

    ListNode* slow = head;
    ListNode* fast = head; 
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return fast;
        }
    }
    return NULL;
}


// Length of Loop in LL

// Method 1
// (using hashmap to store node and counter)
// TC O(N*2)
// SC O(N)
int lengthOfLoop(ListNode *head){
    ListNode* temp = head;
    unordered_map<ListNode*,int> hash;
    int cnt = 1;
    while(temp != NULL){
        if(hash.find(temp) != hash.end()){
            int value = cnt - hash[temp];
            return value;
        }
        hash.emplace(temp,cnt);
        cnt++;
        temp = temp->next;
    }

    return 0;
}

// Method 2 
// (slow fast pointer) detect the loop(where slow == fast) then start a counter from that point until the same point is reached again.
// TC O(2N)
// SC O(1)
int lengthOfLoop(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    int cnt = 0;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            cnt++;
            slow = slow->next;
            while(fast != slow){
                cnt++;
                slow = slow->next;
            }
            return cnt;
        }
    }
    return 0;
}

// Palindrome Linked List

// Method 1
// Using fast and slow pointers and storing half elements of linked list in a vector.Then comparing it with second half.
// TC O(N)
// SC O(N/2)
bool isPalindrome(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    vector<int> vec;
    while(fast != NULL && fast->next != NULL){
        vec.emplace_back(slow->val);
        fast = fast->next->next;
        slow = slow->next;
    }
    if(fast != NULL){
        slow = slow->next;
    }
    while(slow != NULL){
        if(vec.back() != slow->val){
            return false;
        }
        slow = slow->next;
        vec.pop_back();
    }
    return true;
}

// Method 2
// Traversing half the LL , then reversing the links of the second half of the LL and comparing both halves
// reversing LL at end (to return original LL)
// SC O(1)
// TC O(2N) <-4*N/2(2 half reversal + 2 half traversal)
ListNode* reverse(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(temp != NULL){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
bool isPalindrome(ListNode* head) {
ListNode* slow = head;
ListNode* fast = head;
while(fast->next != NULL && fast->next->next != NULL){
    fast = fast->next->next;
    slow = slow->next;
}
ListNode* newhead = reverse(slow->next);
ListNode* first = head;
ListNode* second = newhead;
while(second != NULL){
    if(first->val != second->val){
        reverse(newhead);
        return false;
    }
    first = first->next;
    second = second->next;
}
reverse(newhead);
return true;
}

// Segrregate odd and even nodes in LL 

// Method 1
// using a vector to store and replace elements
// SC O(N)
// TC O(2N)
ListNode* oddEvenList(ListNode* head) {
    if(head == NULL || head->next ==NULL){
        return head;
    }
    vector<int> vec;
    ListNode* temp = head;
    while(temp != NULL && temp->next != NULL){
        vec.emplace_back(temp->val);
        temp = temp->next->next;
    }
    if(temp){
        vec.emplace_back(temp->val);
    }
    temp = head->next;
    
    while(temp != NULL && temp->next != NULL){
        vec.emplace_back(temp->val);
        temp = temp->next->next;
    }
    if(temp){
        vec.emplace_back(temp->val);
    }
    temp = head;
    int i = 0;
    while(temp!= NULL){
        temp->val = vec[i];
        i++;
        temp = temp->next;
    }
    return head;
}

// Method 2 
// Links changing
// TC O(N)
// SC O(1)
ListNode* oddEvenList(ListNode* head) {
    if(head == NULL || head->next ==NULL){
        return head;
    }
    ListNode* odd = head;
    ListNode* evenhead = head->next;
    ListNode* even = head->next;
    while(even != NULL && even->next != NULL ){  // Since even is always one ahead of odd therefore we will do a condition check on even.
        odd->next = odd->next->next;
        even->next = even->next;

        odd = odd->next;
        even = even->next->next;   
    }
    odd->next = evenhead;
    return head;   
}

// Remove Nth node from the back of the LL

// Method 1
// Finding the element in position of node from the start and then deleting element
// SC O(1)
// TC O(2N)
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head->next == NULL){
        return NULL;
    }
    ListNode* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;   
        temp = temp->next;
    }
    int target = cnt-n+1;
    temp = head;
    if(target == 1){
        head = head->next;
        delete temp;
        return head;
    }
    for(int i = 1;i < target-1;i++){     // Move to one node previous to target.
        temp = temp->next;
    }
    ListNode* ele = temp->next;
    temp->next = ele->next;
    delete ele;
    return head;
}

// Method 2
// Taking a 2 , one pointer n steps from head and one on the head.
// SC O(1)
// TC O(N)
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head->next == NULL){
        return NULL;
    }
    ListNode* temp = head;
    ListNode* forward = head;
    ListNode* prev = temp;
    for(int i = 1;i<n;i++){
        forward = forward->next;
    }
    while(forward->next != NULL){
        prev = temp;
        temp = temp->next;
        forward = forward->next;
    }
    if(temp == head){
        head = head->next;
        delete temp;
        return head;
    }
    prev->next = temp->next;
    delete temp;
    return head;        
}


// Delete the middle node of LL

// Method 1
// Using slow and fast pointers to find the middle element
// SC O(1)
// TC O(N/2)
ListNode* deleteMiddle(ListNode* head) {
    if(head->next == NULL){
        return NULL;
    }
    ListNode* slow = head;
    ListNode* prev = slow;
    ListNode* fast = head;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    prev->next = slow->next;
    delete slow;
    return head;
}

// Sort a LL

// Method 1 
// creating a vector of lements , sorting and replacing
// SC O(N)
// TC O(2N +Nlog(N))
int f(vector<int>& arr , int low ,int high){
    int pindex = low;
    int i = low;
    int j = high;
    while(i<j){
        while(i < high && arr[i] <= arr[pindex]){
            i++;
        }
        while(j > low && arr[j] > arr[pindex]){
            j--;
        }
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[j],arr[low]);
    return j;

}

void quicksort(vector<int>& arr,int low,int high){
    if(low<high){
        int pindex = f(arr,low,high);
        quicksort(arr,low,pindex-1);
        quicksort(arr,pindex+1,high);
    }

}
ListNode* sortList(ListNode* head) {
    ListNode* temp = head;
    int cnt = 1;
    vector<int> vec;
    while(temp != NULL){
        cnt++;
        vec.emplace_back(temp->val);
        temp = temp->next;
    }
    int low = 0;
    int high = vec.size() - 1;
    quicksort(vec,low,high);
    cnt = 0;
    temp = head;

    while(temp != NULL){
        temp->val = vec[cnt];
        cnt++;
        temp = temp->next;
    }

    return head;
}


//  Method 2
// SC O(1)
// TC O(log(N)*(N+N/2)) 

ListNode* findmiddle(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;   // stop at first middle in case of even length
        slow = slow->next;
    }
    return slow;
}
ListNode* mergelists(ListNode* list1, ListNode* list2){
    ListNode* dummynode = new ListNode(-1);
    ListNode* temp = dummynode;
    while(list1 != NULL && list2 != NULL){
        if(list1->val < list2->val){
            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        }
        else{
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }
    }
    if(list1) temp->next = list1;
    else temp->next = list2;

    return dummynode->next;
}
ListNode* sortList(ListNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }
    ListNode* mid = findmiddle(head);
    ListNode* high = mid->next;
    mid->next = nullptr;
    ListNode* low = head;


    low = sortList(low);
    high = sortList(high);
    return mergelists(low,high);      

}


// Intersection of 2 LL 

// Method 1
// Using Hashmaps
// SC O(N1)
// TC O(N1 + N2)
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* temp1 = headA;
    ListNode* temp2 = headB;
    unordered_map<ListNode *,int> hash1;
    // vector<ListNode *> vec2;
    while(temp1 ){
        hash1.emplace(temp1,1);
        temp1 = temp1->next;
    }

    while(temp2){
        if(hash1.find(temp2) != hash1.end()){
            return temp2;
        }
        temp2 = temp2->next;
    }

    return NULL;
}

// Method 2
// Move l2-l1 from head in the longer linked list, this will place starting point of both LL equally away from the intersection.
// terate both until find the common node.
// SC O(N1 + N2 + (N2-N1) + N1) = O(N1 + 2*N2)   considering n1 is smaller
// TC O(N1 +)
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* temp1 = headA;
    ListNode* temp2 = headB;
    int t1 = 0,t2 = 0;
    while(temp1){
        t1++;
        temp1 = temp1->next;
    }
    while(temp2){
        t2++;
        temp2 = temp2->next;
    }
    temp1 = headA;
    temp2 = headB;

    while(t1 > t2){
        temp1 = temp1->next;
        t1--;
    }

    while(t1 < t2){
        temp2 = temp2->next;
        t2--;
    }
    
    while(temp1 != temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return temp1;
}

// Method 3
// SC O(1)
// TC O(N1+N2)
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* temp1 = headA;
    ListNode* temp2 = headB;
    if(headA == NULL || headB == NULL){
        return NULL;
    }
    while(temp1 != temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;
        if(temp1 == temp2){
            return temp1;
        }
        if(temp1 == NULL){
            temp1 = headB;
        }
        if(temp2 == NULL){
            temp2 = headA;
        }
        
    }
    return temp2;
} 


// Add 1 to a number represented by LL

// Method 1
// Reverse the list, add 1 to the first node taking care if number in node is 9 take carry .
// Add extra node if all nodes have 9 and then reverse again.
// SC O(1)
// TC O(3N) which can be taken as O(N)
Node* addOne(Node* head) {
    // Your Code here
    if(head == NULL){
        return head;
    }
    Node* temp = head;
    Node* prev = nullptr;
    while(temp){
        Node* ahead = temp->next;
        temp->next = prev;
        prev = temp;
        temp = ahead;
    }
    
    Node* newhead = prev;
    temp = prev;
    prev= nullptr;
    Node* curr = temp ;
    int carry = 0;
    while(curr){
        if(curr-> data < 9){
            curr->data += 1;
            break;
        }
        if(curr->data == 9){
            carry = 1;
            curr->data = 0;
        }
        if (curr->next == NULL && carry == 1) {
            curr->next = new Node(carry);
            carry = 0;
            break;
        }
        curr = curr->next;
    }
    

    while(temp){
        Node* ahead = temp->next;
        temp->next = prev;
        prev = temp;
        temp = ahead;
        
    }

    return prev;
        
    }

//  Method 2
// Recursion
// SC O(N)
// TC O(N)
int helper(Node * temp){
    if(temp == NULL){
        return 1;
    }
    int carry = helper(temp->next);
    temp->data = temp->data + carry;
    if(temp->data < 10){
        return 0;
    }
    return 1;
}

Node* addOne(Node* head) {
    Node* temp = head;
    int carry = helper(temp);
    if(carry == 1){
        Node* newnode = new Node(1);
        newnode->next = head;
        return newnode;
    }
    return head;
}

int  main(){
    return 0;
} 