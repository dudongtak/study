#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, t;
    cin >> n >> k >> t;

    vector<long long> nadori(n);
    long long total = 0;

    for (int i = 0; i < n; i++) {
        cin >> nadori[i];
        total += nadori[i];
    }

    if (total % k != 0) {
        cout << "NO";
        return 0;
    }

    sort(nadori.begin(), nadori.end());

    long long cnt = 0;
    
    for(int i=1;i<=total/k;i++){
        cnt+=k-nadori[n-i];
        if(cnt>t){
            cout<<"NO";
            return 0;
        }
    }
    
    cout<<"YES";
}
