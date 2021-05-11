#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <list>



/**/
constexpr auto SIZE = 128;

/**
 * \brief   Queue - Class implementation
 * 
 *          Queue implemented using a class.-
 * 
 *          References:              
 *            https://medium.com/techie-delight/top-algorithms-data-structures-concepts-every-computer-science-student-should-know-e0549c67b4ac
 *            https://www.techiedelight.com/queue-implementation-cpp/
 */
    
 
/**
 * \class   queue 
 * 
 * \brief   A class to store a queue
 */
class queue{
    private:
        int *arr;
        int capacity;
        int count;
        int front;
        int rear;
    public:
        queue(int size = SIZE);
        ~queue();
        void enqueue(int x);
        void dequeue();
        int getSize();
        int peek();
        bool isEmpty();
        bool isFull();
};

/*Constructor to initialize a queue*/
queue::queue(int size){
    arr = new int[size];
    capacity = size;
    count = 0;
    front = 0;
    rear = -1;
}
/*Queue class destructor*/
queue::~queue(){
    delete[] arr;
}
/*Utility function to add an item to the queue*/
void queue::enqueue(int x){
    /*Queue full*/
    if(isFull()){
        std::cout << "Underflow\nProgram Terminated" << std::endl;
        exit(EXIT_FAILURE);
    }
    /**/
    std::cout << "Inserting " << x << std::endl;
    /*Icrement rear*/
    rear = (rear+1) % capacity;
    /*Enqueue item*/
    arr[rear] = x;
    /*Increment size counter*/
    count++;
}
/*Utility function to dequeue the front element*/
void queue::dequeue(){
    /*Empty queue*/
    if (isEmpty()){
        std::cout << "Underflow\nProgram Terminated" << std::endl;
        exit(EXIT_FAILURE);
    }
    /**/
    std::cout << "Removing " << arr[front] << std::endl;
    /*Increment front*/
    front = (front + 1) % capacity;
    /*DEcrement size counter*/
    count--;
}
/*Utility function to return the size of the queue*/
int queue::getSize(){
    return count;
}
/*Utility function to return the front element of the queue*/
int queue::peek(){
    /*Queue empty*/
    if(isEmpty()){
        std::cout << "Underflow\nProgram Terminated" << std::endl;
        exit(EXIT_FAILURE);
    }
    return arr[front];
}
/*Utility function to check if the queue is empty or not*/
bool queue::isEmpty(){
    return (getSize() == 0);
}
/*Utility function to check if the queue is full or not*/
bool queue::isFull(){
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
    std::cout << "Queue - Class implementation : " << std::endl;
    /*Declare, init and run*/


    /*Create a queue of capacity 5*/
    queue q(5);
    /*Enqueue*/
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    /**/
    std::cout << "The front element is " << q.peek() << std::endl;
    /*Dequeue*/
    q.dequeue();
    q.enqueue(4);
    /**/
    std::cout << "The queue size is " << q.getSize() << std::endl;
    /*Dequeue*/
    q.dequeue();
    q.dequeue();
    q.dequeue();
    /**/
    if (q.isEmpty()) {
        std::cout << "The queue is empty\n";
    }
    else {
        std::cout << "The queue is not empty\n";
    }


    return 0;
}