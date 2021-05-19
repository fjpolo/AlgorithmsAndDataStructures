#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

/**/
constexpr auto SIZE = 10;

/**
 * \brief   Stack - Template arrays
 * 
 *          Stack with generic data to support alldata types.-
 * 
 *          References:              
 *            https://medium.com/techie-delight/top-algorithms-data-structures-concepts-every-computer-science-student-should-know-e0549c67b4ac
 *            https://www.techiedelight.com/stack-implementation-using-templates/
 */
    
 
/**
 * \class   stack  
 * 
 * \brief   A class to represent a Stack.-
 */
template <class X>
class stack{
private:
    X *arr;
    int top;
    int capacity;
 
public:
    stack(int size = SIZE);         // constructor
 
    void push(X);
    X pop();
    X peek();
 
    int size();
    bool isEmpty();
    bool isFull();
 
    // destructor
    ~stack() {
        delete[] arr;
    }
};
 
// Constructor to initialize the stack
template <class X>
stack<X>::stack(int size){
    arr = new X[size];
    capacity = size;
    top = -1;
}
 
// Function to add an element `x` to the stack
template <class X>
void stack<X>::push(X x){
    if (isFull())
    {
        std::cout << "Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
 
    std::cout << "Inserting " << x << std::endl;
    arr[++top] = x;
}
 
// Function to pop the top element from the stack
template <class X>
X stack<X>::pop(){
    // check for stack underflow
    if (isEmpty())
    {
        std::cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
 
    std::cout << "Removing " << peek() << std::endl;
 
    // decrease stack size by 1 and (optionally) return the popped element
    return arr[top--];
}
 
// Function to return the top element of the stack
template <class X>
X stack<X>::peek(){
    if (!isEmpty()) {
        return arr[top];
    }
    else {
        exit(EXIT_FAILURE);
    }
}
 
// Utility function to return the size of the stack
template <class X>
int stack<X>::size() {
    return top + 1;
}
 
// Utility function to check if the stack is empty or not
template <class X>
bool stack<X>::isEmpty() {
    return top == -1;               // or return size() == 0;
}
 
// Utility function to check if the stack is full or not
template <class X>
bool stack<X>::isFull() {
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
    std::cout << "Stack - Template arrays: " << std::endl;
    /*Declare, init and run*/
    stack<std::string> pt(2);
    /*Push*/
    pt.push("A");
    pt.push("B");
    /*Pop*/
    pt.pop();
    pt.pop();
    /*Push*/
    pt.push("C");
    // Prints the top of the stack
    std::cout << "The top element is " << pt.peek() << std::endl;
    // Returns the total number of elements present in the stack
    std::cout << "The stack size is " << pt.size() << std::endl;
    /*Pop*/
    pt.pop();
    // check if the stack is empty or not
    if (pt.isEmpty()) {
        std::cout << "The stack is empty\n";
    }
    else {
        std::cout << "The stack is not empty\n";
    }



    return 0;
}