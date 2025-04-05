#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

using namespace std;
int t = 1, n, x;

struct node{
    int data;
    node *next;
};

void print(node *head){
    while(head != NULL){
        if(head->data != x) cout << head->data << ' ';
        head = head->next;
    }
}

node *makeNode(int x){
    node *newNode = new node();
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void push_back(node *&head, int x){
    node *tmp = head;
    node *newNode = makeNode(x);
    if(head == NULL){
        head = newNode;
        return;
    }
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

int main(){
    boost;
    // cin >> t;
    while(t--){
        cin >> n;
        node *head = NULL;
        for(int i = 1; i <= n; ++i){
            int a; cin >> a;
            push_back(head, a);
        }
        cin >> x;
        print(head);
    }
}