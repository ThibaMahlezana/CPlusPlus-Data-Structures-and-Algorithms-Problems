#include <iostream>
#include <queue>

using namespace std;

class Node{
public:
    int data;
    node* left;
    node* right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

node * buildTree(){
    int d;
    cin >> d;

    if(d == 1){
        return NULL;
    }

    node* n = new node(d);
    n->left = buildTree();
    n->right = buildTree();

    return n;
}

void levelOrderPrint(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        node*temp = q.front();
        if(temp == NULL){
            cout << endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else {
            q.pop();
            cout << temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    return;
}

void printAtLevelK(node* root, int k){
    if(root == NULL){
        return;
    }
    if(k == 0){
        cout << root->data << " ";
        return;
    }
    printAtLevelK(root->left, k - 1);
    printAtLevelK(root->right, k - 1);
    return;
}

void printNodesAtDistanceK(node* root, node* target, int k){
    if(root == NULL){
        return -1;
    }

    if(root == target){
        printAtLevelK(target, k);
        return 0;
    }

    int DL = printNodesAtDistanceK(root->left, target, k);
    if(DL !=  -1){
        if(DL + 1 == k){
            cout << root->data;
        }
        else{
            printAtLevelK(root->right, k-2-DL);
        }
        return 1 + DL;
    }
    int DR = printNodesAtDistanceK(root->right, target, k){
        if(DR + 1 == k){
            cout << root->data << " ";
        }
        else{
            printAtLevelK(root->left, k-2-DR);
        }
        return 1 + DR;
    }
    return -1;
}

int main(){
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);
    root->left->right->left = new node(7);
    root->left->right->right = new node(8);
    root->right->right->right->right = new node(10);

    node* target = root->left->right;
}