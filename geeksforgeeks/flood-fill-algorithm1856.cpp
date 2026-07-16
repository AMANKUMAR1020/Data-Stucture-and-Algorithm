struct Pair{
    int i;
    int j;
};

const int X[] = {0, 1, 0, -1};
const int Y[] = {1, 0, -1, 0};

class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        int n = image.size();
        int m = image[0].size();
        int ans = 0;
        queue<Pair> q;
        
        
        int oldColor = image[sr][sc];
        if (oldColor == newColor)
            return image;
            
        image[sr][sc] = newColor;
        q.push({sr, sc});
        
        while(!q.empty()){
            int i = q.front().i;
            int j = q.front().j;
            q.pop();
            
            for(int k=0; k<4; k++){
                int y = i + Y[k];
                int x = j + X[k];
                if(x < 0 || y < 0 || x >= m || y >= n)
                    continue;
                
                if(image[y][x] == oldColor){
                    image[y][x] = newColor;
                    q.push({y, x});
                }
            }
        }
        
        return image;
        
    }
};
