#include <iostream>
using namespace std;

int start_index = -1;
int last_index = -1;
int stack_size = 20;

void display(int arr[])
{
    cout << "[";
    for (int i = start_index; i <= last_index; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << "]" << endl;
}

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

void stack_push(int arr[], int val)
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
    int temp = arr[last_index];
    last_index--;
    for (int i = start_index, j = 0; i <= last_index; i++, j++) // Inserting all back to same stack
    {
        arr[i] = arr2[j];
    }
    return temp;
}
int stack_pop(int arr[])
{
    // We need to pop all elements from given arr used as queue to new queue
    int arr2[last_index - start_index] = {};
    int start = start_index;
    int end = last_index;
    for (int i = start, j = last_index; i < end; i++, j--) // Inserting all values except last in new stack
    {
        cout << "Choti bachi \n";
        arr2[j] = queue_pop(arr);
    }
    start_index = ++start;
    last_index = end;
    *arr = *arr2;
}

int main()
{
    int arr[stack_size] = {};
    stack_push(arr, 2);
    stack_push(arr, 9);
    stack_push(arr, 62);
    stack_push(arr, 11);
    stack_push(arr, 3);
    stack_push(arr, 4);
    display(arr);
    stack_pop(arr);
    display(arr);
    return 0;
}
