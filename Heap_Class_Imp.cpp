// Write your code here
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define mp make_pair

template<typename t>
class MinHeap{
public:
	int size;
	t * arr;
	int cap;
	MinHeap(){}
	MinHeap(int size){
		this->size=0;		
		this->cap=size;
		this->arr=(int *)malloc(sizeof(t)*cap);	
	}
	void heapify(){
		
	}
	void insert(t elm){
		size++;
		cout<<"this size is "<<size<<endl;
		int i=size-1;
		arr[i]=elm;
		while(arr[parent(i)]>arr[i] and parent(i)>=0){
			swap(arr[parent(i)],arr[i]);
			i=parent(i);
		}
	}
	t min(){
		return arr[0];	
	}

	int parent(int pos){
		return pos/2;
	}
	int lc(int pos){
		return pos*2+1;
	}
	int rc(int pos){
		return pos*2+2;
	}
	void decreasekey(int i,t newVal);
	void deleteKey(int pos);

};




int main(){
    
    
    MinHeap<int> x(10); 
    x.heapify(10);x.heapify(4);   
    cout<<x.min()<<endl; 
   return 0;
}
