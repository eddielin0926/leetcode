class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        vector<vector<int>> results;
        for (int i = 0; i < num2.size(); i++) {
            vector<int> currentResult(i, 0);
            int carry = 0;
            int digit2 = num2[i] - '0';
            for (auto digit1: num1) {
                int product = (digit1 - '0') * digit2 + carry;
                carry = product / 10;
                currentResult.push_back(product % 10);
            }
            if (carry) {
                currentResult.push_back(carry);
            }
            results.push_back(currentResult);
        }

        vector<int> answer = results.back();
        vector<int> newAnswer;
        results.pop_back();

        for (auto result: results) {
            newAnswer.clear();
            int carry = 0;

            for (int i = 0; i < answer.size() || i < result.size(); i++) {
                int digit1 = i < result.size() ? result[i] : 0;
                int digit2 = i < answer.size() ? answer[i] : 0;

                int sum = digit1 + digit2 + carry;
                carry = sum / 10;
                newAnswer.push_back(sum % 10);
            }

            if (carry) {
                newAnswer.push_back(carry);
            }
            answer = newAnswer;
        }

        string res;
        for (auto iter = answer.rbegin(); iter != answer.rend(); iter++) {
            res.push_back(*iter + '0');
        }

        return res;
    }
};