#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, n;
int Level[1005];

struct Node {
    int data;
    Node *left, *right;
    Node (int x) {
        data = x;
        left = right = NULL;
    }
};

void insertNode (Node *root, int u, int v, char c) {
    if (root != NULL) {
        if (root->data == u) {
            if (c == 'L') root->left = new Node(v);
            else root->right = new Node(v);
        } else {
            insertNode(root->left, u, v, c);
            insertNode(root->right, u, v, c);
        }
    }
}

void order(Node *root, int lv = 0) {
    if (!root) return;
    ++Level[lv];
    order(root->left, lv + 1);
    order(root->right, lv + 1);
}

string check() {
    for (int i = 0; i < 31; ++i) {
        if (!Level[i]) return "Yes\n";
        if (Level[i] != (1 << i)) return "No\n";
    }
}

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n;
        Node *root = NULL;
        fill(Level, Level + 31, 0);
        for (int i = 0; i < n; ++i) {
            int x, y;
            char z;
            cin >> x >> y >> z;
            if (!root) {
                root = new Node(x);
                insertNode(root, x, y, z);
            } else insertNode(root, x, y, z);
        }
        order(root);
        cout << check();
    }
}