#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int height(TreeNode* root) {
        if (root == NULL) return -1;
        int lh = 1 + height(root->left);
        int rh = 1 + height(root->right);
        if (lh > rh) return lh;
        else return rh;
    }

    void utility(TreeNode* root, int &max) {
        if (root == NULL) return;
        int lh = height(root->left);
        int rh = height(root->right);
        if ((lh + rh + 2) >= max) max = lh + rh + 2;
        utility(root->left, max);
        utility(root->right, max);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int max = 0;
        utility(root, max);
        return max;
    }
};

int main() {
    TreeNode* new_tree = new TreeNode(1);

    // new_tree->left = new TreeNode(2);
    // new_tree->right = new TreeNode(3);

    // new_tree->left->right = new TreeNode(5);
    // new_tree->left->left = new TreeNode(4);
    // new_tree->left->left->right = new TreeNode(9);

    // new_tree->right->left = new TreeNode(6);
    // new_tree->right->right = new TreeNode(7);
    // new_tree->right->left->left = new TreeNode(8);
    // new_tree->right->right->right = new TreeNode(11);
    // new_tree->right->right->left = new TreeNode(10);
    // new_tree->right->right->right->right = new TreeNode(12);

    new_tree->left = new TreeNode(2);
    new_tree->left->left = new TreeNode(3);
    //new_tree->right = new TreeNode(4);

    // new_tree->left = new TreeNode(2);
    // new_tree->left->left = new TreeNode(3);
    // new_tree->left->left->left = new TreeNode(4);
    // new_tree->left->left->right = new TreeNode(5);

    // new_tree->left = new TreeNode(8);
    // new_tree->right = new TreeNode(-4);
    // new_tree->left->left = new TreeNode(8);
    // new_tree->left->right = new TreeNode(-5);
    // new_tree->right->left = new TreeNode(-1);

    // new_tree->left->left->left = new TreeNode(-9);
    // new_tree->left->left->right = new TreeNode(9);
    // new_tree->left->right->left = new TreeNode(8);
    // new_tree->left->right->right = new TreeNode(8);

    // new_tree->left->left->left->left = new TreeNode(-5);
    // new_tree->left->left->left->right = new TreeNode(6);
    // new_tree->left->right->left->right = new TreeNode(-4);
    // new_tree->left->right->right->right = new TreeNode(4);

    // new_tree->left->left->left->right->left = new TreeNode(8);
    // new_tree->left->left->left->right->right = new TreeNode(8);
    // new_tree->left->right->right->right->right = new TreeNode(5);

    // new_tree->left->right->right->right->right->right = new TreeNode(-9);
    
    Solution obj;
    cout << obj.diameterOfBinaryTree(new_tree);
} 