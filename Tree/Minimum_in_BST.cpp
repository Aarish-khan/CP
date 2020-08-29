//https://practice.geeksforgeeks.org/problems/minimum-element-in-bst/1

int minValue(Node* root)
{
    // Code here
    if(root == nullptr) return -1;
    
    while(root->left){
        root = root->left;
    }
    return root->data;
    
}
