class Solution {
public:
    
    
    bool is_safe(int row , int col, vector<int>& rowhash, vector<int>& low_diag, vector<int>& up_diag, int n)
    {
        if(rowhash[row] == 1 or low_diag[row+col] == 1 or up_diag[row-col +(n-1)] == 1)
            return false;
        
        return true;
    }
    
    void helper(int col, int n, vector<string> &board, vector<vector<string>> & ans, vector<int>& rowhash, vector<int>& low_diag, vector<int>& up_diag)
    {
        
        if(col == n)
        {
            ans.push_back(board);
            return;
        }
        
        for(int row=0; row<n; row++)
        {
            if(is_safe(row, col, rowhash, low_diag, up_diag, n))
            {
                rowhash[row] = 1;
                low_diag[row+col] = 1;
                up_diag[row-col + (n-1)] = 1;
                board[row][col] = 'Q';
                
                
                helper(col+1, n, board, ans, rowhash, low_diag, up_diag);
                
                
                board[row][col] = '.';      //backtracking
                rowhash[row] = 0;
                low_diag[row+col] = 0;
                up_diag[row-col + (n-1)] = 0;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        vector<int> rowhash(n,0);
        vector<int> low_diag(2*n - 1, 0);
        vector<int> up_diag(2*n - 1, 0);
        
        string dots = "";
        
        for(int i=0; i<n; i++)
        {
            dots += '.';
        }
        
        vector<string> board;
        
        for(int i=0; i<n; i++)
            board.push_back(dots);
        
        
        helper(0, n, board, ans, rowhash, low_diag, up_diag);
        
        return ans;
    }
};