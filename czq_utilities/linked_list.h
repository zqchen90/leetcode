#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "czqstring.h"
#include "stdlib.h"  // atoi

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

// Build a linked list from vector<int> 
ListNode * build_linked_list(std::vector<int> &vals) {
    ListNode *root = NULL;
    ListNode *prev = root;
    ListNode *cur;
    for (int i = 0; i < vals.size(); ++i) {
        if (0 == i) {  // root node
            root = new ListNode(vals[i]);
            prev = root;
        } else {
            cur = new ListNode(vals[i]);
            prev->next = cur;
            prev = cur;
        }
    }
    return root;
}

// Build a linked list from string
ListNode * build_linked_list(std::string str, const char delim) {
    using std::string;
    using std::vector;
    vector<string> elems = split(str, delim);
    vector<int> vals;
    for (int i = 0; i < elems.size(); ++i) {
        vals.push_back(atoi(elems[i].c_str()));
    }
    return build_linked_list(vals);
}

// Print linked list
void print_linked_list(const ListNode *root) {
    using std::cout;
    using std::endl;
    if (NULL == root) {
        cout<<"NULL";
    } else {
        const ListNode *p = root;
        cout<<p->val;
        p = p->next;
        while (p != NULL) {
            cout<<" => "<<p->val;
            p = p->next;
        }
    }
    cout<<endl;
}


#endif
