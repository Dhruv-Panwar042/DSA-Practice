#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> w(n);
    for(int i = 0; i < n; i++) {
        cin >> w[i];
    }

    sort(w.begin(), w.end());

    int l = 0;
    int r = n - 1;
    int ans = 0;

    while(l <= r) {
        if(w[l] + w[r] <=x)
            l++;
        r--;
        ans++;
    }

    cout << ans << "\n";
    return 0;
}