// https://leetcode.com/problems/largest-perimeter-triangle/

// Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.

// Example 1:

// Input: nums = [2,1,2]
// Output: 5

// Example 2:

// Input: nums = [1,2,1]
// Output: 0

// Constraints:

// 3 <= nums.length <= 104
// 1 <= nums[i] <= 106

// level:easy

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int largestPerimeter(vector<int> &nums)
    {
        bool isTrue = false;
        int result{0};

        // verilen vector listi büyükten kücüge sırala
        sort(nums.begin(), nums.end());
        // bütün nums değerlerinin üstünden geç
        for (int i = nums.size() - 1; i > 1; i--)
        {
            // eğer a+b>c kosulunu sağlıyorsa
            if (nums[i] < nums[i - 1] + nums[i - 2])
            {
                // o değerleri topla (max çevreyi bul)
                result = nums[i] + nums[i - 1] + nums[i - 2];
                return result;
            }
        }
        return 0;
        // 1,4,3,6,8,1,4
        // n n+1 n+2
        //  n + n+1 > n+2
    }
};

int main()
{
    int result{0};
    Solution test{};
    vector<int> nums = {1, 2, 1, 4, 5, 7, 3, 9, 3};
    result = test.largestPerimeter(nums);
    cout << result;
    return 0;
}