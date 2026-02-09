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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vec;
        bst(root,vec);
        int n = vec.size();
        return balanced(vec,0,n-1);  
    }
private:
    void bst(TreeNode* root, vector<int>& vec){
        if(root == nullptr)
            return ;
        bst(root->left,vec);
        vec.push_back(root->val);
        bst(root->right,vec);
    }

    TreeNode* balanced(vector<int>& vec, int l, int r){
        if(l > r)
            return nullptr;
        int mid = l + (r - l)/2;
        TreeNode* root = new TreeNode(vec[mid]);
        root->left = balanced(vec,l,mid-1);
        root->right = balanced(vec,mid+1,r);
        return root;
    }
};
