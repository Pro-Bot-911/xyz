#include <iostream>
using namespace std;

struct node
{
    int data;
    node*left;
    node*right;
    node(int val):data(val),left(nullptr),right(nullptr){}
};

//function prototype
void insert(node *&root,int k);
void search(node* root,int k);
node *postorderpre(node *root,int k);
void postorder(node *root);

void insert(node *&root,int k){
    if(root==nullptr){
     root=new node(k);
    }
    else if(k<root->data){
      insert(root->left,k);
    }
    else{
        insert(root->right,k);
    }
}

void search(node *root, int k){
    if(root==nullptr)
    {
        cout<<"key not found :";
        return;
    }
    if(k==root->data){
        cout<<"key found :";
        return;

    }
    if(k<root->data){
        search(root->left,k);
    }
    else{
        search(root->right,k);

    }
}

    node * postorderpre(node *root,int k){
        node *temp=root;
        node * prev=nullptr;
        while(temp){
        if(k==temp->data){
            return prev;

        }
        else  if(k<temp->data){
            prev=temp;
            temp=temp->left;
            return prev;

        }
        else{
            prev=temp;
            temp=temp->right;
            return prev;
        }
        }
        return prev;
    }

    void postorder(node*root){
        if(root==nullptr){
            return ;
        }
        postorder(root->left);
        postorder(root->right);
        cout<<root->data;
    }
int main(){
    node *root=NULL;
    insert(root,4);
     insert(root,2);
      insert(root,6);
       insert(root,3);
        insert(root,9);
         insert(root,5);
          insert(root,8);

    int key=8;
    search(root,key);
    node*predecessor=postorderpre(root,key);
    cout<<"postorderprecedor is :"<<predecessor->data<<endl;

    cout<<"post order traversal is :"<<endl;
    postorder(root);
    return 0;

}
