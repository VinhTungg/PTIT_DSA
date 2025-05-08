#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;
unordered_map<int, int> mp;

struct Node{
    int data;
    Node *left, *right;
    Node (int x){
        data = x;
        left = right = NULL;
    }
};

Node *buildTree(vector<int> inOrder, vector<int> level, int n, int st, int end){
    if(n){
        Node *root = new Node(level[0]);
        int idx = mp[level[0]];
        cerr << idx << endl;
        unordered_set<int> s(inOrder.begin() + st, inOrder.begin() + idx);
        vector<int> L, R;
        for(int i = 1; i < n; ++i){
            if(s.count(level[i])) L.emplace_back(level[i]);
            else R.emplace_back(level[i]);
        }
        root->left = buildTree(inOrder, L, idx - st, st, idx - 1);
        root->right = buildTree(inOrder, R, end - idx, idx + 1, end);
        return root;
    }
    return NULL;
}

void postOrder(Node *root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << ' ';
    }
}

int main(){
    boost;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> InOrder(n), LevelOrder(n);
        for(auto &x : InOrder) cin >> x;
        for(auto &x : LevelOrder) cin >> x;
        for(int i = 0; i < n; ++i) mp[InOrder[i]] = i;
        Node *root = buildTree(InOrder, LevelOrder, n, 0, n - 1);
        postOrder(root);
        cout << endl;
        cerr << endl;
        mp.clear();
    }
}