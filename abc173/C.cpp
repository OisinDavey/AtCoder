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

bool board[8][8];
int row_count[8];
int col_count[8];

bool biton(int x, int pos){
    return (x & (1 << pos));
}

int main(){
    int h, w, k;
    cin >> h >> w >> k;
    int ans = 0;
    for(int i=0;i<h;++i){
        for(int j=0;j<w;++j){
            char tmp;
            cin >> tmp;
            board[i][j] = (tmp == '#');
        }
    }
    int state = 0;
    while(state < (1 << h)){
        int state2 = 0;
        while(state2 < (1 << w)){
            int left = 0;
            for(int i=0;i<h;++i){
                for(int j=0;j<w;++j){
                    if(biton(state, i) || biton(state2, j)){
                        continue;
                    }else{
                        left += (board[i][j]);
                    }
                }
            }
            ans += (left == k);
            ++state2;
        }
        ++state;
    }
    cout << ans << endl;
}
