class Solution {
    public boolean exist(char[][] board, String word) {
        boolean vis = new boolean[board.length][board[0].length];
        for(int i=0;i<board.length;i++){
            for(int j=0;j<board[0].length;j++){
                if(solve(i,j,board,word,0,vis))
                    return true;
            }
        }
        return false ;
    }

    boolean solve(int i , int j , char [][] board , String word , int index , boolean [][] vis){
        if(i<0 || j<0 || i>=board.length || j>=board[0].length || vis[i][j] || board[i][j]!=word.charAt(index))
            return false;

        if(index==word.length()-1)
            return true;    

        vis[i][j]=true;

        return 
        solve(i+1,j,board,word,index+1,vis) ||
        solve(i-1,j,board,word,index+1,vis) ||
        solve(i,j+1,board,word,index+1,vis) ||
        solve(i,j-1,board,word,index+1,vis);
    }
}