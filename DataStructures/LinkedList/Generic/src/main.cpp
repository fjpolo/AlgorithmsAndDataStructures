#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

/**
 * \brief   Linked List - Generic Method
 * 
 *          When the number of nodes is getting bigger, this is a better method than
 *         Naive or Single Line. If the keys are given in any container, such as an
 *         array, vector or set, we can easily construct a liked list by traversing
 *         the container.
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
 * \brief   Function for linked list implementation from a given set of keys


 */ 
Node* constructExmpleList(std::vector<int> const &keys){
    Node* head, *node = nullptr;
 
    // start from the end of the array
    for (auto key : keys){
        node = newNode(key, node);
        head = node;
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
    std::cout << "Linked Lists - Generic method: " << std::endl;
    /*Declare, init and run*/
    // input keys (in reverse order)
    std::vector<int> keys = { 4, 3, 2, 1 };
    // construct linked list
    Node *head = constructExmpleList(keys);
    // print linked list
    printList(head);


    return 0;
}