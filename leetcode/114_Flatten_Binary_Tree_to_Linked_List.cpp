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
    void flatten(TreeNode* root) {
        stack<TreeNode*> st;
        bfsPre(root, st);
        TreeNode* ans = nullptr;
        
        while(!st.empty()){
            TreeNode* temp = st.top(); st.pop();
            temp->left = nullptr;
            temp->right = ans;
            ans = temp;
        }
        root = ans;
    }
private:
    void bfsPre(TreeNode* root, stack<TreeNode*>& st){
        if(root == nullptr)
            return;
        st.push(root);      
        bfsPre(root->left, st);
        bfsPre(root->right, st);

    }
};
