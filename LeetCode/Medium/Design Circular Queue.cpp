#include <bits/stdc++.h>
using namespace std;

// TC: O(1), SC: O(capacity)

struct Node {
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
};

class MyCircularQueue {
public:
    int cap = 0, size;
    mutex m;
    Node* head = NULL, *tail = nullptr;

    MyCircularQueue(int k) {
        cap = k;
        size = 0;
    }

    bool enQueue(int value) {
        m.lock();
        if (!isFull()) {
            Node* temp = new Node(value);
            if (head == NULL) {
                head = tail = temp;
            } else {
                tail->next = temp;
                tail = temp;
            }
            tail->next = head;
            ++size;
            m.unlock();
            return true;
        }
        m.unlock();
        return false;
    }

    bool deQueue() {
        m.lock();
        if (!isEmpty()) {
            if (head == tail) {
                head = tail = NULL;
            }
            else {
                Node* tmp = head;
                head = head->next;
                delete tmp;
                tail->next = head;
            }
            --size;
            m.unlock();
            return true;
        }

        m.unlock();
        return false;
    }

    int Front() {
        return size > 0 ? head->val : -1;
    }

    int Rear() {
        return size > 0 ? tail->val : -1;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == cap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

int main(void) {
    MyCircularQueue* obj = new MyCircularQueue(3);
    bool p1 = obj->enQueue(4);
    cout << p1;
    p1 = obj->enQueue(5);
    cout << p1;
    p1 = obj->enQueue(6);
    cout << p1;
    p1 = obj->enQueue(8);
    cout << p1;
}