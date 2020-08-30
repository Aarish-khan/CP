
//https://practice.geeksforgeeks.org/problems/symmetric-tree/1/


bool isMirror(Node* r1, Node* r2){
    
    if(r1==nullptr && r2 == nullptr) return true;
    
    if((r1==nullptr && r2!=nullptr) || (r1!=nullptr && r2==nullptr))
        return false;
    
    if(r1->data == r2->data){
        return isMirror(r1->left,r2->right) && isMirror(r1->right, r2->left);
    }
    else return false;
}

/*
Alternate way of framing of conditions
bool isMirror(Node* r1, Node* r2){
    
    if(r1==nullptr && r2 == nullptr) return true;
    
    if(r1 && r2 && r1->data == r2->data){
        return isMirror(r1->left,r2->right) && isMirror(r1->right, r2->left);
    }
    else return false;
}
*/


// return true/false denoting whether the tree is Symmetric or not
bool isSymmetric(struct Node* root)
{
	if(root == nullptr) return true;
	
	return isMirror(root->left,root->right);
}
