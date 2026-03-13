//Design Circular Queue
#include <iostream>
#include <vector>
using namespace std;
class MyCircularQueue {
public:
    vector<int> q;
    int front, rear, size;

    MyCircularQueue(int k) {
        q.resize(k);
        front = rear = -1;
        size = k;
    }

    bool enQueue(int value) {
        if (isFull())
            return false;

        if (isEmpty())
            front = 0;

        rear = (rear + 1) % size;
        q[rear] = value;

        return true;
    }

    bool deQueue() {
        if (isEmpty())
            return false;

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % size;

        return true;
    }

    int Front() {
        if (isEmpty())
            return -1;

        return q[front];
    }

    int Rear() {
        if (isEmpty())
            return -1;

        return q[rear];
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return ((rear + 1) % size) == front;
    }
};
int main() {

    MyCircularQueue* obj = new MyCircularQueue(3);
    cout << obj->enQueue(1) << endl;
    cout << obj->enQueue(2) << endl;
    cout << obj->enQueue(3) << endl;
    cout << obj->enQueue(4) << endl;
    cout << obj->Rear() << endl;
    cout << obj->isFull() << endl;
    cout << obj->deQueue() << endl;
    cout << obj->enQueue(4) << endl;
    cout << obj->Rear() << endl;

    return 0;
}
