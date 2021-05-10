#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

/**
 * \brief   Linked List - Standard Solution
 * 
 *          Add a single node to the head end of any list. This function
 *         is called push(). Since we are adding the link to the head end,
 *         making a list looks like a stack.
 * 
 *          C++ has its built-in &argument feature to implement reference 
 *         parameters. If we append an & to the type parameter, the compiler
 *         will automatically make the parameter operate by reference without
 *         disturbing the arguments type.-
 * 
 *          References:              
 *            https://medium.com/techie-delight/top-algorithms-data-structures-concepts-every-computer-science-student-should-know-e0549c67b4ac
 *            https://www.techiedelight.com/linked-list-implementation-cpp/
 */
    
 
/**
 * \class   Node  
 * 
 * \brief   A Linked List Node
 */
class Node{
  public:
    int key;        // data field
    Node* next;     // pointer to the next node
};
 
/**
 * \fn      void push(Node* &headRef, int key)
 * 
 * \brief   push() in C++ — we just add `&` to the right-hand side of the head
 *         parameter type, and the compiler makes that parameter work by reference.
 *          
 *          So, this code changes the caller's memory, but no extra uses of `*` are
 *         necessary — we access "head" directly, and the compiler makes that
 *         change reference back to the caller.
 */
void push(Node* &headRef, int key){
    // allocate a new node in a heap and set its data
    Node* node = new Node;
    node->key = key;
 
    // set the `.next` pointer of the new node to point to the current
    // first node of the list.
 
    // no extra use of `*` necessary on the head — the compiler
    // takes care of it behind the scenes
    node->next = headRef;
 
    // change the head pointer to point to the new node, so it is
    // now the first node in the list.
    headRef = node;
}
 
/**
 * \fn      Node* constructList(vector<int> const &keys)
 * 
 * \brief   Function for linked list implementation from a given set of keys
 */ 
Node* constructList(std::vector<int> const &keys){
    Node* head = nullptr;
 
    // start from the end of the array
    for (int key: keys){
        // Note that no extra use `&` necessary — the compiler takes
        // care of it here too. These calls are changing the head.
        push(head, key);
    }
    return head;
}
 
/**
 * \fn        void printList(Node* head)
 * 
 * \brief     Helper function to print a linked list
   
 */
void printList(Node* head){
    Node* ptr = head;
    while (ptr){
        std::cout << ptr->key << " -> ";
        ptr = ptr->next;
    }
    std::cout << "nullptr";
}


/**
 * \fn main
 * 
 * \brief
 */
int main() {
    /*Say hi*/
    std::cout << "Linked Lists - Standard Solution: " << std::endl;
    /*Declare, init and run*/
    // input keys (in reverse order)
    std::vector<int> keys = { 4, 3, 2, 1 };
    // construct linked list
    Node *head = constructList(keys);
 
    // print linked list
    printList(head);


    return 0;
}