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







class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int l = 0, r = height.size()-1;
        int maxL = height[l];
        int maxR = height[r];

        while(l<r){
            if(maxL < maxR){
                ans += maxL - height[l];
                maxL = max(maxL, height[++l]);
            }else{
                ans += maxR - height[r];
                maxR = max(maxR, height[--r]);
            }
        }
        return ans;
    }
};


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        vector<int> l(n);
        vector<int> r(n);

        for(int i=0; i<n; i++)
            l[i] = i==0 ? height[i] : max(height[i], l[i-1]);

        for(int i=n-1; i>=0; i--)
            r[i] = i==n-1 ? height[i] : max(height[i], r[i+1]);

        for(int i=0; i<n; i++)
            ans += min(l[i], r[i]) - height[i];
        
        return ans;
    }
};

