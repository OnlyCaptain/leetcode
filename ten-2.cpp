#include <iostream>
#include <vector>
using namespace std;

struct node {
    node* left;
    node* right;
    int val;
    node(int v):val(v),left(nullptr),right(nullptr) {};
};

void getPathSum(int presum, int& sum, node* cur) {
    if (cur == nullptr) return;
    cout << cur->val << " ";
    if (cur->left == nullptr && cur->right == nullptr) {
        presum *= 10;
        presum += cur->val;
        sum += presum;
        return;
    }
    presum *= 10;
    presum += cur->val;
    if (cur->left != nullptr) getPathSum(presum, sum, cur->left);
    if (cur->right != nullptr) getPathSum(presum, sum, cur->right);
}

int main() {
    node* root = new node(4);
    root->left = new node(9);
    root->right = new node(0);
    root->left->left = new node(5);
    root->left->right = new node(1);
    int sum = 0;
    getPathSum(0, sum, root);
    cout << sum << endl;
}