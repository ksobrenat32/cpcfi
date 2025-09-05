bool validate(int x, int y){
	if(vis[x][y]) return false;
	if(maze[x][y] == '#') return false;
	if(x<0 or x>=n or y<0 or y>=m) return false;
	return true;
}

bool solveMaze(int x, int y){
    queue<pii> q;
    q.push(mp(x,y));
    vis[x][y] = true;

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    char move_dir[] = {'D', 'U', 'R', 'L'};

	while(!q.empty()){
		int u =  q.front().fs;
		int v = q.front().sc;
		q.pop();

		if(maze[u][v] == 'B'){
			while(true){
				res.push_back(path[u][v]);

				if(res.back() == 'U' && u + 1 < n) u++;
				if(res.back() == 'D' && u - 1 >= 0) u--;
				if(res.back() == 'L' && v + 1 < m) v++;
				if(res.back() == 'R' && v - 1 >= 0) v--;

				if(u == x and v ==y) break;
			}
			return true;
		}
            for (int i = 0; i < 4; ++i) {
                int new_u = u + dx[i];
                int new_v = v + dy[i];
                if (validate(new_u, new_v)) {
                    path[new_u][new_v] = move_dir[i];
                    vis[new_u][new_v] = true;
                    q.push(mp(new_u, new_v));
                }
            }
        }
    return false;
}
