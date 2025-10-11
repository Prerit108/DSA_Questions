#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Node{        // if we use class instead of struct this will work fine
   // Struct are like classes but lack abstraction,inheritance,encapsulationstc
    public:
    int data;
    Node* next;
    Node* back;

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

