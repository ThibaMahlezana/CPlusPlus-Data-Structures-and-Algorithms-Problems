#include <iostream>
using namespace std;

class Node {
public:
    int key;
    Node *left;
    Node *right;

    Node(int key){
        this->key = key;
        left = right = NULL;
    }
};

Node* insert(Node* root, int key){
    if(root == NULL){
        return new Node(key);
    }

    if(key < root->key){
        root->left = insert(root->left, key);
    }
    else{
        root->right = insert(root->right, key);
    }

    return root;
}

void printInOrder(Node *root){
    if(root == NULL){
        return;
    }
    printInOrder(root->left);
    cout << root->key << " ,";
    printInOrder(root->right);
}

Node * inorderSucc(Node * root, Node * target){
    if(target->right != NULL){
        Node* temp = temp->right;
        while(temp->left != NULL){
            temp = temp->left;
        }
        return temp;
    }
    Node * temp = root;
    Node * succ = NULL;

    while(temp != NULL){
        if(temp->key > target->key){
            succ = temp;
            temp = temp->left;
        }
        else if(temp->key < target->key){
            temp = temp->right;
        }
        else{
            break;
        }
    }
    return succ;
}

int main(){
    Node * root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1;
    root = insert(root, 6);
    root = insert(root, 14);
    root = insert(root, 4;
    root = insert(root, 7);
    root = insert(root, 13);

    Node* t1 = root->left->right->right;
    Node* t2 = root->right;

    cout << "Inorder succ of 7 is " << inorderSucc(root, t1)->key << endl;
    cout << "Inorder succ of 10 is " << inorderSucc(root, t2)->key << endl;

    return 0;
}