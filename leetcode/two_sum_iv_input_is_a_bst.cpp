/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int i = 0, j = n-1;
        while(i < j){
            int sum = numbers[i] + numbers[j];
            if(sum == target)
                return true;
            else if(sum > target)
                j--;
            else
                i++;
        }
        return false;
    }

    void bst(TreeNode* root, vector<int>& nums){
        if(root == nullptr)
            return;
        bst(root->left, nums);
        nums.push_back(root->val);
        bst(root->right, nums);
    }

    bool dfs(TreeNode* root, int k, unordered_set<int>& st){
        if(root == nullptr)
            return false;

        if(st.find(root->val) != st.end())
            return true;

        st.insert(k - root->val);
        // st.insert(root->val + k);

        return dfs(root->left, k, st) ||  dfs(root->right, k, st);
    }

    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;

        return dfs(root, k, st);
    }
};
