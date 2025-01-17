// Nth Fibonacci Number
// https://www.naukri.com/code360/problems/nth-fibonacci-number_74156?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION
#include<bits/stdc++.h>
using namespace std;

int fib(int n,vector<int> &dp){
        if(n==1){
                return 1;
        }
        if(n<=0)
                return 0;
        if(dp[n]!=-1)
                return dp[n];
        dp[n]=fib(n-1,dp)+fib(n-2,dp);
        return dp[n];
}
int main()
{
        /*
        *  Write your code here. 
         *  Read input as specified in the question.
         *  Print output as specified in the question.
        */
        int n;
        cin>>n;
        vector<int> dp(n+1);
        for(int i=0;i<=n;i++)
                dp[i]=-1; 
        cout<< fib(n,dp)<<endl;
        return 0;
}