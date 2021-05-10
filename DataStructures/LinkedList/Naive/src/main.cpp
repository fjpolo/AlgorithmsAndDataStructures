#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

/**
 * \brief   Linked List - Naive Method
 * 
 *          A simple solution would be to allocate memory for all individual
 *         nodes of the linked list, set their data and rearrange their pointers
 *         to build the complete list.
 * 
 *          Diagram: 
 *            https://www.techiedelight.com/wp-content/uploads/Linked-List-Construction.png
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
Node* newNode(int key){
    // allocate a new node in a heap and set its data
    Node* node = new Node;
    node->key = key;
 
    // `.next` pointer of the new node points to nothing
    node->next = nullptr;
 
    return node;
}
 
/**
 * \fn      Node* constructExmpleList()
 * 
 * \brief   Function for linked list implementation containing three nodes

 */ 
Node* constructExmpleList(){
    // construct three linked list nodes
    Node* first = newNode(1);
    Node* second = newNode(2);
    Node* third = newNode(3);
 
    // rearrange the pointers to construct a list
    Node* head = first;
    first->next = second;
    second->next = third;
 
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
    std::cout << "Linked Lists - Naive method: " << std::endl;
    /*Declare, init and run*/
    // `head` points to the first node (also known as a head node) of a linked list
    Node *head = constructExmpleList();
    // print linked list
    printList(head);


    return 0;
}