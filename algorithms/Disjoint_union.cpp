#include <bits/stdc++.h>
using namespace std;

class Disjoint {
private:
    vector<int> parent;
    vector<int> sizes;

public:
    Disjoint(int size) {
        parent.assign(size, 0);
        sizes.assign(size, 1);
        
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        return parent[x] == x ? x : (parent[x] = find(parent[x]));
    }

    bool Union(int x, int y) {
        int x_root = find(x);
        int y_root = find(y);
        
        if (x_root == y_root) return false;
        if (sizes[x_root] < sizes[y_root]) {
            swap(x_root, y_root);
        }
        
        sizes[x_root] += sizes[y_root];
        parent[y_root] = x_root;
        return true;
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};
