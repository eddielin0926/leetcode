#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode head;
        ListNode **nxt = &(head.next);
        while (l1 && l2)
        {
            ListNode *cur = new ListNode(l1->val + l2->val + carry);
            if (cur->val >= 10) {
                carry = 1;
                cur->val %= 10; 
            } else {
                carry = 0;
            }
            *nxt = cur;
            nxt = &(cur->next);
            l1 = l1->next;
            l2 = l2->next;
        }
        if (!l1) {
            l1 = l2;
        }
        while (l1)
        {
            ListNode *cur = new ListNode(l1->val + carry);
            if (cur->val >= 10) {
                carry = 1;
                cur->val %= 10; 
            } else {
                carry = 0;
            }
            *nxt = cur;
            nxt = &(cur->next);
            l1 = l1->next;
        }
        if (carry) {
            *nxt = new ListNode(1);
        }
        return head.next;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    ListNode l1, l2;
    s.addTwoNumbers(&l1, &l2);
    return 0;
}
