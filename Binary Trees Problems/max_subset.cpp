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

class Pair{
    int inc;
    int exc;
};

Pair maxSubsetSum(node* root){
    Pair p;
    if(root == NULL){
        p.inc = p.exc = 0;
        return p;
    }

    Pair Left = maxSubsetSum(root->Left);
    Pair Right = maxSubsetSum(root->Right);

    p.inc = root->data + Left.exc + Right.exc;
    p.exc = max(Left.inc, Left.exc) + max(Right.inc, Right.exc);

    return p;
}

int main(){
    node* root = buildTree();
    levelOrderPrint(root);
    
    Pair p = maxSubsetSum(root);
    cout << "Max Sum : " << max(p.inc, p.exc) << endl;
    
    return 0;
}