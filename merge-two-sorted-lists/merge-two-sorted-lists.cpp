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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (NULL == l1) {
            return l2;
        }
        if (NULL == l2) {
            return l1;
        }
        ListNode *head = l1;
        ListNode *tmp2 = l2;
        while (l2 != NULL) {
            tmp2 = l2;
            l2 = l2->next;
            head = insert(head, tmp2);
        }
        return head;
    }
    
    ListNode *insert(ListNode *head, ListNode *toInsert) {
        if (toInsert->val < head->val) {
            toInsert->next = head;
            head = toInsert;
            return head;
        }
        ListNode *cur = head;
        while (cur->next != NULL && cur->next->val < toInsert->val) {
            cur = cur->next;
        }
        toInsert->next = cur->next;
        cur->next = toInsert;
        return head;
    }
};