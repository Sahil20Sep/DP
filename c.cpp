#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define c(ans) cout << ans << endl
#define cs(ans) cout << ans << " "
#define fori(i, j, k) for(ll i = j; i < k; i++)
#define ifor(i, j, k) for(ll i = j; i >= k; i--)
#define inarr(j, n, a) for(ll i = j; i < n; i++) cin >> a[i];
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define pb push_back
#define ff first
#define ss second
#define ce cout << endl
 
typedef vector<ll> vll;
 
const ll inf = 1e6 + 1;
const ll mod = 1e9 + 7;
const ll N = 2048;
 
//----------------------------------Function----------------------------------//
 
void cv(vector<ll> v){
    fori(i, 0, sz(v)){
        cs(v[i]);
    }
    cout << endl;
}
 
void cp(vector<pair<ll, ll>> p){
    for(auto i : p){
        cout << i.ff << " " << i.ss << endl;
    }
}
 
struct my{
    bool flag;
};
 
ll b_power(ll a, ll b)
{
    a %= mod;
    ll res = 1 % mod;
    while (b > 0) {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll dp[100001][101];

ll func(vector<ll> &v, ll i, ll put, ll m){
    if(i < 0 || put > m || put <= 0){
        return dp[i][put] = 0LL;
    }
    if(i == 0){
        if(v[i] == put || v[i] == 0){
            return dp[i][put] = 1LL;
        }else{
            return dp[i][put] = 0LL;
        }
    }
    if(dp[i][put] != -1){
        return dp[i][put];
    }
    ll ans = 0;
    if(v[i] == put || v[i] == 0){
        ans = (((func(v, i - 1, put - 1, m) % mod) + (func(v, i - 1, put, m) % mod) + (func(v, i - 1, put + 1, m)) % mod) % mod);
    }else{
        return dp[i][put] = 0LL;
    }
    // cout << i << ' ' << put << ' ' << ans << endl;
    return dp[i][put] = ans;
}
 
//------------------------------------code------------------------------------//
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll T = 1;
    // cin >> T;
    while(T--){
        ll n, m; cin >> n >> m;
        vll v(n); inarr(0, n, v);
        memset(dp, -1, sizeof(dp));
        fori(i, 1, m + 1){
            func(v, n - 1, i, m);
        }
        ll final = 0;
        fori(i, 1, m + 1){
            final = (final + dp[n - 1][i]) % mod;
        }
        cout << final << endl;
        sahil:; 
    }
    return 0;
}