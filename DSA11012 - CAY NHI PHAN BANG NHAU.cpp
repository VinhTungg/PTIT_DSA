#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, n, m;

struct Node {
    int data;
    Node *left, *right;
    Node (int x) {
        data = x;
        left = right = NULL;
    }
};

void insertNode(Node *root, int u, int v, char c) {
    if (root) {
        if (root->data == u) {
            if (c == 'L') root->left = new Node(v);
            else root->right = new Node(v);
        } else {
            insertNode(root->left, u, v, c);
            insertNode(root->right, u, v, c);
        }
    }
}

int check(Node *firstRoot, Node *secondRoot) {
    if (!firstRoot and !secondRoot) return 1;
    if (!firstRoot or !secondRoot) return 0;
    if (firstRoot->data != secondRoot->data) return 0;
    return check(firstRoot->left, secondRoot->left) and check(firstRoot->right, secondRoot->right);
}

int main(){
    boost;
    cin >> t;
    while(t--){
        cin >> n;
        Node *firstRoot = NULL;
        for (int i = 1; i <= n; ++i) {
            int x, y;
            char z;
            cin >> x >> y >> z;
            if (!firstRoot) {
                firstRoot = new Node(x);
                insertNode(firstRoot, x, y, z);
            } else insertNode(firstRoot, x, y, z);
        }
        cin >> m;
        Node *secondRoot = NULL;
        for (int i = 1; i <= m; ++i) {
            int x, y;
            char z;
            cin >> x >> y >> z;
            if (!secondRoot) {
                secondRoot = new Node(x);
                insertNode(secondRoot, x, y, z);
            } else insertNode(secondRoot, x, y, z);
        }
        if (n != m) cout << "0\n";
        else cout << check(firstRoot, secondRoot) << endl;
    }
}