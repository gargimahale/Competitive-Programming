#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

Node* head;

Node* getNewNode(int x){
    Node* curr = new Node();
    curr->data = x;
    curr->prev = NULL;
    curr->next = NULL;
    return curr;
}

void insertAtHead(int x){
    Node* temp = getNewNode(x);
    if (!head) {
        head = temp;
        return;
    }
    head->prev = temp;
    temp->next = head;
    head = temp;
}

void insertAtTail(int x){
    Node* curr = getNewNode(x);
    if (!head){
        head = curr;
        return;
    }
    Node* temp = head;
    while(temp->next) temp = temp->next;
    temp->next = curr;
    curr->prev = temp;
}

void printNode(){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void printRev(){
    Node* temp = head;
    if(!head) return;
    while(temp->next) temp=temp->next;
    while(temp){
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main() {
    head = NULL;
    // insertAtHead(2);
    // insertAtHead(4);
    // insertAtHead(10);
    // insertAtHead(1);
    insertAtTail(1);
    insertAtTail(2);
    insertAtTail(3);
    insertAtTail(4);
    cout << "Forward: ";
    printNode();
    cout << "Reverse: ";
    printRev();
    return 0;
}