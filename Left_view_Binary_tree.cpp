int max_depth=-1;
void solve(Node* root,int depth) {
if(!root)
return;
if(depth>max_depth)
{cout<<root->data<<" ";max_depth=depth;}
solve(root->left,depth+1);
solve(root->right,depth+1);
}
void leftView(Node *root)
{
max_depth=-1;
solve(root,0);
}



////Another approach - Do level order traversal, for each time a new level visited , printout the node that visits it(keep its track
using a bool visited[],for keeping track of levels use map[child]=map[parent]+1
