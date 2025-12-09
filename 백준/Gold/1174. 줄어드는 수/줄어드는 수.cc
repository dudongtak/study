#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;
vector<ll> nums;
int n;

void make_num(string num,int idx){
    num+=idx+'0';
    nums.push_back(stoll(num));
    for(int i=idx-1;i>=0;i--)make_num(num,i);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0;i<=9;i++)make_num("",i);
    sort(nums.begin(),nums.end());
    
    cin>>n;
    if(n>nums.size())cout<<-1;
    else cout<<nums[n-1];
}