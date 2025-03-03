class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> pre,suff,mid;

        for(int n : nums){
            if(pivot == n) 
                mid.push_back(n);
            else if(pivot < n) 
                pre.push_back(n);
            else 
                suff.push_back(n);
        }
        for(int n : pre){
            cout<<n<<" ";
        }
        for(int n : suff){
            cout<<n<<" ";
        }
        vector<int> ans = pre;
        ans.insert(ans.begin(), mid.begin(),mid.end());
        ans.insert(ans.begin(), suff.begin(),suff.end());

        return ans;
    }
};
