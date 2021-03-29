//POSTFIX SOLUTION

//We move from LEFT-TO-RIGHT and whenever we come across an operator we simply act on the last two values that was inserted in the stack

#include<iostream>
#include<stack>
#include<math.h>
#include<string.h>
using namespace std;

int main(){
    stack<int> st;
    string post;
    cin>>post;

    for(int i=0; i<post.length(); i++){
        if(isdigit(post[i]))
            st.push(post[i]-'0');
        else{
            if(st.size()>=2){
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();

                switch(post[i]){

                    case '+':
                        st.push(op1+op2);
                        break;

                    case '-':
                        st.push(op1-op2);
                        break;

                    case '*':
                        st.push(op1*op2);
                        break;

                    case '/':
                        st.push(op1/op2);
                        break;

                    default:
                        st.push(pow(op1, op2));
                        break;
                }

            }
        }

    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

}

