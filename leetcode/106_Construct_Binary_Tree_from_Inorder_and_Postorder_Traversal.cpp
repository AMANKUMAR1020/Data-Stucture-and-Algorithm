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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return build(postorder, inorder, 0, n-1, 0, n-1);
    }
private:
    TreeNode* build(vector<int>& postorder, vector<int>& inorder, int postStart, int postEnd, int inStart, int inEnd){

        if(postStart > postEnd || inStart > inEnd){
            return nullptr;
        }

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inIndex = inStart;

        while(inIndex <= inEnd && inorder[inIndex] != postorder[postEnd]){
            inIndex++;
        }

        int leftSize = inIndex - inStart;

        root->left = build(postorder, inorder, postStart, postStart + leftSize - 1, inStart, inIndex-1);

        root->right = build(postorder, inorder, postStart+leftSize, postEnd-1, inIndex+1, inEnd);

        return root;
    }
};
