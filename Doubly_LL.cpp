#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Node{        // if we use class instead of struct this will work fine
   // Struct are like classes but lack abstraction,inheritance,encapsulationstc
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

// Deletion codes
Node* deletehead(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    head->back = nullptr;
    temp->next = nullptr ; 
    delete temp;
    return head;
}

Node* deleteend(Node* head){
    if(head == NULL || head-> next == NULL){
        return NULL;
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->back->next = nullptr;  // changing next of element before tail to null ptr
    temp->back = nullptr;
    delete temp;
    return head;
}

Node* deleteatind(Node* head,int ind){
    if(head == NULL){
        return NULL;
    }
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(cnt == ind){
            break;
        }
        temp = temp->next;
    }
    Node* front = temp->next;
    Node* prev = temp->back;
    if(temp->next == NULL && temp->back == NULL){     // only 1 element in the DLL
        return NULL;
    }
    if(temp->back == NULL){
        head = deletehead(head);
        return head;
    }
    if(temp->next == NULL){
        head = deleteend(head);
        return head;
    }
    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;
    return head;
}

void deletenode(Node* temp){    // Do note delete head node
    Node* prev = temp->back;
    Node* front = temp->next;
    if(front == NULL){
        prev->next = nullptr;
        temp->back = nullptr;
        delete temp;
    
    }
    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    delete temp;
}


// Insertion Codes
Node* insertbeforehead(Node* head,int val){
    Node* newnode = new Node(val,head,nullptr);
    head-> back = newnode;
    return newnode;
}

Node* insertbeforetail(Node* head,int val){
    Node* tail = head;
    if(head->next == NULL){           // If the DLL has only one node
        Node* newnode = new Node(val,head,nullptr);
        head-> back = newnode;
        return newnode;

    }
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* newnode = new Node(val,tail,tail->back);
    tail->back->next = newnode;
    tail->back = newnode;
    return head;
}

Node* insertbeforekth_node(Node* head,int k,int val){
    Node* temp = head;
    if(k == 1){
        head = insertbeforehead(head,val);
        return head;
    }
    int cnt = 1;
    while(k != cnt){
        cnt++;
        if(cnt == k){
            Node* newnode = new Node(val,temp->next,temp);
            temp->next = newnode;
            newnode->next->back = newnode;
            return head;
        }
        temp = temp->next;
    }
    return head;
}

void insertbefore_given_node(Node* node,int val){   // donot change the head 
    Node* newnode = new Node(val,node,node->back);
    node->back->next = newnode;
    node->back = newnode; 
}

int main(){
    vector<int> arr = {2,4,6,8,10};
    Node* head = arraytoDLL(arr);
    traversal(head);

    // Deletion code
    // head = deletehead(head);
    // traversal(head);

    // head = deleteend(head);
    // traversal(head);
    
    // head = deleteatind(head,5);
    // traversal(head);

    // deletenode(head->next);
    // traversal(head);
    

    // Insertion code
    // head = insertbeforehead(head.90);
    // traversal(head);

    // head = insertbeforetail(head,100);
    // traversal(head);

    // head = insertbeforekth_node(head,1,11);
    // traversal(head);

    insertbefore_given_node(head->next->next,20);
    traversal(head);



    return 0;
}

