class Solution {
public:
    bool isAlphanumeric(char c) {
        if (c >= 'a' && c <= 'z') {
            return true;
        }
        if (c >= 'A' && c <= 'Z') {
            return true;
        }
        if (c >= '0' && c <= '9') {
            return true;
        }
        return false;
    }
    char lowercase(char c) {
        if (c >= 'a' && c <= 'z') {
            return c;
        }
        if (c >= 'A' && c <= 'Z') {
            return (c - 'A') + 'a';
        }
        return c;
    }
    bool isPalindrome(string s) {
        int n = s.length();
        int left = 0, right = n - 1;
        while (left < right) {
            while (left < n && !isAlphanumeric(s[left])) {
                left += 1;
            }
            while (right >= 0 && !isAlphanumeric(s[right])) {
                right -= 1;
            }
            if (left == n && right != -1) {
                return false;
            }
            if (left != n && right == -1) {
                return false;
            }
            if (left == n && right == -1) {
                return true;
            }
            if (lowercase(s[left]) != lowercase(s[right])) {
                return false;
            }
            left += 1;
            right -= 1;
        }
        return true;
    }
};