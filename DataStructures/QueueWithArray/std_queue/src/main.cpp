#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <queue>



/**/
constexpr auto SIZE = 128;

/**
 * \brief   Queue - std::queue
 * 
 *          Queue implemented using std::queue
 * 
 *          References:              
 *            https://medium.com/techie-delight/top-algorithms-data-structures-concepts-every-computer-science-student-should-know-e0549c67b4ac
 *            https://www.techiedelight.com/queue-implementation-cpp/
 */
    
 
/**
 * \class     
 * 
 * \brief   
 */

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
    std::cout << "Queue - std::queue : " << std::endl;
    /*Declare, init and run*/
    std::queue<std::string> q;
    /*Push*/
    q.push("A");        // Insert `A` into the queue
    q.push("B");        // Insert `B` into the queue
    q.push("C");        // Insert `C` into the queue
    q.push("D");        // Insert `D` into the queue
    // Returns the total number of elements present in the queue
    std::cout << "The queue size is " << q.size() << std::endl;
    // Prints the front of the queue (`A`)
    std::cout << "The front element is " << q.front() << std::endl;
    // Prints the rear of the queue (`D`)
    std::cout << "The rear element is " << q.back() << std::endl;
    /*Pop*/
    q.pop();            // removing the front element (`A`)
    q.pop();            // removing the next front element (`B`)
    /**/
    std::cout << "The queue size is " << q.size() << std::endl;
    // check if the queue is empty
    if (q.empty()) {
        std::cout << "The queue is empty\n";
    }
    else {
        std::cout << "The queue is not empty\n";
    }

    


    return 0;
}