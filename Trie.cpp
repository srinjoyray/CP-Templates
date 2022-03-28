struct node
{
    bool leaf;  //if the node is a leaf then, a word in the dictionary ends at this node.
    node* child[26];
};

node* create()
{
    node* curr = new node();
    for(int i=0;i<26;i++)curr->child[i]=NULL;
    curr->leaf=false;
    return curr;
}

void add(string x , node* root)
{
    node* curr=root;  
    for(int i=0;i<x.length();i++)
    {
        if(curr->child[x[i]-'0']==NULL)
        {
            curr->child[x[i]-'0']=create();
        }
        curr=curr->child[x[i]-'0'];
    }
    curr->leaf=true;
}

node* root=create(); //add this inside solve function