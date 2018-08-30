#include <bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node*left;
    node*right;
}*start1;

string encrypt(string str)
{
    
    int i=0;
    string ans="";
    while(i<str.size())
    {
        if( (int) str[i] + 3 <=122)
          ans+= (char)((int) str[i] + 3);
        else if((int) str[i] + 3 >122)
        {
            int count=3- (122- (int) str[i]);
            count--;
            ans+= (char)(97+count);
            
        }
    }
    return ans;
    
    
    
}
node* newNode(int nval)
{
    node* temp;
    temp->val=nval;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

node* creation(int rval)
{
    node* start=new node;
    start->val=rval;
    node*ptr=start;
    start1=start;
    char ch='y';
    char choice;
    validation: while(ch!='n')
    {
        int sum=0;
        cout<<"Current node val"<<ptr->val<<"\n";
        cout<<"Want to enter left child?(y/n) \n";
        cin>>choice;
        if(ch=='y')
        {
            cout<<"enter Lchild\n";
            int val;
            cin>>val;
            ptr->left=newNode(val);
           // ptr=ptr->left;
        }
        cout<<"Want to enter right child?(y/n) \n";
        cin>>choice;
        if(ch=='y')
        {
            cout<<"enter Rchild\n";
            int val;
            cin>>val;
            ptr->right=newNode(val);
            //ptr=ptr->right;
        }
        if(ptr->val < (ptr->left->val + ptr->right->val))
            {
                cout<<"Parent node's value cannot be snaller than the sum of children node\n";
                cout<<"enter again\n";
                goto validation;
            }
        if(ptr->left)
           ptr=ptr->left;
        if(ptr->left==NULL && ptr->right!=NULL)
          ptr=ptr->right;
        cout<<"Want to enter more? (y/n) \n";
        cin>>ch;
    }
}
void editSubtree(node * root,int nval)
{
   if(root==NULL)
   return;
   else if(root->val==nval)
   {
       cout<<"enter the new value\n";
       int newval;
       cin>>newval;
       root->val=newval;
       cout<<"Successfully Edited\n";
       return;
   }
   else
   {
       
           editSubtree(root->left,nval);
           editSubtree(root->right,nval);
           
   }
    
}
void editleaf(node*root , int nval)
{

if(root==NULL)
   return;
   else if(root->val==nval && root->right==NULL && root->left==NULL)
   {
       cout<<"enter the new value\n";
       int newval;
       cin>>newval;
       root->val=newval;
       cout<<"Successfully Edited\n";
       return;
   }
   else
   {
       
           editSubtree(root->left,nval);
           editSubtree(root->right,nval);
           
   }
    
}
int LongestChain(node* root)
{
    if(root==NULL)
       return 0;
    else
    return 1+ max(LongestChain(root->left),LongestChain(root->right));
}
node * find(node* start1,int nval)
{
    if(start1->val==nval)
       return start1;
       
    find(start1->left,nval);
    find(start1->right,nval);
}
int Height(node* np)
{
    if(np==NULL)
    return 0;
    
    return 1+max(Height(np->left),Height(np->right));
}
void merge(int val1,int val2)
{
    node* np1=find(start1,val1);
    node* np2=find(start1,val2);
    if(Height(np1)> Height(np2))
       {
           np1->val+=np2->val;
           np2->val=0; //consider for deletion
       }
    else 
    {
        np2->val+=np1->val;
        np1->val=0 ;   //consider for deletion
    }
}
void transferOwn(int old,int nw)
{
    //validate old user Password and assign new password for new user for same id(here)
}

int main()
{
  int userChoice,rootval;
  int id;
  string upass;
  unordered_map<int,pair<string,node*> > m;
  cout<<"Press 1 for NEW User\n Press 2 for OLD user\n";
  cin>>userChoice;
 if(userChoice==1)
  {
      //New User
 newUser: cout<<"Register Yourself/n";
      cout<<"Enter Your id\n";
      cin>>id;
      if(m.find(id)==m.end())
      {
          cout<<"Enter Password\n";
          cin>>upass;
          pair<string,node> temp;
          upass=encrypt(upass);
        moreG:  cout<<"Creating New Genesis Node For You\n";
          node* np=NULL;
          cout<<"Enter the Value of Root Node\n";
          cin>>rootval;
          np=creation(rootval);
          m[id]=make_pair(upass,np);
         // m.insert(make_pair(id,make_pair(upass,np)));
          cout<<"Successfully Registered\n";
          cout<<"Press 1 if want to create more Genesis node\n";
          cin>>userChoice;
          if(userChoice==1)
             goto moreG;
      }
      else {
          cout<<"User Already Registered\n";
          goto newUser;
           }
  }
  else
  {
      //Old User
      incPass: cout<<"Enter User ID and Password to signIn\n";
      cin>>id>>upass;
      if(m.find(id)!=m.end())
      {
          unordered_map<int,pair<string,node* > > :: iterator it;
          it=m.find(id);
          if(it->second.first != encrypt(upass))
             {
                 cout<<"Incorrect Password\n";
                 goto incPass;
             }
            else
            {
                cout<<"Login Successgful\n";
                int ch=1;
                do{
                      cout<<"press 1 for Editing subtree of node\n ";
                      cout<<"press 2 for Trickling down the subtree value \n "; 
                      cout<<"press 3 for Editing Leaf Node\n";
                      cout<<"press 4 for Longest Chain\n";
                      cout<<"press 5 for merge\n";
                      cout<<"press 6 for transfering ownership\n";
                      cout<<"press 0 for Exit\n";
                      cin>>ch;
                       int nodeval;
                      switch(ch)
                      {
                       case 1: cout<<"enter node value to be edited\n";
                              
                               cin>>nodeval;
                               editSubtree(it->second.second,nodeval);
                               break;
                        case 2: cout<<"";
                               break;
                        case 3: cout<<"enter leaf node value to be edited\n";
                            
                                cin>>nodeval;
                                editleaf(it->second.second,nodeval);
                                break;
                        case 4: 
                                cout<<LongestChain(it->second.second);
                                break;
                        case 5: cout<<"enter nodes value to be merged\n";
                                 int v1,v2;
                                 cin>>v1>>v2;
                                 merge(v1,v2);
                                 break;
                        case 6: cout<<"enter new and old id of owners\n";
                                 int old,nw;
                                 cin>>old>>nw;
                                 transferOwn(old,nw);
                                 break;
                      }
                  }
                  while(ch!=0);
            }
             
      }
      
      
  }
  
	return 0;
}
