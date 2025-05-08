#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

struct Node{
    int data;
    Node *left, *right;
    Node (int x){
        data = x;
        left = right = NULL;
    }
};

void makeNode(Node *root, int u, int v, char c){
    if(c == 'L') root->left = new Node(v);
    else root->right = new Node(v);
}

void insertNode(Node *root, int u, int v, char c){
    if(root == NULL) return;
    if(root->data == u) makeNode(root, u, v, c);
    else{
        insertNode(root->left, u, v, c);
        insertNode(root->right, u, v, c);
    }
}

void Order(Node *root){
    if(!root) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *tmp = q.front();
        q.pop();
        cout << tmp->data << ' ';
        if(tmp->left) q.push(tmp->left);
        if(tmp->right) q.push(tmp->right);
    }
}

int main(){
    boost;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Node *root = NULL;
        int u, v;
        char c;
        for(int i = 0; i < n; ++i){
            cin >> u >> v >> c;
            if(root == NULL){
                root = new Node(u);
                insertNode(root, u, v, c);
            }else insertNode(root, u, v, c);
        }
        Order(root);
        cout << endl;
    }
}