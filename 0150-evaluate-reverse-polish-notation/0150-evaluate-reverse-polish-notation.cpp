class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stck;
        for (auto &token: tokens) {
            if (token != "+" && token != "-" && token != "*" && token != "/") {
                stck.push(stoi(token));
            }
            else {
                int num1 = stck.top();
                stck.pop();
                int num2 = stck.top();
                stck.pop();
                if (token == "+") {
                    stck.push(num2 + num1);
                }
                else if (token == "-") {
                    stck.push(num2 - num1);
                }
                else if (token == "*") {
                    stck.push(num2 * num1);
                }
                else if (token == "/") {
                    stck.push(num2 / num1);
                }
            }
        }
        return stck.top();
    }
};