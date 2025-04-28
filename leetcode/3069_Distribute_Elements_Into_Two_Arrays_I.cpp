class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
    // int n = nums.size();
    //     vector<int> vec1, vec2;
    //     vec1.push_back(nums[0]);
    //     vec2.push_back(nums[1]);
        
    //     for(int i = 2; i < n; i++){
    //         if(vec1.back() > vec2.back())
    //             vec1.push_back(nums[i]);
    //         else
    //             vec2.push_back(nums[i]);
    //     }
        
    //     vec1.insert(vec1.end(), vec2.begin(), vec2.end());
    //     return vec1;
    // }

        int n = nums.size();
        vector<int> vec1, vec2;
        vec1.push_back(nums[0]);
        vec2.push_back(nums[1]);
        
        for(int i=2; i<n; i++){
            if(vec1.back() > vec2.back())
                vec1.push_back(nums[i]);
            else
                vec2.push_back(nums[i]);
        }
            vec1.insert(vec1.end(), vec2.begin(), vec2.end());
            return vec1;
    }
};
