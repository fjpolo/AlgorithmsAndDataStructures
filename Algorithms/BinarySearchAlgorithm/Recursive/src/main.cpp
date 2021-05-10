#include <cstdio>
#include <iostream>
#include <queue>

/**
 * \brief    Binary Search Algorithm - Recursive Implementation
 *          
 *           Given a sorted array on n intefers and a target value, determine
 *          if the target exists in the array or not, in  alogarithmic time, using
 *          the binary search algorithm. If target exists in the array, print the 
 *          index of it.      
 *              
 *          https://medium.com/techie-delight/top-algorithms-data-structures-concepts-every-computer-science-student-should-know-e0549c67b4ac
 *          https://www.techiedelight.com/binary-search/
 */
    

/**
 * \class     
 * 
 * \brief    
 */


/**
 * \fn       binarySearch   
 * 
 * \brief    Recursive implementation of the binary search algorithm to return 
 *          the position of target `x` in subarray `A[low…high]`  
 */
// 
int binarySearch(int A[], int low, int high, int x){
    // Base condition (search space is exhausted)
    if (low > high) {
        return -1;
    }
 
    // find the mid-value in the search space and
    // compares it with the target
 
    int mid = (low + high)/2;    // overflow can happen
    // int mid = low + (high - low)/2;
 
    // Base condition (target value is found)
    if (x == A[mid]) {
        return mid;
    }
 
    // discard all elements in the right search space,
    // including the middle element
    else if (x < A[mid]) {
        return binarySearch(A, low, mid - 1, x);
    }
 
    // discard all elements in the left search space,
    // including the middle element
    else {
        return binarySearch(A, mid + 1, high, x);
    }
}




/**
 * \fn main
 * 
 * \brief
 */
int main() {
    /*Say hi*/
    std::cout << "Binary Search Algorithm - Recursive Implementation: " << std::endl;
    /*Declare, init and run*/
    int A[] = { 2, 5, 6, 8, 9, 10 };
    int target = 5;
    int n = sizeof(A)/sizeof(A[0]);
    int low = 0, high = n - 1;
    int index = binarySearch(A, low, high, target);
 
    /*Check if found and print*/
    if (index != -1) {
        std::cout << "Element found at index " << index << std::endl;
    }
    else {
        std::cout << "Element not found in the array" << std::endl;
    }
    std::cout << "Complexity: O(log2n)" << std::endl;

    return 0;
}