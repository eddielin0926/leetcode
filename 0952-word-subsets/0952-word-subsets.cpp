class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int> count2;
        for (const string& word : words2) {
            unordered_map<char, int> countw;
            for (char c : word) {
                countw[c] += 1;
            }
            for (const auto& it : countw) {
                count2[it.first] = max(count2[it.first], it.second);
            }
        }

        vector<string> res;
        for (const string& word : words1) {
            bool flag = true;
            unordered_map<char, int> countw;
            for (char c : word) {
                countw[c] += 1;
            }
            for (const auto& it : count2) {
                if (countw[it.first] < it.second) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                res.push_back(word);
            }
        }
        return res;
    }
};