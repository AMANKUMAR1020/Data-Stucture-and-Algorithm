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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        return build(preorder, postorder, 0, n - 1, 0, n - 1);
    }

private:
    TreeNode* build(vector<int>& preorder, vector<int>& postorder, int preStart, int preEnd, int postStart, int postEnd) {

        if (preStart > preEnd || postStart > postEnd) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);

        if (preStart == preEnd) {
            return root;
        }

        int leftRootIndex = postStart;

        while (postorder[leftRootIndex] != preorder[preStart + 1]) {
            leftRootIndex++;
        }

        int leftSize = leftRootIndex - postStart + 1;
        root->left = build(preorder, postorder, preStart + 1, preStart + leftSize, postStart, leftRootIndex);

        root->right = build(preorder, postorder, preStart + leftSize + 1, preEnd, leftRootIndex + 1, postEnd - 1);

        return root;
    }
};

/*
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        return build(preorder, postorder, 0, n-1, 0, n-1);
    }
private:
    TreeNode* build(vector<int>& preorder, vector<int>& postorder, int preStart, int preEnd, int postStart, int postEnd){

        if(preStart > preEnd || postStart > postEnd){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[preStart]);

        if(preStart == preEnd){
            return root;
        }

        int leftIndex = postStart;

        while(postorder[leftIndex] != preorder[preStart + 1]){
            leftIndex++;
        }

        int leftSize = leftIndex - postStart + 1;

        root->left = build(preorder, postorder, preStart + 1, preStart + leftSize, postStart, leftIndex);

        root->right = build(preorder, postorder, preStart + leftSize + 1, preEnd, postStart + leftIndex + 1, postEnd);

        return root;
    }
};



class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        return build(preorder, postorder, 0, n-1, 0, n-1);
    }
private:
    TreeNode* build(vector<int>& preorder, vector<int>& postorder, int preStart, int preEnd, int postStart, int postEnd){
        
        if(preStart > preEnd || postStart > postEnd){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[preStart]);

        if(preStart == preEnd || postStart || postEnd){
            return root;
        }

        int preIndex = preStart;
        int postIndex = postEnd;
        unordered_map<int,bool> mp;
        
        while(preIndex < preEnd || postIndex < postEnd){
            if(mp.find(preorder[preIndex]) != mp.end()){
                break;
            }
            mp[preorder[preIndex]] = true;
            mp[postorder[postIndex]] = true;
            preIndex++;
            postIndex--;
        }
        int leftSize = preIndex - preStart;

        root->left = build(preorder, postorder, preStart + 1, preIndex - 1, postStart, postIndex+1);

        root->right = build(preorder, postorder, preIndex, preEnd, postIndex+1, postEnd);
        return root;
    }
};
*/
