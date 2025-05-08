#include <bits/stdc++.h>
#define ll long long
#define boost ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define MOD 1000000007

/*           Vĩnh Tùng đẹp trai siêu cấp vũ trụ
Nếu có ai đẹp trai hơn anh, đó chỉ có thể là anh của ngày mai */
using namespace std;
int t = 1;

struct Node{
    int co, ex;
    Node *next;
    Node(int c, int e){
        co = c;
        ex = e;
        next = NULL;
    }
};

void insertNode(Node *&head, int c, int e){
    Node *newNode = new Node(c, e);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node *tmp = head;
    while(tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = newNode;
}

void initalize(Node *&head, string s){
    stringstream ss(s);
    while(ss >> s){
        if(s == "+") continue;
        int co, ex, i = 0;
        while(i < s.size() and s[i] != '*') ++i;
        co = stoi(s.substr(0, i));
        ex = stoi(s.substr(i + 3));
        insertNode(head, co, ex);
    }
}

int Find(Node *head, int x){
    while(head != NULL){
        if(head->ex == x) return head->co;
        else if(head->ex < x) return 0;
        head = head->next;
    }
    return 0;
}

void print(Node *head){
    while(head != NULL){
        if(head->co) cout << head->co << "*x^" << head->ex;
        head = head->next;
        if(head != NULL and head->co) cout << " + ";
    }
    cout << endl;
}

int main(){
    boost;
    cin >> t;
    cin.ignore();
    while(t--){
        Node *A, *B, *C;
        A = B = C = NULL;
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);
        initalize(A, s1);
        initalize(B, s2);
        int MAX = max(A->ex, B->ex);
        for(int i = MAX; ~i; --i){
            int c = Find(A, i) + Find(B, i);
            if(c) insertNode(C, c, i);
        }
        print(C);
        delete A, B, C;
    }
}