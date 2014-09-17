#include <iostream>

/*
	1->1->2   1->2
	1->1->2->3->3	1->2->3
*/

using namespace std;

struct ListNode {
	ListNode *next;
	int val;
	ListNode(int x): val(x), next(NULL) {}
};

ListNode * reverseList(ListNode *node) {
    ListNode *p1 = node;
    if (NULL == node ||NULL == node->next) {
        return node;
    }
    ListNode *p2 = node->next;
    if (NULL == node->next->next) {
        p2->next= p1;
        p1->next = NULL;
        return p2;
    }
    ListNode *p3 = p2->next;
    node->next = NULL;
    while (p3->next != NULL) {
        p2->next = p1;
        p1 = p2;
        p2 = p3;
        p3 = p3->next;
    }
    p2->next = p1;
    p3->next = p2;
    return p3;
}

ListNode * mergeList(ListNode *first, ListNode *second) {
    if (NULL == first->next) {
        first->next = second;
        return first;
    }
    ListNode *head = first;
    ListNode *p1 = first->next;

    while (first->next != NULL) {
    	p1 = first->next;
    	first->next = second;
    	second = second->next;
    	first->next->next = p1;
    	first = p1;
    }
    first->next = second;
    return head;
}

void printList(ListNode *head) {
	while (head != NULL) {
		cout<<head->val<<"->";
		head = head->next;
	}
	cout<<endl;
}

void reorderList(ListNode *head) {
    if (NULL == head || NULL == head->next || NULL == head->next->next) {
        return;
    }
    // Cut in the middle
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next;
        fast = fast->next;
    }
    ListNode *second_head = slow->next;
    cout<<"second head "<<second_head->val<<endl;
    slow->next = NULL;
    // Reverse the second sub-list
    second_head = reverseList(second_head);
    printList(second_head);
    // Merge two sub-lists
    head = mergeList(head, second_head);
}

int main() {
	ListNode node1(1);
	ListNode node2(2);
	ListNode node3(3);
	//ListNode node4(4);
	
	node1.next = &node2;
	node2.next = &node3;
	node3.next = NULL;
	//node4.next = NULL;
	
	printList(&node1);

	reorderList(&node1);

	printList(&node1);
}