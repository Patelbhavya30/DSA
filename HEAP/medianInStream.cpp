#include<bits/stdc++.h>
using namespace std;
int signum(int a, int b) {
    return (a > b) - (a < b);
}
vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here 
	priority_queue<int,vector<int>,greater<int>> minHeap;
	priority_queue<int> maxHeap;
	vector<int> ans;
	for(int i=0;i<n;i++){
		// For first element or second element.
		if(maxHeap.empty() || minHeap.empty()){
			// If first element push it in maxHeap.
			if(maxHeap.empty()){
		   maxHeap.push(arr[i]);
			}else{
				// If second elemnt is greater than first element then push it in minHeap.
               if(arr[i]>maxHeap.top()){
				   minHeap.push(arr[i]);
			   }else{
				   minHeap.push(maxHeap.top());
				   maxHeap.pop();
				   maxHeap.push(arr[i]);
			   }
			}
		}else{
         if(arr[i]>maxHeap.top()){
			 minHeap.push(arr[i]);
		 }else{
			 maxHeap.push(arr[i]);
		 }
		}
		// Find Median
		switch(signum(maxHeap.size(),minHeap.size())){
			case 0:{
				int median=(maxHeap.top()+minHeap.top())/2;
		   		ans.push_back(median);
				   break;
				
			}
			case 1:{
				ans.push_back(maxHeap.top());
				break;
			}
			case -1:{
				ans.push_back(minHeap.top());
				break;
			}
		}
       
	}
	return ans;
}
