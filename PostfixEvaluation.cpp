#include <iostream>
using namespace std;
#include <string>

class Node
{
public:
    char val;
    Node *next;

    Node()
    {
        val = NULL;
    }
    Node(char c, Node *next)
    {
        this->next = next;
        this->val = c;
    }
};

class List
{
private:
    Node *head = NULL;
    Node *tail = NULL;

public:
    List()
    {
        head = NULL;
    }
    Node *getHead()
    {
        return head;
    }
    void display() ///////////////////HErerererererere
    {
        Node *temp = new Node;
        temp = head;
        if (head == NULL)
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
    void display_test()
    {
        Node *temp = new Node;
        temp = head;
        if (head == NULL)
        {
            cout << "List is empty \n";
            return;
        }
        while (temp != NULL)
        {
            if (!(temp->val == '+' || temp->val == '-' || temp->val == '*' || temp->val == '/'))
            {
                int temporary = temp->val;
                cout << temporary << "<->";
                temp = temp->next;
            }
            else
            {
                cout << temp->val << "<->";
                temp = temp->next;
            }
        }
        cout << "\n";
    }

    // Insert at end in doubly
    void push_end(char valu)
    {
        Node *newp = new Node;
        newp->val = valu;
         cout<<"Checking here :"<< (int)newp->val <<endl;
        if (head == NULL)
        {
            head = tail = newp;
        }
        else
        {
            tail->next = newp;
            tail = newp;
        }
        tail->next = NULL;
    }
    // Push at start
    void push_start(char valu)
    {
        Node *newp = new Node;
        newp->val = valu;
        // cout<<newp->val <<endl;
        if (head == NULL)
        {
            head = tail = newp;
        }
        else
        {
            newp->next = head;
            head = newp;
        }
    }

    // TO pop the last node
    char pop()
    {
        Node *curr = head;
        Node *tem = head;
        while (curr->next != NULL)
        {
            tem = curr;
            curr = curr->next;
        }
        char temp = curr->val;
        tem->next = NULL;
        tail = tem;
        if (curr == head)
        {
            head = NULL;
        }
        return temp;
    }
    // TO pop the first node
    char pop_start()
    {
        Node *curr = head;
        Node *temp = head->next;
        curr->next = NULL;
        head = temp;
        return curr->val;
    }
};
/*
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
} */
/*
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
    return head == NULL;
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
 */

int evaluate_postfix(Node *head)
{
    List li2;
    int sum = 0;
    // int len=size(val);
    Node *azy = head;
    while (azy != NULL)
    {
        if (azy->val == '+' || azy->val == '-' || azy->val == '*' || azy->val == '/')
        {

            cout << azy->val << " Spotted \n";

            int temp1 = li2.pop();
            int temp2 = li2.pop();
            li2.display_test();
            switch (azy->val)
            {
            case '+':
                sum = temp1 + temp2;
                break;
            case '-':
                sum = temp1 - temp2;
                break;
            case '*':
                sum = temp1 * temp2;
                break;
            case '/':
                sum = temp1 / temp2;
                break;

            default:
                break;
            }
            char temp_sum=sum ;
            cout<<"Pushing the result "<< sum << endl;
            li2.push_end(sum);
            li2.display_test();
        }
        else
        {
            cout << "Pushing " << ((int)azy->val ) << endl;
            li2.push_end(azy->val); // Pushing char equavalent of int
            li2.display_test();
        }
        azy = azy->next;
    }
    return sum;
}

int main()
{
    // cout << infix_to_postfix("12*24+5*10");
    // cout << multiple_baraces("[{(])}");
    string arr[] = {"12", "24", "*", "510", "*", "+"};
    List li;
    li.push_end(288);
    li.push_end(24);
    li.push_end('*');
    li.push_end(5);
    li.push_end(10);
    li.push_end('*');
    li.push_end('+');
    li.display_test();
    cout << evaluate_postfix(li.getHead());
    // cout << evaluate_postfix("1224");

    //  string str="abcdefgh";
    //  str.erase(1,2);
    //  cout<<str;
    return 0;
}