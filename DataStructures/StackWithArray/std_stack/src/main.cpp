#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <stack>




/**
 * \brief   Stack - std::stack
 * 
 *          Stack implemented using std::stack
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
    std::cout << "Stack - std::stack : " << std::endl;
    /*Declare, init and run*/
    std::stack<std::string> s;
    s.push("A");    // Insert `A` into the stack
    s.push("B");    // Insert `B` into the stack
    s.push("C");    // Insert `C` into the stack
    s.push("D");    // Insert `D` into the stack
    // returns the total number of elements present in the stack
    std::cout << "The stack size is " << s.size() << std::endl;
    // prints the top of the stack (`D`)
    std::cout << "The top element is " << s.top() << std::endl;
    s.pop();        // removing the top element (`D`)
    s.pop();        // removing the next top (`C`)
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