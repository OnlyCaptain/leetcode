/* *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
#include <vector>
using namespace std;

class Solution {
public:
    void reversePrint(ListNode* head, vector<int>& ans) {
        if (head == nullptr) return;
        reversePrint(head->next, ans);
        ans.push_back(head->val);
    }
    vector<int> reversePrint(ListNode* head) {
        vector<int> ans;
        reversePrint(head, ans);
        return ans;
    }
};

int main() {

}