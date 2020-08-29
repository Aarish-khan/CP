/*
https://practice.geeksforgeeks.org/problems/sum-of-binary-tree/1
*/
long int sumBT(Node* root)
{
    if(root == nullptr) return 0;
    
    return root->key + sumBT(root->left) + sumBT(root->right);
}
