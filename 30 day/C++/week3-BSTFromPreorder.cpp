#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
    void insertBST(TreeNode* &root, int data) {
        if (root == NULL) {
            root = new TreeNode(data);
        }
        else {
            if (data < root->val) {
                insertBST(root->left, data);
            }
            else {
                insertBST(root->right, data) ;
            }
        }
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;
        for (int i = 0 ; i < preorder.size() ; i++) {
            insertBST(root, preorder[i]);
        }
        return root;
    }

void printLevelOrder(TreeNode *root) { 
    if (root == NULL)  return; 
    queue<TreeNode *> q; 
    q.push(root); 
    while (q.empty() == false) { 
        TreeNode *node = q.front(); 
        if (node == NULL) cout << "null ";
        else cout << node->val << " "; 
        q.pop(); 
        /*if (node->left != NULL)*/ q.push(node->left); 
        /*if (node->right != NULL)*/ q.push(node->right); 
    } 
} 

int main() {
    vector<int> preorder = {8,5,1,7,10,12};
    TreeNode* root = bstFromPreorder(preorder);
    printLevelOrder(root);
}