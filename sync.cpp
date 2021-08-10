#include <bits/stdc++.h>
using namespace std;

class Restaurant {
    enum class Status { idle, newOrder, ready };
    Status orderStatus = Status::idle;
    mutex order;
    condition_variable orderBell;

public:
    void chef() {

        unique_lock<mutex> ul(order);
        orderBell.wait(ul, [ = ]() { return orderStatus == Status::newOrder; });
        //cook the order
        orderStatus = Status::ready;
        orderBell.notify_one();
    }

    void waiter() {
        {
            lock_guard<mutex> lg(order);
            orderStatus = Status::newOrder;
            orderBell.notify_one();
        } // lg out of its scope = order.unlock()

        unique_lock<mutex> ul(order);
        orderBell.wait(ul, [ = ]() { return orderStatus == Status::ready; });
        orderStatus = Status::idle;
        ul.unlock();
        //serve the dishes
    }
};

int main() {
    Restaurant restaurant;
    thread chef(&Restaurant::chef, ref(restaurant));
    thread waiter(&Restaurant::waiter, ref(restaurant));
    chef.join();
    waiter.join();
    return 0;
}