/*
IF A OPEN PARENTHESIS i.e [/{/( THEN PUSH IN THE STACK

IF A CLOSED ONE THEN CHECK IF THE TOP OF THE STACK IS OF SAME TYPE AS THAT OF THE CLOSED ONE
    --> IF YES : REMOVE THE TOP
    --> IF NO  : THEN IT'S UNBALANCED
*/

#include<iostream>
#include<stack>
using namespace std;


bool balanced(string s){
    if(s.size()==0)
        return true;

    stack<char> st;

    for(int i=0; i<s.length(); i++){
        if(s[i]=='{' || s[i]=='[' || s[i]=='('){
            st.push(s[i]);
        }

        else{
            if((s[i]=='[' && st.top()==']') || (s[i]=='{' && st.top()=='}') || (s[i]=='(' && st.top()==')') && !st.empty())
                st.pop();

            else
                return false;
        }
    }

    return true;
}


int main(){
    string s;
    getline(cin, s);

    if(balanced(s))
        cout<<"BALANCED";

    else
        cout<<"UNBALNCED";
}