//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            200001
#define mp              make_pair
#define mod7            1000000007
#define modpi           314159
#define PI              3.141592653589793238
#define pb              push_back
#define FastIO          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define All(a)          a.begin(),a.end()
#define fi              first
#define se              second
#define ll              long long int
#define ull             unsigned long long int

int kx[8]  =            {+2, +2, -2, -2, +1, +1, -1, -1};
int ky[8]  =            {+1, -1, +1, -1, +2, -2, +2, -2};
int d9x[9] =            {+1, +1, +1, +0, +0, +0, -1, -1, -1};
int d9y[9] =            {+1, +0, -1, +1, +0, -1, +1, +0, -1};
int dx4[4] =            {+0, +0, +1, -1};
int dy4[4] =            {+1, -1, +0, +0};

ll gcd(ull a, ull b){
    return (a==0)?b:gcd(b%a,a);
}

ll lcm(ull a, ull b){
    return a*(b/gcd(a,b));
}

const long long INF = 1e18;

using namespace std;

struct node{
    node* l;
    node* r;

    int L;
    int R;

    int val;
};

//Global Variables
node* root;
int N;
int Q;
int kinder[MX_N];
int iq[MX_N];

struct priority_comp{
    bool operator()(int a, int b){
        return iq[a] < iq[b];
    }
};

priority_queue<int, vector<int>, priority_comp> PQ[MX_N];

int find_top(int at){
    while((!PQ[at].empty()) && (kinder[PQ[at].top()] != at)){
        //cout << "lazy deleting at PQ " << at << ' ' << PQ[at].top() << endl;
        PQ[at].pop();
        //cout << "New PQ size ";
        //cout << PQ[at].size() << endl;
    }
    if(PQ[at].empty()){
        return 0;
    }else{
        return PQ[at].top();
    }
}

int cmp(node* a, node* b){
    if(a->val != 0){
        if(b->val != 0){
            return min(a->val, b->val);
        }else{
            return a->val;
        }
    }else{
        return b->val;
    }
}

node* build_segtree(int L, int R){
    node* at = new node;
    at->L = L;
    at->R = R;
    if(L == R){
        at->val = iq[find_top(L)];
        at->l = NULL;
        at->r = NULL;
    }else{
        int M = L + (R - L)/2;
        at->l = build_segtree(L, M);
        at->r = build_segtree(M+1, R);
        at->val = cmp(at->l, at->r);
    }
    return at;
}

void update_segtree(node* at, int pos){
    if(at->L == at->R){
        at->val = iq[find_top(pos)];
    }else{
        int M = at->L + (at->R - at->L)/2;
        if(pos > M){
            update_segtree(at->r, pos);
        }else{
            update_segtree(at->l, pos);
        }
        at->val = cmp(at->l, at->r);
    }
}

void print_data(){
    cout << "Top of PQ 1, 2, 3: \n";
    cout << find_top(1) << ' ' << find_top(2) << ' ' << find_top(3) << endl;
    cout << "Value at root: \n";
    cout << root->val << endl;
}

int main(){
    cin >> N >> Q;
    for(int i=1;i<=N;++i){
        cin >> iq[i] >> kinder[i];
        PQ[kinder[i]].push(i);
    }
    root = build_segtree(0, 200000);
//    cout << find_top(1) << ' ' << find_top(2) << ' ' << find_top(3) << endl;
//    cout << root->val << endl;
    for(int i=0;i<Q;++i){
        int c, new_kinder;
        cin >> c >> new_kinder;
        int old_kinder = kinder[c];
        kinder[c] = new_kinder;
        PQ[new_kinder].push(c);
        find_top(new_kinder);
        find_top(old_kinder);
        update_segtree(root, new_kinder);
        update_segtree(root, old_kinder);
        //print_data();
        cout << root->val << endl;
    }
}
