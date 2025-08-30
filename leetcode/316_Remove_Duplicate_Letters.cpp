class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26, 0);
        vector<bool> visited(26, false);
        string result = "";

        // Count frequency of each character
        for (char c : s) {
            count[c - 'a']++;
        }

        for (char c : s) {
            int index = c - 'a';
            count[index]--;

            if (visited[index]) continue;

            // Remove characters that are bigger than current and still have remaining counts
            while (!result.empty() && c < result.back() && count[result.back() - 'a'] > 0) {
                visited[result.back() - 'a'] = false;
                result.pop_back();
            }

            result += c;
            visited[index] = true;
        }

        return result;
    }
};






// class Solution {
// public:
//     string removeDuplicateLetters(string s) {
//         string str="";
//         int n = s.size();
//         vector<bool> check(26,false);

//         for(int i=n-1; i>0; i--){
//             if(check[ s[i] - 'a' ] == true){
//                 str = newStr(str, s[i] + str);
//                 check[s[i] - 'a'] = false;
//             }else{
//                 str = s[i] + str;
//                 check[s[i] - 'a'] = true;
//             }
//         }
//         str = newStr(str, s[0] + str);
//         return str;
//     }
// private:
//     string newStr(string str1, string str2){
//         int n = str2.size();
//         bool ok = false;
//         string str=""; 
//         str += str2[0];

//         for(int i=0; i<n; i++){
//             if(str1[i] == str2[i]){
//                 continue;
//             }else if(str1[i] < str2[i]){
//                 return str1;
//             }else{
//                 ok = true;
//                 break;
//             }
//         }
//         if(ok){
//             for(char c : str2)
//                 if(c != str2[0])
//                     str += c;
//             return str;
//         }
//         return str1;
//     }
// };




