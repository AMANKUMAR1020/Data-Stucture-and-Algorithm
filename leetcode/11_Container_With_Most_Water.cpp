class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        
        int i = 0, j = n-1;

        while(i < j){
            int w = j - i;
            int h = min(height[i], height[j]);
            
            if(height[i] < height[j])
                i++;
            else
                j--;
            // cout<<w*h<<" "<<w<<" "<<h<<" : "<<i<<" "<<j<<endl;
            ans = max(ans, w*h);

        }

        return ans;
    }
};














// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int n = height.size();
//         int ans = 0;
        
//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 int w = j - i;
//                 int h = min(height[i], height[j]);

//                 ans = max(ans, w*h);
//             }
//         }
//         return ans;
//     }
// };
