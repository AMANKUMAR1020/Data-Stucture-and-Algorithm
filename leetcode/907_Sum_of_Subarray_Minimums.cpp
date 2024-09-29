class Solution {
public:
   int sumSubarrayMins(vector<int>& arr) {
    const int MOD = 1e9 + 7;
    stack<int> s; // stack to keep track of previous minimum elements
    vector<int> counts(arr.size()); // array to keep count of min subarrays ending at each element
    long long sum = 0; // overall sum of min subarrays

    for (int i = 0; i < arr.size(); i++) {
        while (!s.empty() and arr[s.top()] >= arr[i]) {
            s.pop();
        }
        if (s.empty()) {
            counts[i] = (i + 1) * arr[i];
        } else {
            counts[i] = counts[s.top()] + (i - s.top()) * arr[i];
        }
        s.push(i);
        sum = (sum + counts[i]) % MOD; // add count for this element to overall sum
    }
    return sum;
}
};
