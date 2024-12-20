#include <queue>
#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    


    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool reversed=0;
        while(!q.empty()){
            int qz=q.size();
            vector<TreeNode*> arr(qz);
            for(int i=0; i<qz; i++){
                auto Node=q.front();
                q.pop();
                if (Node->left) q.push(Node->left);
                if (Node->right) q.push(Node->right);
                if (reversed){
                    arr[i]=Node;
                    if (i>=qz/2) 
                        swap(arr[i]->val, arr[qz-1-i]->val); 
                }
            }
            reversed=!reversed;
        }
        return root;
    }
};

// Function to print the tree in level-order to verify the result
void printLevelOrder(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* currentNode = q.front();
        q.pop();
        cout << currentNode->val << " ";

        if (currentNode->left) q.push(currentNode->left);
        if (currentNode->right) q.push(currentNode->right);
    }
    cout << endl;
}


int main() {
    // Create a sample binary tree
    //         1
    //        / \
    //       2   3
    //      / \ / \
    //     4  5 6  7
    //    / \
    //   8   9

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);

    cout << "Original tree (Level Order): ";
    printLevelOrder(root);

    // Reverse the odd levels
    root->reverseOddLevels(root);

    cout << "Tree after reversing odd levels (Level Order): ";
    printLevelOrder(root);

    return 0;
}
