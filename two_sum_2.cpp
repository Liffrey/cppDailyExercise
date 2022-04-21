//! template version 1.7
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]

// level: easy
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    int diff = 0;
    vector<int> result;
    unordered_map<int, int> sumMap;
    // 2,7,11,15 t=9
    // *         sum=target-index 9-2 = 7  key=0
    //   *       sum=target-index 7-7 = 0  key=1
    // return (0,1)
    // 3,2,4 t=6
    // *         sum=target-index 6-3 = 3 key=0
    //   *       sum=target-index

    //-------------------------------------------------------------------------
    // index,fark,değer    tutabileceğim parametreler
    //  *    *     -       unique parametreler
    // index               sorunun bende istediği
    //

    // targettan dizideki ilk elemanı cıkar
    // çıkan sonucu undordered_map'teki konumunu bul

    for (int i = 0; i < nums.size(); i++)
    {
        diff = target - nums[i];
        // 2 7 11 15 t=9
        // diff target num dict
        //  7      9    2   7,0
        //  2      9    7   2,1

        if (sumMap.find(diff) != sumMap.end())
        {
            // array[key] = value
            result.push_back(sumMap[diff]);
            result.push_back(i);
            return result;
        }
        sumMap[nums[i]] = i;
    }
    return result;
}

int main()
{
    vector<int> test1 = {2, 7, 11, 15};
    vector<int> result;
    int target;
    target=9;
    result = twoSum(test1,target);
    for (int i =0 ; i<result.size();i++)
    {
        cout<<result[i]<<",";
    }
    // vector<int> test1 = {2, 7, 11, 15};
    // vector<int> test2 = {3, 2};
    // vector<int> test3 = {3, 3};
    // vector<int> targets = {9,6,6};
    // vector<vector<int>> tests = {test1, test2, test3};
    // for (vector<int> &test : tests)
    // {
    //     cout << "input:	";

    //     for (int i = 0; i < test.size(); i++)
    //     {
    //         cout << test[i];
    //         result = twoSum(test, targets[i]);
    //     }
    //     //result = twoSum(test, targets[i]);
    //     cout << "	result: ";
    //     for (int i = 0; i < result.size(); i++)
    //     {
    //         cout << result[i];
    //     }
    //     cout << endl;
    // }
    return 0;
}