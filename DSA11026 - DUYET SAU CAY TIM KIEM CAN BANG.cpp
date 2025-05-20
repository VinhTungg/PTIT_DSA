#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, n;
vector<int> tree;

struct Node {
    int val;
    Node *left, *right;
    Node (int x) {
        val = x;
        left = right = NULL;
    }
};

Node* build(int l, int r) {
    if (l > r) return NULL;
    int mid = l + r >> 1;
    Node *root = new Node(tree[mid]);
    root->left = build(l, mid - 1);
    root->right = build(mid + 1, r);
    return root;
}

void postOrder(Node *root) {
    if (!root) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << ' ';
}

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n;
        tree.resize(n);
        for (auto &x : tree) cin >> x;
        sort(tree.begin(), tree.end());
        Node *root = build(0, n - 1);
        postOrder(root);
        cout << endl;
    }
}