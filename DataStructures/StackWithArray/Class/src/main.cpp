#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstdlib>
using namespace std;
 
// Define the default capacity of the stack
#define SIZE 10
 
// A class to represent a stack
class stack{
    int *arr;
    int top;
    int capacity;
 
public:
    stack(int size = SIZE);         // constructor
    ~stack();                       // destructor
 
    void push(int);
    int pop();
    int peek();
 
    int size();
    bool isEmpty();
    bool isFull();
};
 
// Constructor to initialize the stack
stack::stack(int size){
    arr = new int[size];
    capacity = size;
    top = -1;
}
 
// Destructor to free memory allocated to the stack
stack::~stack() {
    delete[] arr;
}
 
// Utility function to add an element `x` to the stack
void stack::push(int x){
    if (isFull()){
        std::cout << "Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
 
    std::cout << "Inserting " << x << std::endl;
    arr[++top] = x;
}
 
// Utility function to pop a top element from the stack
int stack::pop(){
    // check for stack underflow
    if (isEmpty()){
        std::cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
 
    std::cout << "Removing " << peek() << std::endl;
 
    // decrease stack size by 1 and (optionally) return the popped element
    return arr[top--];
}
 
// Utility function to return the top element of the stack
int stack::peek(){
    if (!isEmpty()) {
        return arr[top];
    }
    else {
        exit(EXIT_FAILURE);
    }
}
 
// Utility function to return the size of the stack
int stack::size(){
    return top + 1;
}
 
// Utility function to check if the stack is empty or not
bool stack::isEmpty(){
    return top == -1;               // or return size() == 0;
}
 
// Utility function to check if the stack is full or not
bool stack::isFull(){
    return top == capacity - 1;     // or return size() == capacity;
}

/**
 * \fn    
 * 
 * \brief   
 */

 



/**
 * \fn main
 * 
 * \brief
 */
int main() {
    /*Say hi*/
    std::cout << "Stack - Class implementation : " << std::endl;
    /*Declare, init and run*/

    stack pt(3);
    /*Push*/
    pt.push(1);
    pt.push(2);
    /*Pop*/
    pt.pop();
    pt.pop();
    /*Push*/
    pt.push(3);
    /*Print*/
    std::cout << "The top element is " << pt.peek() << std::endl;
    std::cout << "The stack size is " << pt.size() << std::endl;
    /*Pop*/
    pt.pop();
    /**/
    if (pt.isEmpty()) {
        std::cout << "The stack is empty\n";
    }
    else {
        std::cout << "The stack is not empty\n";
    }



    return 0;
}