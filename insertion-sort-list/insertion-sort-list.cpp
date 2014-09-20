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
    ListNode *insertionSortList(ListNode *head) {
        if (NULL == head || NULL == head->next) {
            return head;
        }
        ListNode *cur = head->next;
        ListNode *tmp = cur;
        head->next = NULL;
        while (cur != NULL) {
            tmp = cur;
            cur = cur->next; 
            head = insert(head, tmp);
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