#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, idx;
vector<int> vals;

struct Node {
    int val;
    Node *left, *right;
    Node (int x) {
        val = x;
        left = right = NULL;
    }
};

void insertNode(Node *root, int u, int v, char c) {
    if (root) {
        if (root->val == u) {
            if (c == 'L') root->left = new Node(v);
            else root->right = new Node(v);
        } else {
            insertNode(root->left, u, v, c);
            insertNode(root->right, u, v, c);
        }
    }
}

void init(Node *root) {
    if (!root) return;
    init(root->left);
    vals.emplace_back(root->val);
    init(root->right);
}

void inOrder(Node *root) {
    if (!root) return;
    inOrder(root->left);
    root->val = vals[idx++];
    cout << root->val << ' ';
    inOrder(root->right);
}

int main(){
    boost;
    cin >> t;
    while(t--){
        int n; cin >> n;
        Node *root = NULL;
        for (int i = 0; i < n; ++i) {
            int x, y;
            char z;
            cin >> x >> y >> z;
            if (!root) {
                root = new Node(x);
                insertNode(root, x, y, z);
            } else insertNode(root, x, y, z);
        }
        vals.clear();
        init(root);
        sort(vals.begin(), vals.end());
        idx = 0;
        inOrder(root);
        cout << endl;
    }
}