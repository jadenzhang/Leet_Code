/*
Question# + Difficulty + Topic + Company + Similar_Question
[36] [Valid Sudoku] [Medium] [Hash Table] 
[Uber Apple Snapchat  ] 
[37].cpp
*/
/*Normal Approach */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool checkrow[9][9] = {0},checkcol[9][9]={0},checkblock[9][9] = {0};
        /*
            use +1 because range(1-9) but index(0-8)
            checkrow[i][j] -> row i number j+1 exist or not
            
        */
        for(int row = 0;row<board.size();row++)
        {
            for(int col = 0;col<board.size();col++)
            {
                if(board[row][col]!='.')
                {
                    int num = board[row][col]-'0'-1;//transform num to index  so -1
                    int block = (row/3)*3+(col/3);// (row/3) 3 vertical zone, *3, Each zone has 3 blocks, (col/3) adjust horizontal shift
                    if(checkrow[row][num] || checkcol[col][num] || checkblock[block][num]) return false;
                    checkrow[row][num] = checkcol[col][num] = checkblock[block][num] = 1;
                }

            }
        }
        return true;
    }
};

/*Hash Table Approach */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,bool> checkrow,checkcol,checkblock;
        /*
            use +1 because range(1-9) but index(0-8)
            checkrow[i][j] -> row i number j+1 exist or not
            
        */
        for(int row = 0;row<board.size();row++)
        {
            for(int col = 0;col<board.size();col++)
            {
                if(board[row][col]!='.')
                {
                    int num = board[row][col]-'0';
                    int block = (row/3)*3+(col/3);// (row/3) 3 vertical zone, *3, Each zone has 3 blocks, (col/3) adjust horizontal shift
                    if(checkrow.count(10*row+num) || checkcol.count(10*col+num) || checkblock.count(10*block+num)) return false;
                    checkrow[10*row+num] = checkcol[10*col+num] = checkblock[10*block+num] = 1;
                }

            }
        }
        return true;
    }
};
