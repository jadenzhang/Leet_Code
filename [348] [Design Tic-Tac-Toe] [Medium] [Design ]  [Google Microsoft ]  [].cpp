/*
Question# + Difficulty + Topic + Company + Similar_Question
[348] [Design Tic-Tac-Toe] [Medium] [Design ] 
[Google Microsoft ] 
[].cpp
*/

class TicTacToe {
public:
    int count;
    int size;
    vector<int> rowflag,colflag,diaflag;
    
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        count = 0;
        size=n;
        rowflag = vector<int>(n,0);
        colflag = vector<int>(n,0);
        diaflag = vector<int>(2,0);
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        count++;
        if(count>size*size) return -1;//illegal move
        int val = player==1? 1:-1;//use 1 as player 1, -1 as player 2
        rowflag[row]+=val; 
        colflag[col]+=val;
        diaflag[0]+= (row==col)?val:0;
        diaflag[1]+= (row+col+1 == size)? val:0;
        
        if(abs(rowflag[row])==size || abs(colflag[col])==size || abs(diaflag[0])==size || abs(diaflag[1])==size) return player;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
