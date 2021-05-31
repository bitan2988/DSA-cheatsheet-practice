// https://www.geeksforgeeks.org/find-maximum-sum-possible-equal-sum-three-stacks/
// The idea is to remove the top element of the two having having the highest and second highest sum
// as for their sum to be equal they must come down to the value of lowest sum

#include<iostream>
#include<stack>
using namespace std;

int stack_sum(stack<int> s){

    int sum = 0;
    while(!s.empty()){

        sum += s.top();
        s.pop();
    }

    return sum;
}

int three_st(stack<int> s1, stack<int> s2, stack<int> s3){

    int sum1 = stack_sum(s1);
    int sum2 = stack_sum(s2);
    int sum3 = stack_sum(s3);

    while(!(sum1==sum2==sum3)){

        if(sum1<sum2 and sum1<sum3){

            sum2 -= s2.top();
            s2.pop();
            sum3 -= s3.top();
            s3.pop();
        }
        else if(sum2<sum1 and sum2<sum3){

            sum1 -= s1.top();
            s1.pop();
            sum3 -= s3.top();
            s3.pop();
        }
        else if(sum3<sum1 and sum3<sum2){

            sum1 -= s1.top();
            s1.pop();
            sum2 -= s2.top();
            s2.pop();
        }
        else if(sum1==sum2 and sum1<sum3)
    }
}