class Solution {
  public:
  
  int X[8] = {1,-1,-1, 1, 0, 1,-1, 0};
  int Y[8] = {1,-1, 1,-1, 1, 0, 0,-1};
  
  void bfs(int i, int j, int n, int m, vector<vector<char>>& grid) {
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j] = 'W';

        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();
            
            for(int axis=0; axis < 8; axis++){
                int xx = X[axis] + x;
                int yy = Y[axis] + y;
                
                if(xx < 0 || yy < 0 || xx >= n || yy >= m || grid[xx][yy]=='W')
                    continue;
                    
                if(grid[xx][yy] == 'L'){
                    grid[xx][yy] = 'W';
                    q.push({xx, yy});
                }
                    
            }
        }
    }

    int countIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 'L'){
                    // dfs(i, j, n, m, grid);
                    bfs(i, j, n, m, grid);
                    ans++;
                }
            }
        }
        return ans;
        
    }
};
