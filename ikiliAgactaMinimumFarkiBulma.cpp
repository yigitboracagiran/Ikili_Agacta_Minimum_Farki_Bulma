#include <iostream>

struct TreeNode {

    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    
};

class Solution {

public:

    int x = 1000000, kontrol = 1;
    TreeNode *r = NULL;

    int minDiffInBST(TreeNode *root) {

        if ( kontrol == 1) {
            r = root;
            kontrol = 0;
        }

        TreeNode *gezici = root;
        if (gezici == NULL) return 0;

        minDiffInBST(gezici -> left);
        secondMinDiffInBST(gezici, r);
        minDiffInBST(gezici -> right);

        return x;

    }

    void secondMinDiffInBST(TreeNode *gecici ,TreeNode *root) {

        TreeNode *gezici = root;

        if (gezici == NULL) return ;

        secondMinDiffInBST(gecici, gezici -> left);

        if ( gecici == gezici ) kontrol = 2;

        if ( kontrol != 2) return ;

        int a = ( gecici -> val - gezici -> val );
        if ( a < 0 ) a *= -1;
        if ( a < x  && gecici != gezici ) x = a;

        secondMinDiffInBST(gecici, gezici -> right);
        
    }

};

int main(void){

    Solution sol;

    // 56,42,77,23,51,75,90,null,null,null,null,67,null,78,99

    TreeNode *root = new TreeNode(56);
    root->left = new TreeNode(42);
    root->right = new TreeNode(77);
    root->left->left = new TreeNode(23);
    root->left->right = new TreeNode(51);
    root->right->left = new TreeNode(75);
    root->right->right = new TreeNode(90);
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->left->right->left = NULL;
    root->left->right->right = NULL;
    root->right->left->left = new TreeNode(67);
    root->right->left->right = NULL;
    root->right->right->left = new TreeNode(78);
    root->right->right->right = new TreeNode(99);

    int x = sol.minDiffInBST(root);
    std::cout << x << "\n";
    return 0;

}