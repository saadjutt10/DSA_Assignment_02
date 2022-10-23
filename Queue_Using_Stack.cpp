#include <iostream>
using namespace std;

class Node
{
public:
    char val;
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

int start_index = -1;
int last_index = -1;
int stack_size = 20;

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

    // Insert at end in doubly
    void push_end(char valu)
    {
        Node *newp = new Node;
        newp->val = valu;
        // cout<<newp->val <<endl;
        if (first == NULL)
        {
            first = last = newp;
            start_index = last_index = 0;
        }
        else
        {
            last->next = newp;
            last = newp;
            last_index += 1;
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
            start_index = last_index = 0;
        }
        else
        {
            newp->next = first;
            first = newp;
            last_index += 1;
        }
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
        last_index -= 1;
        return temp;
    }
    // TO pop the first node
    char pop_start()
    {
        Node *curr = first;
        Node *temp = first->next;
        curr->next = NULL;
        first = temp;
        start_index += 1;
        return curr->val;
    }

    void shift_right()
    {
        if (last_index == stack_size - 1)
        {
            cout << "The last index is already occupied \n";
            return;
        }
        else
        {
            start_index += 1;
            last_index += 1;
        }
    }
};

void queue_push(List l)
{
    l.shift_right();
    l.push_start('d');
}
void queue_pop(List l)
{
    l.pop();
    last_index -= 1;
}

// Arrays
void shift_right(int arr[])
{
    if (last_index == -1)
    {
        cout << "Stack is empty \n";
        start_index += 2; // Since we're subtrating 1 after function call in queue_push
        last_index += 1;
        return;
    }
    else if (last_index == stack_size - 1)
    {
        cout << "Last index is occupied  \n";
        return;
    }
    else if (last_index < stack_size - 1)
    {
        for (int i = last_index; i >= start_index; i--)
        {
            cout << "Here \n";
            arr[i + 1] = arr[i];
        }
        cout << "Out \n";
    }
    start_index += 1;
    last_index += 1;
}

void shift_left(int arr[])
{
    if (start_index == -1)
    {
        cout << "Stack is empty \n";
        return;
    }
    else if (start_index == 0)
    {
        cout << "First index is occupied  \n";
        return;
    }
    else if (start_index > 0)
    {
        for (int i = start_index; i <= last_index; i++)
        {
            arr[i] = arr[i + 1];
        }
    }
    start_index -= 1;
    last_index -= 1;
}

void queue_push(int arr[], int val)
{
    shift_right(arr);
    arr[--start_index] = val;
}

int queue_pop(int arr[])
{
    // We need to pop all elements from given arr used as stack push back except last one
    int arr2[last_index - start_index] = {};
    for (int i = start_index, j = 0; i < last_index; i++, j++) // Inserting all values except last in new stack
    {
        arr2[j] = arr[i];
    }
    int temp= arr[last_index];
    last_index--;
    for (int i = start_index, j = 0; i <= last_index; i++, j++) // Inserting all back to same stack
    {
        arr[i] = arr2[j];
    }
    return temp;
}

void display(int arr[])
{
    cout << "[";
    for (int i = start_index; i <= last_index; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << "]" << endl;
}

int main()
{
    int arr[stack_size] = {};
    queue_push(arr, 9);
    queue_push(arr, 19);
    queue_push(arr, 91);
    queue_push(arr, 21);
    queue_push(arr, 1);
    display(arr);
    queue_pop(arr);
    display(arr);

    return 0;
}
