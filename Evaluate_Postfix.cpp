#include <iostream>
using namespace std;
#include <string>

int start_index = -1;
int last_index = -1;

int arr_pop(int arr[])
{
    return arr[last_index--];
}

void arr_push(int arr[], int val)
{
    if(start_index==-1){
        start_index=0;
    }
    last_index++;
    cout<<"Last index is :"<< last_index << endl;
    arr[last_index] = val;
}

void display(int arr[])
{
    cout<<" Start Index is " << start_index <<" And Last index is "<< last_index << endl;
    cout << "[";
    for (int i = start_index; i <= last_index; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << "]" << endl;
}

int evaluate_postfix_arr(string val)
{
    int arr[] = {};
    int sum = 0;
    for (int i = 0; i < val.length() ; i++)
    {
        if (isdigit(val.at(i)))
        {
            int temp = val.at(i) - '0';
            cout<<"Pusihng " << temp <<endl;
            arr_push(arr, temp);
            display(arr);
        }

        else
        {
            cout << val.at(i) << " Spotted \n";
            int temp1 = arr_pop(arr);
            cout << temp1 << endl;
            int temp2 = arr_pop(arr);
            cout << temp2 << endl;
            // li2.display();
            switch (val.at(i))
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
            int temp = sum;
            cout << "Sum is :" << temp << endl;
            arr_push(arr, temp);
            display(arr);
        }
    }
    return sum;
}

int main()
{
    string a="57+67+*";
    cout<< a.length();
   // cout << evaluate_postfix_arr("57+67+*");
    return 0;
}