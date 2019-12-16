
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

	MinHeap(int cap){
		this->size=0;		
		this->cap=cap;
		this->arr=(int *)malloc(sizeof(t)*cap);	
	}

	void insert(t elm){
		//size++;//size is 1 indexed
		cout<<"this size is "<<size<<endl;
		int i=size;
		arr[i]=elm;
		while(arr[parent(i)]>arr[i] and parent(i)>=0){
			swap(arr[parent(i)],arr[i]);
			i=parent(i);
		}
		size++;
	}

	t min(){
		return arr[0];	
	}

	int parent(int pos){
		if(pos%2==0)
		return pos/2-1;
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
	
	void minheapify(int i){
		t l=lc(i);
		t r=rc(i);
		t smallest=i;
		if(l<size and arr[l]<arr[i])
			smallest=l;
		if(r<size and arr[r]<arr[i])
			smallest=r;
		if(smallest!=i)//very important break condition decides when to stop
		{
			swap(arr[i],arr[smallest]);
			minheapify(smallest);
		}
	}

	t extractMin(){
		if(size==0)
			return INT_MIN;
		if(size==1){
		size--;
		//cout<<"extracted minimum element"<<arr[0]<<endl;		
		return arr[0];		
		} 
		
		t root=arr[0];
		size--;
		//arr[0]=arr[size-1];
		arr[0]=arr[size];
		minheapify(0);
		cout<<"extracted minimum element"<<endl;
		return root;
	}
	void heapsort(){
	this->size=cap;
		for(int i=0;i<this->cap;i++){
			 this->size--;
			 int temp=arr[i];
			 arr[i]=arr[this->size];
			 arr[this->size]=temp;
			 minheapify(0);
			 //this->size--;
		}
		for(int i=0;i<this->cap;i++){
			cout<<this->arr[i]<<endl;
		}
	}
	
};




int main()
{
    MinHeap<int> x(10); 
    x.insert(1);x.insert(-2);x.insert(10);x.insert(20);
    x.heapsort();

	
   return 0;
}
