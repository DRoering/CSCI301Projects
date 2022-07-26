#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ostream>
#include <cstring>

using namespace std;

class Stacks
{
public:
    typedef char item;

    //constructor
    Stacks(){top = NULL; depth = 0;}

    //destructor
    //~Stacks();
    //Modification member functions
    void push(item entry);
    item pop();
    //constant member functions
    int Size(){return depth;}
    bool Empty(){return top == NULL;}
    item peak(){return top->data;}

private:
    struct node
    {
        item data;
        node *next;
    };
    node *top;
    int depth;
};

void Stacks::push(item entry)
{
    node *temp;
    temp = new node;
    temp->data = entry;
    temp->next = top;
    top = temp;
    ++depth;
}

Stacks::item Stacks::pop()
{
    node *temp;
    item popped;
    popped = top->data;
    temp = top;
    top = top->next;
    delete temp;
    --depth;
    return popped;
}

class Stacks2
{
public:
    typedef char item;

    //constructor
    Stacks2(){top2 = NULL; depth2 = 0;}

    //destructor
    //~Stacks();
    //Modification member functions
    void push2(item entry);
    item pop2();
    //constant member functions
    int Size2(){return depth2;}
    bool Empty2(){return top2 == NULL;}
    item peak2(){return top2->data2;}

private:
    struct node2
    {
        item data2;
        node2 *next2;
    };
    node2 *top2;
    int depth2;
};

void Stacks2::push2(item entry)
{
    node2 *temp2;
    temp2 = new node2;
    temp2->data2 = entry;
    temp2->next2 = top2;
    top2 = temp2;
    ++depth2;
}

Stacks2::item Stacks2::pop2()
{
    node2 *temp2;
    item popped2;
    popped2 = top2->data2;
    temp2 = top2;
    top2 = top2->next2;
    delete temp2;
    --depth2;
    return popped2;
}


int main()
{
    Stacks s;
    Stacks2 s2;
    char palindrome;
    int counter, counter2;
    char input, input2;
    cout << "Welcome to the Palindrome Verifier!" << endl;
    cout << "Please enter the length of the palindrome: " << endl;
    cin >> counter;
    counter2 = counter;
    cout << "enter the palindrome letter by letter, separated by an Enter: " << endl;
    while(counter > 0)
    {
        cin >> palindrome;
        s.push(palindrome);
        counter--;
    }

        int a = counter2;
        int b = counter2;

    if(counter2 % 2 == 0)
    {
        a = a/2;
        b = a;

        while(a > 0)
        {

            palindrome = s.pop();
            s2.push2(palindrome);
            a--;
        }

        while(b > 0)
        {
            input = s.pop();
            input2 = s2.pop2();

            if(input == input2)
            {
                b--;
            }
            else
            {
                cout << "It is not a Palindrome. " << endl;
                return 0;
            }
        }
        cout << "This IS a Palindrome!" << endl;

    }



    else
    {

         a = a-1;
         a = a/2;
         b = a;

        while(a > 0)
        {

            palindrome = s.pop();
            s2.push2(palindrome);
            a--;
        }
        input = s.pop();

        while(b > 0)
        {
            input = s.pop();
            input2 = s2.pop2();

            if(input == input2)
            {
                b--;
            }
            else
            {
                cout << "It is not a Palindrome. " << endl;
                return 0;
            }
        }
        cout << "This IS a Palindrome!" << endl;

    }

    return 0;
}
