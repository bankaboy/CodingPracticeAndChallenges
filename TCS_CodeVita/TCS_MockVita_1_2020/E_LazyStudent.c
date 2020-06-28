/*
Problem Description
There is a test of Algorithms. Teacher provides a question bank 
consisting of N questions and guarantees all the questions in the 
test will be from this question bank. Due to lack of time and his 
laziness, Codu could only practice M questions. There are T 
questions in a question paper selected randomly. Passing criteria 
is solving at least 1 of the T problems. Codu can't solve the 
question he didn't practice. What is the probability that Codu 
will pass the test?

Constraints
0 < T <= 10000

0 < N, T <= 1000

0 <= M <= 1000

M,T <= N

Input Format
First line contains single integer T denoting the number of test 
cases.

First line of each test case contains 3 integers separated by 
space denoting N, T, and M.

Output
For each test case, print a single integer.

If probability is p/q where p & q are co-prime, print 
(p*mulInv(q)) modulo 1000000007, where mulInv(x) is multiplicative 
inverse of x under modulo 1000000007.

Timeout
1

Test Case
Example 1

Input
1
4 2 1

Output
500000004

Explanation
The probability is ½. So output is 500000004.
*/


//This is The Coding Area
// Passing sample, re in actual
#include<stdio.h>
unsigned long long int combinations(unsigned long long int n,unsigned long long int r) {
unsigned long long int itr;
   unsigned long long int nume=1,demo=1,res;
   for(itr=1;itr<=r;itr++)
   {
       demo=demo*itr;
       nume=nume*(n-(itr-1));
   }
   res=nume/demo;
   return res;

}
unsigned long long int calgcd(unsigned long long int num1,unsigned long long int num2) {
 unsigned long long int rem;
    while(1)
    {
          rem=num1%num2;
        if(rem==0)
      {  
          return num2;
      }
    if(rem!=0)
    {
    num1=num2;
    num2=rem;
    }
    }
}
 unsigned long long int mulInv(unsigned long long int a) {
    unsigned long long int m=1000000007,itr,b;
    for(itr=1;itr<m;itr++)
    {
        if((itr*m+1)%a==0)
        {
            b=(itr*m+1)/a;
            break;
        }
    }
    return b;
}
int main() {
    int t,itr;
    scanf("%d",&t);
    for(itr=1;itr<=t;itr++) {
        unsigned long long int db_questions,learnt,chosen,unknown,p,q,gcd,result;
        unsigned long long int waysofchosing,waysoffailing;
        scanf("%llu %llu %llu",&db_questions,&learnt,&chosen);
        unknown=db_questions-learnt;
        waysofchosing=combinations(db_questions,chosen);
        waysoffailing=combinations(unknown,chosen);
        p=waysofchosing-waysoffailing;
        q=waysofchosing; 
        gcd=calgcd(p,q);
        if(gcd!=1)  {
            p=p/gcd;
            q=q/gcd;
        }
        result=(p*mulInv(q))%1000000007;
        printf("%llu\n",result);
    }
return 0;
}