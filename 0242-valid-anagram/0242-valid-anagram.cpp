class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char, int> sMap;
        for (auto c: s) {
            sMap[c]++;
        }
        for (auto c: t) {
            if (sMap.find(c) != sMap.end()) {
                sMap[c]--;
            }
            else {
                return false;
            }
        }
        for (auto m: sMap) {
            if(m.second != 0) {
                return false;
            }
        }
        return true;
    }
};