#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1, n, ans;

struct Node {
	int data;
	Node *left = NULL, *right = NULL;
	Node (int x) {
		data = x;
	}
};

void insert_node(Node *root, int u, int v, char c) {
	if (root) {
		if (root->data == u) {
			if (c == 'L') root->left = new Node(v);
			else root->right = new Node(v);
		} else {
			insert_node(root->left, u, v, c);
			insert_node(root->right, u, v, c);
		}
	}
}

void order(Node *root, int mark = 0) {
	if (!root) return;
    if (!root->left and !root->right and !mark) {
        ans += root->data;
    }
    order(root->left, 0);
    order(root->right, 1);
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
        Node *root = NULL;
        unordered_map<int, Node*> mp;
        for (int i = 0; i < n; ++i) {
            int x, y;
            char z;
            cin >> x >> y >> z;
            if (!root) {
                root = new Node(x);
                mp[x] = root;
                if (z == 'L') {
                    mp[x]->left = new Node(y);
                    mp[y] = mp[x]->left;
                } else {
                    mp[x]->right = new Node(y);
                    mp[y] = mp[x]->right;
                }
            } else {
                if (z == 'L') {
                    mp[x]->left = new Node(y);
                    mp[y] = mp[x]->left;
                } else {
                    mp[x]->right = new Node(y);
                    mp[y] = mp[x]->right;
                }
            }
        }
		ans = 0;
		order(root);
		cout << ans << endl;
		free(root);
	}
}
