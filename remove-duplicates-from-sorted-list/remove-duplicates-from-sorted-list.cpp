#include <iostream>

/*
	1->1->2   1->2
	1->1->2->3->3	1->2->3
*/

using namespace std;

struct ListNode {
	ListNode *next;
	int val;
	//ListNode(int x): val(x), next(NULL) {}
};

ListNode * deleteDuplicates(ListNode *head) {
	if (NULL == head || NULL == head->next) {
		return head;
	}
	ListNode * p = head;
	while (p->next != NULL) {
		if (p->val == p->next->val) { 
			p->next = p->next->next;
		} else {
			p = p->next;
		}
	}
	return head;
}

void printList(ListNode *head) {
	while (head != NULL) {
		cout<<head->val<<"->";
		head = head->next;
	}
	cout<<endl;
}

int main() {
	ListNode node1;
	ListNode node2;
	ListNode node3;
	ListNode node4;
	ListNode node5;
	
	node1.val = 1;	node1.next = &node2;
	node2.val = 1;	node2.next = &node3;
	node3.val = 2;	node3.next = &node4;
	node4.val = 3;	node4.next = &node5;
	node5.val = 3;	node5.next = NULL;
	
	printList(&node1);

	ListNode *ret = deleteDuplicates(&node1);

	printList(ret);
}