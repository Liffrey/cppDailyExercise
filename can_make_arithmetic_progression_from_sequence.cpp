// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/?envType=study-plan&id=programming-skills-i

// A sequence of arrbers is called an arithmetic progression if the difference between any two consecutive elements is the same.

// Given an array of arrbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise, return false.

// Example 1:

// Input: arr = [3,5,1]
// Output: true
// Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 respectively, between each consecutive elements.

// Example 2:

// Input: arr = [1,2,4]
// Output: false
// Explanation: There is no way to reorder the elements to obtain an arithmetic progression.

// Constraints:

// 2 <= arr.length <= 1000
// -106 <= arr[i] <= 106

// level:easy

#include <iostream>
#include <vector>

using namespace std;

vector<int> SortingFunction(vector<int> &arr)
{
    vector<int> result{};
    return result;
}

class Solution
{
public:
    bool canMakeArithmeticProgression(vector<int> &arr)
    {
        int N = arr.size();
        //tüm array'deki sayıların arasındaki farkı kontrol et
        for (;;)
        {
            //eğer sayı farkları eşitse true 

            //değilse false dondur
        }
    }
};

int main()
{
    bool result = false;
    vector<int> arr1{1, 3, 5};
    vector<int> arr2{1, 2, 4};
    vector<vector<int>> arrs{arr1, arr2};
    vector<bool> expected{
        true,
        false,
    };
    Solution test{};
    for (int i = 0; i < arrs.size(); i++)
    {
        result = test.canMakeArithmeticProgression(arrs[i]);
        cout << "Beklenen->" << expected[i] << "   "
             << "Sonuc->" << result << endl;
    }
    return 0;
}