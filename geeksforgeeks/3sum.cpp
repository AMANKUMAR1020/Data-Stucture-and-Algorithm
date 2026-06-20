//method 1
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0; i<n-2; i++){
            int target = nums[i];
            int j = i+1;
            int k = n-1;
            while(j < k){
                
                if((nums[j] + nums[k] + nums[i]) == 0){
                    vector<int> vec={nums[i], nums[j], nums[k]};
                    
                    if(ans.empty() || (ans.find(vec) == ans.end()))
                        ans.insert(vec);
                    j++;    k--;
                }else if((nums[j] + nums[k] + nums[i])< 0){
                    j++;

                }else{
                    k--;
                }
            }
        }
        vector<vector<int>> vec {ans.begin(), ans.end()};
        return vec;
    }
};





// method 2
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for(int i=0; i<n-2; i++){
            if(i>0 && nums[i-1] == nums[i])
                continue;

            int j = i+1;
            int k = n-1;
            int sum = 0;
            vector<int> vec;

            while(j < k){
                sum = nums[i] + nums[j] + nums[k];

                if(sum == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});

                    while(j+1<k && nums[j] == nums[j+1]){j++;}
                    while(j<k-1 && nums[k] == nums[k-1]){k--;}
                    j++; k--;

                } else if(sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }
            if(!vec.empty()){
                ans.push_back(vec);
            }
        }
        return ans;
    }
};

