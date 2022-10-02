//02/10/2022
// https://leetcode.com/problems/happy-number/

// Write an algorithm to determine if a number n is happy.

// A happy number is a number defined by the following process:

// Starting with any positive integer, replace the number by the sum of the squares of its digits.
// Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
// Those numbers for which this process ends in 1 are happy.
// Return true if n is a happy number, and false if not.

// Example 1:

// Input: n = 19
// Output: true
// Explanation:
// 1^2 + 9^2 = 82
// 8^2 + 2^2 = 68
// 6^2 + 8^2 = 100
// 1^2 + 0^2 + 0^2 = 1

// Example 2:

// Input: n = 2
// Output: false

//  level:easy


#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
private:
    int nextSum(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int digitValue = n % 10;
            n = n / 10;
            sum += digitValue * digitValue;
        }
        return sum;
    }

public:
    bool isHappy(int n)
    {
        unordered_set<int> seen;
        while (n != 1 && seen.find(n) == seen.end())
        {
            seen.insert(n);
            n = nextSum(n);
        }
        return n == 1;
    }
};

int main()
{
    vector<int> nums{19, 2, 0};
    vector<bool> results{true, false, false};
    Solution test{};
    bool result = false;
    for (int i = 0; i < nums.size(); i++)
    {
        result = test.isHappy(nums[i]);
        cout << "Beklenen"
             << "->" << results[i] << "   "
             << "Sonuc"
             << "->" << result << endl;
    }
    return 0;
}