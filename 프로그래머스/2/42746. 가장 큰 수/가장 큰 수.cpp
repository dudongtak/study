#include <string>
#include <vector>
#include<algorithm>
using namespace std;

bool cmp(string &a,string &b){
    return a+b>b+a;
}

string solution(vector<int> numbers) {
    vector<string> strs;
    string answer="";
    
    for(int i=0;i<numbers.size();i++)strs.push_back(to_string(numbers[i]));
    
    vector<string> res;
    sort(strs.begin(),strs.end(),cmp);
    for(int i=0;i<strs.size();i++)answer+=strs[i];
    
    if(answer[0]=='0')answer="0";
    
    return answer;
}