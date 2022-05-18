#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr)
    {
    }
    ListNode(int x) : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode *next) : val(x), next(next)
    {
    }
};

class Solution
{
  public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
            return NULL;

        ListNode *cur = head;
        ListNode *nxt = head->next;
        while (nxt)
        {
            if (cur->val == nxt->val)
            {
                cur->next = nxt->next;
            }
            else {
                cur = nxt;
            }
            nxt = nxt->next;
        }

        return head;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    ListNode *n = NULL;
    cout << s.deleteDuplicates(n) << endl;
    return 0;
}
