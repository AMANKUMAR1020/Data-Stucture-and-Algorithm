class Solution {

public:

 int trap(vector<int>& height) {

    if (height.empty()) return 0;

    int n = height.size(), left = 0, right = n - 1, res = 0, maxleft = height[left], maxright = height[right];

    while (left < right) {

        if (height[left] <= height[right]) {

            maxleft = max(maxleft, height[left]);

            res += maxleft - height[left];

            ++left;

        } else {

            maxright = max(maxright, height[right]);

            res += maxright - height[right];

            --right;

        }

    }

    return res;

}

};
