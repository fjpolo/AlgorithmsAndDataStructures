#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

/**
 * \brief   Queue - Linked List
 * 
 *          A queue is a linear data structure that serves as a collection of elements, 
 *         with three main operations: enqueue, dequeue and peek. 
 * 
 *          A queue can be easily implemented using a liked list. In singly linked
 *         list implementation, enqueuing happens at the tail of the list, and the
 *         dequeuing of items happens at the head of the list. We need a pointer to
 *         the laswt node to keep O(1) efficiency for insertion.
 * 
 *          Since a doubly linked list offers O(1) insertion and deletion at both ends,
 *         use it if we want to enqueue tohappen at the beginning and dequeing
 *         at the tail of the linked list.
 * 
 *          References:              
 *            https://medium.com/techie-delight/top-algorithms-data-structures-concepts-every-computer-science-student-should-know-e0549c67b4ac
 *            https://www.techiedelight.com/queue-implementation-using-linked-list/ 
 */
    

/**
 * \struct  Node  
 * 
 * \brief   A Linked List Node
 */
template <typename X>
struct Node{
    X data;               // integer data
    struct Node* next;      // pointer to the next node
};


/**
 * \class  queue  
 * 
 * \brief   A queue class.-
 */
template <class X>
class queue{
    private:
        Node<X>* rear;
        Node<X>* front;
        struct Node<X>* newNode(X item);

    public:
        queue();
        ~queue();
        X dequeue();
        void enqueue(X item);
        X peek();
        bool isEmpty();


};
// Constructor
template <class X>
queue<X>::queue(){
   rear = nullptr;
   front = nullptr;
}
// Destructor
template <class X>
queue<X>::~queue(){
   // Still need to delete every node created 
   while(rear != nullptr){
       dequeue();
   }
   /**/
   rear = nullptr;
   front = nullptr;
}
// Utility function to dequeue the front element
template <class X>
struct Node<X>* queue<X>::newNode(X item){
    // allocate a new node in a heap
    Node<X>* node = new Node<X>{};
 
    // check if the queue (heap) is full. Then inserting an element would
    // lead to heap overflow
    if (node != nullptr)
    {
        // set data in the allocated node and return it
        node->data = item;
        node->next = nullptr;
        return node;
    }
    else {
        std::cout << "\nHeap Overflow";
        exit(EXIT_FAILURE);
    }
}
// Utility function to dequeue the front element
template <class X>
X queue<X>::dequeue(){
    if (front == nullptr){
        std::cout << "\nQueue Underflow" << std::endl;
        exit(EXIT_FAILURE);
    }
 
    struct Node<X>* temp = front;
    std::cout << "Removing " << temp->data << std::endl;
 
    // advance front to the next node
    front = front->next;
 
    // if the list becomes empty
    if (front == nullptr) {
        rear = nullptr;
    }
 
    // deallocate the memory of the removed node and
    // optionally return the removed item
    int item = temp->data;
    delete temp;
    return item;
}
// Utility function to add an item to the queue
template <class X>
void queue<X>::enqueue(X item){
    // allocate a new node in a heap
    struct Node<X>* node = newNode(item);
    std::cout << "Inserting " << item << std::endl;
 
    // special case: queue was empty
    if (front == nullptr){
        // initialize both front and rear
        front = node;
        rear = node;
    }
    else {
        // update rear
        rear->next = node;
        rear = node;
    }
}
// Utility function to return the top element in a queue
template <class X>
X queue<X>::peek(){
    // check for an empty queue
    if (front != nullptr) {
        return front->data;
    }
    else {
        exit(EXIT_FAILURE);
    }
}
// Utility function to check if the queue is empty or not
template <class X>
bool queue<X>::isEmpty(){
    return (rear == nullptr && front == nullptr);
}




/**
 * \fn main
 * 
 * \brief
 */
int main(){
    /*Say hi*/
    std::cout << "Queue - Linked List: " << std::endl;
    /*Declare, init and run*/

    /*Declare and init queue*/
    queue<int> myQueue{};

    /*Enqueue*/
    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.enqueue(4);
    /**/
    std::cout << "The front element is " << myQueue.peek() << std::endl;
    /*Dequeue*/
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();
    /**/
    if (myQueue.isEmpty()) {
        std::cout << "The queue is empty" << std::endl;
    }
    else {
        std::cout << "The queue is not empty" << std::endl;
    }
 
    return 0;
}

