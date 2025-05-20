#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1;

struct Node {
    int val;
    Node *left, *right;
    Node (int x) {
        val = x;
        left = right = NULL;
    }
};
set<int> s;

void build(Node *&root, int val) {
    if (!root) root = new Node(val);
    else {
        if (root->val > val) build(root->left, val);
        else build(root->right, val);
    }
}

void order(Node *root) {
    if (!root) return;
    if (!root->left and !root->right) s.insert(root->val);
    if (root->left) order(root->left);
    if (root->right) order(root->right);
}

int main(){
    boost;
    cin >> t;
    while(t--){
        int n; cin >> n;
        Node *root = NULL;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            build(root, x);
        }
        s.clear();
        order(root);
        for (auto &x : s) cout << x << ' ';
        cout << endl;
    }
}