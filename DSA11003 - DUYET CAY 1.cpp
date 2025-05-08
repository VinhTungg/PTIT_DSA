#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, idx = 0;
unordered_map<int, int> inOrderIndex;

struct Node{
    int data;
    Node *left, *right;
    Node (int x){
        data = x;
        left = right = NULL;
    }
};

Node *BuildTree(const vector<int> &InOrder, const vector<int> &PreOrder, int left, int right){
    if(left > right) return NULL;
    Node *root = new Node(PreOrder[idx++]);
    int pos = inOrderIndex[root->data];
    root->left = BuildTree(InOrder, PreOrder, left, pos - 1);
    root->right = BuildTree(InOrder, PreOrder, pos + 1, right);
    return root;
}

void PostOrder(Node *root){
    if(root != NULL){
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->data << ' ';
    }
}

int main(){
    boost;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> PreOrder(n), InOrder(n);
        for(auto &x : InOrder) cin >> x;
        for(auto &x : PreOrder) cin >> x;
        for(int i = 0; i < n; ++i) inOrderIndex[InOrder[i]] = i;
        idx = 0;
        Node *root = BuildTree(InOrder, PreOrder, 0, n - 1);
        PostOrder(root);
        cout << endl;
    }
}