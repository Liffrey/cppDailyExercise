//! template version 1.8
// In MATLAB, there is a handy function called reshape which can reshape an m x n matrix into a new one with a different size r x c keeping its original data.

// You are given an m x n matrix mat and two integers r and c representing the number of rows and the number of columns of the wanted reshaped matrix.

// The reshaped matrix should be filled with all the elements of the original matrix in the same row-traversing order as they were.

// If the reshape operation with given parameters is possible and legal, output the new reshaped matrix; Otherwise, output the original matrix.

// Example 1:

// Input: mat = [[1,2],[3,4]], r = 1, c = 4
// Output: [[1,2,3,4]]

// Example 2:

// Input: mat = [[1,2],[3,4]], r = 2, c = 4
// Output: [[1,2],[3,4]]

// level:easy
#include <iostream>
#include <vector>
using namespace std;

// [1,2],[3,4] mxn matrisi rxc matrise dönüştür [1,2,3,4]
// |1 2|
// |3 4| ===> rxc = 1x4 ===> |1 2 3 4|
//
// |1 2|
// |3 4| ===> rxc = 2x4 ===> return original

// 1. adım verilen matrisi lineer bir diziye dönüştür.
// 1.1 verilen matrisin tüm elemanlarını gez ve bunu yeni diziye ekle
// 2. adım dizideki elemanları verilen row ve column için tekrar oluştur.

vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
{
    const int M = mat[0].size();
    const int N = mat.size();
    vector<int> linearArray;
    int p = 0;
    vector<vector<int>> result;
    if (M * N == r * c)
    {
        for (int i = 0; i < N; i++)
        {
            // sutün
            for (int j = 0; j < M; j++)
            {
                // satır elemanlarını linear arraye ekle
                linearArray.push_back(mat[i][j]);
            }
        }
        // linearArray deki elemanları verilen row ve column'a göre tekrar şekillendir
        result.resize(r);
        for (int k = 0; k < r; k++)
        {
            // sutün
            result[k].resize(c);
            for (int l = 0; l < c; l++)
            {
                // linear arraydaki eleamnları sırasıyla row'lara ata
                result[k][l] = linearArray[p];
                p++;
            }
        }
        return result;
    }
    return mat;
}

int main()
{
    vector<vector<int>> result;
    vector<vector<int>> test1 = {{1, 2}, {3, 4}};

    result = matrixReshape(test1, 2, 4);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[0].size(); j++)
        {
            cout << result[i][j];
            cout << " ";
        }
        cout << endl;
    }
    // vector<int> test2 = {3, 2};
    // vector<int> test3 = {3, 3};
    // vector<int> targets = {9,6,6};
    // vector<vector<int>> tests = {test1, test2, test3};
    // for (vector<int> &test : tests)
    // {
    //     cout << "input:	";

    //     for (int i = 0; i < test.size(); i++)
    //     {
    //         cout << test[i];
    //         result = matrixReshape();
    //     }
    //     cout << "	result: ";
    //     for (int i = 0; i < result.size(); i++)
    //     {
    //         cout << result[i];
    //     }
    //     cout << endl;
    // }
    // return 0;
}


vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
{
    const int M = mat[0].size();
    const int N = mat.size();
    vector<int> linearArray(r*c,-1);
    int p = 0;
    vector<vector<int>> result(r,vector<int>(c,-1));
    if (M * N == r * c)
    {
        for (int i = 0; i < N; i++)
        {
            // sutün
            for (int j = 0; j < M; j++)
            {
                // satır elemanlarını linear arraye ekle
                linearArray[M*i+j] = mat[i][j];
                //m=2 n=3
                //o=0 i=0; j=0; *
                //o=1 i=0; j=1; *
                //o=2 i=0; j=2; *
                //o=3 i=1; j=0; x 3i + j 
                //o=4 i=1; j=1; x 
                //o=5 i=1; j=2; x
                
                //m=2 n=2
                //o=0 i=0; j=0; * 
                //o=1 i=0; j=1; * 
                //o=2 i=1; j=0; x SUTUNSAYISI*i + j
                //o=3 i=1; j=1; x
                
                //m=3 n=3
                //o=0 i=0; j=0;
                //o=1 i=0; j=1;
                //o=2 i=0; j=2;
                //o=3 i=1; j=0;
                //o=4 i=1; j=1;
                //o=5 i=1; j=2;
                //o=6 i=0; j=1;

            }
        }
        // linearArray deki elemanları verilen row ve column'a göre tekrar şekillendir
        for (int k = 0; k < r; k++)
        {
            // sutün
            for (int l = 0; l < c; l++)
            {
                // linear arraydaki eleamnları sırasıyla row'lara ata
                result[k][l] = linearArray[p];
                p++;
            }
        }
        return result;
    }
    return mat;
}