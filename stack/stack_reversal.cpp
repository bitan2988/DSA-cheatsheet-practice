/*
We can use recursion to reverse a stack
*/
#include<iostream>
#include<stack>
using namespace std;

void rev(stack<char>& st){
    
    if(st.empty())
        return;

    else{
        char c;
        c = st.top();
        st.pop();
        rev(st);
        cout<<c;
    }
}

int main(){

    stack<char> st;
    string s = "Hi this is me bitan";
    for(int i=0;i<s.length();i++)
        st.push(s[i]);

    rev(st);

    return 0;
}