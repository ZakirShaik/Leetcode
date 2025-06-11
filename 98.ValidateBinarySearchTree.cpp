#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <unordered_set>
#include <algorithm>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Solution {
// Solution 1: Inorder recursion: Time Complexity: O(n); Space Complexity: O(n)
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return isBst(root, prev);
    }
public:
    bool isBst(TreeNode* root, TreeNode* &prev) {
        if(root == nullptr) return true;
        bool leftResult = isBst(root->left, prev);
        bool result = true;
        if(prev) {
            if(root->val <= prev->val) result = false;
        }
        prev = root;
        bool rightResult = isBst(root->right, prev);
        return leftResult && rightResult && result;
    }
};

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(10);
    root -> left = new TreeNode(5);
    root -> right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root -> right -> left = new TreeNode(12);
    root->right->right = new TreeNode(17);
    Solution sol;
    cout << sol.isValidBST(root) << endl;
    return 0;
}


