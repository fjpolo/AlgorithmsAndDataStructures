#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <list>



/**/
constexpr auto SIZE = 128;

/**
 * \brief   Queue - std::list
 * 
 *          Queue implemented using std::list
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
    std::cout << "Queue - std::list : " << std::endl;
    /*Declare, init and run*/
    std::list<std::string> q;
    /*Push back*/
    q.push_back("A");        // Insert `A` into the queue
    q.push_back("B");        // Insert `B` into the queue
    q.push_back("C");        // Insert `C` into the queue
    q.push_back("D");        // Insert `D` into the queue
    // Returns the total number of elements present in the queue
    std::cout << "The queue size is " << q.size() << std::endl;
    // Prints the front of the queue (`A`)
    std::cout << "The front element is " << q.front() << std::endl;
    // Prints the rear of the queue (`D`)
    std::cout << "The rear element is " << q.back() << std::endl;
    /*Pop front*/
    q.pop_front();          // removing the front element (`A`)
    q.pop_front();          // removing the next front element (`B`)
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