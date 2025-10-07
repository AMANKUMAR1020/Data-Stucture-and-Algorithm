using namespace std;

class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        int i=0, j=0;
        int cnt = 0;
        int ans = 0;

        while (i < n && j < n) {
            if (arr[i] < dep[j]) {
                cnt++;
                ans = max(ans, cnt);
                i++;
            } else {
                cnt--;
                j++;
            }
        }
        return ans;
    }
};



/*
class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        int ans = 0;
        int cnt = 0;
        vector<pair<int,char>> vec;
        for(int i=0; i<n; i++){
            vec.push_back({arr[i], '+'});
            vec.push_back({dep[i], '-'});
        }
        
        sort(vec.begin(), vec.end(), [](pair<int,char>& a, pair<int,char>& b){
            if(a.first == b.first)
                return a.second == '+';
            return a.first < b.first;
        });
        
        for(pair<int,char>& v : vec){
            if(v.second == '+')
                cnt++;
            else
                cnt--;
            ans = max(ans, cnt);
        }
        return ans;
    }
};


// (900,'+'), (940,'+'), (950,'+'), (1100,'+'), (1500,'+'), (1800,'+')
// (910,'-'), (1200,'-'), (1120,'-'), (1130,'-'), (1900,'-'), (2000,'-')



*/
