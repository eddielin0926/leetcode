class Solution {
public:
    vector<int> minOperations(string boxes) {
        // Solution 1. 暴力解
        // 兩個迴圈來檢查任兩個 i, j 的距離
        // 當 boxes[j] 是 '1' 時就可以加到答案裡
        // int n = boxes.length();
        // if (n == 0) {
        //     return {};
        // }

        // vector<int> answers;
        // for (int i = 0; i < n; i++) {
        //     int move = 0;
        //     for (int j = 0; j < n; j++) {
        //         if (i == j)  {
        //             continue;
        //         }
        //         if (boxes[j] == '1') {
        //             move += abs(i - j);
        //         }
        //     }
        //     answers.push_back(move);
        // }

        // return answers;

        // Solution 2. 前綴和
        // 從左邊開始累加向右的移動，然後從右邊開始累加向左的移動
        // 以 boxes[0] == '1' 來說，每一個位置需要的移動就是 0, 1, 2, ...
        // 另外在累加的時候要記錄現在有多少顆球，每次要增加的移動數量就是球的數量
        // 而每一個位置需要的移動就是左的前綴和加右的前綴和
        int n = boxes.length();
        if (n == 0) {
            return {};
        }

        int leftPrefixMoves = 0;
        int rightPrefixMoves = 0;
        int balls = 0;
        vector<int> answers;

        for (int i = 0; i < n; i++) {
            leftPrefixMoves += balls;
            answers.push_back(leftPrefixMoves);
            if (boxes[i] == '1') {
                balls += 1;
            }
        }

        balls = 0;
        for (int i = n - 1; i >= 0; i--) {
            rightPrefixMoves += balls;
            answers[i] += rightPrefixMoves;
            if (boxes[i] == '1') {
                balls += 1;
            }
        }

        return answers;
    }
};