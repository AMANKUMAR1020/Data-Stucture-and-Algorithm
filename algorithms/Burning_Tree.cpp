class Solution {
public:
    unordered_map<Node*, Node*> parentMap;
    unordered_set<Node*> visited;
    Node* node=NULL;
    int ans = 0;

    void storeParents(Node* node, Node* parent) {
        if (!node) return;
        parentMap[node] = parent;      
        storeParents(node->left, node);
        storeParents(node->right, node);
    }
    
    void depthFirstSearch(Node* node, int time) {
        if (!node || visited.count(node)) return; // Use pointer comparison
        
        visited.insert(node); // Mark the node as visited
        ans = max(ans, time);
        //cout<<ans<<'\n';
        
        // Explore left, right, and parent
        depthFirstSearch(node->left, time + 1);
        depthFirstSearch(node->right, time + 1);
        depthFirstSearch(parentMap[node], time + 1);
    }
    
    Node* Target(Node* root, int target) {
        if (!root) return nullptr;
    
       // cout<<" root "<<root->data<<'\n';
        
        if (root->data == target){node = root;}
        
        if (root->left) Target(root->left, target);
        if (root->right) Target(root->right, target);
    }

    int minTime(Node* root, int target) {
        storeParents(root, nullptr);
        Target(root, target);
        
        if (node) {
            depthFirstSearch(node, 0);      
        }
        
        return ans;
    }
};
