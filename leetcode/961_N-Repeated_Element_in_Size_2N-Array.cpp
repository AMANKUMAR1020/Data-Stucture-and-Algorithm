#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_map<int, int> count;

        for (int x : A) {
            count[x]++;
        }

        for (const auto& kv : count) {
            if (kv.second > 1)
                return kv.first;
        }

        // Problem guarantees an answer exists
        return -1;
    }
};
