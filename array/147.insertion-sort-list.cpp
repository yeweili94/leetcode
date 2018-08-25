/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* pre = dummy;
        ListNode* cur = head;
        ListNode* next = cur->next;
        while (cur) {
            pre = dummy;
            while (pre && pre->next && pre->next->val < cur->val) {
                pre = pre->next;
            }
            next = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = next;
        }
        return dummy->next;
    }
};
