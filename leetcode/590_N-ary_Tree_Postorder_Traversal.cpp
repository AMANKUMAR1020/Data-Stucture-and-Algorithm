class Solution {
public:
vector<int> vec;
    void bts(Node* root){
        
        vector<Node*> temp = root->children;
        if(temp.empty()) return;
        
        for(int i=0; i<temp.size(); i++){
            bts(root->children[i]);
            vec.push_back(root->children[i]->val);
        }
    } 
    vector<int> postorder(Node* root) {
        if(root == nullptr)return {};
        if(root->children.empty())return {root->val};
        
        bts(root);
        vec.push_back(root->val);
        return vec;
    }
};
