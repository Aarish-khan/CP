
//https://practice.geeksforgeeks.org/problems/print-all-nodes-that-dont-have-sibling/1/
void NoSibling(Node* node, vector<int>& vec){
    if(node == nullptr) return;
    
    if(node->left == nullptr && node->right == nullptr) return;
    
    if(node->left != nullptr && node->right != nullptr){
        NoSibling(node->left,vec);
        NoSibling(node->right,vec);
        
    }
    else if(node->right != nullptr){
        vec.push_back(node->right->data);
        NoSibling(node->right,vec);
    }
    else{
        //means node->left != nullptr
        vec.push_back(node->left->data);
        NoSibling(node->left,vec);
    }
}

vector<int> noSibling(Node* node)
{
    vector<int> temp;
    temp.push_back(-1);
    if(node == nullptr) return temp;
    
    vector<int> vec;
    
    NoSibling(node,vec);
    sort(vec.begin(),vec.end());
    if(vec.size()==0) return temp;
    else return vec;
}
