// Answer to Question 2
// Mechanism: Represents the integer stack with a singly linked list with a pointer to the last integer and an integer tracking the stack's size to make fundamental operations efficient.
#include <vector>
#include <iostream>
using namespace std;

// an element of the integer stack
class StackElement{
private: 
	int value;
	StackElement* next;
public:
	StackElement(int val) : value(val) { next = nullptr; };
	int getValue() const { return value; };
	StackElement* getNext() { return next; };
	void setNext(StackElement* nextElement) { next = nextElement; };
};

// a growable integer stack
class IntStack {
private:
	int stackSize;
	StackElement* stack;
	StackElement* lastInt;
public:
	// default an empty stack
	IntStack() : stackSize(0) {
		stack = nullptr;
		lastInt = stack;
	};

	// initialize a stack with a single element of specified value
	IntStack(int firstInt) : stackSize(1) {
		stack = new StackElement(firstInt);
		lastInt = stack;
	};

	// adds a given value to the top
	void push(int val) {
		StackElement* newInt = new StackElement(val);
		if (stack != nullptr)
			lastInt->setNext(newInt); // add the value to the stack
		else
			stack = newInt;
		lastInt = newInt; // update the last integer
		stackSize++; // update size of stack
	};

	// returns and removes the value at the top
	int pop() {
		if (size() == 0)
			exit(1);

		int topValue = lastInt->getValue(); //save the value at top for return
		if (size() == 1) {
			delete lastInt;
			stack = nullptr;
			lastInt = stack;
		}
		else {
			// find the second to last integer and update the last integer to it
			StackElement* newLast = stack;
			for (int i = 1; i < stackSize - 1; i++)
				newLast = newLast->getNext();
			newLast->setNext(nullptr); // prepare the new last integer
			delete lastInt; // delete the dynamic allocation
			lastInt = newLast; // update
		}

		stackSize--; // update size of stack
		return topValue;
	}

	// returns the value at the top
	int peek() {
		if (size() == 0)
			exit(1);
		return lastInt->getValue();
		
	};

	// returns the count of values
	int size() const {
		return stackSize;
	};

	// print stack for debugging
	void printStack() {
		if (size() == 0)
			cout << "Stack is empty!" << endl;
		else {
			cout << "A peak at the stack: " << peek() << endl;
			cout << "Here is my stack, from bottom to top, of size " << size() << ":";
			StackElement* thisInt = stack;
			while (true) {
				cout << " " << thisInt->getValue();
				if (thisInt->getNext() != nullptr)
					thisInt = thisInt->getNext();
				else {
					cout << endl;
					break;
				}
			}
		}
	};
};

int main() {
	IntStack myStack = IntStack();
	myStack.push(3);
	myStack.push(2);
	myStack.push(3);
	myStack.push(4);
	myStack.push(5);
	myStack.printStack(); // expecting 3 2 3 4 5
	myStack.pop();
	myStack.pop();
	myStack.pop();
	myStack.pop();
	myStack.printStack(); // expecting 3
	myStack.pop();
	myStack.printStack(); // expecting empty
};
