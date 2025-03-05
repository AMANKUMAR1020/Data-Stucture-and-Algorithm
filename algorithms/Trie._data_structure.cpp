struct Node{
    Node* links[26];
    bool flag = false;

    bool containKey(char ch){
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node* node){
        links[ ch - 'a'] = node;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }
};

class Trie{
private:
    Node* root;

    // Helper function to free memory
    void freeMemory(Node* node) {
        if (node == nullptr) return;
        for (int i = 0; i < 26; i++) {
            freeMemory(node->links[i]);
        }
        delete node;
    }

public:
    Trie(){
        root = new Node();
    }

    ~Trie() {
        freeMemory(root);
    }

    void insert(string const& str){
        Node* node = root;
        for(int i=0; i<str.size(); i++){
            if(!node->containKey(str[i])){                
                node->put(str[i], new Node());
            }
            node = node->get(str[i]);
        }
        node->setEnd();
    }

    bool search(string const& str){
        Node* node = root;
        for(int i=0; i<str.size(); i++){
            if(!node->containKey(str[i])){                
                return false;
            }
            node = node->get(str[i]);
        }
        return node->isEnd();
    }

    bool StartWith(string const& str){
        Node* node = root;
        for(int i=0; i<str.size(); i++){
            if(!node->containKey(str[i])){
                return false;
            }
            node = node->get(str[i]);
        }
        return true;
    }
};
