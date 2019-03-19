#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// 指针之道 玄妙之极

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode*);

ListNode* reversePart(ListNode* begin, ListNode* end) {  // [ )
    ListNode* tmp, *next;
    next = end;
    while (begin != end) {
        tmp = begin->next;
        begin->next = next;
        next = begin;
        begin = tmp;
    }
    return next;
}


ListNode* reverseKGroup(ListNode* head, int k) {
    if (k <= 1) return head;
    ListNode *cur, *result=NULL, *last=NULL;
    int i;
    while (head != NULL) {
        i = 0;
        cur = head;
        while (i < k && cur != NULL) {
            cur = cur->next;
            i ++;
        }
        if (i != k) 
            break;
        auto tmp = reversePart(head, cur);
        if (last != NULL)
            last->next = tmp;
        if (result == NULL) 
            result = tmp;
        last = head;
        head = cur;
    }
    return (result == NULL)?head:result;
}


ListNode* reverseKGroup_1(ListNode* head, int k) {
    if (k <= 1) return head;
    ListNode *pre, *cur;
    int i=0;
    pre = head;
    while (pre != NULL) {
        cur = pre;
        i = 0;
        // stack<int> tmp;
        // int tmp[100];
        vector<int> tmp;
        // int size=0;
        while (i < k) {
            // tmp.push(cur->val);
            tmp.push_back(cur->val);
            cur = cur->next;
            i ++;
            if (cur == NULL) 
                break;
        }
        if (cur == NULL && i < k) 
            pre = NULL;
        i -= 1;
        while (pre != cur) {
            pre->val = tmp[i];
            // tmp.pop();
            pre = pre->next;
            i --;
        }
    }    
    return head;
}


void printList(ListNode* head) {
    cout << head->val;
    head = head->next;
    while (head != NULL) {
        cout << "->" << head->val;
        head = head->next;
    }
    cout << endl;
}


int main ()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    printList(head);
    printList(reverseKGroup(head, 2));
}