#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;
    Node* back;

    Node(int data1, Node* next1,Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};
Node* arraytoDLL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1;i < arr.size();i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
void traversal(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Reversing a DLL

// Method 1
// Pushing every element in a stack starting from head, then adding the element in stack into DLL starting from the head
// Node* reverse(Node* head){
//     Node* temp = head;
//     vector<int> stack;
//     while(temp != NULL){
//         stack.push(temp->data);
//         temp = temp->next;
//     }
//     temp = head;
//     while(temp != NULL){
//         temp->data = stack.top();
//         stack.pop()
//         temp = temp->next;
//     }
//     return head;

// }

// Method 2 (reversing the links)
// TC O(N)
// SC(1)
Node* reverse2(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* current = head;
    Node* last = NULL;
    while(current != NULL){
        last = current->back;
        current->back = current->next;
        current->next = last;
        current = current-> back;
    }    
    return last->back;   // new
}

 
int  main(){
    vector<int> arr = {1,2,3,4,5,6};
    Node* head = arraytoDLL(arr);
    traversal(head);

    head = reverse2(head);
    traversal(head);




    return 0;
}