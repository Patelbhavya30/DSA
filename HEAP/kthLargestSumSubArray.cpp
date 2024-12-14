//  K-th Largest Sum Subarray
// https://www.naukri.com/code360/problems/k-th-largest-sum-contiguous-subarray_920398?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=PROBLEM
#include<iostream>
#include <vector>
#include <queue>
using namespace std;
int kthLargest(vector<int> &arr, int k) {
        // code here
        priority_queue <int, vector<int>, greater<int> > pq;
        for(int i=0;i<k;i++){
            pq.push(arr[i]);
        }
        int n=arr.size();
        for(int i=k;i<n;i++){
            if(arr[i]>pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        return pq.top();
        
    }
int getKthLargest1(vector<int> &arr, int k)
{
	//	Write your code here.
	vector<int> sums;
    // Time complexity: O(n^2) space complexity: O(n^2)
	for(int i=0;i<arr.size();i++){
		int sum=0;
          for (int j = i; j < arr.size(); j++) {
			  sum+=arr[j];
            sums.push_back(sum);
          }
        }
        // time complexity: O(n^2logk) space complexity: O(k) by using mean heap for sums array with n^2 elements.
        // By sorting the sums array and returning the kth element from the end. time complexity: O(n^2logn^2)===O(n^2logn) space complexity: O(n^2)
	return kthLargest(sums,k);
}