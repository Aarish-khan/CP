//https://practice.geeksforgeeks.org/problems/count-non-leaf-nodes-in-tree/1

int countNonLeafNodes(Node* root)
{
    // Code here
    if(root == nullptr) return 0;
    if(root->left == nullptr && root->right == nullptr) return 0;
    
    return 1+countNonLeafNodes(root->left) +countNonLeafNodes(root->right);
}
