#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define f(i,a,b) for(ll i=a;i<b;i++)

int main(){

	ll n;cin>>n;
	int a[n]={0};
	f(i,0,n){
		cin>>a[i];
	}
	deque<ll> q;
	stack<ll> s;
	ll k;
	cin>>k;
	ll max=-9999;
	f(i,0,k)
	{	q.push_back(a[i]);
		if(a[i]>max)
			max=a[i];
	}

	cout<<max<<' ';s.push(max);


	f(i,k,n){
		ll p=q.front();
		q.pop_front();
		if(p==max){

				q.push_back(a[i]);
				deque<ll>::iterator it;ll maxQueue=-9999;
				for(it = q.begin();it!=q.end();it++){
					if(*it>maxQueue){
						maxQueue=*it;
					}
				}
				s.push(maxQueue);

		}
		else{
			q.push_back(a[i]);
			ll maxStack=s.top();
			if(maxStack<a[i])
				s.push(a[i]);
		}
		ll ans=s.top();max=ans;
		cout<<ans<<' ';

	}

	return 0;
}
