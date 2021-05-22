//
// ~oisín~ C++ Template
//

#include                <bits/stdc++.h>
#define MX_N            5001
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

int n;
int p[400001];
int l[400001];
int r[400001];
int d[400001];
int q;

vector<int> D[400001];
vector<int> kids[400001];

int step = 0;

void fill(int at, int depth){
    d[at] = depth;
    D[depth].pb(at);
    l[at] = step++;
    for(int to : kids[at]){
        fill(to, depth+1);
    }
    r[at] = step++;
    return;
}

int main(){
    cin >> n;
    for(int i=1;i<n;++i){
        int x;
        cin >> x;
        --x;
        p[i] = x;
        kids[x].pb(i);
    }
    for(int i=0;i<n;++i){
        sort(All(kids[i]));
    }
    fill(0, 0);
    cin >> q;
    while(q--){
        int u, df;
        cin >> u >> df;
        --u;
        if(df < d[u] || D[df].size() == 0){
            cout << "0\n";
            continue;
        }
        if(df == d[u]){
            cout << "1\n";
            continue;
        }
        int L = 0;
        int R = D[df].size()-1;
        while(L < R){
            int M = L + (R - L)/2;
            if(l[D[df][M]] < l[u]){
                L = M+1;
            }else{
                R = M;
            }
        }
        int a = L;
        L = 0;
        R = D[df].size();
        while(L < R){
            int M = L + (R - L)/2;
            if(r[D[df][M]] < r[u]){
                L = M+1;
            }else{
                R = M;
            }
        }
        int b = L-1;
        if(l[D[df][a]] >= l[u] && r[D[df][a]] <= r[u] && l[D[df][b]] >= l[u] && r[D[df][b]] <= r[u]){
            cout << b-a+1 << endl;
        }else{
            cout << "0\n";
        }
    }
}

