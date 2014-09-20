/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
#include <algorithm> 
struct ListNodeSizeCompare {
    bool operator () ( ListNode *l1,  ListNode *l2) {
        if (l1 == NULL && l2 == NULL) {
            return true;
        }
        if (l1 == NULL) {
            return true;
        } 
        if (l2 == NULL) {
            return false;
        }
        int len1 = 0;
        int len2 = 0;
        ListNode *p = l1;
        while (p != NULL) {
            ++len1;
            p = p ->next;
        }
        p = l2;
        while (p != NULL) {
            ++len2;
            p = p ->next;
        }
        return len1 < len2;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int n = lists.size();
        if (0 == n) {
            return NULL;
        }
        priority_queue<ListNode *, vector<ListNode *>, ListNodeSizeCompare> waiting;
        for (int i = 0; i < n; ++i) {
            waiting.push(lists[i]);
        }
        ListNode *l1, *l2;
        while (waiting.size() > 1) {
            l1 = waiting.front();
            waiting.pop();
            l2 = waiting.front();
            waiting.pop();
            l1 = mergeTwoLists(l1, l2);
            if (l1 != NULL) {
                waiting.push(l1);
            }
        }
        return waiting.front();
    }
    
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