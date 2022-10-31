#include <iostream>
using namespace std;
#include <string>

class Node
{
public:
    char val;
    int calc;
    Node *next;
    Node()
    {
        val = NULL;
    }
    Node(char c)
    {
        this->val = c;
    }
};
Node *first = NULL;
Node *last = NULL;

class List
{
private:
    Node *head = NULL;

public:
    List()
    {
        head = NULL;
    }
    void display()
    {
        Node *temp = new Node;
        temp = first;
        if (first == NULL)
        {
            cout << "List is empty \n";
            return;
        }
        while (temp != NULL)
        {
            cout << temp->val << "<->";
            temp = temp->next;
        }
        cout << "\n";
    }

    void display_int()
    {
        Node *temp = new Node;
        temp = first;
        if (first == NULL)
        {
            cout << "List is empty \n";
            return;
        }
        while (temp != NULL)
        {
            cout << temp->calc << "<->";
            temp = temp->next;
        }
        cout << "\n";
    }

    // Insert at end in doubly
    void push_end(char valu)
    {
        Node *newp = new Node;
        newp->val = valu;
        // cout<<newp->val <<endl;
        if (first == NULL)
        {
            first = last = newp;
        }
        else
        {
            last->next = newp;
            last = newp;
        }
        last->next = NULL;
    }
    // Push at start
    void push_start(char valu)
    {
        Node *newp = new Node;
        newp->val = valu;
        // cout<<newp->val <<endl;
        if (first == NULL)
        {
            first = last = newp;
        }
        else
        {
            newp->next = first;
            first = newp;
        }
    }

    // Ovveide Methode
    void push_endi(int valu)
    {
        Node *newp = new Node;
        newp->calc = valu;
        // cout<<newp->val <<endl;
        if (first == NULL)
        {
            // cout<<"First ha boss \n";
            first = last = newp;
        }
        else
        {
            last->next = newp;
            last = newp;
        }
        last->next = NULL;
    }

    // TO pop the last node
    char pop()
    {
        Node *curr = first;
        Node *tem = first;
        while (curr->next != NULL)
        {
            tem = curr;
            curr = curr->next;
        }
        char temp = curr->val;
        tem->next = NULL;
        if (curr == first)
        {
            first = NULL;
        }
        return temp;
    }
        // TO pop the first node
    char pop_start()
    {
        Node *curr = first;
        Node *temp = first->next;
        curr->next=NULL;
        first=temp;
        return curr->val;
    }
    // Ovveride
    int pop_int()
    {
        Node *curr = first;
        Node *tem = first;
        while (curr->next != NULL)
        {
            tem = curr;
            curr = curr->next;
        }
        int temp = curr->calc;
        tem->next = NULL;
        last=tem;
        if (curr == first)
        {
            first = NULL;
        }
        return temp;
    }
};

bool single_baraces(string str)
{
    int len = size(str);
    List li;
    int count = 1;
    for (int i = 0; i < len; i++)
    {
        if (str.at(i) == '(') // TO add in the list
        {
            cout << "Adding \n";
            li.push_end(str.at(i));
        }
        else if (str.at(i) == ')') // TO remove from the list
        {
            if (str.at(i - count) == '(')
            {
                cout << "Removing \n";
                li.pop();
                count += 1;
            }
            else
            {
                cout << "Retirng false \n";
                return false;
            }
        }
    }
    cout << "List created \n";
    if (first == NULL)
    {
        return true;
    }
    return false;
}

bool multiple_baraces(string str)
{
    int len = size(str);
    List li;
    int count = 1;
    for (int i = 0; i < len; i++)
    {
        if (str.at(i) == '(' || str.at(i) == '{' || str.at(i) == '[') // TO add in the list
        {
            cout << "Adding \n";
            li.push_end(str.at(i));
        }
        else
        {
            switch (str.at(i))
            {
            case ')':
            {
                if (str.at(i - count) == '(')
                {
                    cout << "Removing \n";
                    li.pop();
                    // str.erase(i-1,2); //erasing elements staring from i-1  and 2 elements
                    // cout<<(str);
                    // exit(0);
                    count += 2;
                }
                else
                {
                    cout << "Retirng false ) \n";
                    return false;
                }
            }
            break;
            case ']': // Case 2
            {
                if (str.at(i - count) == '[')
                {
                    cout << "Removing \n";
                    li.pop();
                    count += 2;
                }
                else
                {
                    cout << "Retirng false ] \n";
                    return false;
                }
            }
            break;
            case '}': // Case 3
            {
                if (str.at(i - count) == '{')
                {
                    cout << "Removing \n";
                    li.pop();
                    count += 2;
                }
                else
                {
                    cout << "Retirng false { \n";
                    return false;
                }
            }
            break;

            default:
                break;
            }
        }
    }
    cout << "List created \n";
    if (first == NULL)
    {
        return true;
    }
    return false;
}

