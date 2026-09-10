class Solution {
public:
void IOT(TreeNode* root,vector<int> &v){
    if(root==NULL)
        return ;
    IOT(root->left,v);
    v.push_back(root->val);
    IOT(root->right,v);
}
    int kthSmallest(TreeNode* root, int k) {
        vector<int>v;
        IOT(root,v);
        return v[k-1];
    }
};