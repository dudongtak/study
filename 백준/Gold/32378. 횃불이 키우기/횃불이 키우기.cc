#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
 
const ll MEGA_LIMIT = 100000000000LL; // 10^11
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    ll k, s;
    cin >> N >> k >> s;
    vector<int> A(N+1);
    for (int i = 1; i <= N; i++){
        cin >> A[i];
    }
    
    // k가 60 이상이면 doubling 효과는 포화되므로 60으로 클램프
    int D = (k < 60 ? (int)k : 60);
    
    // reverse DP를 수행하여 후보 최종 크기 T를 달성 가능한지 판단하는 함수
    auto feasible = [&](ll T) -> bool {
        // dp[d] : 남은 doubling d번으로 도달하기 위해 필요한 최소 시작 크기
        ll cur[65], nxt[65];
        for (int d = 0; d <= D; d++){
            cur[d] = T;  // F[N+1][d] = T
        }
        // i = N downto 1
        for (int i = N; i >= 1; i--){
            // d = 0: 먹기만 선택 → F[i][0] = max(1, F[i+1][0] - A[i])
            ll feed = cur[0] - A[i];
            nxt[0] = (feed < 1 ? 1 : feed);
            // d >= 1: 먹기와 doubling 중 최소 요구 크기 선택
            for (int d = 1; d <= D; d++){
                ll needFeed = cur[d] - A[i];
                if(needFeed < 1) needFeed = 1;
                // doubling 선택: F[i][d] = ceil(F[i+1][d-1] / 2)
                ll needDouble = (cur[d-1] + 1) / 2;
                nxt[d] = min(needFeed, needDouble);
            }
            for (int d = 0; d <= D; d++){
                cur[d] = nxt[d];
            }
        }
        return (cur[D] <= s);
    };
    
    // 생존 가능한 경우가 하나도 없으면 -1 출력
    if(!feasible(1)){
        cout << -1;
        return 0;
    }
    
    // 이진 탐색으로 최대 달성 가능한 최종 크기 T를 결정
    ll low = 1, high = MEGA_LIMIT + 1, ans = 1;
    while(low <= high){
        ll mid = (low + high) / 2;
        if(feasible(mid)){
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    if(ans > MEGA_LIMIT)
        cout << "MEGA";
    else
        cout << ans;
    
    return 0;
}
