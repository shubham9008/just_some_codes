#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(ll i=a;i<b;i++)


class Trie{
	public:
	Trie * child[26];//very important part
	bool isEndofWord;
	

	Trie(){
		//Trie * node  = (Trie *)malloc(sizeof(Trie *));//not forget to add pointer(*) symbol 
		this->isEndofWord=false;
		for(int i=0;i<26;i++)
			this->child[i]=NULL;
		
	}
	
	
	void insert(string a){
		
		Trie * temp=this;//as we are copying the entire current object
		for(int i=0;i<a.length();i++){
			
			/*if(!(temp[a[i]-97])){
				temp[a[i]-97]=new Trie();
			}*/
			if(temp->child[a[i]-97]==NULL){
			
				temp->child[a[i]-97]=new Trie();
				
			}
			temp=temp->child[a[i]-97];
			//temp=temp[a[i]-97];
		}
		//temp[a[a.length()-1]-97]->isEndofWord=true;//this is giving wroong . is giving correct
		//cout<<"inserted successfully"<<endl;
		temp->isEndofWord=true;
	}
	
	
	bool search(string a){
		Trie * temp=this;//as we are copying the entire current object
		if(temp==NULL)
			return false;
		
		
		for(int i=0;i<a.length();i++){
			
			/*if(!(temp[a[i]-97])){
				temp[a[i]-97]=new Trie();
			}*/
			
				temp=temp->child[a[i]-97];
				if(temp==NULL)
					return false;
			
			
			
		}
		//temp[a[a.length()-1]-97]->isEndofWord=true;//this is giving wroong . is giving correct
		return ( temp->isEndofWord);
	}
	
//	void search(
};



/*int main(){
Trie x;
//Trie * x is wrong 
//Trie * x = new Trie(); is correct
x.insert("haha");
x.insert("alphabet");
x.insert("aahahaeep");

cout<<x.search("alphabet")<<endl;
//delete(y);
return 0;
}*/

int main(){

//Trie * x is wrong 
//Trie * x = new Trie(); is correct
//Trie x is correct;
Trie x;
ll t;cin>>t;
	while(t--){
        ll n;
        cin>>n;
        string s;
        f(i,0,n){
        	cin>>s;x.insert(s);
        }
        cin>>s;
          cout<<x.search(s)<<endl;
	    
	}
	return 0;
}
