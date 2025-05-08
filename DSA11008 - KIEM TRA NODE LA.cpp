#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;
unordered_set<int> s;

struct Node{
    int data;
    Node *left, *right;
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

void makeNode(Node *root, int u, int v, char c){
    if(c == 'L') root->left = new Node(v);
    else root->right = new Node(v);
}

void insertNode(Node *root, int u, int v, char c){
    if(!root) return;
    if(root->data == u) makeNode(root, u, v, c);
    else{
        insertNode(root->left, u, v, c);
        insertNode(root->right, u, v, c);
    }
}

void check(Node *root, int cnt = 0){
    if(!root) return;
    if(!root->right and !root->left) s.insert(cnt);
    check(root->left, cnt + 1);
    check(root->right, cnt + 1);
}

int main(){
    boost;
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        int u, v;
        char c;
        Node *root = NULL;
        for(int i = 0; i < n; ++i){
            cin >> u >> v >> c;
            if(!root){
                root = new Node(u);
                insertNode(root, u, v, c);
            }else insertNode(root, u, v, c);
        }
        s.clear();
        check(root);
        cout << (s.size() == 1) << endl;
    }
}