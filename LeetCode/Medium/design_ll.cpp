#include<bits/stdc++.h>
using namespace std;

class MyLinkedList {
public:
    struct Node {
        int val;
        Node * prev, * next;
        Node(int x) {
            val = x;
            prev = NULL;
            next = NULL;
        }
        Node(int x, Node * p, Node * n) {
            val = x;
            prev = p;
            next = n;
        }
    };
    Node *head;
    int size;
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = new Node(-1);
        size = 0;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= size) {
            return -1;
        }
        Node * cur = head;
        for (int i = 0; i <= index; i++) {
            cur = cur->next;
        }
        return cur->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        size ++;
        Node *newnode = new Node(val, head, head->next);
        if (head->next) {
            head->next->prev = newnode;
        }
        head->next = newnode;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        size ++;
        Node * cur = head;
        while (cur->next) {
            cur = cur->next;
        }
        Node * newnode = new Node(val, cur, NULL);
        cur->next = newnode;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size) {
            return;
        }
        if (index == size) {
            addAtTail(val);
            return;
        }
        Node * prev = head, *cur = head->next;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
            cur = cur->next;
        }
        Node * newnode = new Node(val, prev, cur);
        prev->next = newnode;
        cur->prev = newnode;
        size ++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) {
            return;
        }
        Node * prev = head, *cur = head->next;
        for (int i = 0; i < index; i++) {
            prev = prev->next;
            cur = cur->next;
        }
        Node * next = cur->next;
        prev->next = next;
        if (next) {
            next->prev = prev;
        }
        delete cur;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */