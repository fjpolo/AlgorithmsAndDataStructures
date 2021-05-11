#include <cstdio>
#include <iostream>
#include <math.h>
#include <cmath>


/**
 * \brief   Bit Manipulation problems
 * 
 *          Reference:
 *              https://medium.com/techie-delight/bit-manipulation-interview-questions-and-practice-problems-27c0e71412e7
 *              https://ptgmedia.pearsoncmg.com/images/9780321842688/samplepages/0321842685.pdf 
 */
    

/**
 * \struct    
 * 
 * \brief  
 */

/**
 * \class    
 * 
 * \brief   
 */

/**
 * \brief Private functions
 * 
 */
namespace{
/**
 * \fn      bool isOdd(int x)
 * 
 * \brief   Returns true if x is Odd. Returns false otherwise.
 */
bool isOdd(const int x){
    return (x & 0x01);
}

/**
 * \fn      bool haveOppositeSign(const int a, const int b)
 * 
 * \brief   Returns true if a and b have opposite sign, false otherwise.
 */
bool haveOppositeSign(const int a, const int b){
    return ((a ^ b) < 0);
}

/**
 * \fn      int AddOne(int x)
 * 
 * \brief   Adds 1 to X and returns value
 */
int AddOne(int &x){
    int temp = -~x;
    return temp;
}

/**
 * \fn      void InPlaceSwap(int &a, int &b)
 * 
 * \brief   Swap two values;
 */
void InPlaceSwap(int &x, int &y){
    if (x != y){
        x = x ^ y;
        y = x ^ y;
        x = x ^ y;
    }
}

/**
 * \fn      void TurnBitOff(int &val, const int k)  
 * 
 * \brief   Turn Kth bit off.- 
 */
void TurnBitOff(int &val, const int k){
    val &= ~(1 << (k-1)); 
}

/**
 * \fn      void TurnBitOn(int &val, const int k)  
 * 
 * \brief   Turn Kth bit on.- 
 */
void TurnBitOn(int &val, const int k){
    val |= (1 << (k-1)); 
}

/**
 * \fn      bool isBitSet(const int val, const int k)  
 * 
 * \brief   Return true if Kth bit is set, false otherwise.-  
 */
bool isBitSet(const int val, const int k){
    return (val & (1 << (k - 1)));
}

/**
 * \fn      void BitToggle(int &val, const int k)       
 * 
 * \brief   Toggle Kth bit.- 
 */
void BitToggle(int &val, const int k){
    val ^= (1 << (k - 1));
}

/**
 * \fn     void UNsetRighmostBit(int &n)            
 * 
 * \brief   Unset Righmost bit.-
 */
void UnsetRighmostBit(int &n){
    n &= (n-1);
}

/**
 * \fn      bool isPow2(const unsigned int a)           
 * 
 * \brief   Return true if positive integer is a power of 2
 */
bool isPow2(const unsigned int n){
    return static_cast<bool>(!(n & (n-1)));
    // return static_cast<bool>((std::log2(n & -n) + 1) == n);
}

/**
 * \fn      bool isPow4(const unsigned int a)           
 * 
 * \brief   Return true if positive integer is a power of 4
 */
bool isPow4(const unsigned int n){
    return !(n & (n - 1))&& (n % 3 == 1);
}

/**
 * \fn      bool isPow8(const unsigned int a)           
 * 
 * \brief   Return true if positive integer is a power of 8
 */
bool isPow8(const unsigned int n){
    // find `log8(n)`
    double i = log(n) / log(8);
    // return true if `log8(n)` is an integer
    return i - trunc(i) < 0.000001;
}

/**
 * \fn     int GetRighmostSetBitPosition(const int a)           
 * 
 * \brief   Return the position of the rightmost set bit.-
 */
int GetRighmostSetBitPosition(const int n){
    // if the number is odd, return 1
    // if ( n & 1) {
    if(isOdd(n)){
        return 0;
    }
    return std::log2(n & -n);
}

/**
 * \fn      int GetPositionOnlySetBit(const int n)               
 * 
 * \brief   Returns the position of the only bit set in an int.-  
 */
int GetPositionOnlySetBit(const int n){
    int temp{n};
    UnsetRighmostBit(temp);
    // unset the rightmost bit and check if the number is non-zero
    // if (n & (n - 1)){
    if(temp){
        std::cout << "Wrong input" << std::endl;
        return 0;
    }
    return std::log2(n);
}

/**
 * \fn      bool hasOddParity(int n)                
 * 
 * \brief   return true if n has odd parity, false otherwise.-        
 */
bool hasOddParity(int n){
    bool parity = false;
    // run until n becomes 0
    while (n){
        // invert the parity flag
        parity = !parity;
        // turn off the rightmost set bit
        // n = n & (n - 1);
        UnsetRighmostBit(n);
    }
 
    return parity;
}

/**
 * \fn      unsigned int AbsoluteValue(const int n)                
 * 
 * \brief   Returns the absolute value of a number.-        
 */
unsigned int AbsoluteValue(const int n){
    return 0;
}

/**
 * \fn      int countSetBits(int n)       
 * 
 * \brief   Returns the total number of set bits in `n`        
 */ 
int countSetBits(int n){
    // `count` stores the total bits set in `n`
    int count = 0;
    while (n){
        UnsetRighmostBit(n);    // clear the least significant bit set
        count++;
    }
    return count;
}

/**
 * \fn      int findBitsToBeFlipped(int x, int y)       
 * 
 * \brief   Returns the total number of bits needed to be flipped to convert `x` to `y`        
 */
int findBitsToBeFlipped(int x, int y){
    // take XOR of x and y and store in n
    int n = x ^ y;
    // Using Brian Kernighan’s algorithm to count set bits
    return countSetBits(n);
}

/**
 * \fn      unsigned findNextPowerOf2(unsigned n)      
 * 
 * \brief   Return: Compute power of two greater than or equal to `n`        
 */
unsigned findNextPowerOf2(unsigned n){
    // decrement `n` (to handle the case when `n` itself is a power of 2)
    n--;
 
    // set all bits after the last set bit
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
 
    // increment `n` and return
    return ++n;
}

/**
 * \fn      unsigned findPreviousPowerOf2(unsigned n)      
 * 
 * \brief   Return: Compute a power of two less than or equal to `n`        
 */
unsigned findPreviousPowerOf2(unsigned n){
    // set all bits after the last set bit
    n = n | (n >> 1);
    n = n | (n >> 2);
    n = n | (n >> 4);
    n = n | (n >> 8);
    n = n | (n >> 16);
 
    // drop all but the last set bit from `n`
    return n - (n >> 1);
}

/**
 * \fn      int superPower(int x, unsigned n)     
 * 
 * \brief   Iterative function to calculate `pow(x, n)` using binary operators. O(log(n))        
 */

int superPower(int x, unsigned n){

    // initialize result by 1
    int pow = 1;
    // loop till `n` become 0
    while (n){
        // if `n` is odd, multiply the result by `x`
        if (n & 1) {
            pow *= x;
        }
        // divide `n` by 2
        n = n >> 1;
        // multiply `x` by itself
        x *= x;
    }
 
    // return result
    return pow;
}
} // END namespace


