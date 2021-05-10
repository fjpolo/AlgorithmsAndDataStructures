#include <cstdio>
#include <iostream>
#include <queue>

/**
 * \brief    Binary Search Algorithm - Iterative Implementation
 *          
 *           Given a sorted array on n intefers and a target value, determine
 *          if the target exists in the array or not, in  alogarithmic time, using
 *          the binary search algorithm. If target exists in the array, print the 
 *          index of it.      
 *              
 *          <https://medium.com/techie-delight/top-algorithms-data-structures-concepts-every-computer-science-student-should-know-e0549c67b4ac
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
 * \brief    Iterative implementation of the binary search algorithm to return
 *          the position of target `x` in array `A` of size `n`    
 */
// 
int binarySearch(int A[], int n, int x){
    // search space is `A[low…high]`
    int low = 0, high = n - 1;
 
    // loop till the search space is exhausted
    while (low <= high){
        // find the mid-value in the search space and
        // compares it with the target
 
        int mid = (low + high)/2;    // overflow can happen
        // int mid = low + (high - low)/2;
        // int mid = high - (high - low)/2;
 
        // target value is found
        if (x == A[mid]) {
            return mid;
        }
 
        // if the target is less than the middle element, discard all elements
        // in the right search space, including the middle element
        else if (x < A[mid]) {
            high = mid - 1;
        }
 
        // if the target is more than the middle element, discard all elements
        // in the left search space, including the middle element
        else {
            low = mid + 1;
        }
    }
    // target doesn't exist in the array
    return -1;
}




/**
 * \fn main
 * 
 * \brief
 */
int main() {
    /*Say hi*/
    std::cout << "Binary Search Algorithm - Iterative Implementation: " << std::endl;
    /*Declare, init and run*/
    int A[] = { 2, 5, 6, 8, 9, 10 };
    int target = 5;
    int n = sizeof(A)/sizeof(A[0]);
    int index = binarySearch(A, n, target);
    /*Check for error*/
    if (index != -1) {
        std::cout << "Element found at index " << index << std::endl;
    }
    else {
        std::cout << "Element not found in the array" << std::endl;
    }
    std::cout << "Complexity: O(1)" << std::endl;

    return 0;
}