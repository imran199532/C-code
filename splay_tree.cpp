#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 100010
#define pi pair<int,int>
#define mp make_pair
#define ss second
#define ff first
#define pb push_back

struct node
{
    int val;
    node* par;
    node*left;
    node*right;
    node(){;}

    node(int x)
    {
        val=x;
        par=NULL;
        left=NULL;
        right=NULL;
    }

};


struct node *root;

void zig_l(node *cur)
{

    node* cur_r=cur->right;

    cur->right=root;
    cur->par=NULL;
    root->par=cur;

    root->left=cur_r;
    cout<<"K";
    if(cur_r!=NULL)cur_r->par=root;

    root=cur;

}

void zig_r(node *cur)
{
    node* cur_l=cur->left;
    cur->left=root;
    cur->par=NULL;
    root->par=cur;
    root->right=cur_l;
    if(cur_l!=NULL)cur_l->par=root;
    root=cur;

}


node * zig_zag_rl(node *cur)
{
    node *p=cur->par;
    node* g=p->par;
    node* parent=g->par;
    int f=0;
    if(parent==NULL)f=2;
    else if(parent->left==g){
        f=1;
    }


    g->right=cur->left;
    p->left=cur->right;
    if(cur->left!=NULL)cur->left->par=g;
    if(cur->right!=NULL)cur->right->par=p;
    cur->left=g;
    cur->right=p;
    g->par=cur;
    p->par=cur;
    if(f==2){
        cur->par=NULL;
        root=cur;
    }
    else if(f){
        parent->left=cur;
        cur->par=parent;
    }

    else{
        parent->right=cur;
        cur->par=parent;
    }

    return cur;


}


node * zig_zag_lr(node *cur)
{
    node *p=cur->par;
    node* g=p->par;
    node* parent=g->par;
    int f=0;
    if(parent==NULL)f=2;
    else if(parent->left==g){
        f=1;
    }


    g->left=cur->right;
    p->right=cur->left;
    if(cur->right!=NULL)cur->right->par=g;
    if(cur->left!=NULL)cur->left->par=p;
    cur->right=g;
    cur->left=p;
    g->par=cur;
    p->par=cur;
    if(f==2){
        cur->par=NULL;
        root=cur;
    }
    else if(f){
        parent->left=cur;
        cur->par=parent;
    }

    else{
        parent->right=cur;
        cur->par=parent;
    }


    return cur;

}


node * zig_zig_rr(node *cur)
{
    node *p=cur->par;
    node* g=p->par;
    node* parent=g->par;
    int f=0;
    if(parent==NULL)f=2;
    else if(parent->left==g){
        f=1;
    }


    g->right=p->left;
    if(p->left!=NULL)p->left->par=g;
    p->left=g;
    g->par=p;
    p->right=cur->left;
    if(cur->left!=NULL)cur->left->par=p;
    cur->left=p;
    p->par=cur;

    g->par=cur;
    p->par=cur;
    if(f==2){
        cur->par=NULL;
        root=cur;
    }
    else if(f){
        parent->left=cur;
        cur->par=parent;
    }

    else{
        parent->right=cur;
        cur->par=parent;
    }

    return cur;


}


node * zig_zig_ll(node *cur)
{
    node *p=cur->par;
    node* g=p->par;
    node* parent=g->par;
    int f=0;
    if(parent==NULL)f=2;
    else if(parent->left==g){
        f=1;
    }


    g->left=p->right;
    if(p->right!=NULL)p->right->par=g;
    p->right=g;
    g->par=p;
    p->left=cur->right;
    if(cur->right!=NULL)cur->right->par=p;
    cur->right=p;
    p->par=cur;

    g->par=cur;
    p->par=cur;
    if(f==2){
        cur->par=NULL;
        root=cur;
    }
    else if(f){
        parent->left=cur;
        cur->par=parent;
    }

    else{
        parent->right=cur;
        cur->par=parent;
    }
    return cur;



}


void print_tree(node *cur)
{
    printf(" %d\n",cur->val);

    node* l=cur->left;
    node* r=cur->right;
    if(l!=NULL){
        cout<<"left "<<cur->val;
        print_tree(l);
    }
    if(r!=NULL){
        cout<<"right "<<cur->val;
        print_tree(r);
    }
}

