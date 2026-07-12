/* Structure for tree and linked list
class Node {
  public:
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    Node* prev = NULL;
    void inorder(Node* root, Node*& head){
        if(!root)
            return;
        
        inorder(root->left, head);
        
        if(!head)
            head = root;
            
        root->left = prev;
        
        if(prev)
            prev->right = root;
        
        prev = root;
        
        inorder(root->right, head);
        
    }
    
    Node* treeToDLL(Node* root) {
        Node* head = nullptr;
        inorder(root, head);
        return head;
    }
};

// This function should return head to the DLL
class Solution {
  public:
  Node* ans = NULL;
  Node* curr = NULL;
    void preorder(Node* root){
        
        if(root->left != NULL){
            preorder(root->left);
        }
        
        if(ans == NULL){
            ans = root;
            curr = ans;
        }else{
            curr->right = root;
            root->left = curr;
            curr = curr->right;
        }
        
        if(root->right != NULL){
            preorder(root->right);
        }
    }
    Node* bToDLL(Node* root) {
        preorder(root);
        return ans;
    }
};

// class Solution {
// public:
//     Node* prev = nullptr;

//     void inorderToDLL(Node* root, Node*& head) {
//         if (!root) return;

//         inorderToDLL(root->left, head);

//         if (!head) head = root;          // first node in inorder
//         root->left = prev;
//         if (prev) prev->right = root;

//         prev = root;

//         inorderToDLL(root->right, head);
//     }

//     Node* treeToDLL(Node* root) {
//         Node* head = nullptr;
//         inorderToDLL(root, head);
//         return head;
//     }
// };



/*

class Solution {
  public:
    Node* inorder(Node* root, Node* parent){
        
        if(root->left == NULL && root->right == NULL)
            return root;
        
        Node* Lnode = root->left;   root->left = NULL;
        Node* lNode = inorder(Lnode, root);
        
        lNode->right = parent;
        parent->left = lNode;
        
        Node* Rnode = root->right;   root->right = NULL;
        Node* rNode = inorder(Rnode, root);
        
        rNode->left = parent;
        parent->right = rNode;

        return rNode;
        
    }
    
    Node* treeToDLL(Node* root) {
        
        Node* Lnode = root->left;
        root->left = NULL;
        Node* last1 = inorder(Lnode, root);
        
        while(last1 != nullptr){
            cout<<last1->data<<" ";
            last1 = last1->left;
        }
        
        // Node* Rnode = root->right;
        // root->right = NULL;
        // Node* last2 = inorder(Rnode, root);
        
        
        // while(last->left != nullptr){
        //     // cout<<last->data<<" ";
        //     last = last->left;
        // }
        
        cout<<endl;
        
        // while(last != nullptr){
        //     cout<<last->data<<" ";
        //     last = last->right;
        // }
        return last1;
    }
};


*/
