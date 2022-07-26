#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;


class TreeNode
{
    public:
        char data;
        TreeNode *left, *right;

        TreeNode(char data)
        {
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};


class StackNode
{
    public:
        TreeNode *treeNode;
        StackNode *next;

        StackNode(TreeNode *treeNode)
        {
            this->treeNode = treeNode;
            next = NULL;
        }
};


class ExpressionTree
{
    private:
        StackNode *top;
    public:

        ExpressionTree()
        {
            top = NULL;
        }


        void clear()
        {
            top = NULL;
        }


        void push(TreeNode *ptr)
        {
            if (top == NULL)
                top = new StackNode(ptr);
            else
            {
                StackNode *nptr = new StackNode(ptr);
                nptr->next = top;
                top = nptr;
            }
        }


        TreeNode *pop()
        {
            if (top == NULL)
            {
                cout<<"Underflow"<<endl;
            }
            else
            {
                TreeNode *ptr = top->treeNode;
                top = top->next;
                return ptr;
            }
        }


        TreeNode *peek()
        {
            return top->treeNode;
        }



        void insert(char val)
        {
            if (isDigit(val))
            {
                TreeNode *nptr = new TreeNode(val);
                push(nptr);
            }
            else if (isOperator(val))
            {
                TreeNode *nptr = new TreeNode(val);
                nptr->left = pop();
                nptr->right = pop();
                push(nptr);
            }
            else
            {
                cout<<"Invalid Expression"<<endl;
                return;
            }
        }


        bool isDigit(char ch)
        {
            return ch >= '0' && ch <= '9';
        }


        bool isOperator(char ch)
        {
            return ch == '+' || ch == '-' || ch == '*' || ch == '/';
        }



        int toDigit(char ch)
        {
            return ch - '0';
        }



        void buildTree(string eqn)
        {
            for (int i = eqn.length() - 1; i >= 0; i--)
                insert(eqn[i]);
        }


        double evaluate()
        {
            return evaluate(peek());
        }


        double evaluate(TreeNode *ptr)
        {
            if (ptr->left == NULL && ptr->right == NULL)
                return toDigit(ptr->data);
            else
            {
                double result = 0.0;
                double left = evaluate(ptr->left);
                double right = evaluate(ptr->right);
                char op = ptr->data;
                switch (op)
                {
                case '+':
                    result = left + right;
                    break;
                case '-':
                    result = left - right;
                    break;
                case '*':
                    result = left * right;
                    break;
                case '/':
                    result = left / right;
                    break;
                default:
                    result = left + right;
                    break;
                }
                return result;
            }
        }


        void postfix()
        {
            postOrder(peek());
        }


        void postOrder(TreeNode *ptr)
        {
            if (ptr != NULL)
            {
                postOrder(ptr->left);
                postOrder(ptr->right);
                cout<<ptr->data;
            }
        }


        void infix()
        {
            inOrder(peek());
        }


        void inOrder(TreeNode *ptr)
        {
            if (ptr != NULL)
            {
                inOrder(ptr->left);
                cout<<ptr->data;
                inOrder(ptr->right);
            }
        }


        void prefix()
        {
            preOrder(peek());
        }


        void preOrder(TreeNode *ptr)
        {
            if (ptr != NULL)
            {
                cout<<ptr->data;
                preOrder(ptr->left);
                preOrder(ptr->right);
            }
        }
};


int main()
{
    int arrSize = 0;
    char arr[10000];
    ExpressionTree et;
    bool valuer=true;
    string fileName;
    cout << "Please input the file you would like to modify: " << endl;
    cin >> fileName;
    cin.ignore();
    ifstream myfile(fileName.c_str());
	if (myfile.is_open())
	{



		while (valuer == true)
		{
			int x;
			myfile >> x;

			if (x == NULL)
				valuer = false;
            else
            {
                cout << "." << endl;
                arr[arrSize++] = x;
            }

		}

		for (int i = 0; i < arrSize; ++i)
			cout << arr[i] << " .";
            cout << endl;
	}

	else
	{
		cout << "Unable to open file";
	}

	for(int i = 0; i < arrSize; i++)
    {
        et.insert(arr[i]);
    }



    cout<<"\nPrefix  : ";
    et.prefix();
    cout<<"\n\nInfix   : ";
    et.infix();
    cout<<"\n\nPostfix : ";
    et.postfix();
    cout<<"\n\nEvaluated Result : "<<et.evaluate();
    return 0;
}