bool stack_empty()
{
    return first == NULL;
}

string priority_check(char str, string output)
{
    List li;

    switch (str)
    {
    case '+':
    {
        if (!stack_empty())
        {
            cout << "Stack not empty \n";
            while (!stack_empty())
            {
                cout << "In While \n";
                char temp = li.pop();
                cout << temp << endl;
                output.push_back(temp);
            }
            li.push_end(str);
        }
        else
        {
            cout << "Stack is empty bro " << str << "\n";
            li.push_end(str);
        }
    }
    break;
    case '-':
    {
        if (!stack_empty())
        {
            while (!stack_empty())
            {
                char temp = li.pop();
                output.push_back(temp);
            }
            li.push_end(str);
        }
        else
        {
            li.push_end(str);
        }
    }
    break;
    case '*':
    {

        if (!stack_empty())
        {
            char temp1 = li.pop();
            if (temp1 == '+' || temp1 == '-')
            {
                cout << "Condition true \n";
                li.push_end(temp1);
                li.push_end(str);
            }
            else
            {
                li.push_end(temp1);
                while (!stack_empty())
                {
                    char temp = li.pop();
                    output.push_back(temp);
                }
                li.push_end(str);
            }
        }
        else
        {
            li.push_end(str);
        }
    }
    break;
    case '/':
    {

        if (!stack_empty())
        {
            char temp1 = li.pop();
            if (temp1 == '+' || temp1 == '-')
            {
                cout << "Condition true \n";
                li.push_end(temp1);
                li.push_end(str);
            }
            else
            {
                li.push_end(temp1);
                while (!stack_empty())
                {
                    char temp = li.pop();
                    output.push_back(temp);
                }
                li.push_end(str);
            }
        }
        else
        {
            li.push_end(str);
        }
    }
    break;

    default:
        break;
    }

    return output;
}
string infix_to_postfix(string str)
{
    string output = "";
    List li;
    int pririority_check = 0;
    int paran_count = 0;
    for (int i = 0; i < size(str); i++)
    {
        if (str.at(i) == '+' || str.at(i) == '-' || str.at(i) == '*' || str.at(i) == '/' || str.at(i) == '(' || str.at(i) == ')')
        {
            if (str.at(i) == '(')
            {
                paran_count = 1;
            }
            else if (str.at(i) == ')')
            {
                paran_count = 0;
                while (!stack_empty())
                {
                    char temp = li.pop();
                    output.push_back(temp);
                }
            }
            if (str.at(i) == '+')
            {
                if (paran_count == 1)
                {
                    li.push_end(str.at(i));
                }
                else
                {
                    output = priority_check(str.at(i), output);
                }
            }
            else if (str.at(i) == '/')
            {
                if (paran_count == 1)
                {
                    li.push_end(str.at(i));
                }
                else
                {
                    output = priority_check(str.at(i), output);
                }
            }
            else if (str.at(i) == '*')
            {
                if (paran_count == 1)
                {
                    li.push_end(str.at(i));
                }
                else
                {
                    output = priority_check(str.at(i), output);
                }
            }
        }
        else
        {
            // cout << "Appending non-operator \n";
            output.push_back(str.at(i));
        }
    }
    cout << "End of string \n";
    li.display();
    while (!stack_empty()) // Removing all elements from stack at the end of string
    {
        char temp = li.pop();
        cout << temp << endl;
        output.push_back(temp);
    }
    return output;
}




int main()
{
    // cout << infix_to_postfix("( (A * B) + (C / D) )");
    // cout << multiple_baraces("[{(])}");
    //  string str="abcdefgh";
    //  str.erase(1,2);
    //  cout<<str;
    return 0;
}