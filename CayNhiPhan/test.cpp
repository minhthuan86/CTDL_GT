#include<iostream>
#include<conio.h>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
};
typedef Node *Tree;
Tree TaoNode(int a){
    Tree p=new Node;
    p->data=a;
    p->left=NULL;
    p->right=NULL;
    return p;
}
Tree TimVT(Tree T,char a){
    Tree p=T,q;
    while(p!=NULL){
        q=p;
        if(p->data==a) return NULL;
        if(p->data>a) p=p->left;
        else p=p->right;
    }
    return q;
}
void Insert(Tree &T,int a){
    Tree p,q;
    p=TaoNode(a);
    if(T==NULL) {
        T=p; return;
    }
    q=TimVT(T,a);
    if(q==NULL) return;
    if(q->data>a) q->left=p;
    else q->right=p;
}
void Insert_DeQui(Tree &T,int a){
    if(T==NULL) {
        T=TaoNode(a);
        return;
    }
    if(T->data==a) return;
    if(T->data>a) Insert_DeQui(T->left,a);
    else Insert_DeQui(T->right,a);
}
void Input(Tree &T){
    char key;
    int a;
    do{ 
        cout<<"Nhap a: ";cin>>a;
        Insert_DeQui(T,a);
        cout<<"Nhap ESC de thoat, phim bat ky de tiep tuc: \n";
        key=getch();
    }while(key!=27);
}
void Input_Mang(Tree &T,int a[],int n){
    for(int i=0;i<n;i++) Insert_DeQui(T,a[i]);
}
void Input_DeQui(Tree &T){
    int a;
    cout<<"nhap a:";cin>>a;
    if(a==0) return;
    Insert(T,a);
    Input_DeQui(T);
}
void NLR(Tree root)
{
    if (root!=NULL)
    {
        cout<<root->data<<"\t";
        NLR(root->left);
        NLR(root->right);
    }
}
Tree TK(Tree T,int n){
    if(T==NULL) return NULL;
    if(T->data==n) return T;
    if(T->data>n) return TK(T->left,n);
    else return TK(T->right,n);
}
int main(){
    int A[]={5,7,3,6,4,8,2,9,1};
    Tree Tree1=NULL;
    Input_Mang(Tree1,A,9);
    //Input_DeQui(Tree1);
    NLR(Tree1);
    Tree p=TK(Tree1,10);
    if(p==NULL) cout<<"\nKo co";
    else cout<<"\nco "<<p->data;
}