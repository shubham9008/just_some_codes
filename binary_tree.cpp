#include<bits/stdc++.h>
using namespace std;
static int countx=0;static int ans=0;
struct node{
int key;struct node *right=NULL,*left=NULL;
};

struct node * getnode(int key){
struct node *x=new node();
x->key=key;
return x;
}


void insert(struct node *root,int key){
struct node * x=getnode(key);
queue<struct node *>q;
q.push(root);
struct node *r=NULL;
while(!q.empty()){
r=q.front();q.pop();
if(r->left){
q.push(r->left);
}
else{
r->left=x;break;
}
if(r->right){
q.push(r->right);
}
else{
r->right=x;break;
}
}
}
int eval(struct node * root){

if(root->key>=100 and root->key<=103)
{
int opd1=0,opd2=0,res=0,opr=0;
opr=root->key;
cout<<opr<<endl;
if(!root->left)
opd1=root->left->key;

else
opd1=eval(root->left);

if(!root->right)
opd2=root->right->key;

else
opd2=eval(root->right);

if(root->key==100)
res=opd1+opd2;
else if(root->key==101)
res=opd1-opd2;
else if(root->key==102)
res=opd1*opd2;
else if(root->key==103)
res=opd1/opd2;

return res;

}

return root->key;
}
int main(){
 struct node* root = getnode(100);
    root->left = getnode(102);
    root->right = getnode(101);
    root->left->left=getnode(5);
root->left->right=getnode(4);
root->right->left=getnode(100);
root->right->right=getnode(20);


int res;
res= eval(root);



cout<<res<<endl;
return 0;
}


