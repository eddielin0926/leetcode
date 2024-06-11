class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> one2nine(10);
        for (int i = 0; i < 9; i++) {
            one2nine.assign(10, false);
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') {
                    continue;
                }
                int num = c - '0';
                if (one2nine[num]) {
                    return false;
                }
                one2nine[num] = true;
            }
        }
        for (int j = 0; j < 9; j++) {
            one2nine.assign(10, false);
            for (int i = 0; i < 9; i++) {
                char c = board[i][j];
                if (c == '.') {
                    continue;
                }
                int num = c - '0';
                if (one2nine[num]) {
                    return false;
                }
                one2nine[num] = true;
            }
        }
        for (int k = 0; k < 3; k++) {
            for (int l = 0; l < 3; l++) {
                one2nine.assign(10, false);
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char c = board[k*3 + i][l * 3 + j];
                        if (c == '.') {
                            continue;
                        }
                        int num = c - '0';
                        if (one2nine[num]) {
                            return false;
                        }
                        one2nine[num] = true;
                    }
                }
            }
        }
        return true;
    }
};