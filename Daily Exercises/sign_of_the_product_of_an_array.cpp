// https://leetcode.com/problems/sign-of-the-product-of-an-array/?envType=study-plan&id=programming-skills-i

// There is a function signFunc(x) that returns:

// 1 if x is positive.
// -1 if x is negative.
// 0 if x is equal to 0.
// You are given an integer array nums. Let product be the product of all values in the array nums.

// Return signFunc(product).

// Example 1:

// Input: nums = [-1,-2,-3,-4,3,2,1]
// Output: 1
// Explanation: The product of all values in the array is 144, and signFunc(144) = 1

// Example 2:

// Input: nums = [1,5,0,2,-3]
// Output: 0
// Explanation: The product of all values in the array is 0, and signFunc(0) = 0

// Example 3:

// Input: nums = [-1,1,-1,1,-1]
// Output: -1
// Explanation: The product of all values in the array is -1, and signFunc(-1) = -1

// Constraints:

// 1 <= nums.length <= 1000
// -100 <= nums[i] <= 100

// level:easy

#include <iostream>
#include <vector>

using namespace std;
int SignBit(int x)
{
    int result = 128 & x;
    if (result == 128) return -1;
    else return 1;
}
class Solution
{
public:
    int arraySign(vector<int>& nums)
    {
        // sayı negatif, pozitif veya sıfır mı?
        int N = nums.size();
        int val = 0;
        int multiply = 1;
        // tüm sayıların üstünden geç
        for (int i = 0; i < N; i++)
        {
            if (nums[i] == 0)
                return 0;

            val = SignBit(nums[i]);
            multiply *= val;
        }
        return multiply;
    }
};

int main()
{
    int result = 0;
    vector<int> num3{ -1, -2, -3, -4, 3, 2, 1 };
    vector<int> num2{ 1, 5, 0, 2, -3 };
    vector<int> num1{ -1, 1, -1, 1, -1 };
    vector<vector<int>> nums{ num3, num2, num1 };
    vector<int> expected{ 1, 0, -1 };
    Solution test{};
    for (int i = 0; i < nums.size(); i++)
    {
        result = test.arraySign(nums[i]);
        cout << "Beklenen->" << expected[i] << "   "
            << "Sonuc->" << result << endl;
    }
    return 0;
}