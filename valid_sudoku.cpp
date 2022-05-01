//! template version 1.9

// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
// Note:

// A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// Only the filled cells need to be validated according to the mentioned rules.

//  Example 1:

// Input: board = 
// [["5","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: true
// Example 2:

// Input: board = 
// [["8","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: false
// Explanation: Same as Example 1, except with the 5 in the top left corner 
// being modified to 8. Since there are two 8's in the top left 3x3 sub-box, 
// it is invalid.

// level:medium

#include <iostream>
#include <vector>
#include <set>
using namespace std;
//1.Each row must contain the digits 1-9 without repetition.
bool checkRow(const vector<char>& row)
{
    vector<char> sudokuNums = { '1','2','3','4','5','6','7','8','9' };
    vector<int> counter = vector<int>(9, 0);
    
    for (int j = 0; j < 9; j++)
    {
        //karşılasılan karakteri depoya at  
        //her iterasyonda depodaki elemanla bir sonraki iterasyon elemanlarını karşılaştır
        //eğer tüm iterayonlar için eşlesen karakter yokse true dön

        for (int k = 0; k < 9; k++)
        {
            //sudokuNums'taki herbir sayıyı her satır elemanı ile karsılastır.

            if (row[j] == sudokuNums[k])
            {
                //eğer birden fazla karşılasma gerçeklesirse
                //cout<<sudokuNums[k]<<"===>"<<board[i][j]<<endl;
                counter[k]++;

                // counter elemanlarının herhangi biri birden fazla mı? 
                if (counter[k] > 1)
                {
                    cout << counter[k] << endl;
                    return false;
                }
            }

        }

    }
    counter = vector<int>(9, 0);

    return true;
}
//2.Each column must contain the digits 1-9 without repetition.
bool checkColumn(const vector<vector<char>>& board, const int col)
{
    vector<char> sudokuNums = { '1','2','3','4','5','6','7','8','9' };
    vector<int> counter = vector<int>(9, 0);
    //satir
    for (int i=0;i<9;i++)
    {
        for (int k = 0; k < 9; k++)
        {
            if (board[i][col] == sudokuNums[k])
            {
                counter[k]++;
                if (counter[k] > 1) {
                    return false;
                }
            }
        }
    }

    counter = vector<int>(9, 0);
    return true;
}
//3.Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
bool checkCell(const vector<vector<char>>& board, const int row, const int col)
{
    vector<char> sudokuNums = { '1','2','3','4','5','6','7','8','9' };
    vector<int> counter = vector<int>(9, 0);

    for (int i=row;i<row+3;i++)
    {
        for (int j=col;j<col+3;j++)
        {
            for(int k=0;k<9;k++)
            {
                if (board[i][j] == sudokuNums[k])
                {
                    counter[k]++;
                    if (counter[k] > 1) {
                        return false;
                    }

                }
            }
            
        }
    }
    counter = vector<int>(9, 0);
    return true;
}

bool isValidSudoku(vector<vector<char>>& board) {

    vector<char> sudokuNums = { '1','2','3','4','5','6','7','8','9' };
    vector<int> counter = vector<int>(9,0);

    bool isValid = true;
    //satir
    
    for (int i = 0; i < 9; i++)
    {
        if (checkRow(board[i]) == false)
        {
            return false;
        }
        if (checkColumn(board,i) == false)
        {
            return false;
        } 
        
    }

    //board,0,0
    //board,0,3
    //board,0,6
    //board,3,0
    //board,3,3
    //board,3,6
    //board,6,0
    //board,6,3
    //board,6,6
    for (int row = 0; row <= 6; row += 3)
        for (int col = 0; col <= 6; col += 3)
        {
            if (checkCell(board, row, col) == false)
            {
                return false;
            }
        }


    return true;
}

int main()
{
    bool result;
    vector<vector<char>> test1 =
    {{'5','3','.','.','7','.','.','.','.'}
    ,{'6','.','.','1','9','5','.','.','.'}
    ,{'.','9','8','.','.','.','.','6','.'}
    ,{'8','.','.','.','6','.','.','.','3'}
    ,{'4','.','.','8','.','3','.','.','1'}
    ,{'7','.','.','.','2','.','.','.','6'}
    ,{'.','6','.','.','.','.','2','8','.'}
    ,{'.','.','.','4','1','9','.','.','5'}
    ,{'.','.','.','.','8','.','.','7','9'} };

    vector<vector<char>> test2 =
    {{'8','3','.','.','7','.','.','.','.'}
    ,{'6','.','.','1','9','5','.','.','.'}
    ,{'.','9','8','.','.','.','.','6','.'}
    ,{'8','.','.','.','6','.','.','.','3'}
    ,{'4','.','.','8','.','3','.','.','1'}
    ,{'7','.','.','.','2','.','.','.','6'}
    ,{'.','6','.','.','.','.','2','8','.'}
    ,{'.','.','.','4','1','9','.','.','5'}
    ,{'.','.','.','.','8','.','.','7','9'} };

    result = isValidSudoku(test1);
    cout << result;
    // for (int i = 0; i < result.size(); i++)
    // {
    //     for (int j = 0; j < result[0].size(); j++)
    //     {
    //         cout << result[i][j];
    //         cout << " ";
    //     }
    //     cout << endl;
    // }
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
    return 0;
}