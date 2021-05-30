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

int main(){
    int k, n;
    cin >> n >> k;
    int h[n][n];
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin >> h[i][j];
        }
    }
    int lo = 0;
    int hi = 1000000001;
    while(lo < hi){
        int mid = lo + (hi-lo)/2;
        int b[n][n];
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                b[i][j] = 0;
                if(i > 0){
                    b[i][j] += b[i-1][j];
                }
                if(j > 0){
                    b[i][j] += b[i][j-1];
                }
                if(i > 0 && j > 0){
                    b[i][j] -= b[i-1][j-1];
                }
                if(h[i][j] > mid){
                    ++b[i][j];
                }else if(h[i][j] < mid){
                    --b[i][j];
                }
            }
        }
        bool exists = false;
        for(int i=k-1;i<n;++i){
            for(int j=k-1;j<n;++j){
                int sum = b[i][j];
                if(i >= k){
                    sum -= b[i-k][j];
                }
                if(j >= k){
                    sum -= b[i][j-k];
                }
                if(i >= k && j >= k){
                    sum += b[i-k][j-k];
                }
                if((k % 2 == 0) && (sum <= +1)){
                    exists = true;
                }
                if((k % 2 == 1) && (sum <= 0)){
                    exists = true;
                }
            }
        }
        if(exists){
            hi = mid;
        }else{
            lo = mid+1;
        }
    }
    cout << lo << endl;
}
