//! template version 1.6
// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

// Example 1:

// Input: nums = [1,2,3,1]
// Output: true
// Example 2:

// Input: nums = [1,2,3,4]
// Output: false
// Example 3:

// Input: nums = [1,1,1,3,3,4,3,2,4,2]
// Output: true

// level:easy
#include <vector>
#include <set>
#include <iostream>

using namespace std;

bool containsDuplicate(vector<int> &nums)
{
    set<int> uniqueNumbers(nums.begin(), nums.end());
    return nums.size() != uniqueNumbers.size();
}

int main()
{
    bool result;
    vector<int> test1 = {1, 2, 3, 1};
    vector<int> test2 = {1,1,1,3,3,4,3,2,4,2};
    vector<int> test3 = {1,2,3,4};
    vector<bool> output = {true,true,false};

    vector<vector<int>> tests = {test1, test2, test3};
    
    for (vector<int> &test : tests)
    {
        cout << "input:	";

        for (int i = 0; i < test.size(); i++)
        {
            cout << test[i];
        }

        //result = containsDuplicate(test);

        cout << "	result: ";

        for (int i = 0; i < output.size(); i++)
        {
            cout << output[i];
        }
        cout << endl;
    }
    return 0;
}
