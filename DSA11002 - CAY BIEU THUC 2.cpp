#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

struct Node{
    string data;
    Node *left, *right;
};

Node *makeNode(string x){
    Node *newNode = new Node();
    newNode->data = x;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *BuildTree(const vector<string> &s){
    int idx = 0, n = s.size();
    queue<Node*> q;
    Node *root = makeNode(s[idx++]);
    q.push(root);
    while(!q.empty() and idx < n){
        Node *tmp = q.front();
        q.pop();
        tmp->left = makeNode(s[idx++]);
        q.push(tmp->left);
        tmp->right = makeNode(s[idx++]);
        q.push(tmp->right);
    }
    return root;
}

ll calc(Node *root){
    if(!root->left and !root->right) return stoll(root->data);   // calc(root->left) and calc(root->right) can be replaced by left and right.
    if(root->data == "+") return calc(root->left) + calc(root->right);
    else if(root->data == "-") return calc(root->left) - calc(root->right);
    else if(root->data == "*") return calc(root->left) * calc(root->right);
    else return calc(root->left) / calc(root->right);
}


int main(){
    boost;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector<string> s(n);
        for(auto &x : s) cin >> x;
        Node *root = BuildTree(s);
        cout << calc(root) << endl;
    }
}