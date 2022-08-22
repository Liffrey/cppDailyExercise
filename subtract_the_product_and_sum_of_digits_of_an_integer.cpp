// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

// Given an integer number n, return the difference between the product of its digits and the sum of its digits.

// Example 1:

// Input: n = 234
// Output: 15
// Explanation:
// Product of digits = 2 * 3 * 4 = 24
// Sum of digits = 2 + 3 + 4 = 9
// Result = 24 - 9 = 15

// Example 2:

// Input: n = 4421
// Output: 21
// Explanation:
// Product of digits = 4 * 4 * 2 * 1 = 32
// Sum of digits = 4 + 4 + 2 + 1 = 11
// Result = 32 - 11 = 21

// Constraints:

// 1 <= n <= 10^5

// level:easy

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int subtractProductAndSum(int n)
    {
        int pod = 1, sod = 0, result = 0, mod = 0, num = 0,i=10,j=1;
        size_t size = to_string(n).length();
        // 234
        // 234 mod 10 4  --- 234 - 234mod10 (4) 230  - ilk basamak 234 mod 10 / 1 = 4
        // 230 mod 100 30 --  234 - 230mod100 (30) 200 - ikinci basamak 230 mod 100 / 10 = 3
		// 234 mod 1000 234 --- 200 / 1000 = (200) - ücüncü basamak için 200 mod 1000 / 100 = 2
        while (size>0)
        {

            mod = n % i;   // i=10 , 234 mod 10 = 4
            i = i * 10;
            num = mod / j; // j=1  , 4/1 = 4
            n = n - num;
            j = j * 10;
            pod = pod * num;
            sod = sod + num;
            size--;
        }
        return result = pod - sod;
    }
};

int main()
{
    Solution test{};
    int result = test.subtractProductAndSum(234);
    cout << "expected answer is : 15/t"
        << "result is: " << result << endl;
    return 0;
}