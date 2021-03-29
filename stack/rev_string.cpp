#include<iostream>
#include<stack>
using namespace std;

int main(){

    stack<char> st;
    string s = "Hello Bitan";

    for(int i=0;i<s.length();i++){
        st.push(s[i]);
    }

    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }

    return 0;
}