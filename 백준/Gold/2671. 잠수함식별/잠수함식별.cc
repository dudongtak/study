#include<iostream>
#include<string>
#include<regex>
using namespace std;

string str;
//(100~1~|01)~
regex re("(100+1+|01)+");

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>str;

    if(regex_match(str,re))cout<<"SUBMARINE";
    else cout<<"NOISE";
}