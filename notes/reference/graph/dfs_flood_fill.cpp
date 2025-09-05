void floodFill(int x, int y, char color,vector<vector<char>>& board){
    if(x<0 or y<0 or x>=board.size() or y>=board[x].size() or board[x][y] != 'O') return;
    board[x][y] = color;
    floodFill(x+1,y,color,board);
    floodFill(x-1,y,color,board);
    floodFill(x,y+1,color,board);
    floodFill(x,y-1,color,board);
}
