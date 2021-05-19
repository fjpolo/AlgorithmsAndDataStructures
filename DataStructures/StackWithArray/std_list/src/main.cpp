#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <list>



/**/
constexpr auto SIZE = 128;

/**
 * \brief   Stack - std::list
 * 
 *          Stack implemented using std::list
 * 
 *          References:              
 *            https://medium.com/techie-delight/top-algorithms-data-structures-concepts-every-computer-science-student-should-know-e0549c67b4ac
 *            https://www.techiedelight.com/stack-implementation-in-cpp/
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
    std::cout << "Stack - std::list : " << std::endl;
    /*Declare, init and run*/
    std::list<std::string> s;
    s.push_front("A");        // Insert `A` into the stack
    s.push_front("B");        // Insert `B` into the stack
    s.push_front("C");        // Insert `C` into the stack
    s.push_front("D");        // Insert `D` into the stack
    // returns the total number of elements present in the stack
    std::cout << "The stack size is " << s.size() << std::endl;
    // prints the top of the stack (`D`)
    std::cout << "The top element is " << s.front() << std::endl;
    s.pop_front();          // removing the top element (`D`)
    s.pop_front();          // removing the next top (`C`)
    std::cout << "The stack size is " << s.size() << std::endl;
    // check if the stack is empty
    if (s.empty()) {
        std::cout << "The stack is empty\n";
    }
    else {
        std::cout << "The stack is not empty\n";
    }

    


    return 0;
}