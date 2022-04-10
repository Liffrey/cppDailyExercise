//! template version 1.5
// https://leetcode.com/problems/plus-one/

// Plus One

// You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

// Increment the large integer by one and return the resulting array of digits.

// Example 1:

// Input: digits = [1,2,3]
// Output: [1,2,4]
// Explanation: The array represents the integer 123.
// Incrementing by one gives 123 + 1 = 124.
// Thus, the result should be [1,2,4].
// Example 2:

// Input: digits = [4,3,2,1]
// Output: [4,3,2,2]
// Explanation: The array represents the integer 4321.
// Incrementing by one gives 4321 + 1 = 4322.
// Thus, the result should be [4,3,2,2].
// Example 3:

// Input: digits = [9]
// Output: [1,0]
// Explanation: The array represents the integer 9.
// Incrementing by one gives 9 + 1 = 10.
// Thus, the result should be [1,0].

// level:easy

// arrayin 0 inci elemanını bir arttır.

// eğer 0. eleman 9 ise o elemanı 0 yap +1. elemanı 1 yap.

// eğer bu durum +1. eleman içinde geçerliyse son elemana kadar bunu yap.

#include <iostream>
#include <vector>
using namespace std;


vector<int> plusOne(vector<int> &digits)
{
    int N = digits.size();
    // eğer 0. eleman 9 dan farklı bir rakamsa,
    if (digits[N] != 9)
    {
        // arrayin 0. elemanını bir atttır.
        cout << "9danfarkliysaif" << endl;
        cout << N << endl;
        digits[N] = digits[N] + 1;
        return digits;
    }
    // eğer 0. eleman 9 ise o elemanı 0 yap +1. elemanı 1 yap.
    // eğer bu durum +1. eleman içinde geçerliyse son elemana kadar bunu yap.
    else
    {
        int i = 0;
        while (digits[N] == 9)
        {
            digits[N] = 0;
            i--;
        }
        // son eleman i. eleman değilse
        if (digits[0] != i)
        {
            digits[i - 1] = digits[i - 1] + 1;
            cout << "iftest" << endl;
        }
        else
        {
            digits[digits.size()] = 0;
            digits.push_back(1);
        }
        return digits;
    }
}

int main()
{
    vector<int> result;
    vector<int> test1{9, 9, 9, 9};
    vector<int> test2{1, 4};
    vector<int> test3{3};
    for (int i = 0; i <= test3.size(); i++)
    {
        cout << test3[i];
    }
    cout << endl;
    result = plusOne(test3);
    for (int i = 0; i <= result.size(); i++)
    {
        cout << result[i];
    }
    return 0;
}

// for (int i = 0; i < digits.size(); i++)
// {
//     // i. karakter 9 mu diye kontrol et.
//     if (digits[i] == 9)
//     {
//         // 9876543210 -> kaçıncı karakter
//         // 9999999999 -> sayı
//         //         +1
//         //          0 ->
//         // 9999999990 -> iter 1
//         // 9999999900 -> iter 2
//         //     .
//         //     .
//         // 9000000000 -> iter n-1
//         // 10000000000 -> iter n
//         digits[i] = 0;
//     }
//     if (digits[i + 1] != 9)
//         (
//             digits[i + 1]++) if (digits[digits.size()] == 9)(

//         )
// }