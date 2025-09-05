void floodFill(int x, int y, char color ,int r, int c) {
	if (maze[x][y] == color) return;
	queue<pii> q;
	q.push(pii(x, y));
    while (!q.empty()) {
        pii currentCoor = q.front();
        q.pop();
        x = currentCoor.fi;
        y = currentCoor.sc;
        if (x >= 0 && x < r && y >= 0 && y < c && maze[x][y] != color) {
            maze[x][y] = color;
            q.push(pii(x + 1, y));
            q.push(pii(x - 1, y));
            q.push(pii(x, y + 1));
            q.push(pii(x, y - 1));
        }
    }
}
