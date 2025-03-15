class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> list = new ArrayList<>();
        int[][] board = new int[n][n];
        solve(board, 0, list);
        return list;
    }

    void solve(int[][] board, int row , List<List<String>> list) {
        if(row == board.length) {
            list.add(convert(board));
            return;
        }
        
        for(int col = 0; col < board[0].length; col++) {
            if(isSafe(board, row, col)) {
                board[row][col] = 1;
                solve(board, row + 1, list);
                board[row][col] = 0; // backtrack
            }
        }
    }

    boolean isSafe(int[][] board, int row, int col) {
        // Check the column on this row
        for (int i = 0; i < row; i++)
            if (board[i][col] == 1)
                return false;
        
        // Check upper left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 1)
                return false;
        
        // Check upper right diagonal
        for (int i = row, j = col; i >= 0 && j < board.length; i--, j++)
            if (board[i][j] == 1)
                return false;

        return true;
    }

    List<String> convert(int[][] board) {
        List<String> list = new ArrayList<>();
        for(int i = 0; i < board.length; i++) {
            StringBuilder row = new StringBuilder();
            for(int j = 0; j < board[0].length; j++) {
                if(board[i][j] == 1)
                    row.append('Q');
                else
                    row.append('.');
            }
            list.add(row.toString());
        }
        return list;
    }
}
