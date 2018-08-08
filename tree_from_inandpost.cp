int *extrackKeys(int in[], int level[], int m, int n)
{
    int *newlevel = new int[m], j = 0;
    for (int i = 0; i < n; i++)
        if (search(in, 0, m-1, level[i]) != -1)
            newlevel[j] = level[i], j++;
    return newlevel;
}


Node* buildTree(int in[], int level[], int inStrt, int inEnd, int n)
{
 
    // If start index is more than the end index
    if (inStrt > inEnd)
        return NULL;
 
    /* The first node in level order traversal is root */
    Node *root = newNode(level[0]);
 
    /* If this node has no children then return */
    if (inStrt == inEnd)
        return root;
 
    /* Else find the index of this node in Inorder traversal */
    int inIndex = search(in, inStrt, inEnd, root->key);
 
    // Extract left subtree keys from level order traversal
    int *llevel  = extrackKeys(in, level, inIndex, n);
 
    // Extract right subtree keys from level order traversal
    int *rlevel  = extrackKeys(in + inIndex + 1, level, n-inIndex-1, n);
 
    /* construct left and right subtress */
    root->left = buildTree(in, llevel, inStrt, inIndex-1, n);
    root->right = buildTree(in, rlevel, inIndex+1, inEnd, n);
 
    // Free memory to avoid memory leak
    delete [] llevel;
    delete [] rlevel;
 
    return root;
}
