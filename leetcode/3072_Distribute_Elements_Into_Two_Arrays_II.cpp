class FenwickTree {
 public:
  FenwickTree(int n) : sums(n + 1) {}

  void add(int i, int delta) {
    while (i < sums.size()) {
      sums[i] += delta;
      i += lowbit(i);
    }
  }

  int get(int i) const {
    int sum = 0;
    while (i > 0) {
      sum += sums[i];
      i -= lowbit(i);
    }
    return sum;
  }

 private:
  vector<int> sums;

  static inline int lowbit(int i) {
    return i & -i;
  }
};

class Solution {
 public:
  vector<int> resultArray(vector<int>& nums) {
    vector<int> arr1;
    vector<int> arr2;
    const unordered_map<int, int> ranks = getRanks(nums);
    FenwickTree tree1(ranks.size());
    FenwickTree tree2(ranks.size());

    add(nums[0], arr1, tree1, ranks);
    add(nums[1], arr2, tree2, ranks);

    for (int i = 2; i < nums.size(); ++i) {
      const int greaterCount1 = arr1.size() - tree1.get(ranks.at(nums[i]));
      const int greaterCount2 = arr2.size() - tree2.get(ranks.at(nums[i]));
      if (greaterCount1 > greaterCount2)
        add(nums[i], arr1, tree1, ranks);
      else if (greaterCount1 < greaterCount2)
        add(nums[i], arr2, tree2, ranks);
      else if (arr1.size() > arr2.size())
        add(nums[i], arr2, tree2, ranks);
      else
        add(nums[i], arr1, tree1, ranks);
    }

    arr1.insert(arr1.end(), arr2.begin(), arr2.end());
    return arr1;
  }

 private:
  unordered_map<int, int> getRanks(const vector<int>& nums) {
    unordered_map<int, int> ranks;
    set<int> sorted(nums.begin(), nums.end());
    int rank = 0;
    for (const int num : sorted)
      ranks[num] = ++rank;
    return ranks;
  }

  void add(int num, vector<int>& arr, FenwickTree& tree,
           const unordered_map<int, int>& ranks) {
    arr.push_back(num);
    tree.add(ranks.at(num), 1);
  };
};







// class Solution {
// public:
//     vector<int> resultArray(vector<int>& nums) {
//         int n = nums.size();
//         multiset<int> set1, set2;
//         vector<int> vec1, vec2;
//         vec1.push_back(nums[0]);
//         vec2.push_back(nums[1]);
//         set1.insert(nums[0]);
//         set2.insert(nums[1]);
        
//         for(int i = 2; i < n; i++){
//             auto it1 = set1.upper_bound(nums[i]);
//             auto it2 = set2.upper_bound(nums[i]);
//             int greaterInVec1 = distance(it1, set1.end());
//             int greaterInVec2 = distance(it2, set2.end());
            
//             if(greaterInVec1 == greaterInVec2){
//                 if(vec1.size() <= vec2.size()){
//                     vec1.push_back(nums[i]);
//                     set1.insert(nums[i]);
//                 }else{
//                     vec2.push_back(nums[i]);
//                     set2.insert(nums[i]);
//                 }
//             }else if(greaterInVec1 > greaterInVec2){
//                 vec1.push_back(nums[i]);
//                 set1.insert(nums[i]);
//             }else{
//                 vec2.push_back(nums[i]);
//                 set2.insert(nums[i]);
//             }
//         }
//         vec1.insert(vec1.end(), vec2.begin(), vec2.end());
//         return vec1;
//     }
// };









// class Solution {
// public:
//     vector<int> resultArray(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> vec1, vec2;
//         vec1.push_back(nums[0]);
//         vec2.push_back(nums[1]);
        
//         for(int i = 2; i < n; i++){
//             if(greaterCount(vec1, nums[i]) == greaterCount(vec2, nums[i])){
//                 if(vec1.size() > vec2.size())
//                     vec2.push_back(nums[i]);
//                 else
//                     vec1.push_back(nums[i]);
//             }else if(greaterCount(vec1, nums[i]) > greaterCount(vec2, nums[i])){
//                 vec1.push_back(nums[i]);
//             }else{
//                 vec2.push_back(nums[i]);
//             }
//         }
//         vec1.insert(vec1.end(), vec2.begin(), vec2.end());
//         return vec1;
//     }
// private:    
//     int greaterCount(vector<int> &arr1, int target){
//         int cnt = 0;
//         for(int i = 0; i < arr1.size(); i++){
//             if(arr1[i] > target)
//                 cnt++;
//         }
//         return cnt;
//     }
// };
