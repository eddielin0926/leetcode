class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.length();
        if (n == 0) {
            return {};
        }

        vector<int> answers;
        for (int i = 0; i < n; i++) {
            int move = 0;
            for (int j = 0; j < n; j++) {
                if (i == j)  {
                    continue;
                }
                if (boxes[j] == '1') {
                    move += abs(i - j);
                }
            }
            answers.push_back(move);
        }

        return answers;
    }
};