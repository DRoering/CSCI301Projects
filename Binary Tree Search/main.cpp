#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ostream>
#include <cstring>
#include <iomanip>

using namespace std;

class List
{
public:
    typedef int item;

    ///constructors
    List(){root=NULL;}
  //  List(List source);

    ///destructor
    ~List();

    ///modification member functions
    void make_empty();
    void Insert(item entry);
    void Remove(item target);
    void operator=(List source);

    ///constent member functions
    bool empty(){return root==NULL;}
    int length(item i);
    bool present(item target);
    void Kth(int K);

    ///friend function
    friend std::ostream& operator << (std::ostream& out_s, List&);


private:
    struct node
    {
        item data;
        node *left;
        node *right;
    };
    node *root;
    node *get_node(item entry, node *link);

    ///destroy recursive
    void destroy(node *r)
    {
        if(r!=NULL)
        {
            destroy(r->left);
            destroy(r->right);
            delete r;
        }
    }

    ///insert recursion
    void Insertr(node *&r, item entry)
    {
        if (r==NULL)
            {
               r= new node;
               r-> data=entry;
               r-> left=NULL;
               r->right=NULL;
            }

        else if(entry<r->data)
            Insertr(r->left,entry);
        else
            Insertr(r->right,entry);
    }

    ///remove recursion
    void Remover(node *&t, item target)
    {
        if(t->data==target)
            {
                remove_node(t);
            }
        else if (target<t->data)
            Remover(t->left,target);
        else
        {
            Remover(t->right,target);
        }
    }

    void remove_node(node*&t)
    {
        node *ptr;
        node *Back;
        if(t->left==NULL && t->right==NULL)
        {
            delete t;
            t=NULL;
        }
        else if(t->left==NULL)
        {
            ptr=t;
            t=t->right;
            delete ptr;
        }
        else if(t->right==NULL)
        {
            ptr=t;
            t=t->right;
            delete ptr;
        }
        else
        {
            Back=t;
            ptr=t->right;
            while(ptr->left!=NULL)
            {
                Back = ptr;
                ptr=ptr->left;
            }
            t->data=ptr->data;
            if(Back==t)
                remove_node(Back->right);
            else
                remove_node(Back->left);
        }
    }

    ///length recursion
    int lengthr(node *p)
    {
        if (p==NULL)
            return 0;
        else
            return lengthr(p->left)+1+lengthr(p->right);
    }

    ///present recursion
    bool presentr(item target, node *r)
    {
        if(r==NULL)
        {
            return false;
        }
        else if(target< r->data)
        {
            return presentr(target,r->left);
        }
        else if (target==r->data)
        {
            return true;
        }
        else
            return presentr(target,r->right);
    }

    ///kth recursion
    void Kthr(int entry, int i, node *r)
    {
        if (r == NULL)
            return;

        i += entry;

        Kthr(entry, i, r->right);

        cout<<endl;

        for (int j = entry; j < i; j++)
            cout<<" ";

        cout<<r->data<<"\n";

        Kthr(entry, i, r->left);

    }
};




//List::List(List source)
//{
//    node *p;
//    node *last;
//    if (source.root==NULL)
//        root= NULL;
//    else
//        root->data;
//    root= get_node(source.root-> data, NULL);
//    last= root;
//    p= source.root-> next;
//    while(p!=NULL)
//    {
//        p= next-> data;
//        cout<< *p<< endl;
//    }
//
//}

List::~List()
{
///    desrtoy(root);
}

///makes list empty
void List::make_empty()
{
    destroy(root);
    root==NULL;
}

///inserts item in correct position
void List::Insert(item entry)
{

    Insertr(root,entry);
//        if (prev->next!=NULL&& prev->next->data<entry)
//           {
//            prev=prev->next;
//            Insertr (entry, prev);
//           }
//
//       else
//            prev->next= get_node(entry,prev->next);

}

///removes value from list
void List::Remove(item target)
{
    Remover(root,target);
//        while(prev-> next-> data!= target)
//            {
//                prev=prev->next;
//            }
//        temp= prev-> next;
//        prev-> next= temp->next;
//        delete temp;

}

void List::operator=(List source)
{
    node *p, *last;
    if(&source != this)
    {
        make_empty();

    }
}

///tells how long the list is
int List::length(item i)
{

    node *p= root;
//    if (p!=NULL)
//    {
//        ++i;
//        p= p->next;
//        root= root->next;
//        length(i);
//    }
    return lengthr(p);
}

//List::node*List::get_node(item entry, node *Forward)
//{
//    node *temp;
//    temp=new node;
//    temp->data=entry;
//    temp-> next= Forward;
//    return temp;
//}

///tells if a value is present in the list
bool List::present(item target)
{
    node *p;
    p=root;
//    while(p!=NULL&& p->data!=target)
//        p=p->next;
//    return p!=NULL;
return presentr(target, p);
}

///tells what value is at kth position
void List::Kth(int entry)
{
    node *r;
    r=root;
    int i=0;

    Kthr(entry,i,r);
}

int main()
{

    int choice;
    int entry;
    bool ans;
    int ansI;
    int i=0;

    List l;

    /// runs until user hits quit
    while(choice !=8)
    {
    cout <<"1  -- Re-initialize the list to be empty. " << endl;
    cout <<"2  -- Insert the value v into the list. " << endl;
    cout <<"3  -- Remove the value v from the list. " << endl;
  ///  cout <<"4  -- Is the list empty? " << endl;
    cout <<"4  -- Report the length of the list. " << endl;
    cout <<"5  -- Is the value v present in the list? " << endl;
   /// cout <<"7  -- Report the k'th value in the list. " << endl;
    cout <<"6  -- Write out the list. " << endl;
    cout <<"7  -- See this menu. " << endl;
    cout <<"8 -- Quit. "  << endl;

    cin >> choice;

    switch (choice)
    {
        case 1:
            l.make_empty();
            break;

        case 2:
            cout<< "What value do you want inserted?"<< endl;
            cin >>entry;
            l.Insert(entry);

            break;

        case 3:
            cout<< "What value do you want removed?"<< endl;
            cin >>entry;
            l.Remove(entry);

            break;

        case 4:
            entry= l.length(i);
            cout<< "The list is "<< entry<< " numbers long."<< endl;
            break;

        case 5:
            cout<< "What is the value you want to check for?"<< endl;
            cin>> entry;
            ans=l.present(entry);
            if (ans==1)
                cout<< entry<< " is present in the list."<< endl;
            else
                cout<< entry<< " is not present in the list."<< endl;
            break;

        case 6:
            entry= l.length(i);

            l.Kth(entry);

            break;

        case 7:
            break;

        case 8:
            break;

        default:
        cout << "Not a Valid Choice. \n"
        << "Choose again.\n";
        break;
    }
    }

return 0;

}


