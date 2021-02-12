#include <bits/stdc++.h>

using namespace std;

class BoundedBlockingQueue {
private:

public:
    int capacity;
    condition_variable cv;
    mutex mtx;
    deque<int> buffer;
    
    BoundedBlockingQueue(int capacity) {
        this->capacity = capacity;
    }
    
    void enqueue(int element) {
        unique_lock<mutex> lck(mtx);
        cv.wait(lck, [this]{ return buffer.size() < capacity;});
        buffer.push_front(element);
        lck.unlock();
        cv.notify_all();
    }
    
    int dequeue() {
        int val;
        unique_lock<mutex> lck(mtx);
        cv.wait(lck, [this]{ return buffer.size() > 0;});
        val = buffer.back();
        buffer.pop_back();
        lck.unlock();
        cv.notify_all();
        return val;
    }
    
    int size() {
        return buffer.size();
    }
};