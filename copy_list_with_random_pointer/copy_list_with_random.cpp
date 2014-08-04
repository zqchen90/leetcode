#include <iostream>
#include <map>
#include <vector>

using namespace std;

/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
https://oj.leetcode.com/problems/copy-list-with-random-pointer/

 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };

 Completed at 2014/8/3 by chenzhaoqun
 */

struct RandomListNode {
   int label;
   RandomListNode *next, *random;
   RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList(RandomListNode *head) {
    if (head == NULL) {
        return NULL;
    }
    RandomListNode *pointer;
    RandomListNode *copy_pointer = new RandomListNode(head->label);
    RandomListNode *copy_head = copy_pointer;
    
    map<RandomListNode *, int> address_index_map;
    vector<RandomListNode *> copy_address_list;

    pointer = head;
    //copy_pointer = &copy_head;
    int index = 0;
    address_index_map.insert(pair<RandomListNode *, int>(pointer, index));
    copy_address_list.push_back(copy_pointer);
    ++index;
    // first tranversal to copy next pointer
    while (pointer->next != NULL) {
    	pointer = pointer->next;
    	RandomListNode *next_copy_node = new RandomListNode(pointer->label);
    	copy_pointer->next = next_copy_node;
        copy_pointer = copy_pointer->next;

        address_index_map.insert(pair<RandomListNode *, int>(pointer, index));
        copy_address_list.push_back(copy_pointer);
        ++index;
    }

    // second traversal to copy the random pointer
    pointer = head;
    copy_pointer = copy_head;
    while (pointer != NULL) {
        if (pointer->random != NULL) {
            index = address_index_map[pointer->random];
            copy_pointer->random = copy_address_list[index];
        } else {
            copy_pointer->random = NULL;
        }
        pointer = pointer->next;
        copy_pointer = copy_pointer->next;
    }

    return copy_head;
}

void print_list(RandomListNode *head) {
	RandomListNode *ori_head = head;

	cout<<"Next list:"<<endl;
	cout<<head->label<<" -> ";
	while (head->next != NULL) {
		head = head->next;
		cout<<head->label<<" -> ";
	}
	cout<<endl;

	cout<<"Random list:"<<endl;
	head = ori_head;
	if (head->random != NULL) {
		cout<<head->label<<" ~> "<<head->random->label<<endl;
	}
	while (head->next != NULL) {
		head = head->next;
		if (head->random != NULL) {
			cout<<head->label<<" ~> "<<head->random->label<<endl;
		}
	}
}

void test_map(RandomListNode *head) {
	cout<<"test map";
	RandomListNode *ori_head = head;
	map<RandomListNode *, int> address_index_map;
	int index = 1;
	address_index_map[head] = index;
	//address_index_map.insert(map<RandomListNode *, int>::value_type(head, index));
	while (head->next != NULL) {
		head = head->next;
		++index;
		address_index_map[head] = index;
		//address_index_map.insert(map<RandomListNode *, int>::value_type(head, index));
	}
	cout<<"Get map: "<<address_index_map.size()<<endl;

	head = ori_head;
	cout<<address_index_map[head]<<endl;
	while (head->next != NULL) {
		head = head->next;
		cout<<address_index_map[head]<<endl;
	}
}

int main() {
	RandomListNode node1 = RandomListNode(1);
	RandomListNode node2 = RandomListNode(2);
	RandomListNode node3 = RandomListNode(3);
	RandomListNode node4 = RandomListNode(4);

	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = NULL;

	node1.random = &node3;
	node2.random = &node4;
	node3.random = &node4;
	node4.random = NULL;

	//print_list(&node1);
	//test_map(&node1);

    RandomListNode *copy = copyRandomList(&node1);
    print_list(copy);
}