#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>

/**
 * \brief    Kadane’s Algorithm - Maximum Sum Subarray Problem 
 *
 *           Given an integer array, find contiguous subarray within it that has the largest 
 *          sum.
 *
 *           Example:
 *          
 *           Input:  {-2, 1, -3, 4, -1, 2, 1, -5, 4}
 *           Output: Subarray with the largest sum is {4, -1, 2, 1} with sum 6.-
 *          
 *          
 *              
 *          https://medium.com/techie-delight/top-algorithms-data-structures-concepts-every-computer-science-student-should-know-e0549c67b4ac
 *          https://www.techiedelight.com/maximum-subarray-problem-kadanes-algorithm/
 */


/**
 * \typedef     
 * 
 * \brief  
 */

 
/**
 * \class     
 * 
 * \brief   
 */

 
/**
 * \fn  kadaneSemifull 
 * 
 * \brief Function to find the maximum sum of a contiguous subarray
 *       in a given integer array 
 */
int kadaneSemifull(int arr[], int n){
    /**
     *  The idea is to mantain a maximum (ositive-sum) subarray "ending" at each index
     * of the given array. This subarray is either empty ( in wich case it sum is zero)
     * or consists of one more element than the maximum subarray ending at the previous
     * index.
     *
     *  The time complexity is O(n) and doesn't require any extra space, where n is the 
     * size of the input.-
     *
     *  This version doesn't handle the case when all the array elements are negative.
     * If the array contains all negative values, the answer is the maximum element.
     *
     */

    // stores the maximum sum subarray found so far
    int max_so_far = 0;
 
    // stores the maximum sum of subarray ending at the current position
    int max_ending_here = 0;
 
    // traverse the given array
    for (int i = 0; i < n; ++i)
    {
        // update the maximum sum of subarray "ending" at index `i` (by adding the
        // current element to maximum sum ending at previous index `i-1`)
        max_ending_here = max_ending_here + arr[i];
 
        // if the maximum sum is negative, set it to 0 (which represents
        // an empty subarray)
        max_ending_here = std::max(max_ending_here, 0);
 
        // update the result if the current subarray sum is found to be greater
        max_so_far = std::max(max_so_far, max_ending_here);
    }
 
    return max_so_far;
}

/**
 * \fn  kadaneTraversal 
 * 
 * \brief Function to find the maximum sum of a contiguous subarray
 *       in a given integer array 
 */
// int kadaneTraversal(int arr[], int n){
//     /**
//      *  This approach requires two traverals of the input array.
//      *
//      */

//     // find the maximum element present in a given array
//     int max_num = *max_element(arr, arr + n);
 
//     // if the array contains all negative values, return the maximum element
//     if (max_num < 0) {
//         return max_num;
//     }
 
//     // stores the maximum sum subarray found so far
//     int max_so_far = 0;
 
//     // stores the maximum sum of subarray ending at the current position
//     int max_ending_here = 0;
 
//     // traverse the given array
//     for (int i = 0; i < n; i++)
//     {
//         // update the maximum sum of subarray "ending" at index `i` (by adding the
//         // current element to maximum sum ending at previous index `i-1`)
//         max_ending_here = max_ending_here + arr[i];
 
//         // if the maximum sum is negative, set it to 0 (which represents
//         // an empty subarray)
//         max_ending_here = max(max_ending_here, 0);
 
//         // update the result if the current subarray sum is found to be greater
//         max_so_far = max(max_so_far, max_ending_here);
//     }
 
//     return max_so_far;
// }

/**
 * \fn  kadaneNeg 
 * 
 * \brief Function to find the maximum sum of a contiguous subarray
 *       in a given integer array (handles negative numbers as well)
 */
int kadaneNeg(int arr[], int n){
    // stores the maximum sum subarray found so far
    int max_so_far = arr[0];
 
    // stores the maximum sum of subarray ending at the current position
    int max_ending_here = arr[0];
 
    // traverse the given array
    for (int i = 1; i < n; i++)
    {
        // update the maximum sum of subarray "ending" at index `i` (by adding the
        // current element to maximum sum ending at previous index `i-1`)
        max_ending_here += arr[i];
 
        // maximum sum should be more than the current element
        max_ending_here = std::max(max_ending_here, arr[i]);
 
        // update the result if the current subarray sum is found to be greater
        max_so_far = std::max(max_so_far, max_ending_here);
    }
 
    return max_so_far;
}






/**
 * \fn main
 * 
 * \brief
 */
int main() {
    /*Say hi*/
    std::cout << "Kadane’s Algorithm - Maximum Sum Subarray Problem: " << std::endl;
    /*Declare, init and run*/
    int arr1[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int arr2[] = { -2, -3,-1, -2, -1, -5, -4 };
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    /*Run*/
    std::cout << "The maximum sum of a contiguous subarray is " << kadaneSemifull(arr1, n1) << std::endl;
    std::cout << "The maximum sum of a contiguous subarray is " << kadaneNeg(arr2, n2) << std::endl;


    return 0;
}
