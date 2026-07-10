struct Cmp {
    bool operator()(Node* a, Node* b) const {
        return a->data > b->data; // min-heap
    }
};

class Solution {
public:
    Node* mergeKLists(vector<Node*>& arr) {
        Node dummy(-1);
        Node* curr = &dummy;

        priority_queue<Node*, vector<Node*>, Cmp> pq;

        for (auto node : arr)
            if (node) pq.push(node);

        while (!pq.empty()) {
            Node* t = pq.top(); pq.pop();
            curr->next = t;
            curr = curr->next;

            if (t->next) pq.push(t->next);
        }

        curr->next = nullptr;
        return dummy.next;
    }
};
