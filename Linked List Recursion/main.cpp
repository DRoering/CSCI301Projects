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
    List(){first=NULL;}
  //  List(List source);

    ///destructor
    ~List();

    ///modification member functions
    void make_empty();
    void Insert(item entry);
    void Remove(item target);
    void operator=(List source);

    ///constent member functions
    bool empty(){return first==NULL;}
    int length(item i);
    bool present(item target);
    int Kth(int K, int i);

    ///friend function
    friend std::ostream& operator << (std::ostream& out_s, List&);


private:
    struct node
    {
        item data;
        node *next;
    };
    node *first;
    node *first2=first;
    node *get_node(item entry, node *link);
    void Insertr(item entry, node *p)
    {
        if (p->next!=NULL&& p->next->data<entry)
           {
            p=p->next;
            Insertr (entry, p);
           }

        else
            p->next= get_node(entry,p->next);
    }

    void Remover(item target, node *prev, node* temp)
    {
        if(prev-> next-> data!= target)
            prev->next->next;
        else
        {
            temp= prev-> next;
            prev-> next= temp->next;
            delete temp;
        }
    }

    int lengthr(item i, node *p)
    {
        if (p!=NULL)
            {
                ++i;
                p= p->next;
                return lengthr(i,p);
            }

        return i;
    }

    bool presentr(item target, node *p)
    {
        if(p!=NULL&& p->data!=target)
        {
            p=p->next;
            return presentr(target,p);
        }

        else
            return p!=NULL;
    }

    int Kthr(int entry, int i, node* prev)
    {
        if (i<entry)
        {
            prev=prev->next;
            i++;
            return Kthr(entry,i,prev);
        }
        else
        return (prev->data);
    }
};

List::~List()
{
    node *temp;
    while(first!=NULL)
    {
        temp= first;
        first= first->next;
        double temp;
    }
}

///makes list empty
void List::make_empty()
{
    node *temp;
    if (first!= NULL)
    {
        temp=first;
        first= first->next;
        delete temp;
        make_empty();
    }
}

///inserts item in correct position
void List::Insert(item entry)
{
    node *prev;
    if (first==NULL||entry< first->data)
        first= get_node(entry,first);
    else
    {
        prev=first;
        Insertr(entry, prev);
    }
}

///removes value from list
void List::Remove(item target)
{
    node *prev;
    node *temp;
    prev=first;
    if (first->data==target)
    {
        first=first->next;
        delete prev;
    }
    else
    {
        Remover(target,prev,temp);

    }
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

    node *p= first;

    return lengthr(i,p);
}

List::node*List::get_node(item entry, node *Forward)
{
    node *temp;
    temp=new node;
    temp->data=entry;
    temp-> next= Forward;
    return temp;
}

///tells if a value is present in the list
bool List::present(item target)
{
    node *p;
    p=first;

return presentr(target, p);
}

///tells what value is at kth position
int List::Kth(int entry, int i)
{
    node *prev;
    prev=first;

return Kthr(entry,i,prev);
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
    while(choice !=10)
    {
     cout << endl;
    cout << endl;
    cout <<" You are about to modify a Linked List! " << endl;
    cout <<"_____________________________________________________________________________________" << endl;
    cout << endl;
    cout << endl;
    cout << "Menu: " << endl;

    cout <<"1    -- Re-initialize the list to be empty. " << endl;
    cout <<"2 v  -- Insert the value v into the list. " << endl;
    cout <<"3 v  -- Remove the value v from the list. " << endl;
    cout <<"4    -- Is the list empty? " << endl;
    cout <<"5    -- Report the length of the list. " << endl;
    cout <<"6 v  -- Is the value v present in the list? " << endl;
    cout <<"7 k1 -- Report the k'1th value in the list. " << endl;
    cout <<"8    -- Write out the list. " << endl;
    cout <<"9    -- See this menu. " << endl;
    cout <<"10   -- Quit. "  << endl;

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
            if (entry==0)
                cout<< "The list is empty."<< endl;
            else
                cout<< "The list is not empty."<< endl;

            break;

        case 5:
            entry= l.length(i);
            cout<< "The list is "<< entry<< " numbers long."<< endl;
            break;

        case 6:
            cout<< "What is the value you want to check for?"<< endl;
            cin>> entry;
            ans=l.present(entry);
            if (ans==1)
                cout<< entry<< " is present in the list."<< endl;
            else
                cout<< entry<< " is not present in the list."<< endl;
            break;

        case 7:
            cout<< "What position do you want to know?"<< endl;
            cin>> entry;
            entry--;
            ansI= l.Kth(entry,i);
            entry++;
            cout<< "the value of the "<< entry<< " position is: "<< ansI <<endl;
            break;

        case 8:
            entry= l.length(i);
            for(int j=0; j < entry; j++)
            {
                ansI= l.Kth(j,i);
                cout<< ansI<< " ";
            }
            cout<< endl;
            break;

        case 9:
            break;

        case 10:
            break;

        default:
        cout << "Not a Valid Choice. \n"
        << "Choose again.\n";
        break;
    }
    }

return 0;

}



