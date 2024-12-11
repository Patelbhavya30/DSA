#include <iostream>
using namespace std;
class heap{
    public:
    int arr[100];
    int i=0;
    // heap(){
    //     arr[i]=-1;
    // }
    void insert(int data){
        arr[++i]=data;
        int curr=i;
        while(curr>1){
            int parent=curr/2;
            if(arr[parent]<arr[curr]){
                swap(arr[parent],arr[curr]);
                curr=parent;
            }else{
                break;
            }
        }
    }
    void print(){
        for(int j=1;j<=i;j++){
            cout<<arr[j]<<" ";
        }
        cout<<endl;
    }
    void deleteFromNode(){
        if(i==0){
            cout<<"nothing to delete."<<endl;
            return;
        }
        arr[1]=arr[i--];
        int j=1;
        while(j<i){
            int left=j*2;
            int right=j*2 + 1;
            if(arr[j]<arr[left] || arr[j]<arr[right]){
                if(arr[left]>=arr[right]){
                    swap(arr[j],arr[left]);
                    j=left;
                }else{
                    swap(arr[j],arr[right]);
                    j=right;
                }
            }
            else{
                break;
            }
        }

    }
};
void heapify(int arr[],int n, int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=n && arr[largest] < arr[left]){
        largest=left;
    }
    if(right<=n && arr[largest]<arr[right]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,n,largest);
    }
}
void heapSort(int arr[],int n){
    int t=n;
    while(t>0){
        // swaping maximum with last node
        swap(arr[t],arr[1]);
        // last node at right place so ingnore it.
        t--;
        heapify(arr,t,1);
    }
}
int main(){
    // heap h;
    // h.insert(40);
    // h.insert(55);
    // h.insert(45);
    // h.insert(30);
    // h.insert(47);
    // h.print();
    // h.deleteFromNode();
    // h.print();
    int arr[10]={-1,54,53,55,52,60,1,100,32,22};
    int n=9;
    for(int i=n/2+1;i>0;i--){
    heapify(arr,n,i);
    }
    for(int i=1;i<=n;i++){
            cout<<arr[i]<<" ";
        
    }
    cout<<endl;
    heapSort(arr,n);
    for(int i=1;i<=n;i++){
            cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}