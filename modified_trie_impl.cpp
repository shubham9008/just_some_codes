#include <iostream>
using namespace std;
struct Trie{
    Trie* children[26];
    bool iswordended;
    string str;
};
Trie* getNode()
{
    Trie* node=new Trie;
    for(int i=0;i<26;i++)
    {
        node->children[i]=NULL;
    }
    node->str="";
    return node;
}
Trie* insert(Trie* root,string s)
{
    Trie* temp=root;
    for(int i=0;i<s.size();i++)
    {
        string prev=temp->str;
        if(!temp->children[s[i]-'a'])
        {
            temp->children[s[i]-'a']=getNode();
            prev.push_back(s[i]);
            temp->children[s[i]-'a']->str=prev;
        }
        
        temp=temp->children[s[i]-'a'];
    }
    
    temp->iswordended=true;
    return root;
}
void print(Trie* temp,char c)
{
    if(!temp->children[c-'a'])
    {
        return;
    }
    
    if(temp->children[c-'a']->iswordended==true)
    {
        cout<<temp->children[c-'a']->str<<" "; 
    }

    for(int i=0;i<26;i++)
    { 
        print(temp->children[c-'a'],char(i+'a'));
    }
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string s[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>s[i];
	    }
	    
	    Trie* root=getNode();
	    for(int i=0;i<n;i++)
	    {
	        root=insert(root,s[i]);
	    }
	    
	    Trie* temp=root;
	    string query;
	    cin>>query;
	    int i=0;
	    for(i=0;i<query.size();i++)
	    {
	        if(temp->children[query[i]-'a'])
	        {
	            print(temp,query[i]);
	            temp=temp->children[query[i]-'a'];
	        }
	        else break;
	        
	        cout<<endl;
	    }
	    while(i<query.size())
	    {
	        cout<<0<<endl;
	        i++;
	    }
	// cout<<root->children['j'-'a']->children['o'-'a']->children['n'-'a']->children['d'-'a']<<endl;
	}
	return 0;
}
