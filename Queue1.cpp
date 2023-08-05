#include<iostream>
#include<vector>
using namespace std;

class Queue {
public:
    vector<int> vec;
    int front;
    int back;

    Queue() {
        back = -1;
        front = -1;
    }

    void enqueue(int data) {
        if (back == -1) {
            front = 0;
        }
        vec.push_back(data);
        back++;
    }

    void dequeue() {
        if (front == back) {
            front = -1;
            back = -1;
            vec.clear();
        }
        else {
            front++;
        }
    }

    int getfront() {
        if (front == -1) {
            return -1;
        }
        return vec[front];
    }

    bool isEmpty() {
        return front == -1;
    }
};

int main() {
    Queue qu;
    cout<<qu.isEmpty()<<endl;
    qu.enqueue(1);
    qu.enqueue(2);
    qu.enqueue(3);
    qu.dequeue();
    qu.enqueue(4);
    cout<<qu.isEmpty()<<endl;
    qu.dequeue();
    qu.dequeue();
    qu.dequeue();
    qu.enqueue(40);
    while(!qu.isEmpty()){
        cout<<qu.getfront()<<endl;
        qu.dequeue();
    }
    return 0;
}
