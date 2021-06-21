#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

/**/
constexpr auto SIZE = 128;

/**
 * \brief   Queue - Template arrays
 * 
 *          Queue with generic data to support alldata types.-
 * 
 *          References:              
 *            https://medium.com/techie-delight/top-algorithms-data-structures-concepts-every-computer-science-student-should-know-e0549c67b4ac
 *            https://www.techiedelight.com/queue-implementation-using-templates-cpp/
 */
    
 
/**
 * \class   queue  
 * 
 * \brief   A class to represent a queue.-
 */
template <class X>
class queue{
    private:
        X *arr;                     // array to store queue elements
        int capacity;               // maximum capacity of the queue
        int front;                  // front points to the front element in the queue (if any)
        int rear;                   // rear points to the last element in the queue
        int count;                  // current size of the queue
    public:
        queue(int size = SIZE);     // constructor
        ~queue();                   // destructor
        void dequeue();             // dequeue
        void enqueue(X x);          // enqueue
        X peek();                   // peek
        int getSize();              // get size
        bool isEmpty();             // check if empty
        bool isFull();              // check if full
};

// Constructor to initialize a queue
template <class X>
queue<X>::queue(int size){
    arr = new X[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

// Destructor
template <class X>
queue<X>::~queue(){}

// Utility function to dequeue the front element
template <class X>
void queue<X>::dequeue(){
    /*Check for queue underflow*/
    if (isEmpty()){
        std::cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    /*Talk to the user*/
    std::cout << "Removing " << arr[front] << std::endl;
    /*Increment front counter*/
    front = (front + 1) % capacity;
    /*Decrement count for size*/
    count--;
}

// Utility function to add an item to the queue
template <class X>
void queue<X>::enqueue(X item){
    /*Check for queue overflow*/
    if (isFull()){
        std::cout << "Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    /*Talk to the user*/
    std::cout << "Inserting " << item << std::endl;
    /*Increment rear counter*/
    rear = (rear + 1) % capacity;
    /*Enqueue new item*/
    arr[rear] = item;
    /*Increment size counter*/
    count++;
}

// Utility function to return the front element of the queue
template <class X>
X queue<X>::peek(){
    /*Empty queue*/
    if (isEmpty()){
        std::cout << "UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    /*Return current item*/
    return arr[front];
}

// Utility function to return the size of the queue
template <class X>
int queue<X>::getSize() {
    return count;
}

// Utility function to check if the queue is empty or not
template <class X>
bool queue<X>::isEmpty() {
    return (getSize() == 0);
}

// Utility function to check if the queue is full or not
template <class X>
bool queue<X>::isFull() {
    return (getSize() == capacity);
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
    std::cout << "Queue - Template arrays: " << std::endl;
    /*Declare, init and run*/


    // create a queue of capacity 4
    queue<std::string> q(4);
 
    q.enqueue("a");
    q.enqueue("b");
    q.enqueue("c");
 
    std::cout << "The front element is " << q.peek() << std::endl;
    q.dequeue();
 
    q.enqueue("d");
 
    std::cout << "The queue size is " << q.getSize() << std::endl;
 
    q.dequeue();
    q.dequeue();
    q.dequeue();
 
    if (q.isEmpty()) {
        std::cout << "The queue is empty\n";
    }
    else {
        std::cout << "The queue is not empty\n";
    }


    return 0;
}