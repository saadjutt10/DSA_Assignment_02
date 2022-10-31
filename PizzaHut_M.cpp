#include <iostream>
using namespace std;

int arr_size = 5;
int front = -1;
int rear = -1;

struct person
{
    string name;
    int age;
    string order;
};

bool isFull()
{
    if ((rear + 1) % arr_size == front)
    {
        return true;
    }
    return false;
}

void age_Priority_Order(person str[], string order, int age)
{
    if (isFull())
    {
        cout << "Queue is Full \n";
        return;
    }
    else if (front == -1)
    {
        cout << "It was Empty \n";
        str[++front % arr_size].order = order;
        str[++rear % arr_size].age = age;
        return;
    }

    for (int i = front; i != rear; i = ++i % arr_size)
    {
        if (str[i].age > age)
        {
            if (i == 0)
            {
                str[rear + 1] = str[i];
            }
            else
            {
                str[i - 1] = str[i];
            }
        }
        else
        {
            if (i == 0)
            {
                cout << "Here \n";
                front = rear + 1;
                str[front].age = age;
                str[front].order = order;
                break;
            }
            else
            {
                cout << "Triggered \n";
                str[i - 1].age = age;
                str[i - 1].order = order;
                front--;
                break;
            }
        }

        // front--;
    }

    cout << "========== \n";
    cout << front << endl;
    cout << "New Order Placed \n";
    cout << rear << endl;
    cout << "========== \n";
}

void new_order(person str[], string order)
{
    if (isFull())
    {
        cout << "Queue is Full \n";
    }
    else if (front == -1)
    {
        rear = (rear + 1) % arr_size;
        str[rear].order = order;
        str[rear].age = 0;
        cout << rear << endl;
        front = (front + 1) % arr_size;
    }
    else
    {

        rear = (rear + 1) % arr_size;
        str[rear].order = order;
        str[rear].age = 0;
    }
}

void new_order_end(person str[], string order)
{
    if (isFull())
    {
        cout << "Queue is Full \n";
    }
    else if (front == -1)
    {
        rear = (rear + 1) % arr_size;
        str[rear].order = order;
        str[rear].age = 0;
        cout << rear << endl;
        front = (front + 1) % arr_size;
    }
    else
    {
        if (front == 0)
        {
            front = rear + 1;
        }
        else
        {
            front = (front - 1) % arr_size;
        }
        str[front].order = order;
        str[front].age = 10;
    }
}
void remove(person str[])
{
    front = (front + 1) % arr_size;
    cout << "Onc Order Delivered" << endl;
    cout << "========== \n";
}
void remove_end(person str[])
{
    if (rear == 0)
    {
        rear = arr_size - 1;
        return;
    }
    rear = (rear - 1) % arr_size;
    cout << "Remoed from rear end" << endl;
    cout << "========== \n";
}
/*
void two_servings(person str[], string order)
{
    int choice;
    cout << "Enter 1 for rear end and 2 for front endd \n";
    cin >> choice;
    if (choice == 2)
    {

        person *temp = new person;
        temp->order = order;
        temp->age = 0;
        for (int i = total_orders - 1; i >= 0; i--)
        {
            str[i + 1] = str[i];
        }
        total_orders++;
        str[0] = *temp;
    }
    else if (choice == 1)
    {
        new_order(str, order);
    }
    else
    {
        cout << "Invalid input \n";
    }
}
 */
void display(person str[])
{
    if (rear < 0)
    {
        cout << "No order yet \n";
        return;
    }
    int i;
    for (i = front; i != rear; i = ++i % arr_size)
    {
        cout << "Order :" << str[i].order << " age :" << str[i].age << endl;
    }
    cout << "Order :" << str[i].order << " age :" << str[i].age << endl;

    cout << "===============" << endl;
}

int main()
{
    // cout << "Test \n";
    // total_orders = 0;
    person pizza[arr_size];
    for (int i = 0; i < arr_size; i++)
    {
        pizza[i] = *new person;
    }
    display(pizza);
    new_order(pizza, "Fajita");
    new_order(pizza, "Cheese");
    new_order(pizza, "BBQ");
    new_order(pizza, "Tikka");
    // new_order(pizza, "Tikka");
    // new_order(pizza, "BBQ");
    display(pizza);
    remove(pizza);
    display(pizza);
    //  two_servings(pizza, "Pepperoni");
    // new_order(pizza, "Tikka");
    age_Priority_Order(pizza, "Saedi", 19); /////Idr
    display(pizza);
    remove(pizza);
    display(pizza);
    // age_Priority_Order(pizza, "Tikka", 9);
    // new_order(pizza, "BBQ");
    // new_order(pizza, "Tikka");
    age_Priority_Order(pizza, "Huzaifa", 9);
    age_Priority_Order(pizza, "Fajita", 129);
    display(pizza);
    remove_end(pizza);
    display(pizza);
    new_order_end(pizza, "Tikka");
    display(pizza);
    return 0;
}