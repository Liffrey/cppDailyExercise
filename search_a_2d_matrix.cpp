// //! template version 1.9
// search-a-2d-matrix
// https://leetcode.com/problems/search-a-2d-matrix/

// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.

// Example 1:

// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true

// Example 2:

// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// Output: false

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 100
// -104 <= matrix[i][j], target <= 104

// level : medium

#include <iostream>
#include <vector>
using namespace std;

// binary search
//    while (low <= high) {
//      int mid = low + (high - low) / 2;

//     if (array[mid] == x)
//       return mid;

//     if (array[mid] < x)
//       low = mid + 1;

//     else
//       high = mid - 1;
//   }

//     - x x x x x x x x x x
//     - x x x x x x x x x x
//     - x x x x x x x x x x
//      (10) x x x x x x x x (x)  midRow,midRow.size()-1
//     + x x x x x x x x x x
//     + x 1 x x x x x x x x
//     + x x x x x x x x x x

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int lowRow = 0;
    int highRow = matrix.size() - 1;
    int midRow = 0;
    if (matrix.size() == 0)
    {
        return false;

    }
    // aranan sayının bulunduğu satir bulunduğunda o satir içinde arama yapılır.
    while (lowRow <= highRow)
    {
        midRow = lowRow + ((highRow - lowRow) / 2);
        // ilk once hedeflenen sayı hangi satırda o bulunur
        // satırların ortanca indexine bul.

        if (matrix[midRow][0] == target)
        {
            return true;
        }
        if (matrix[midRow][0] > target)
        {
            highRow = midRow - 1;
            continue;
        }
        if (matrix[midRow][0] < target)
        {
            // hedef aynı satırdaysa
            if (matrix[midRow][matrix[midRow].size() - 1] >= target)
            {
                int lowCol = 0;
                int highCol = matrix[midRow].size() - 1;
                int midCol = 0;

                while (lowCol <= highCol)
                {
                    midCol = lowCol + (highCol - lowCol) / 2;
                    if (matrix[midRow][midCol] == target)
                    {
                        return true;
                    }
                    if (matrix[midRow][midCol] > target)
                    {
                        highCol = midCol - 1;
                        continue;
                    }
                    if (matrix[midRow][midCol] < target)
                    {
                        lowCol = midCol + 1;
                        continue;
                    }
                }
                return false;
            }
            // hedef aynı satırda değil ve büyükse
            if (matrix[midRow][matrix[midRow].size() - 1] < target)
            {
                lowRow = midRow + 1;
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> test1 = { {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60} };
    vector<vector<int>> test2 = { {1} }; // 0 
    vector<vector<int>> test3 = { {1,1} }; // 2
    bool result;
    result = searchMatrix(test3, 2);
    cout << result;
    // vector<int> targets = {3};
    // vector<bool> results;
    // for (int i = 0; i < targets.size(); i++)
    // {
    //     results.push_back(searchMatrix(test1, targets[i]));
    //     cout << results[i] << endl;
    // }
    return 0;
}