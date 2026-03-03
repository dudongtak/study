#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;
vector<long long> leftSum, rightSum;
int n;
long long S;

void dfs(int idx, int end, long long sum, vector<long long>& arr){
    if(idx == end){
        arr.push_back(sum);
        return;
    }
    dfs(idx+1, end, sum + v[idx], arr);
    dfs(idx+1, end, sum, arr);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> S;
    v.resize(n);
    for(int i=0;i<n;i++) cin >> v[i];

    int mid = n/2;

    dfs(0, mid, 0, leftSum);
    dfs(mid, n, 0, rightSum);

    sort(leftSum.begin(), leftSum.end());
    sort(rightSum.begin(), rightSum.end());

    long long answer = 0;
    int l = 0;
    int r = rightSum.size() - 1;

    while(l < leftSum.size() && r >= 0){
        long long sum = leftSum[l] + rightSum[r];

        if(sum == S){
            long long lv = leftSum[l];
            long long rv = rightSum[r];
            long long cntL = 0;
            long long cntR = 0;

            while(l < leftSum.size() && leftSum[l] == lv){
                cntL++;
                l++;
            }
            while(r >= 0 && rightSum[r] == rv){
                cntR++;
                r--;
            }

            answer += cntL * cntR;
        }
        else if(sum < S){
            l++;
        }
        else{
            r--;
        }
    }

    if(S == 0) answer--;

    cout << answer;
}