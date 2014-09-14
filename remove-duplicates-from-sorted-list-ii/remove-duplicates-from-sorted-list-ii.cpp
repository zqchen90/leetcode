#include <iostream>

/*
	1->2->3->3->4->4->5   1->2->5
	1->1->1->2->3	2->3
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
	bool head_dup_flag = false;
	while (head->next != NULL) {
		if (head->val != head->next->val) {
			if (head_dup_flag) {
				head = head->next;
				head_dup_flag = false;
			} else {
				break;	
			}
			
		} else {
			head_dup_flag = true;
			head = head->next;
		}
	}
	if (head->next == NULL && head_dup_flag) {
		return NULL;
	}
	if (head == NULL || head->next == NULL) {
		return head ;
	}

	ListNode * p1 = head;
	ListNode * p2 = head->next;
	bool dup_flag = false;
	while (NULL != p2 && p2->next != NULL) {
		if (p2->val == p2->next->val) { 
			//p1->next = p2;
			p2->next = p2->next->next;
			dup_flag = true;
		} else {
			if (dup_flag) {
				p1->next = p2->next;
				p2 = p1->next;
				dup_flag = false;
			} else {
				p1 = p1->next;
				p2 = p1->next;
				dup_flag = false;
			}
		}
	}
	if (dup_flag) {
		p1->next = NULL;
	}
	return head;
}

void printList(ListNode *head) {
	if (NULL == head) {
		cout<<"null"<<endl;
		return;
	}
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
	ListNode node6;
	ListNode node7;
	
	node1.val = 1;	node1.next = &node2;
	node2.val = 1;	node2.next = &node3;
	node3.val = 1;	node3.next = &node4;
	node4.val = 2;	node4.next = &node5;
	node5.val = 3;	node5.next = NULL;
	printList(&node1);
	ListNode *ret = deleteDuplicates(&node1);
	printList(ret);
	cout<<endl;

	node1.val = 1;	node1.next = &node2;
	node2.val = 2;	node2.next = &node3;
	node3.val = 3;	node3.next = &node4;
	node4.val = 3;	node4.next = &node5;
	node5.val = 4;	node5.next = &node6;
	node6.val = 4;	node6.next = &node7;
	node7.val = 5;	node7.next = NULL;
	printList(&node1);
	ret = deleteDuplicates(&node1);
	printList(ret);
	cout<<endl;

	node1.val = 1;	node1.next = &node2;
	node2.val = 1;	node2.next = &node3;
	node3.val = 2;	node3.next = NULL;
	printList(&node1);
	ret = deleteDuplicates(&node1);
	printList(ret);
	cout<<endl;	

	node1.val = 1;	node1.next = &node2;
	node2.val = 1;	node2.next = NULL;
	printList(&node1);
	ret = deleteDuplicates(&node1);
	//cout<<":" <<(int)(NULL == ret)<<endl;
	printList(ret);	
	cout<<endl;

	node1.val = 1;	node1.next = &node2;
	node2.val = 1;	node2.next = &node3;
	node3.val = 2;	node3.next = &node4;
	node4.val = 2;	node4.next = NULL;
	printList(&node1);
	ret = deleteDuplicates(&node1);
	printList(ret);	
	cout<<endl;
}