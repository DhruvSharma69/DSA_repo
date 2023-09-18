#include<iostream>
#include<queue>
#include<map>

using namespace std; 

class node
{
    public:
    int data;
    node* left;
    node* right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;  
    }
};

// INPUT ->  1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1   ,,  1 2 4 -1 -1 5 7 -1 -1 8 -1 -1 3 -1 6 -1 9 -1 10 -1 -1


node* BT()
{
    cout<<"Enter the data for root node \n";
    int d;
    cin>>d;

    if(d== -1)
    return NULL;

    node* root = new node(d);
    cout<<"\n Enter left  of  "<<d<<endl;
    root ->left = BT();

    cout<<"\n Enter right of  "<<d<<endl;
    root ->right = BT();

    return root;

}

map<node*,node*> get_parent(node* root)
{
    map<node*,node*> m;
    queue<node*> q;
    q.push(root);
    m[root] = NULL;
    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();
        if(temp->left)
       { 
            q.push(temp->left);
            m[temp->left] = temp;
       
       }

        if(temp->right)
        {
            q.push(temp->right);
            m[temp->right] = temp;
        }
    }
    return m;
}

int Burning_tree(node* root, node* target)
{
    if(root == NULL)
    {
        return 0;
    }
    int seconds = 0;

   map<node*,node*> root_to_parent =  get_parent( root);
   map<node*,bool> burnt;
   //initialising burnt
   map<node*,node*> :: iterator it1 = root_to_parent.begin();
   while(it1 != root_to_parent.end())
   {
        burnt[it1->first] = false;
        it1++;
   }

   queue<node*> q;
   q.push(target);
   while(!q.empty())
   {
        int temp_sec = 0;
        
        node* temp = q.front();

        if(burnt[temp] == false)
        { 
             burnt[temp] = true;
             temp_sec += 1;
        
        }

        q.pop();

        if(temp->left && burnt[temp->left] == false)
        {
            q.push(temp->left);
            burnt[temp->left] = true;
            temp_sec += 1;
        }

         if(temp->right && burnt[temp->right] == false)
        {
            q.push(temp->right);
            burnt[temp->right] = true;
            temp_sec += 1;
        }
            node* parent = root_to_parent[(temp)];
        if(parent && burnt[parent] == false )
        {
            q.push(parent);
            burnt[parent] = true;
            temp_sec += 1;
        }

        // seconds update
        if(temp_sec != 0)
        seconds += 1;
   }
   return seconds;
}

int main()
{
    node* root = NULL;
    root = BT();
  int ans = Burning_tree(root, root->left->right->right);
  cout<<" \n ans -> "<<ans;
    return 0 ;
}