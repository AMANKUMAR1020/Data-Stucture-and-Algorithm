// class Solution {
//   public:
//     int findPages(vector<int> &arr, int k) {
//         int n = arr.size();
//         if(k > n)   return -1;
//         int l = *min_element(arr.begin(), arr.end());
//         int r = accumulate(arr.begin(), arr.end(),0);
//         int mid = 0, ans = 0;
//         sort(arr.begin(), arr.end());

//         while(l < r){
//             int target = l + (r-l)/2;
//             int temp = bs(arr, target);
//             if(k <= temp){
//                 ans = target;
//                 l = target + 1;
//             }else{
//                 r = target;
//             }
//         }
//         return ans;
//     }
    
//     int bs(vector<int>& arr, int target){
//         int temp = 0;
//         int cnt = 1;
//         for(int a : arr){
//             if(temp + a > target){
//                 cnt++;
//                 temp = a;
//             }else{
//                 temp += a;
//             }
//         }
//         return cnt;
//     }
// };



class Solution {
public:
    int findPages(vector<int>& arr, int k) {
        int n = arr.size();
        if (k > n) return -1;

        int l = *max_element(arr.begin(), arr.end());
        int r = accumulate(arr.begin(), arr.end(), 0);
        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int requiredStudents = countStudents(arr, mid);

            if (requiredStudents <= k) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }

    int countStudents(vector<int>& arr, int maxPages) {
        int students = 1, pages = 0;
        for (int a : arr) {
            if (pages + a > maxPages) {
                students++;
                pages = a;
            } else {
                pages += a;
            }
        }
        return students;
    }
};
