#include<iostream>
#include<queue>
using namespace std;
class node
{
        public:
        int data;
        node* left,*right;

        node(int data)
        {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }

        //member func
         void  Tree_display(node* root)
{
    queue<node*> q ;
    q.push(root);
    while(!q.empty())
    {
        node* temp = q.front();
        cout<<" node -> "<<temp->data;
        if(temp->left == NULL)
        cout <<" left  "<<"-1";
        else
       cout <<" left  "<<temp->left->data;
        if(temp->right == NULL)
        cout <<" right  "<<"-1"<<endl;
        else
        cout<<"  right  "<<temp->right->data<<endl;


        q.pop();
        if(temp->left)
        q.push(temp->left);

        if(temp->right)
        q.push(temp->right);

    }

    
}

};

node* BST( int arr[], int size)
{
    node* root = new node(arr[0]);       
    
    for(int i=1; i<size; i++)
    {
        node* temp = root;
        bool place_found = false;
       while(place_found == false)
       {
           // cout<<"hello";
            if(arr[i] < temp -> data)
            {
                if(temp->left != NULL)
                temp = temp->left;
                else
               {
                 temp ->left = new node(arr[i]);
                 place_found = true;
                 
                }
            }

             if(arr[i] > temp -> data)
            {
                if(temp->right != NULL)
                temp = temp->right;
                else
               {
                 temp ->right = new node(arr[i]);
                 place_found = true;
                 
                }
            }

       }
    }
    return root;
}


node* BST_toLL(node* root, node* &head)
{
    if(root == NULL)
    return NULL;

    BST_toLL(root->right, head);
    root ->right = head;

    if(head != NULL)
    {
        head ->left = root;
    }
    head = root;
    BST_toLL(root->left,head);

    return head;
}


node* mergeLL(node* head1, node* head2, node* fin)
{
    node* tail  =NULL;
    if(head1 == NULL)
    return head2;

    if(head2 ==  NULL)
    return head1;

     if(head1->data  < head2->data)
        {
           fin = head1;
           tail = head1;
           head1 = head1->right;
        }
        else{
            fin = head2;
            tail = head2;
            head2 = head2 ->right;
        }
    

    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data  < head2->data)
        {
            tail ->right = head1;
            head1->left = tail;
            tail = head1;
            head1=  head1->right;
        }
        else{
            tail ->right = head2;
            head2->left = tail;
            tail = head2;
            head2=  head2->right;
        }

    }

    while(head1 != NULL)
    {
            tail ->right = head1;
            head1->left = tail;
            tail = head1;
            head1=  head1->right;
    }

    while(head2 != NULL)
    {
            tail ->right = head2;
            head2->left = tail;
            tail = head2;
            head2=  head2->right;
    }
    return fin;
}

node* LL_toBST(node* &head,int n)
{
    if(head == NULL || n <= 0)
    return NULL;

    // create left sbt from n/2 nodes
    node* left = LL_toBST(head,n/2);
    node* root = head;
    root->left = left;
    head = head->right;
    root->right = LL_toBST(head,n-1-n/2);

    return root;

}

node* solve(node* root1, node* root2)
{
     node* head1 = BST_toLL(root1,head1);
     node* head2 = BST_toLL(root2,head2);

     node* LL = mergeLL(head1,head2,LL);
     node* fin = LL_toBST(LL,6); // get 6 by putting count in any func made above


     return fin;
}

int main()
{
    int arr1[] = {1,4,5};
    node* root1 = BST(arr1,3);

    int arr2[] = {6,2,8};
    node* root2 = BST(arr2,3);
   
   node * root = solve(root1,root2);
   

 
    return 0;

}




// *************     METHOD OF MERGING TWO SORTED_INORDER VECTORS AND MAKING A BST OUT OF IT**************
//  TO FURTHER OPTIMIZE THE SPACE COMPLEXITY TO O(1) WE WILL USE LINKED LIST METHOD************


// void getin(node* root, vector<int> &v)
// {
//     if(root == NULL)
//     return;

//     if(root->left)
//     getin(root->left,v);

//     v.push_back(root->data);

//     if(root->right)
//     getin(root->right,v);

//     return;

// }

// vector<int> merge2(vector<int> &v1, vector<int> &v2)
// {
//     vector<int> ret;
//     int i1 = 0,i2 = 0;
//     while(i1 < v1.size()  &&  i2 < v2.size())
//     {
//         if(v1[i1] > v2[i2])
//         {
//             ret.push_back(v2[i2]);
//             i1++;
//         }
//         else{
//             ret.push_back(v1[i1]);
//             i2++;
//         }
//     }
// while(i1 < v1.size())
// {
//     ret.push_back(v1[i1]);
//     i1++;
// }

// while(i2 < v2.size())
// {
//     ret.push_back(v2[i2]);
//     i2++;
// }
//     return ret;
// }

// node* inToB(vector<int> &v,int s, int e)
// {
//     if(s > e)
//     return NULL;

//     int mid = (s + e) / 2;
//     node* root = new node(v[mid]);
//     root->left = inToB(v,0,mid-1);
//     root->right = inToB(v,mid+1,e);

//     return root;

// }

// node* solve(node* root1, node* root2)
// {
//     vector<int> in1;    // stores inorder of first tree
//      getin(root1,in1);
//     vector<int> in2;
//     getin(root2,in2);   //stores inorder of second tree

//     // merge two vectors
//     vector<int> fin;
//     fin = merge2(in1, in2);

//     // inorder to BST
//     node* root = inToB(fin, 0 , fin.size()-1);


//     return root;
// }
