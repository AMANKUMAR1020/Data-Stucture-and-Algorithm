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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return build(preorder, inorder, 0, n-1, 0, n-1);
    }
private:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preStart,int preEnd, int inStart, int inEnd){
        if(preStart > preEnd || inStart > inEnd){
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);

        int inIndex = inStart;
        while(inIndex < inEnd && inorder[inIndex] != preorder[preStart]){
            inIndex++;/**
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return build(preorder, inorder, 0, n-1, 0, n-1);
    }
private:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preStart,int preEnd, int inStart, int inEnd){
        if(preStart > preEnd || inStart > inEnd){
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);

        int inIndex = inStart;
        while(inIndex < inEnd && inorder[inIndex] != preorder[preStart]){
            inIndex++;
        }

        int leftSize = inIndex - inStart;

        root->left = build( preorder, inorder, preStart + 1, preStart + leftSize, inStart, inIndex-1 );

        root->right = build( preorder, inorder, preStart + leftSize + 1, preEnd, inIndex + 1, inEnd );

        return root;
    }
};

// class Solution {
// public:
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         int n = preorder.size();
//         return build(head,preorder, inorder, 0, n,0);
//     }
// private:
//     TreeNode* build(TreeNode* head,vector<int>& preorder,vector<int>& inorder,int i,int n, int nextPreorderValue){
//         if(nextPreorderValue >= n || i>=n || i<0)
//             return nullptr;

//         TreeNode* root;
//         for(int j=i; j<n; j++){
//             cout<<inorder[j]<<" "<<j<<endl;
//             int num1 = inorder[j];
//             int num2 = preorder[nextPreorderValue];

//             if(num1 == num2){           
//                 TreeNode* temp = new TreeNode(inorder[j]);
                
//                 nextPreorderValue++;                
//                 temp->left = build(head, preorder, inorder, 0, j-1, nextPreorderValue);

//                 nextPreorderValue++;
//                 temp->right = build(head, preorder, inorder, j+1, n, nextPreorderValue);

//                 root = temp;

//                 break;
//             }
//         }
//         return root;
//     }
// };
        }

        int leftSize = inIndex - inStart;

        root->left = build( preorder, inorder, preStart + 1, preStart + leftSize, inStart, inIndex-1 );

        root->right = build( preorder, inorder, preStart + leftSize + 1, preEnd, inIndex + 1, inEnd );

        return root;
    }
};
