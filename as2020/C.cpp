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

int dp[10001];

int main(){
    for(int x=1;true;++x){
        bool tmp1 = false;
        for(int y=1;true;++y){
            bool tmp2 = false;
            for(int z=1;true;++z){
                int ans = x*x + y*y + z*z + x*y + y*z + x*z;
                if(ans > 10000){
                    break;
                }else{
                    tmp1 = true;
                    tmp2 = true;
                    ++dp[ans];
                }
            }
            if(!tmp2){
                break;
            }
        }
        if(!tmp1){
            break;
        }
    }
    int n;
    cin >> n;
    for(int i=1;i<=n;++i){
        cout << dp[i] << endl;
    }
}
