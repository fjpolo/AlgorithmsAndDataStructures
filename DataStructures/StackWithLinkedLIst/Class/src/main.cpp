#include <cstdio>
#include <iostream>


/**
 * \brief   Stack - Linked List
 * 
 *          A stack is a linear data structure that serves as a collection of elements,
 *         with three main operations: pop, push and peek. We can easily implement
 *         a stack with a linked list. A stack is a pointer to the head of the list
 *         where pushing and popping items happens, with perhaps a counter to 
 *         keep track of the size.
 * 
 *          The advantage of using a liked list over arrays is that it is possible to
 *         implement a stack that can grow or shrink as much as needed. Using anarray
 *         will restrict the maximum capacity of the array, which can lead to stack
 *         overflow. Here each new node will be dinamically allocated, so overflow
 *          is not possible unless memory is exhausted.-
 * 
 *          References:              
 *            https://medium.com/techie-delight/top-algorithms-data-structures-concepts-every-computer-science-student-should-know-e0549c67b4ac
 *            https://www.techiedelight.com/stack-implementation-using-linked-list/ 
 */
    

/**
 * \struct  Node  
 * 
 * \brief   A Linked List Node
 */
struct Node{
    int data;               // integer data
    struct Node* next;      // pointer to the next node
};


/**
 * \class  stack  
 * 
 * \brief   A stack class.-
 */
class stack{
    private:
        Node* top;

    public:
        stack();
        ~stack();
        void push(int x);
        int isEmpty();
        int peek();
        void pop();
};
// Constructor
stack::stack(){
    top = NULL;
}

// Destructor
stack::~stack(){
    while(!isEmpty()){
        pop();
    }
}

// Utility function to add an element `x` to the stack
void stack::push(int x)        // insert at the beginning
{
    // allocate a new node in a heap
    struct Node* node = NULL;
    node = (struct Node*)malloc(sizeof(struct Node));
 
    // check if stack (heap) is full. Then inserting an element would
    // lead to stack overflow
    if (!node){
        printf("\nHeap Overflow");
        exit(1);
    }
 
    printf("Inserting %d\n", x);
 
    // set data in the allocated node
    node->data = x;
 
    // set the `.next` pointer of the new node to point to the current
    // top node of the list
    node->next = top;
 
    // update top pointer
    top = node;
}
 
// Utility function to check if the stack is empty or not
int stack::isEmpty() {
    return (top == NULL);
}
 
// Utility function to return the top element of the stack
int stack::peek(){
    // check for an empty stack
    if (!isEmpty()) {
        return top->data;
    }
    else {
        exit(EXIT_FAILURE);
    }
}
 
// Utility function to pop a top element from the stack
void stack::pop()        // remove at the beginning
{
    struct Node *node;
 
    // check for stack underflow
    if (top == NULL){
        printf("\nStack Underflow");
        exit(1);
    }
 
    printf("Removing %d\n", peek());
 
    node = top;
 
    // update the top pointer to point to the next node
    top = top->next;
 
    // free allocated memory
    free(node);
}

/**
 * \fn main
 * 
 * \brief
 */
int main(){
    /*Say hi*/
    std::cout << "Stack - Linked List: " << std::endl;
    /*Declare, init and run*/

    stack s{};
    /*Push*/
    s.push(1);
    s.push(3);
    s.push(2);
    /*Print*/
    printf("The top element is %d\n", s.peek());
    /*Pop*/
    s.pop();
    s.pop();
    s.pop();
    /**/
    if (s.isEmpty()) {
        printf("The stack is empty");
    }
    else {
        printf("The stack is not empty");
    }
 
    return 0;
}

