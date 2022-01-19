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

node* levelOrderBuild(){
    int d;
    cin >> d;
    node* root = new node(d);

    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* current = q.front();
        q.pop();

        int c1, c2;
        cin >> c1 >> c2;

        if(c1 != -1){
            current->left = new node(c1);
            q.push(current->left);
        }
        if(c2 != -1){
            current->right = new node(c2);
            q.push(current->right);
        }
    }
    return root;
}

int height(node* root){
    if(root == NULL){
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    return 1 + max(h1, h2);
}

int diameter(node* root){
    if(root == NULL){
        return 0;
    }
    int D1 = height(root->left) + height(root->right);
    int D2 = diameter(root->left);
    int D3 = diameter(root->right);

    return max(D1, max(D2, D3));
}

int replaceWithSum(node *root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL and root->right == NULL){
        return root->data;
    }

    int LS = replaceWithSum(root->left);
    int RS = replaceWithSum(root->right);

    int temp = root->data;
    root->data = LS + RS;
    return root->data + temp;
}

int height(node* root){
    if(root == NULL){
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);
    return 1 + max(h1, h2);
}

pair<int, bool> isHeightBalanced(node *root){
    pair<int, bool> p, left, right;

    if(root == NULL){
        p.first = 0;
        p.second = true;
        return p;
    }

    left = isHeightBalanced(root->left);
    Right = isHeightBalanced(root->left);

    int height = max(Left.first, Right.first) + 1;
    if(abs(Left.first - Right.first) <= 1 and Left.second and Right.second){
        return make_pair(height, true);
    }
    return make_pair(height, false);
}

int main(){
    // node* root = buildTree();
    node* root = levelOrderBuild();
    replaceWithSum(root);
    levelOrderPrint(root);
    //cout << diameter(root) << endl;
    return 0;
}