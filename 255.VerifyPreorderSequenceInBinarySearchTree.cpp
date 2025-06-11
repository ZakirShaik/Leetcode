#include <stack>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <iostream>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 };

class Solution {
    //Solution 3: (Optimal but modifying input array) Time Complexity: O(n); Space Complexity: O(1)
public:
    bool verifyPreorder(vector<int>& preorder) {
        int minLimit = INT_MIN;
        int i = 0;
        for(auto ele : preorder) {
            while(i > 0 && ele > preorder[i-1]) {
                minLimit = preorder[i-1];
                --i;
            }
            if(ele <= minLimit) return false;
            preorder[i++] = ele;
        }
        return true;
    }

    //Solution 2: (Optimal) Time Complexity: O(n); Space Complexity: O(n)
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> s;
        int minLimit = INT_MIN;
        for(auto ele : preorder) {
            while(!s.empty() && ele > s.top()) {
                minLimit = s.top();
                s.pop();
            }
            if(ele <= minLimit) return false;
            s.push(ele);
        }
        return true;
    }

    //Solution 1: (Not optimal) Time Complexity: O(2n) ~ O(n); Space Complexity: O(3n) ~ O(n)
// public:
//     bool verifyPreorder(vector<int>& preorder) {
//         stack<TreeNode*> s;
//         TreeNode* root = new TreeNode(preorder[0]);
//         s.push(root);
//         TreeNode* prev = nullptr;
//         int i = 1;
//         while(!s.empty() && i < preorder.size()) {
//             TreeNode* newNode = new TreeNode(preorder[i]);
//             if(preorder[i] < s.top()->val) {
//                 s.top()->left = newNode;
//             } else {
//                 while(!s.empty() && preorder[i] > s.top()->val) {
//                     prev = s.top();
//                     s.pop();
//                 }
//                 prev->right = newNode;
//             }
//             s.push(newNode);
//             i++;
//         }
//         prev = nullptr;
//         return isBst(root, prev);
//     }
// public:
//     bool isBst(TreeNode* root, TreeNode* &prev) {
//         if(root == nullptr) return true;
//         bool leftResult = isBst(root->left, prev);
//         bool result = true;
//         if(prev) {
//             if(root->val < prev->val) result = false;
//         }
//         prev = root;
//         bool rightResult = isBst(root->right, prev);
//         return leftResult && rightResult && result;
//     }
};

int main(int argc, const char * argv[]) {
    TreeNode* root = new TreeNode(10);
    root -> left = new TreeNode(5);
    root -> right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root -> right -> left = new TreeNode(12);
    root->right->right = new TreeNode(17);

    vector<int> preorder = {5,2,1,3,6,2};

    Solution sol;
    cout << sol.verifyPreorder(preorder) << endl;

    return 0;
}
