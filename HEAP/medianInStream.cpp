#include<bits/stdc++.h>
using namespace std;
int signum(int a, int b) {
    if(a==b){
        return 0;
    }else if(a>b){
        return 1;
    }else{
        return -1;
    }
}
vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here 
	priority_queue<int,vector<int>,greater<int>> minHeap;
	priority_queue<int> maxHeap;
	vector<int> ans;
    int median=0;
	for(int i=0;i<n;i++){
        int element=arr[i];
		// Find Median
		switch(signum(maxHeap.size(),minHeap.size())){
			case 0:{
                if(element>median){
                    minHeap.push(element);
                    median=minHeap.top();
                }else{
                    maxHeap.push(element);
                    median=maxHeap.top();
                   
                }
				break;			
			}
			case 1:{
				if(element>median){
                    minHeap.push(element);
                    median=(maxHeap.top()+minHeap.top())/2;
                    
                }else{
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    maxHeap.push(element);
                    median=(maxHeap.top()+minHeap.top())/2;
                   
                }
				break;
			}
			case -1:{
				if(element>median){
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                    minHeap.push(element);
                    median=(maxHeap.top()+minHeap.top())/2;
                    
                }else{
                    maxHeap.push(element);
                    median=(maxHeap.top()+minHeap.top())/2;
                    
                }
				break;
			}

		}
        ans.push_back(median);
       
	}
   return ans;
}
