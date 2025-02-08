#include <iostream>
#include <vector>
#include <set>

using namespace std;
#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const ll maxn = 2e5 + 100;

ll q, n, a[maxn], b[maxn];

bool ok(ll x){
    ll c = 0;
    for(ll i = 0; i < n; i++){
        if(x - 1 - a[i] <= c && c <= b[i]) c++;
    }
    return c >= x;
}

int main(){
    fast_io;

    cin >> q;
    while(q--){
        cin >> n;
        for(ll i = 0; i < n; i++){
            cin >> a[i] >> b[i];
        }
        ll l = -1, r = n + 1, mid;
        while(r - l > 1){
            mid = (l + r) >> 1;
            if(ok(mid)) l = mid;
            else r = mid;
        }
        cout << l << "\n";
    }
    return 0;
}