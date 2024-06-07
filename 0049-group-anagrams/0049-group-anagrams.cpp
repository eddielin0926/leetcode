class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> hashMap;
        for (auto &str: strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            if (hashMap.find(sortedStr) != hashMap.end()) {
                hashMap[sortedStr].push_back(str);
            }
            else {
                hashMap[sortedStr] = {str};
            }
        }
        vector<vector<string>> result;
        for (auto &it: hashMap) {
            result.push_back(it.second);
        }
        return result;
    }
};