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

ll binpow(ll base, int expo){
    if(expo == 0){
        return 1LL;
    }
    if(expo == 1){
        return base;
    }
    ll tmp = binpow(base, expo/2);
    tmp *= tmp;
    if(expo % 2 == 1){
        tmp *= base;
    }
    return tmp;
}

int main(){
    ll x;
    cin >> x;
    ll n = 26;
    ll offset = 0;
    vector<ll> ans;
    for(ll i=0;true;++i){
        if((x - (offset + 1)) < 0){
            break;
        }
        ans.pb( ( ( x - (offset + 1) ) % binpow(n, i+1) ) / (binpow(n, i)));
        offset += binpow(n, i+1);
    }
    reverse(All(ans));
    for(ll c : ans){
        cout << (char)(c+'a');
    }
    cout << endl;
}
