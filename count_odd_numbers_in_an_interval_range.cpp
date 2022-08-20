// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/

// Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).

// Example 1:

// Input: low = 3, high = 7
// Output: 3
// Explanation: The odd numbers between 3 and 7 are [3,5,7].
// Example 2:

// Input: low = 8, high = 10
// Output: 1
// Explanation: The odd numbers between 8 and 10 are [9].

// Constraints:

// 0 <= low <= high <= 10^9

// level:easy

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution
{
public:
    int countOdds(int low, int high)
    {
        int result = 0;
        int range = high - low + 1;
        // if the range is even
        if (range % 2 == 0)
        {
            // 3 - 8 -> range 8-3 +1 =6  --- 3,5,7 <> 4,6,8
            result = (high - low) / 2 + 1;
        }
        // if the range is odd
        if (range % 2 != 0)
        {
            // if high and low both even
            if (high % 2 == 0 && low % 2 == 0)
            {
                result = floor((high - low) / 2);
                // 12-6 --range = 7/2 3,5  7,9,11
                return result;
            };
            // if high or low one of them odd
            //  6 - 3  range - 4 --- 2  - 3,5
            if (high % 2 != 0 || low % 2 != 0)
            {
                result = ceil((high - low) / 2) + 1;
                // 3 - 7  -> range 7-3 +1 = 5 --- 3,5,7 <> 4,6
                return result;
            };
        }
        return result;
    }
};

int main()
{
    int result = 0;
    Solution test;
    result = test.countOdds(3, 7);
    cout << result << endl;
    return 0;
}

int main()
{
    int result = 0;
    Solution test;
    result = test.countOdds(3, 7);
    cout << result << endl;
    return 0;
}