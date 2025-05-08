#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1;

struct Node{
    char data;
    Node *left, *right;
};

Node *makeNode(char x){
    Node *newNode = new Node();
    newNode->data = x;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void inOrder(Node *root){
    if(root != NULL){
        inOrder(root->left);
        cout << root->data;
        inOrder(root->right);
    }
}

int main(){
    boost;
    cin >> t;
    while(t--){
        string s;
        stack<Node*> st;
        cin >> s;
        for(auto &x : s){
            if(x == '+' or x == '-' or x == '*' or x == '/'){
                Node *tmp = makeNode(x);
                tmp->right = st.top();
                st.pop();
                tmp->left = st.top();
                st.pop();
                st.push(tmp);
            }else
                st.push(makeNode(x));
        }
        inOrder(st.top());
        cout << endl;
    }
}