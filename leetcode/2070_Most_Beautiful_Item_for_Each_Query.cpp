class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {
        vector<int> ans(queries.size());

        // Sort and store max beauty
        sort(items.begin(), items.end(),
             [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });

        int maxBeauty = items[0][1];
        for (int i = 0; i < items.size(); i++) {
            maxBeauty = max(maxBeauty, items[i][1]);
            items[i][1] = maxBeauty;
        }

        for (int i = 0; i < queries.size(); i++) {
            // answer i-th query
            ans[i] = binarySearch(items, queries[i]);
        }

        return ans;
    }

    int binarySearch(vector<vector<int>>& items, int targetPrice) {
        int left = 0;
        int right = items.size() - 1;
        int maxBeauty = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (items[mid][0] > targetPrice) {
                right = mid - 1;
            } else {
                // Found viable price. Keep moving to right
                maxBeauty = max(maxBeauty, items[mid][1]);
                left = mid + 1;
            }
        }
        return maxBeauty;
    }
};










/*
#define all(x) x.begin(), x.end()

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) { 
        int n = items.size();  // The number of items (number of rows in items)
        int m = items[0].size();  // The number of columns in items (usually 2 based on the problem)
        
        vector<int> vec(1e5, 0);  // A large vector to hold max values up to 100000
        
        // Sorting items: first by the first element, and if equal, by the second element
        sort(all(items), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]) 
                return a[1] < b[1];  // Sort by second element if first elements are equal
            return a[0] < b[0];  // Sort by first element
        });

        int maxi = INT_MIN;

        // Traverse through the items and fill the 'vec' array with max values
        for (auto& item : items) {
            maxi = max(maxi, item[1]);
            vec[item[0]] = maxi;  // Store the max value at the index corresponding to the first element of item
        }

        // Now propagate the maximum values across the vector to make sure vec[i] is the max value for all i <= current
        int maxLimit = items.back()[0];  // The maximum limit is determined by the largest first element in items
        maxi = INT_MIN;
        
        for (int i = 0; i <= maxLimit; i++) {
            maxi = max(vec[i], maxi);  // Update maxi with the largest value so far
            vec[i] = maxi;  // Update vec[i] with the largest value encountered so far
        }

        // For each query, replace it with the corresponding value from the 'vec' array
        for (int& q : queries) {
                if(q > maxLimit)
                    q = vec[maxLimit];
                else
                    q = vec[q];  // Set each query to the precomputed maximum value
        }
        
        return queries;
    }
};

*/
