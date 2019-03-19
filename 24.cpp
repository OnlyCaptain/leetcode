#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* swapPairs(ListNode* head) {
    ListNode* pre, *cur;
    int tmp;
    pre = head;
    while (pre != NULL) {
        cur = pre->next;
        if (cur == NULL) {
            pre = NULL;
            continue;
        }
        else {
            tmp = pre->val;
            pre->val = cur->val;
            cur->val = tmp;
        }
        pre = pre->next->next;
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

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    printList(head);
    printList(swapPairs(head));

}