void splay(node *cur)
{

    if(cur->par==NULL)return;
    if(root->left==cur){


        zig_l(cur);
        return;
    }

    if(root->right==cur){
        zig_r(cur);
        return;
    }


    node *p=cur->par;
    node* g=p->par;

    if(g->right==p && p->left==cur){
        node* temp=zig_zag_rl(cur);
        splay(temp);
    }
    else if(g->left==p && p->right==cur){
        node* temp=zig_zag_lr(cur);
        splay(temp);
    }

    else if(g->right==p && p->right==cur){

        node* temp=zig_zig_rr(cur);

        splay(temp);
    }

    else if(g->left==p && p->left==cur){

        node* temp=zig_zig_ll(cur);
        splay(temp);
    }



}

void find_val(int val,node *cur)
{

    if(cur==NULL)return;
    if(cur->val==val){
        splay(cur);
        return;
    }

    if(val<cur->val)find_val(val,cur->left);

    else find_val(val,cur->right);



}

pair<node *,int> split(node *cur,int x)
{
    if(cur->val==x)return mp(cur,0);
    if(cur->left==NULL && cur->right==NULL){
        if(x<cur->val)return mp(cur,1);
        return mp(cur,2);
    }

    if(cur->left==NULL && cur->val>x)return mp(cur,1);
    if(cur->right==NULL && cur->val<x)return mp(cur,2);
    if(cur->right!=NULL && cur->val<x)return split(cur->right,x);
    if(cur->left!=NULL && cur->val>x)return split(cur->left,x);

}

pair<node *,int> find1(node *cur,int x)
{
    if(cur->val==x)return mp(cur,1);

    if(cur->left==NULL && cur->val>x)return mp(cur,0);
    if(cur->right==NULL && cur->val<x)return mp(cur,0);
    if(cur->right!=NULL && cur->val<x)return find1(cur->right,x);
    if(cur->left!=NULL && cur->val>x)return find1(cur->left,x);

}

void insert1(int val)
{

    if(root==NULL){
        node *temp=new node(val);
        root=temp;
        return;
    }

    pair<node*,int> ret=split(root,val);
   // cout<<ret.ff->val<<endl;
    splay(ret.ff);

    node *temp,*left,*right;
    temp=new node(val);

    if(ret.ss==1){
        temp->right=root;
        root->par=temp;
    }

    else if(ret.ss==2){

        right=root->right;

        root->right=NULL;
        temp->left=root;

        temp->right=right;

        root->par=temp;
        if(right!=NULL)right->par=temp;

    }
    root=temp;
}

node *mx_node(node*cur)
{
    if(cur->right==NULL)return cur;
    return mx_node(cur->right);
}

void delete1(int x)
{
    pair<node *,int>temp=find1(root,x);

    if(temp.ss==0)return;

    splay(temp.ff);

    //cout<<"< "<<root->val<<endl;
    if(root->left==NULL)
    {
        root=root->right;
        root->par=NULL;
    }


    node* mxi=mx_node(root->left);
    node* right=root->right;
    root=root->left;
    root->par=NULL;
    splay(mxi);

    root->right=right;
    right->par=root;


}

int main()
{

   // freopen("C:/Users/imran/Desktop/input.txt","rb",stdin);
    //freopen("output.txt","w",stdout);

    int arr[]={1,4,2,7,9,6};
    for(int i=0;i<=5;i++){
        insert1(arr[i]);
        print_tree(root);
        cout<<endl<<endl;

    }

    insert1(5);
    print_tree(root);
    cout<<endl;
    delete1(4);
    print_tree(root);
    cout<<endl;


    /*

    root=new node(5);
    node *let=new node(8);
    node *rig=new node(6);
    root->right=let;
    let->par=root;
    let->left=rig;
    rig->par=let;

    print_tree(root);
    cout<<endl;

    find_val(8,root);
    print_tree(root);
*/







   // fclose(stdin);
    //fclose(stdout);

}

