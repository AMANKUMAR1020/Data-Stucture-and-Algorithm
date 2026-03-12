class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        int i=0,j=0;
        int cnt = 0;
        vector<int> vec;
        
        while(i<n && j<m){
            if(cnt%4 == 0){
                
                for(int temp = j; temp<m; temp++) 
                    vec.push_back(mat[i][temp]);
                i++;
                
            }else if(cnt%4 == 1){
                
                for(int temp = i; temp<n; temp++) 
                    vec.push_back(mat[temp][m-1]);
                m--;
                
            }else if(cnt%4 == 2){

                for(int temp = m-1; j <= temp; temp--) 
                    vec.push_back(mat[n-1][temp]);
                n--;

            }else if(cnt%4 == 3){
                for(int temp = n-1; i <= temp; temp--) 
                    vec.push_back(mat[temp][j]);
                j++;
            }
            cnt++;
        }
        
        return vec;
    }
};