#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

string formula;
int length;
int Max=-2147483648;
vector<int> nums;
vector<char> ops;

int cal(int a,int b,char op){
    if(op=='+')return a+b;
    if(op=='-')return a-b;
    return a*b;
}

void dfs(int now,int sum){
    if(now==nums.size()-1){
        Max=max(Max,sum);
        return;
    }
    dfs(now+1,cal(sum,nums[now+1],ops[now]));

    if(now+2<nums.size()){
        int tmp=cal(nums[now+1],nums[now+2],ops[now+1]);
        dfs(now+2,cal(sum,tmp,ops[now]));
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>length>>formula;

    for(int i=0;i<length;i++){
        if(i%2==0)nums.push_back(formula[i]-'0');
        else ops.push_back(formula[i]);
    }
    dfs(0,nums[0]);

    cout<<Max;
}