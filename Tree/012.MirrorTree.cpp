//https://practice.geeksforgeeks.org/problems/mirror-tree/1

void mirror(Node* node) 
{
     // Your Code Here
     if(node == nullptr) return;
     
     if(node->left == nullptr && node->right == nullptr) return;
     
     //recursively mirror left subtree
     mirror(node->left);
     //recursively mirror right subtree
     mirror(node->right);
     
     ////make the left child as right and right as left after each recusive fuction call
     Node *temp = node->left;
     node->left = node->right;
     node->right = temp;
}
