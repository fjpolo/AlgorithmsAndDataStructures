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
struct Node{
    int data;               // integer data
    struct Node* next;      // pointer to the next node
};


/**
 * \class  queue  
 * 
 * \brief   A queue class.-
 */
class queue{
    private:
        Node* rear;
        Node* front;
        struct Node* newNode(int item);

    public:
        queue();
        ~queue();
        int dequeue();
        void enqueue(int item);
        int peek();
        int isEmpty();


};
// Constructor
queue::queue(){
   rear = nullptr;
   front = nullptr;
}
// Destructor
queue::~queue(){
   // Still need to delete every node created 
   while(rear != nullptr){
       dequeue();
   }
   /**/
   rear = nullptr;
   front = nullptr;
}
// Utility function to dequeue the front element
struct Node* queue::newNode(int item){
    // allocate a new node in a heap
    Node* node = new Node{};
 
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
        printf("\nHeap Overflow");
        exit(EXIT_FAILURE);
    }
}
// Utility function to dequeue the front element
int queue::dequeue(){
    if (front == nullptr){
        std::cout << "\nQueue Underflow" << std::endl;
        exit(EXIT_FAILURE);
    }
 
    struct Node* temp = front;
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
void queue::enqueue(int item){
    // allocate a new node in a heap
    struct Node* node = newNode(item);
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
int queue::peek(){
    // check for an empty queue
    if (front != nullptr) {
        return front->data;
    }
    else {
        exit(EXIT_FAILURE);
    }
}
// Utility function to check if the queue is empty or not
int queue::isEmpty(){
    return rear == nullptr && front == nullptr;
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
    queue myQueue{};

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

