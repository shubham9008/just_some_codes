struct node
{
    int data;
    struct node *left;
    struct node *right;
    struct node *next;
};
 
/* Set next of p and all descendents of p by traversing them in reverse Inorder */
void populateNext(struct node* p)
{
    // The first visited node will be the rightmost node
    // next of the rightmost node will be NULL
    static struct node *next = NULL;
 
    if (p)
    {
        // First set the next pointer in right subtree
        populateNext(p->right);
 
        // Set the next as previously visited node in reverse Inorder
        p->next = next;
 
        // Change the prev for subsequent node
        next = p;
 
        // Finally, set the next pointer in left subtree
        populateNext(p->left);
    }
}


// An implementation that doesn't use static variable
 
// A wrapper over populateNextRecur
void populateNext(struct node *root)
{
    // The first visited node will be the rightmost node
    // next of the rightmost node will be NULL
    struct node *next = NULL;
 
    populateNextRecur(root, &next);
}
 
/* Set next of all descendents of p by traversing them in reverse Inorder */
void populateNextRecur(struct node* p, struct node **next_ref)
{
    if (p)
    {
        // First set the next pointer in right subtree
        populateNextRecur(p->right, next_ref);
 
        // Set the next as previously visited node in reverse Inorder
        p->next = *next_ref;
 
        // Change the prev for subsequent node
        *next_ref = p;
 
        // Finally, set the next pointer in right subtree
        populateNextRecur(p->left, next_ref);
    }
}
