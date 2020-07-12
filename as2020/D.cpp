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

void modulo(ll& x, ll mod){
    if(mod == 0){
        return;
    }
    if(x < 0){
        x = (mod + (x%mod)) % mod;
        //(a%b) == (b + (a%b)) % b
    }else if(x >= mod){
        x %= mod;
    }
}

ll binpow(ll base, int expo, ll k){
    if(k == 0ll){
        return 0ll;
    }
    if(expo == 0){
        return 1ll;
    }else if(expo == 1){
        return base;
    }
    ll tmp = binpow(base, expo/2ll, k);
    tmp *= tmp;
    modulo(tmp, k);
    if(expo % 2ll == 1ll){
        tmp *= base;
        modulo(tmp, k);
    }
    return tmp;
}

int main(){
    int n;
    cin >> n;
    vector<bool> s(n);
    ll pcount = 0ll;
    for(int i=0;i<n;++i){
        char c;
        cin >> c;
        s[i] = (c=='1');
        if(s[i]){
            ++pcount;
        }
    }
    reverse(All(s));
    ll new_num[2];
    new_num[0] = new_num[1] = 0ll;
    //For any given flipping, the modulo will either be pcount + 1, or pcount - 1
    //                                                    zero          one
    for(int i=0;i<(int)s.size();++i){
        if(!s[i]){
            continue;
        }
        new_num[0] += binpow(2, i, pcount+1);
        new_num[1] += binpow(2, i, pcount-1);
        modulo(new_num[0], pcount+1);
        modulo(new_num[1], pcount-1);
    }
//    cout << "New nums : " << new_num[0] << ' ' << new_num[1] << endl;
    //For every inversion, if we are flipping a zero, we add 2^pos mod to the new_num[0]
    //                     if we are flipping a one, we take 2^pos mod from the new_num[1]
    vector<ll> ans(n);
    for(int i=0;i<(int)s.size();++i){
        if(!s[i]){
            ll tmp = binpow(2, i, pcount+1);
            ans[i] = new_num[0] + tmp;
            modulo(ans[i], pcount+1);
        }else{
            ll tmp = binpow(2, i, pcount-1);
            ans[i] = new_num[1] - tmp;
            modulo(ans[i], pcount-1);
        }
    }
    reverse(All(ans));
    reverse(All(s));
    for(int i=0;i<n;++i){
        if(pcount == 1 && s[i]){
            cout << "0\n";
            continue;
        }
        int tmp = (int)ans[i];
        int res = 1;
        while(tmp > 0){
            ++res;
            tmp = tmp % __builtin_popcount(tmp);
        }
        cout << res << endl;
    }
}
