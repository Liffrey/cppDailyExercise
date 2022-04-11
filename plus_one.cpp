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

// arrayin N inci elemanını bir arttır.

// eğer N. eleman 9 ise o elemanı 0 yap +1. elemanı 1 yap.

// eğer bu durum +1. eleman içinde geçerliyse son elemana kadar bunu yap.

// eğer son rakam 9 dan küçük bir sayı ise 1 ile toplanır 
// eğer son rakam 9 dan ise bir ile toplanır elde 1 olur bu sayı bir soldaki rakamla toplanır. 
// eğer bir soldaki rakamda 9 ise bu işlem soldaki sayı 9 olmayana devam eder. 
//  9999 
//     1
//------
//     0  +1
//    00  +1
//   000  +1
// 10000

// 1234
//    1
//-----
// 1235

//    9
//    1
//-----
//   10

// 7899
//    1
//-----
//    0 +1
//   00 +1
//  900
// 7900

// 7989
//    1
//-----
//    0 +1
//   90 +1
//  990
// 7990

#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int>& digits)
{
	int i = digits.size() - 1;

	while (i >= 0)
	{
		digits[i] += 1;
		if (digits[i] == 10)
		{
			digits[i] = 0;
			//digits[i - 1] += 1;
			i--;
		}
		else
		{
			return digits; //10000, 9000
		}
	}
	if (digits[0] == 0)
	{
		digits.insert(digits.begin(), 1);
	}
	return digits;
}

int main()
{
	vector<int> result;
	vector<int> test1 = { 9, 9, 9, 9 };
	vector<int> test2 = { 1, 4 };
	vector<int> test3 = { 3 };
	vector<int> test4 = { 9 };
	vector<int> test5 = { 0 };


	vector<vector<int>> tests = { test1, test2, test3, test4, test5 };
	for (vector<int>& test : tests)
	{
		cout << "input:	";

		for (int i = 0; i < test.size(); i++)
		{
			cout << test[i];
		}
		
		result = plusOne(test);
		cout << "	result: ";
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i];
		}
		cout << endl;
	}
	return 0;
}
