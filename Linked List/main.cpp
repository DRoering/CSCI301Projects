#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

///
///Header File
///
class List
{
public:
    typedef int Item;

    //constructors
    List(){first = NULL;}
///   List(List source);

    //destructor
    ~List();

    //modification member functions
    void make_empty();
    void Insert(Item entry);
    void Remove(Item target);
    void operator=(List source);

    //constent member functions
    bool empty(){return first == NULL;}
    int length();
    bool present(Item target);
    int Kth(int chosen);

    //friend function
    friend std::ostream& operator << (std::ostream & out_s, List&);

private:
    struct node
    {
        Item data;
        node *next;

    };
    node *first;
    node *get_node(Item entry, node *link);


};


///
///Function Deffinitions
///
///void List::List(List source)
///{
///  node *p;
///  node *last;
///  if(source.first == NULL)
///        first = NULL;
///  else
///        first->data;
///
///  first = get_node(source.first->data,NULL);
///  last = first;
///  p = source.first->next;
///  while(p != Null)
///  {
///      p = next->data;
///      cout << *p << endl;
///  }
///}

List::~List()
{
    node *temp;
    while(first != NULL)
    {
        temp = first;
        first = first->next;
        double temp;
    }
}

void List::make_empty()
{
    node *temp;
    while(first != NULL)
    {
        temp = first;
        first=first->next;
        delete temp;
    }
}


void List::Insert(Item entry)
{
    node *prev;
    if(first == NULL || entry < first->data)
        first = get_node(entry, first);
    else
    {
        prev = first;
        while(prev->next != NULL && prev->next->data < entry)
            prev = prev->next;

        prev->next = get_node(entry, prev->next);
    }
}

void List::Remove(Item target)
{
    node *prev;
    node *temp;
    prev = first;
    if(first->data == target)
    {
        first = first->next;
        delete prev;
    }
    else
    {
        while(prev->next->data != target)
            prev = prev->next;

        temp = prev->next;
        prev->next = temp->next;
        delete temp;
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

bool List::present(Item target)
{
    node *p;
    p = first;
    while(p != NULL && p->data != target)
        p = p->next;
    return p != NULL;
}

int List::length()
{
    node *p = first;
    int i = 0; cout << "Please enter a number, 1 through 10 to enter the function to modify the linked list." << endl;
    while(p != NULL)
    {
        ++i;
        p = p->next;
    }
    return i;
}

List::node* List::get_node(Item entry, node *Forward)
{
   node *temp;
   temp = new node;
   temp->data = entry;
   temp->next = Forward;

   return temp;
}

int List::Kth(int entry)
{
    node *p = first;
    int temporary;
    node *prev;
    node *temp;
    prev=first;
    int i=0;
    while(i<entry)
    {
        prev=prev->next;
        i++;
    }
    return (prev->data);
}

///
///Main
///
int main()
{
    int choice;
    int entry;
    bool ans;
    int ansI;
    List l;
while(choice != 10)
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

    cout << "Please enter a number, 1 through 10 to enter the function to modify the linked list." << endl;
    cin >> choice;

        switch(choice)
        {
            case 1:
                {
                    l.make_empty();
                    break;
                }

            case 2:
                {
                    cout<< "What value do you want inserted?"<< endl;
                    cin >>entry;
                    l.Insert(entry);

                    break;
                }

            case 3:
                {
                    cout<< "What value do you want removed?"<< endl;
                    cin >>entry;
                    l.Remove(entry);

                    break;
                }

            case 4:
                {
                    entry= l.length();
                    if (entry==0)
                    cout<< "The list is empty."<< endl;
                        else
                    cout<< "The list is not empty."<< endl;

                    break;
                }

            case 5:
                {
                    entry= l.length();
                    cout<< "The list is "<< entry<< " numbers long."<< endl;

                    break;
                }

            case 6:
                {
                     cout<< "What is the value you want to check for?"<< endl;
                    cin>> entry;
                    ans=l.present(entry);
                    if (ans==1)
                    cout<< entry<< " is present in the list."<< endl;
                    else
                    cout<< entry<< " is not present in the list."<< endl;

                    break;
                }

            case 7:
                {
                   cout<< "What position do you want to know?"<< endl;
                    cin>> entry;
                    ansI= l.Kth(entry);
                    cout<< "the value of the "<< entry<< " position is: "<< ansI <<endl;

                    break;
                }

            case 8:
                {
                    entry= l.length();
                    for(int i=0; i < entry; i++)
                    {
                        ansI= l.Kth(i);
                        cout<< ansI<< " ";
                    }
                    cout<< endl;

                    break;
                }

            case 9:
                {

                    break;
                }

            case 10:
                {
                    break;
                    return 0;
                }
            default:
                {
                    cout << "Invalid Answer, choose again" << endl;
                }
        }

    }


}
