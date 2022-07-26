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
    typedef double Item;
    //constructors
    List(){first = NULL;}
///   List(List source);

    //destructor
    ~List();

    //modification member functions
    void make_empty();
    void Insert(Item entry, int entry2);
    void Remove(Item target);
    void operator=(List source);

    //constent member functions
    bool empty(){return first == NULL;}
    double length();
    bool present(Item target);
    double Kth(double chosen);
    void multiply(Item entry);
    int degree();
    void derivative();
    void print();

    //friend function
    friend std::ostream& operator << (std::ostream & out_s, List&);

private:
    struct node
    {
        Item data;
        int data2;
        node *next;

    };
    node *first;
    node *get_node(Item entry, int entry2, node *link);


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


void List::Insert(Item entry, int entry2)
{
    node *prev;
    if(first == NULL || entry2 < first->data2)
        first = get_node(entry, entry2, first);
    else
    {
        prev = first;
        while(prev->next != NULL && prev->next->data < entry)
            prev = prev->next;

        prev->next = get_node(entry, entry2, prev->next);
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

double List::length()
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

List::node* List::get_node(Item entry, int entry2, node *Forward)
{
   node *temp;
   temp = new node;
   temp->data = entry;
   temp-> data2 = entry2;
   temp->next = Forward;

   return temp;
}

double List::Kth(double entry)
{
    node *p = first;
    double temporary;
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

void List::multiply(Item entry)
{
   node *p = first;
    int i = 0;
    while(p != NULL)
    {
        ++i;
        p-> data *=entry;
        p = p->next;
    }
}

int List::degree()
{
 node *p = first;
 int i = 0;
    while(p != NULL)
    {
        ++i;
        p = p->next;
    }
    node *q = first;
    int j = 1;
    while(j < i)
    {
        q = q->next;
        j++;
    }
    return q->data2;
}

void List::derivative()
{
     node *p = first;
     node *q = first;
    int i = 0; cout << "Please enter a number, 1 through 10 to enter the function to modify the linked list." << endl;
    while(p != NULL)
    {
        ++i;
        p->data *= p->data2;
        p->data2 -= 1;
        cout << p->data << "*x^" << p->data2 << "+ ";
        p = p->next;
    }
    cout << endl;

    while(q != NULL)
    {
        q->data2 += 1;
        q->data /= q->data2;
        q = q->next;
    }
}

void List::print()
{
     node *p = first;
    int i = 0; cout << "Please enter a number, 1 through 10 to enter the function to modify the linked list." << endl;
    while(p != NULL)
    {
        ++i;
        cout << p->data << "*x^" << p->data2 << "+ ";
        p = p->next;
    }
    cout << endl;
}

///
///Main
///
int main()
{
    int choice;
    int counter;
    double entry;
    int entry2;
    bool ans;
    int ansI;
    List l;
while(choice != 8)
    {
    cout << endl;
    cout << endl;
    cout <<" You are about to modify a Linked List! " << endl;
    cout <<"_____________________________________________________________________________________" << endl;
    cout << endl;
    cout << endl;
    cout << "Menu: " << endl;

    cout <<"1 v n -- Insert the term v*x^n into the polynomial." << endl;
    cout <<"2     -- Reinitialize the polynomial to 0. " << endl;
    cout <<"3     -- Report the degree of the polynomial." << endl;
    cout <<"4 v   -- Multiply the polynomial by v." << endl;
    cout <<"5     -- Report the derivative of the polynomial. " << endl;
    cout <<"6     -- Write out the polynomial." << endl;
    cout <<"7     -- See this menu. " << endl;
    cout <<"8    -- Quit. "  << endl;

    cout << "Please enter a number, 1 through 8 to enter the function to modify the linked list." << endl;
    cin >> choice;

        switch(choice)
        {
            case 1:
                {
                    cout<< "Inset value 'v' in v*x^n" << endl;
                    cin >> entry;
                    cout << "Insert value 'n' in v*x^n" << endl;
                    cin >> entry2;
                    l.Insert(entry, entry2);
                    ++counter;
                    break;

                }

            case 2:
                {
                    l.make_empty();
                    break;
                }


            case 3:
                {
                    entry2=l.degree();
                    cout << "The degree of the Polynomial is: " << entry2 << endl;
                    break;
                }

            case 4:
                {
                    cout << "Enter the Number you would like to multiply the Polynomial By: " << endl;
                    cin >> entry2;
                    l.multiply(entry2);
                    break;
                }

            case 5:
                {
                    l.derivative();
                    break;
                }



            case 6:
                {
                    l.print();
                    break;
                }

            case 7:
                {
                    cout <<"1 v n -- Insert the term v*x^n into the polynomial." << endl;
                    cout <<"2     -- Reinitialize the polynomial to 0. " << endl;
                    cout <<"3     -- Report the degree of the polynomial." << endl;
                    cout <<"4 v   -- Multiply the polynomial by v." << endl;
                    cout <<"5     -- Report the derivative of the polynomial. " << endl;
                    cout <<"6     -- Write out the polynomial." << endl;
                    cout <<"7     -- See this menu. " << endl;
                    cout <<"8    -- Quit. "  << endl;
                    break;
                }

            case 8:
                {
                    break;
                }
            default:
                {
                    cout << "Invalid Answer, choose again" << endl;
                }
        }

    }


}
