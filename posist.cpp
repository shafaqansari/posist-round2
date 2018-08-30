#include <bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node*left;
    node*right;
};

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
                      }
                  }
                  while(ch!=0);
            }
             
      }
      
      
  }
  
	return 0;
}