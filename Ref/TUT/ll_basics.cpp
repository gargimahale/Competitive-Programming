#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* next;
};

// Declared as Global
Node* head;

void insert(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->next = head;
    head = temp;
}

// void insert2(int data){
//     Node* temp = head;
//     Node* temp1 = new Node();
//     temp1->data=data;
//     while(temp!=NULL) temp = temp->next;
//     temp = temp1;
//     temp->next = NULL;
// }

void insertAt(int data, int pos){
    Node* temp1 = new Node();
    temp1->data = data;
    temp1->next = NULL;
    if(pos==1){
        temp1->next = head;
        head = temp1;
        return;
    }
    Node* temp2 = head;
    for(int i=0;i<pos-2;++i) temp2 = temp2->next;
    temp1->next = temp2->next;
    temp2->next = temp1;
}

void deleteAt(int pos){
    Node* temp1 = head;
    if(pos==1){
        head=temp1->next;
        delete temp1;
        return;
    }
    for(int i=0;i<pos-2;++i) temp1=temp1->next;
    Node* temp2 = temp1->next; //nth node
    temp1->next = temp2->next;
    delete temp2;
}

void print(){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    head = NULL;
    // int n;
    // cout << "How many numbers: ";
    // cin >> n;
    // for(int i=0;i<n;i++){
    //     int x;
    //     cin >> x;
    //     head = insert(head, x);
    //     // print();
    // }
    // insertAt(2,1);
    // insertAt(3,2);
    // insertAt(4,1);
    // insertAt(5,2);
    insert2(2);
    insert2(4);
    insert2(6);
    insert2(5);
    // int pos =0;
    // deleteAt(pos);
    print();
    return 0;
}