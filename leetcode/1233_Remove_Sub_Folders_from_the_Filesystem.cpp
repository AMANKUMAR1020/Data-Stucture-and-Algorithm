#define all(x) (x).begin(), (x).end()

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& arr) {
    int n = arr.size();
    sort(all(arr));
    vector<string> ans;
    ans.push_back(arr[0]);

    for(int i=1; i<arr.size(); i++){
        string str="";
        int m = arr[i].size();
        int size = ans.size()-1;
        int j;

        for(j=0; j<m; j++){

            if(arr[i][j] == '/' && str.size() > 1){
                if(str == ans[size]){
                    break;
                }
            }
            str += arr[i][j];
        }

        if(j==m){ans.push_back(str);}
        }
        return ans;       
    }
};
