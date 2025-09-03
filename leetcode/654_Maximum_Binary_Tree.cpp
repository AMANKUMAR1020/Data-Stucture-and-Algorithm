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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
         return buildTree(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* buildTree(vector<int>& nums, int start, int end) {
        if (start > end) return nullptr;

        int maxIdx = start;
        for (int i = start + 1; i <= end; ++i) {
            if (nums[i] > nums[maxIdx]) {
                maxIdx = i;
            }
        }

        TreeNode* node = new TreeNode(nums[maxIdx]);
        node->left = buildTree(nums, start, maxIdx - 1);
        node->right = buildTree(nums, maxIdx + 1, end);
        return node;
    }
};



/*
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        return bfs(nums,0,n-1);
    }
private:
    TreeNode* bfs(vector<int>& nums, int start, int end){
        TreeNode* temp = nullptr;
        if(start == end)
            return nullptr;

        int maxi_ind = start;

        for(int i=start; i<=end; i++)
            if(nums[maxi_ind] < nums[i])
                maxi_ind = i;

        temp->val = new TreeNode(nums[maxi_ind]);
        temp->left = bfs(nums, 0, maxi_ind - 1);
        temp->right = bfs(nums, maxi_ind + 1, end);

        return temp;
    }
};

// 3,2,1,6,0,5
// 3,2,1   6   0,5
//         6
// 3             5
//     2       0
//        1
*/
