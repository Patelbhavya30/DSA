#include <bits/stdc++.h> 
using namespace std;
string reArrangeString(string &s)
{
	// Write your code here.
	unordered_map<char,int> freq;

	for (char c : s) {
        freq[c]++;
    }
	// Max-heap to store characters by frequency
    priority_queue<pair<int, char>> maxHeap;
    for (auto entry : freq) {
        maxHeap.push({entry.second, entry.first});
    }
	pair<int, char> maxFreq=maxHeap.top();
	if(maxFreq.first>(s.length()+1)/2){
		return "not possible";
	}
	string ans="";
	pair<int, char> prev={0,'\0'};
	while(!maxHeap.empty()){
		pair<int, char> temp=maxHeap.top();
		maxHeap.pop();
		ans.push_back(temp.second);
        if (prev.first > 0) {
            maxHeap.push(prev);
        }
        prev={--temp.first,temp.second};
	}
	return ans;


}
