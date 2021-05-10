#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

/**
 * \brief   Linked List - Single Line Method
 * 
 *          Rewrite the Naive Method in a single line by passing the next nodes
 *         as an argument to the newNode() function.-
 * 
 *          Diagram: 
 *            https://www.techiedelight.com/wp-content/uploads/Linked-List-Construction-2.png
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
 * \fn    Node* newNode(int key)
 * 
 * \brief Utility function to return new linked list node from the heap
  
 */
Node* newNode(int key, Node* next){
    // allocate a new node in a heap and set its data
    Node* node = new Node;
    node->key = key;
    // set the `.next` pointer of the new node to point to the current
    // first node of the list.
    node->next = next;
 
    return node;
}
 
/**
 * \fn      Node* constructExmpleList()
 * 
 * \brief   Function for linked list implementation containing three nodes

 */ 
Node* constructExmpleList(){
    Node* head = newNode(1, newNode(2, newNode(3, nullptr))); 
    // return a pointer to the first node in the list
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
    std::cout << "Linked Lists - Single Line method: " << std::endl;
    /*Declare, init and run*/
    // `head` points to the first node (also known as a head node) of a linked list
    Node *head = constructExmpleList();
    // print linked list
    printList(head);


    return 0;
}