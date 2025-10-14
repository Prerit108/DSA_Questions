#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Node{        // if we use class instead of struct this will work fine
   // Struct are like classes but lack abstraction,inheritance,encapsulationstc
    public:
    int data;
    Node* next;

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArr2LL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i = 1;i < arr.size();i++){
        Node* newnode = new Node(arr[i]);
        temp->next = newnode;
        temp = newnode;
    }
    return head; 
}

void traversal(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
    return;
}

void search(Node* head,int val){
        Node* temp = head;
    while(temp != nullptr){
        
        if (temp->data == val){
            cout << "element found" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << " Element not found" << endl;
    return;
}


// Deletion codes

Node* deletehead(Node* head){
    if(head == NULL)  return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node * deleteend(Node* head){
    Node* temp = head;
    if(temp == NULL || temp->next == NULL){
        return NULL;
    }
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;
    return head;

}

Node * deleteindex(Node* head,int ind){
    if(head == NULL) return NULL;
    
    if(ind == 1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* temp = head;
    Node* prev = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(cnt == ind){
            prev->next = temp->next;
            delete temp;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node * removeELE(Node* head,int ele){
    if(head == NULL) return NULL;
    
    if(head->data == ele){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* temp = head;
    Node* prev = head;
    while(temp != NULL){
        if(temp->data == ele){
            prev->next = temp->next;
            delete temp;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

// Insertion codes

Node* inserthead(Node* head,int val){
    Node* temp = new Node(val ,head);
    return temp;
}

Node* insertionend(Node* head,int val){
    if(head == NULL){
        return new Node(val,nullptr);
    }

    Node* newnode = new Node(val);
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
    return head;

}

Node* insertindex(Node* head, int val,int ind){
    if(head == NULL){
        return new Node(val);
    }
    if(ind == 1){
        Node* temp = new Node(val);
        temp->next= head;
        return temp;
    }
    Node* temp = head;
    Node* newnode = new Node(val);
    int cnt = 1;
    while(temp-> next != nullptr){
        cnt++;
        if(cnt == ind){
            newnode->next = temp->next;
            temp->next = newnode;
            return head;
        }
        temp = temp->next;
    }
}


int main(){
    vector<int> arr = {6,5,7,19};
    // Node *y = new Node{arr[0], nullptr};
    // cout << y->data << endl;


    Node* head = convertArr2LL(arr);
    // cout << head->data << endl;

    // traversal(head);

    // search(head,7);

    //  Deletion in LL

    // head = deletehead(head);
    // traversal(head);

    // head = deleteend(head);
    // traversal(head);

    // head = deleteindex(head,3);
    // traversal(head);

    // head = deleteindex(head,3);
    // traversal(head);

    // head = removeELE(head,8);
    // traversal(head);
     
    // Insertion in LL
    // head = inserthead(head,50);
    // traversal(head);

    // head = insertionend(head,100);
    // traversal(head);

    head = insertindex(head,200,5);
    traversal(head);





 
    return 0;
}