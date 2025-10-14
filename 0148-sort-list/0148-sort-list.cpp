/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head) return NULL;
        if (!head->next) return head;

        ListNode* left = head;
        ListNode* right = getMid(head);
        ListNode* tmp = right->next;
        right->next = NULL;
        right = tmp;

        left = sortList(left);
        right = sortList(right);
        return merge(left, right);
    }
private:
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* head = NULL;
        ListNode** nxt = &head;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                *nxt = list1;
                nxt = &list1->next;
                list1 = list1->next;
                *nxt = NULL;
            } else {
                *nxt = list2;
                nxt = &list2->next;
                list2 = list2->next;
                *nxt = NULL;
            }
        }
        if (list1) {
            *nxt = list1;
        } else {
            *nxt = list2;
        }
        return head;
    }
};