//Implement a first in first out(FIFO) queue using only two stacks.
//The implemented queue should support all the functions of a normal queue(push, peek, pop, and empty).
//
//Implement the MyQueue class :
//
//    void push(int x) Pushes element x to the back of the queue.
//    int pop() Removes the element from the front of the queue and returns it.
//    int peek() Returns the element at the front of the queue.
//    boolean empty() Returns true if the queue is empty, false otherwise.
//    Notes :
//
//You must use only standard operations of a stack, 
//which means only push to top, peek / pop from top, size, and is empty operations are valid.
//Depending on your language, the stack may not be supported natively.
//You may simulate a stack using a list or deque(double - ended queue)
//as long as you use only a stack's standard operations.


#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> main;
    stack<int> store;

    MyQueue() {
        
    }

    void push(int x) {
        main.push(x);
    }

    int pop() {
        int value = 0;

        while (!main.empty()) {
            store.push(main.top());
            main.pop();
        }

        value = store.top();
        store.pop();

        while (!store.empty()) {
            main.push(store.top());
            store.pop();
        }

        return value;
    }

    int peek() {
        int value = 0;

        while (!main.empty()) {
            store.push(main.top());
            main.pop();
        }

        value = store.top();

        while (!store.empty()) {
            main.push(store.top());
            store.pop();
        }

        return value;
    }

    bool empty() {
        return main.empty();
    }
};
