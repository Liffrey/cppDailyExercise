//! template version 1.2
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
//  Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

// Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

// Return k after placing the final result in the first k slots of nums.

// Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.

// Custom Judge:

// The judge will test your solution with the following code:

// int[] nums = [...]; // Input array
// int[] expectedNums = [...]; // The expected answer with correct length

// int k = removeDuplicates(nums); // Calls your implementation

// assert k == expectedNums.length;
// for (int i = 0; i < k; i++) {
//     assert nums[i] == expectedNums[i];
// }
// If all assertions pass, then your solution will be accepted.

// Example 1:

// Input: nums = [1,1,2]
// Output: 2, nums = [1,2,_]
// Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).
// Example 2:

// Input: nums = [0,0,1,1,1,2,2,3,3,4]
// Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
// Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
// It does not matter what you leave beyond the returned k (hence they are underscores).

// level:easy

// iter 1. i=0 counter=0 k=1 enbüyük = 0 karsilastirma = 0 - 0 ------> 0 0 1 1 1 2
// iter 2. i=1 counter=0 k=1 enbüyük = 0 karsilastirma = 0 - 0 ------> 0 0 1 1 1 2
// iter 3. i=2 counter=1 k=2 enbüyük = 1 karsilastirma = 0 - 1 ------> 0 (1) 1 1 1 2
// iter 4. i=3 counter=1 k=2 enbüyük = 1 karsilastirma = 1 - 1 ------> 0 1 1 1 1 2
// iter 5. i=4 counter=1 k=2 enbüyük = 1 karsilastirma = 1 - 1 ------> 0 1 1 1 1 2
// iter 6. i=5 counter=2 k=3 enbüyük = 2 karsilastirma = 1 - 2 ------> 0 1 (2) 1 1 2

#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int counter = 0;
    int biggest = nums[0];

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > biggest)
        {
            biggest = nums[i];
            counter++;
            nums[counter] = biggest;
        }
    }
    return counter + 1;
}

int main()
{
    int output = 0;
    vector<int> beklenen{1, 3, 4, 6, 7, 8, 8, 8};
    vector<int> test{1, 3, 4, 6, 6, 7, 8, 8};
    int k = removeDuplicates(test);
    cout << k;
    return 0;
}

// vector<int> uniq_element;
// for(int i=0;i<nums.size();i++)
// {
//     isUnique = true;
//     for(int j=0;j<uniq_element.size();j++)
//         {
//             if(nums[i]==uniq_element[j])
//             {
//                 isUnique = false;
//                 break;
//             }
//         }
//         if(isUnique)
//         {
//             uniq_element.push_back(nums[i]);
//         }
// }
// for (int i=0;i<uniq_element.size();i++)
// {
//     cout<<uniq_element[i]<<" ";
// }