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

int findClosestInBST(Node * root, int target){
    int closest;
    int diff = INT_MAX;

    Node *temp = root;

    while(temp != NULL){
        int current_diff = abs(temp->key - target);
        if(current_diff == 0){
            return temp->key;
        }

        if(current_diff < diff){
            diff = current_diff;
            closest = temp->key;
        }

        if(temp->key < target){
            temp = temp->right;
        }
        else{
            temp = temp->left;
        }
    }
    return closest;
}

class LinkedList{
public:
    Node* head;
    Node* tail;
};

LinkedList tree2LL(Node * root){
    LinkedList l;
    if(root == NULL){
        l.head = l.tail = NULL;
        return l;
    }
    if(root->left == NULL and root->right == NULL){
        l.head = l.tail = root;
    }

    else if(root->left == NULL and root->right == NULL){
        LinkedList leftLL = tree2LL(root->left);
        leftLL.tail->right = root;

        l.head = leftLL.head;
        l.tail = root;
    }
    
    else if(root->left == NULL and root->right != NULL){
        LinkedList rightLL = tree2LL(root->right);
        root->right = rightLL.head;

        l.head = root;
        l.tail = rightLL.tail;
    }

    else {
        LinkedList leftLL = tree2LL(root->left);
        LinkedList rightLL = tree2LL(root->right);
        leftLL.tail->right = root;
        root->right = rightLL.head;

        l.head = leftLL.head;
        l.tail = rightLL.tail;
    }

    return l;
}

int main(){
    Node * root = NULL;
    int arr[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};

    for(int x : arr){
        root = insert(root, x);
    }

    LinkedList l = tree2LL(root);

    Node* temp = l.head;
    while(temp != NULL){
        cout << temp->key << " ";
        temp = temp->right;
    }
    
    return 0;
}