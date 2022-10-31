#include <iostream>
using namespace std;

class Node
{
public:
    Node *next;
    char c;

    Node()
    {
        c = NULL;
    }
    Node(char c)
    {
        this->c = c;
    }
};

Node* first=NULL;
Node* last=NULL;
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
        temp=first;
        while (temp != NULL)
        {
            cout << temp->c << "<->";
            temp = temp->next;
        }
        cout << "\n";
    }

    // Insert at end in doubly
void insert_end(char valu)
{
    Node *newp = new Node;
    newp->c = valu;
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

// TO pop the last node
char pop()
{
    Node *curr = first;
    Node* tem=first;
    while (curr->next != NULL)
    {   tem=curr;
        curr = curr->next;
    }
    char temp = curr->c;
    tem->next = NULL;
    return temp;
}
};




bool palindrome_check_doubly(string str)
{
    int len = size(str);
    List li;
    for (int i = 0; i < len; i++)
    {
        li.insert_end(str.at(i));
    }
    cout << "List created \n";

    for (int i = 0; i<=len-1; i++ )
    {
        if  (str.at(i) != li.pop() )
        {
            return false;
        }
    }
    return true;
}

bool palindrome_check_singly(string str)
{
    int len = size(str);
    List li;
    for (int i = 0; i < len; i++)
    {
        li.insert_end(str.at(i));
    }
    cout << "List created \n";

    for (int i = 0; i<=len-1; i++ )
    {
        if  (str.at(i) != li.pop() )
        {
            return false;
        }
    }
    return true;
}

bool palindrome_check_array(string str)
{
    char arr[size(str)];
    // cout<<  size(str) << endl ;
    cout << sizeof(arr) / sizeof(arr[0]) << endl;
    int len = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < len; i++)
    {
        arr[i] = str.at(i);
    }
    for (int i = len - 1, j = 0; i >= 0; i--, j++)
    {

        if (arr[i] != str.at(j))
        {
            cout << "Wrong number \n";
            return false;
        }
    }
    return true;
}

int main()
{
    cout << palindrome_check_doubly("bacscab") << endl;

    return 0;
}