/**
 * \brief Tasks
 * 
 */
namespace Task{
/*Tasks*/
void BasicTask(){
    /**
     * Basic 
     */
    std::cout << "Basic:" << std::endl << std::endl;
    /*Integer is Even or Odd*/
    std::cout << "Integer is Even or Odd:" << std::endl;
    if(isOdd(124463)) std::cout << "124463 is Odd" << std::endl;
    else std::cout << "124463 is Even" << std::endl;
    if(isOdd(316518)) std::cout << "316518 is Odd" << std::endl;
    else std::cout << "316518 is Even" << std::endl;
    std::cout << std::endl;
    /*Two integers have opposite sign*/
    std::cout << "Two integers have opposite sign:" << std::endl;
    if(haveOppositeSign(-16868, 1868)) std::cout << "-16868 and 1868 have opposite sign" << std::endl;
    else std::cout << "-16868 and 1868 don't have opposite sign" << std::endl;
    if(haveOppositeSign(891, 1868)) std::cout << "891 and 1868 have opposite sign" << std::endl;
    else std::cout << "891 and 1868 don't have opposite sign" << std::endl;
    std::cout << std::endl;
    /*Add 1 to integer*/
    int a{};
    std::cout << "Add 1 to integer:" << std::endl;
    a = 354;
    std::cout << a << "  + 1 = " << AddOne(a) << std::endl;
    a = 0;
    std::cout << a << "  + 1 = " << AddOne(a) << std::endl;
    a = -354;
    std::cout << a << "  + 1 = " << AddOne(a) << std::endl;
    std::cout << std::endl;
    /*In Place swap*/
    int b{};
    a = 55;
    b = 99;
    std::cout << "In Place swap:" << std::endl;
    std::cout << "Before: " << a << " | " << b << std::endl;
    InPlaceSwap(a, b);
    std::cout << "After: " << a << " | " << b << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}
/*kthBitTask*/
void kthBitTask(){
    /**
     * Kth Bit 
     */
    std::cout << "Kth Bit:" << std::endl << std::endl;
    /*Turn off k’th bit in a number*/
    int a{0xFF};
    int k{1};
    std::cout << "Turn off k’th bit in a number:" << std::endl;
    std::cout << "Before " << a << std::endl;
    TurnBitOff(a, k);
    std::cout << "After " << a << std::endl;
    std::cout << std::endl;
    /*Turn on k’th bit in a number*/
    std::cout << "Turn on k’th bit in a number:" << std::endl;
    std::cout << "Before " << a << std::endl;
    TurnBitOn(a, k);
    std::cout << "After " << a << std::endl;
    std::cout << std::endl;
    /*Check if k’th bit is set for a number*/
    std::cout << "Check if k’th bit is set for a number:" << std::endl;
    k = 6;
    if(isBitSet(a, k)) std::cout << "Bit " << k << " is set." << std::endl;
    else std::cout << "Bit " << k << " is not set." << std::endl;
    std::cout << std::endl;
    /*Toggle the k’th bit*/
    std::cout << "Toggle the k’th bit:" << std::endl;
    std::cout << "Before " << a << std::endl;
    BitToggle(a, k);
    std::cout << "After " << a << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}
/*RigmostSetBit*/
void RigmostSetBitTask(){
    /**
     * Righmost set bit 
     */
    int a{0xFF};
    int b{0x11};
    std::cout << "Righmost set bit:" << std::endl << std::endl;
    /*Unset righmost bit*/
    std::cout << "Unset righmost bit:" << std::endl;
    std::cout << "Before " << a << std::endl;
    UnsetRighmostBit(a);
    std::cout << "After " << a << std::endl;
    std::cout << std::endl;
    /*Check if a positive integer is a power of 2*/
    std::cout << "Check if a positive integer is a power of 2:" << std::endl;
    if(isPow2(a)) std::cout << a << " is a power of 2." << std::endl;
    else std::cout << a << " is not a power of 2." << std::endl;
    std::cout << std::endl;
    /*Find the position of the rightmost set bit*/
    std::cout << "Find the position of the rightmost set bit:" << std::endl;
    std::cout << a << "'s righmost set bit isat position " << GetRighmostSetBitPosition(a) << std::endl;
    std::cout << std::endl;
    /*Find the position of the only set bit in a number*/
    std::cout << "Find the position of the only set bit in a number:" << std::endl;
    b = 0x10;
    std::cout << b << "'s only set bit is at position " << GetPositionOnlySetBit(b) << std::endl;
    std::cout << std::endl;
    // /*Computing parity of a number*/
    // std::cout << "Computing parity of a number:" << std::endl;
    if(hasOddParity(a)) std::cout << a << " has Odd Parity.-" << std::endl;
    else std::cout << a << " has Even Parity.-" << std::endl;
    if(hasOddParity(0x02)) std::cout <<"0x02 has Odd Parity.-" << std::endl;
    else std::cout << "0x02 has Even Parity.-" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}
/*FlippingBitsTask*/
void FlippingBitsTask(){
    /**
     * Find the total number of bits needed to be flipped
     */
    std::cout << "Find the total number of bits needed to be flipped:" << std::endl;
    int a{65};
    int b{80};
    std::cout << a << " | " << b << " -> " << findBitsToBeFlipped(a, b) << " bits to be flipped." << std::endl << std::endl << std::endl;
}
/*PowerTask*/
void PowerTask(){
    /**
     * Problems with Power (2, 4, 8...)
     */
    std::cout << "Problems with Power:" << std::endl << std::endl;

    /*Round up to the next highest power of 2*/
    std::cout << "Round up to the next highest power of 2:" << std::endl;
    unsigned n = 131;
    std::cout << "The next power of 2 of " << n << " is "<< findNextPowerOf2(n) << std::endl;
    std::cout << std::endl;

    /*Round up to the previous  highest power of 2*/
    std::cout << "Round up to the previous  highest power of 2:" << std::endl;
    std::cout << "The previous  power of 2 of " << n << " is "<< findPreviousPowerOf2(n) << std::endl;
    std::cout << std::endl;

    /*Check if a positive integer is a power of 2*/
    std::cout << "Check if a positive integer is a power of 2:" << std::endl;
    if(isPow2(n)) std::cout << n << " is a power of 2." << std::endl;
    else std::cout << n << " is not a power of 2." << std::endl;
    std::cout << std::endl;

    /*Check if a positive integer is a power of 4*/
    std::cout << "Check if a positive integer is a power of 4:" << std::endl;
    if(isPow4(n)) std::cout << n << " is a power of 4." << std::endl;
    else std::cout << n << " is not a power of 4." << std::endl;
    std::cout << std::endl;

    /*Check if a positive integer is a power of 8*/
    std::cout << "Check if a positive integer is a power of 8:" << std::endl;
    if(isPow8(n)) std::cout << n << " is a power of 8." << std::endl;
    else std::cout << n << " is not a power of 8." << std::endl;
    std::cout << std::endl;

    /*Efficiently implement power function*/
    std::cout << "Check if a positive integer is a power of 8:" << std::endl;
    int x = -2;
    unsigned m = 10;
    std::cout << "pow(" << x << "," << m << ") = " << superPower(x, m) << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}

} // END namespace Task




/**
 * \fn main
 * 
 * \brief
 */
int main(){
    /*Say hi*/
    std::cout << "Bit Manipulation problems: " << std::endl << std::endl << std::endl << std::endl;
    
    /*Tasks*/
    Task::BasicTask();
    Task::kthBitTask();
    Task::RigmostSetBitTask();
    Task::FlippingBitsTask();
    Task::PowerTask();
    
    return 0;
}

