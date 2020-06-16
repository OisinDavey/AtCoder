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

ll n_from_x(ll x){
    return (-1LL + (long long)sqrt(1 + 8 * x)) >> 1;
}

int main(){
    ll n;
    cin >> n;
    ll N = n;
    ll s = sqrt(N);
    int cur = 2;
    map<ll, int> factor_frequency;
    while(cur <= sqrt(n)){
        if(n % cur == 0){
            n/=cur;
            ++factor_frequency[cur];
        }else{
            ++cur;
        }
    }
    if(n == 1){
        cout << "0\n";
        return 0;
    }
    ++factor_frequency[n];
    int ans = 0;
    for(auto it = factor_frequency.begin(); it != factor_frequency.end(); ++ it){
        ans += n_from_x(it->second);
    }
    cout << ans << endl;
}
