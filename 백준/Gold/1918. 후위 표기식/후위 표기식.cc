#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string infix;

    cin>>infix;

    stack<char> op;

    for(int i=0;i<infix.size();i++){
        if(infix[i]>='A'&&infix[i]<='Z'){
            cout<<infix[i];
        }
        else{
            if(infix[i]=='(')op.push(infix[i]);
            else if(infix[i]==')'){
                while(!op.empty()&&op.top()!='('){
                    cout<<op.top();
                    op.pop();
                }
                op.pop();
            }
            else if(infix[i]=='*'||infix[i]=='/'){
                while(!op.empty()&&(op.top()=='*'||op.top()=='/')){
                    cout<<op.top();
                    op.pop();
                }
                op.push(infix[i]);
            }
            else if(infix[i]=='+'||infix[i]=='-'){
                while(!op.empty()&&op.top()!='('){
                    cout<<op.top();
                    op.pop();
                }
                op.push(infix[i]);
            }

        }
    }
    while(!op.empty()){
        cout<<op.top();
        op.pop();
    }
}