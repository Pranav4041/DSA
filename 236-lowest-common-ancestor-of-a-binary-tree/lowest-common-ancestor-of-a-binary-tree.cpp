class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* r, TreeNode* p, TreeNode* q) {
        if (!r || r == p || r == q)
            return r;

        TreeNode* l = lowestCommonAncestor(r->left, p, q);
        TreeNode* x = lowestCommonAncestor(r->right, p, q);

        if (l && x)
            return r;

        return l ? l : x;
    }
};