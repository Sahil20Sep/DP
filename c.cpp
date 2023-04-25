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
 
ll dp[5001][5001];
 
ll func(ll i, ll j, string &s, string &t){
    if(i < 0){
        return (j + 1LL);
    }
    if(j < 0){
        return (i + 1LL);
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    ll ans = s.size() + t.size();
    if(s[i] == t[j]){
        ans = min(ans, func(i - 1, j - 1, s, t));
    }else{
        ans = min(ans, func(i - 1, j - 1, s, t) + 1LL);
        ans = min(ans, func(i, j - 1, s, t) + 1LL);
        ans = min(ans, func(i - 1, j, s, t) + 1LL);
    }
    // cout << i << ' ' << j << ' ' << ans << endl;
    return dp[i][j] = ans;
}
 
//------------------------------------code------------------------------------//
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll T = 1;
    // cin >> T;
    while(T--){
        string s, t; cin >> s >> t;
        memset(dp, -1, sizeof(dp));
        cout << func(sz(s) - 1, sz(t) - 1, s, t) << endl;
        sahil:; 
    }
    return 0;
}