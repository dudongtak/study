#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string str;

char who_win(){
    int s[]={0,0};
    //가로줄
    bool winner[]={false,false};
    for(int i=0;i<9;i+=3){
        s[0]=0;
        s[1]=0;
        for(int j=0;j<3;j++){
            if(str[j+i]=='O')s[0]++;
            else if(str[i+j]=='X')s[1]++;
        }
        if(s[0]==3)winner[0]=true;
        if(s[1]==3)winner[1]=true;
    }
    //세로줄
    for(int i=0;i<3;i++){
        s[0]=0;
        s[1]=0;
        for(int j=0;j<9;j+=3){
            if(str[j+i]=='O')s[0]++;
            else if(str[i+j]=='X')s[1]++;
        }
        if(s[0]==3)winner[0]=true;
        if(s[1]==3)winner[1]=true;
    }
    //대각선
    s[0]=0;
    s[1]=0;
    for(int i=0;i<9;i+=4){
        if(str[i]=='O')s[0]++;
        else if(str[i]=='X')s[1]++;
    }
    if(s[0]==3)winner[0]=true;
    if(s[1]==3)winner[1]=true;
    s[0]=0;
    s[1]=0;
    for(int i=2;i<7;i+=2){
        if(str[i]=='O')s[0]++;
        else if(str[i]=='X')s[1]++;
    }
    if(s[0]==3)winner[0]=true;
    if(s[1]==3)winner[1]=true;
    if(winner[0]&&winner[1])return 'F';
    if(winner[0])return 'O';
    if(winner[1])return 'X';
    return 'N';
}

bool check(){
    int x=count(str.begin(),str.end(),'X');
    int o=count(str.begin(),str.end(),'O');
    int dot=count(str.begin(),str.end(),'.');
    char c=who_win();

    if(c=='F')return false;
    if(o>x)return false;
    if(c=='O')return x==o;
    if(c=='X')return x==o+1;
    return dot==0&&x==o+1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(true){
        cin>>str;
        if(str=="end")break;
        if(check())cout<<"valid\n";
        else cout<<"invalid\n";
    }
}