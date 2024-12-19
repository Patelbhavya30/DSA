#include<bits/stdc++.h>
using namespace std;
int maximumFrequency(vector<int> &arr, int n)
{
    //Write your code here
    unordered_map<int,int> maxFreq;
    for(int i:arr){
        maxFreq[i]++;
    }
    int maxi=0;
    for(int i:arr){
        if(maxFreq[maxi]<maxFreq[i])
            maxi=i;
    }
    return maxi;
}