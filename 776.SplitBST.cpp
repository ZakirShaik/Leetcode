#include <iostream>
#include <stack>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Solution {

//Solution 3: Time Complexity: O(h); Space Complexity: O(1); Where 'h' is the height of the tree.
public:
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        TreeNode *dummyLeft = new TreeNode(-1), *dummyRight = new TreeNode(-1);
        TreeNode *leftCurrent = dummyLeft, *rightCurrent = dummyRight;
        while(root != nullptr) {
            if(root->val > target) {
                rightCurrent->left = root;
                rightCurrent = rightCurrent->left;
                root = root->left;
            } else {
                leftCurrent->right = root;
                leftCurrent = leftCurrent->right;
                root = root->right;
            }
        }
        leftCurrent->right = nullptr;
        rightCurrent->left = nullptr;
        return {dummyLeft->right, dummyRight->left};
    }

/*
Solution 2: Time Complexity: O(h); Space Complexity: O(h); Where 'h' is the height of the tree.
        vector<TreeNode*> result = {nullptr, nullptr};
        stack<TreeNode*> s;
        while(root != nullptr) {
            s.push(root);
            if(root->val > target)
                root = root->left;
            else root = root->right;
        }
        while(!s.empty()) {
            TreeNode* node = s.top();
            if(node->val > target) {
                node->left = result[1];
                result[1] = node;
            } else {
                node->right = result[0];
                result[0] = node;
            }
            s.pop();
        }
        return result;
*/

/*
Solution 1: Time Complexity: O(h); Space Complexity: O(h); Where 'h' is the height of the tree.
public:
    vector<TreeNode*> splitBST(TreeNode* root, int target) {      
        if(root == nullptr) return {nullptr, nullptr};
        if(root->val > target) {
            vector<TreeNode*> leftSplit = splitBST(root->left, target);
            root->left = leftSplit[1];
            return {leftSplit[0], root};
        } else {
            vector<TreeNode*> rightSplit = splitBST(root->right, target);
            root->right = rightSplit[0];
            return {root, rightSplit[1]};
        }
    }
*/
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
    vector<TreeNode*> res = sol.splitBST(root, 12);
    return 0;
}
