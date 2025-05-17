#include <string>
#include <vector>

using namespace std;
int cnt=0;

void dfs(int idx,int n,int t,vector<int> nums){
    if(idx>=nums.size()){
        if(n==t)cnt++;
        return;
    }
    dfs(idx+1,n+nums[idx],t,nums);
    dfs(idx+1,n-nums[idx],t,nums);
}

int solution(vector<int> numbers, int target) {
    dfs(0,0,target,numbers);
    int answer = cnt;
    return answer;
}