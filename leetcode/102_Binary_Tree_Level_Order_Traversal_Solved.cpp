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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        if (root == nullptr) return vec; // Handle the case where the root is nullptr

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> temp;
            int levelSize = q.size(); // Number of nodes at the current level

            for (int i = 0; i < levelSize; ++i) { // Loop over the current level
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);

                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            vec.push_back(temp);
        }

        return vec;
    }
};
