/*
Question# + Difficulty + Topic + Company + Similar_Question
[37] [Sudoku Solver] [Hard] [Hash Table Backtracking ] 
[Uber Snapchat ] 
[36].cpp
*/

/*My DFS*/
class Solution {
public:
    void backtrack(vector<vector<char>>& board,unordered_map<int,bool> checkrow, unordered_map<int,bool> checkcol, unordered_map<int,bool>checkblock,int myrow, int mycol,bool& done)
    {
        int row = myrow, col = mycol;
        for(;row<board.size();row++)
        {
            for(;col<board.size();col++)
            {
                if(board[row][col]!='.') continue;// ignore pre-filled grid
                int block = (row/3)*3+(col/3);
                for(int num = 1;num<10;num++)//possible num
                {
                    if(!checkrow.count(10*row+num) && !checkcol.count(10*col+num) && !checkblock.count(10*block+num))
                    {
                        board[row][col] = '0'+num;
                        checkrow[10*row+num] = checkcol[10*col+num] = checkblock[10*block+num] = 1;
                        backtrack(board,checkrow,checkcol,checkblock,row,col+1,done);
                        if(done==1) return;
                        checkrow.erase(10*row+num);checkcol.erase(10*col+num);checkblock.erase(10*block+num);
                        board[row][col] = '.';
                    }
                }
                if(board[row][col] == '.')return;//didn't put a num 
            }
            col = 0;
        }
        done=1;
        return;
    }
    void solveSudoku(vector<vector<char>>& board) {
        unordered_map<int,bool> checkrow, checkcol,checkblock;
        for(int row = 0;row<board.size();row++)
        {
            for(int col = 0;col<board.size();col++)
            {
                if(board[row][col]!='.')
                {
                    int num = board[row][col]-'0';
                    int block = (row/3)*3+(col/3);// (row/3) 3 vertical zone, *3, Each zone has 3 blocks, (col/3) adjust horizontal shift
                    checkrow[10*row+num] = checkcol[10*col+num] = checkblock[10*block+num] = 1;
                }
            }
        }
        bool done = 0;
        backtrack(board,checkrow,checkcol,checkblock,0,0,done);
    }
};

/*Faster Version Instead of UNdoing Stuff, Use constrain to solve*/
class Solution {
	struct cell // encapsulates a single cell on a Sudoku board
	{
		uint8_t value; // cell value 1..9 or 0 if unset
		// number of possible (unconstrained) values for the cell
		uint8_t numPossibilities;
		// if bitset[v] is 1 then value can't be v
		bitset<10> constraints;
		cell() : value(0), numPossibilities(9),constraints() {};
	};
	array<array<cell,9>,9> cells;

	// sets the value of the cell to [v]
	// the function also propagates constraints to other cells and deduce new values where possible
	bool set(int i, int j, int v)
	{ 
		// updating state of the cell
		cell& c = cells[i][j];
		if (c.value == v)
			return true;
		if (c.constraints[v])
			return false;
		c.constraints = bitset<10>(0x3FE); // all 1s
		c.constraints.reset(v);
		c.numPossibilities = 1;
		c.value = v;

		// propagating constraints
		for (int k = 0; k<9; k++) {
			// to the row: 
			if (i != k && !updateConstraints(k, j, v))
				return false;
			// to the column:
			if (j != k && !updateConstraints(i, k, v))
				return false;
			// to the 3x3 square:
			int ix = (i / 3) * 3 + k / 3;
			int jx = (j / 3) * 3 + k % 3;
			if (ix != i && jx != j && !updateConstraints(ix, jx, v))
				return false;
		}
		return true;
	}
	// update constraints of the cell i,j by excluding possibility of 'excludedValue'
	// once there's one possibility left the function recurses back into set()
	bool updateConstraints(int i, int j, int excludedValue)
	{
		cell& c = cells[i][j];
		if (c.constraints[excludedValue]) {
			return true;
		}
		if (c.value == excludedValue) {
			return false;
		}
		c.constraints.set(excludedValue);
		if (--c.numPossibilities > 1)
			return true;
		for (int v = 1; v <= 9; v++) {
			if (!c.constraints[v]) {
				return set(i, j, v);
			}
		}
		assert(false);
	}

	// backtracking state - list of empty cells
	vector<pair<int, int>> bt;

	// find values for empty cells
	bool findValuesForEmptyCells()
	{
		// collecting all empty cells
		bt.clear();
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (!cells[i][j].value)
					bt.push_back(make_pair(i, j));
			}
		}
		// making backtracking efficient by pre-sorting empty cells by numPossibilities
		sort(bt.begin(), bt.end(), [this](const pair<int, int>&a, const pair<int, int>&b) {
			return cells[a.first][a.second].numPossibilities < cells[b.first][b.second].numPossibilities; });
		return backtrack(0);
	}

	// Finds value for all empty cells with index >=k
	bool backtrack(int k)
	{
		if (k >= bt.size())
			return true;
		int i = bt[k].first;
		int j = bt[k].second;
		// fast path - only 1 possibility
		if (cells[i][j].value)
			return backtrack(k + 1);
		auto constraints = cells[i][j].constraints;
		// slow path >1 possibility.
		// making snapshot of the state
		array<array<cell,9>,9> snapshot(cells);
		for (int v = 1; v <= 9; v++) {
			if (!constraints[v]) {
				if (set(i, j, v)) {
					if (backtrack(k + 1))
						return true;
				}
				// restoring from snapshot,
				// note: computationally this is cheaper
				// than alternative implementation with undoing the changes
				cells = snapshot;
			}
		}
		return false;
	}
public:
	void solveSudoku(vector<vector<char>> &board) {
		cells = array<array<cell,9>,9>(); // clear array
		// Decoding input board into the internal cell matrix.
		// As we do it - constraints are propagated and even additional values are set as we go
		// (in the case if it is possible to unambiguously deduce them).
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++) {
				if (board[i][j] != '.' && !set(i, j, board[i][j] - '0'))
					return; // sudoku is either incorrect or unsolvable
			}
		}
		// if we're lucky we've already got a solution,
		// however, if we have empty cells we need to use backtracking to fill them
		if (!findValuesForEmptyCells())
			return; // sudoku is unsolvable

		// copying the solution back to the board
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++) {
				if (cells[i][j].value)
					board[i][j] = cells[i][j].value + '0';
			}
		}
	}
};
