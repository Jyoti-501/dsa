#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    int top;
    int maxSize;
    T* stackArray;

public:
    // Constructor to initialize the stack
    Stack(int size) {
        maxSize = size;
        stackArray = new T[maxSize];
        top = -1;
    }

    // Destructor to clean up memory
    ~Stack() {
        delete[] stackArray;
    }

    // Check if the stack is full
    bool isFull() const {
        return top == maxSize - 1;
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return top == -1;
    }

    // Push operation
    void push(const T& item) {
        if (isFull()) {
            cout << "Stack is full! Cannot push " << item << "." << endl;
        } else {
            stackArray[++top] = item;
            cout << "Pushed: " << item << endl;
        }
    }

    // Pop operation
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty! Cannot pop." << endl;
        } else {
            cout << "Popped: " << stackArray[top--] << endl;
        }
    }

    // Return the top element of the stack
    T peek() const {
        if (isEmpty()) {
            cout << "Stack is empty! No top element." << endl;
            return T(); // Return default value of the template type
        } else {
            return stackArray[top];
        }
    }
};

int main() {
    // Stack for integers
    Stack<int> intStack(5);

    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    cout << "Top element: " << intStack.peek() << endl;

    intStack.pop();
    cout << "Top element after pop: " << intStack.peek() << endl;

    intStack.pop();
    intStack.pop();
    intStack.pop();  // Trying to pop from an empty stack

    return 0;
}
