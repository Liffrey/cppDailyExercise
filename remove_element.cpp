//! template version 1.3
// Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The relative order of the elements may be changed.

// Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

// Return k after placing the final result in the first k slots of nums.

// Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

// Example 1:

// Input: nums = [3,2,2,3], val = 3
// Output: 2, nums = [2,2,_,_]
// Explanation: Your function should return k = 2, with the first two elements of nums being 2.
// It does not matter what you leave beyond the returned k (hence they are underscores).
// Example 2:

// Input: nums = [0,1,2,2,3,0,4,2], val = 2
// Output: 5, nums = [0,1,4,0,3,_,_,_]
// Explanation: Your function should return k = 5, with the first five elements of nums containing 0, 0, 1, 3, and 4.
// Note that the five elements can be returned in any order.
// It does not matter what you leave beyond the returned k (hence they are underscores).

// level:easy

// iter 1 -> counter=0 val=3, 3 = 3 -----> 3 2 2 3 isEqual=true
// iter 2 -> counter=1 val=3, 2 =/= 3 ---> 2 2 2 3 isEqual=false
// iter 3 -> counter=2 val=3, 2 =/= 3 ---> 2 2 2 3 isEqual=false
// iter 4 -> counter=2 val=3, 3 = 3 -----> 2 2 2 3 isEqual=true

#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int> &nums, int val)
{
    int counter = 0;
    const int SIZE = nums.size();
    for (int i = 0; i < SIZE; i++)
    {
        if (nums[i] != val)
        {
            nums[counter] = nums[i];
            counter++;
        }
    }
    return counter;
}

int main()
{
    vector<int> test{3, 2, 2, 3};
    int val = 3;
    int result = removeElement(test, 3);
    // cout << result;
    return 0;
}