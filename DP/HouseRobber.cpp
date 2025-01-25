// House Robber II
// https://www.naukri.com/code360/problems/house-robber_839733?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
#include <bits/stdc++.h>
using namespace std;
long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here
    if(valueInHouse.size()==1)
        return valueInHouse[0];
    long long int prev1=0;
    long long int prev2=valueInHouse[0];
    for(long long int i=1;i<valueInHouse.size()-1;i++){
        long long int temp=prev2;
        prev2=max(prev1+valueInHouse[i],prev2);
        prev1=temp;
    }
    long long int prev3=0;
    long long int prev4=valueInHouse[1];
    for(long long int i=2;i<valueInHouse.size();i++){
        long long int temp=prev4;
        prev4=max(prev3+valueInHouse[i],prev4);
        prev3=temp;
    }

    return max(prev2,prev4);

}