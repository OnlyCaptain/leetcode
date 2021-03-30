#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode():val(0),next(nullptr) {}
    ListNode(int x):val(x),next(nullptr) {}
    ListNode(int x, ListNode *next):val(x),next(next) {}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    void reverseFull(ListNode* head) {
        ListNode *pre = nullptr, *cur = head;
        while (cur != nullptr) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *first = new ListNode(-1);
        first->next = head;
        ListNode *leftNode, *rightNode, *pre = first;
        for (int i = 0; i < left-1; i ++) {
            pre = pre->next;
        }
        rightNode = pre;
        for (int i = 0; i < right-left+1; i ++) {
            rightNode = rightNode->next;
        }
        leftNode = pre->next;
        ListNode *cur = rightNode->next;
        rightNode->next = nullptr;
        pre->next = nullptr;
        
        reverseFull(leftNode);

        pre->next = rightNode;
        leftNode->next = cur;
        return first->next;
    }
};

int main() {

}