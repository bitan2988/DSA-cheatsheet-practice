/*
TRAVERSE FROM LEFT-TO-RIGHT
if operand
    print
if (
    push to stack
if )
    pop from stack until a ( is found
if operator
    pop from stack until an operator with less 
    presedance is found and after finding that operator push the opeator in-hand into the stack
*/


#include<bits/stdc++.h>
using namespace std;

int precedence(char ch){

    if(ch=='+' || ch=='-')
        return 1;

    else if(ch=='*' || ch=='/')
        return 2;

    else if(ch=='^')
        return 3;

    else
        return -1;
}

string itopo(string s){
    if(s.size()==0)
        return s;

    string res;
    stack<char> st;

    for(int i=0; i<s.size(); i++){
        if(s[i]>='0' && s[i]<='9')
            res += s[i];

        else if(s[i]=='('){
            st.push(s[i]);
        }

        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                res += st.top();
                st.pop();
            }
            if(!st.empty())
                st.pop();
        }

        else{
            int pre1 = precedence(s[i]);
            while(!st.empty() && (precedence(st.top()) > pre1)){
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }

    }

    while(!st.empty()){
        res += st.top();
        st.pop();
    }

    return res;

}


int main(){
    string s = "(a-b/c)*(a/k-l)";
    cout<<endl<<itopo(s);
}


