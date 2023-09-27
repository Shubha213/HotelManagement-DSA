/*
    Shubham Kaspate
    20141241
    Using Singly Linked list create hotel bill format
*/
#include <iostream>
#include <cstdio>
#include <string>
#include <windows.h>

using namespace std;
int c = 0;

class database
{
public:
    int quantity, rate;
    string code, product;
    int Amount;
};

class node
{
public:
    database data;
    node *next;
    node(database x)
    {
        this->data = x;
        next = NULL;
    }
};

node *checkIsPresent(string sno, node *head)
{
    // based on serial number
    node *temp = head;
    while (temp)
    {
        if (temp->data.code == sno)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

node *create_data(node *head)
{
    database d;
    cout << "Order details "
         << " : " << endl;

    cout << "Enter the code = ";
    cin >> d.code;

    cout << "Enter the product = ";
    cin >> d.product;

    cout << "Enter the quantity = ";
    cin >> d.quantity;

    cout << "Enter the rate = ";
    cin >> d.rate;

    d.Amount = d.rate * d.quantity;
    cout << endl;
    cout << "Amount is " << d.Amount << endl;
    ;

    node *temp = checkIsPresent(d.code, head);
    if (temp)
    {
        temp->data.quantity += d.quantity;
        temp->data.Amount = temp->data.quantity * temp->data.rate;
    }
    else
    {
        node *curr = new node(d);
        cout << curr->data.Amount;
        if (head == NULL)
            return curr;
        else
        {
            node *temp = head;
            while (temp->next)
            {
                temp = temp->next;
            }
            temp->next = curr;
        }
    }
    return head;
}

void displaying(node *head)
{
    system("cls");
    system("Color A");
    cout << endl;

    int p = 1;

    cout << "Sr_no"
         << "\tCode"
         << "\tProduct"
         << "\t\tQuantity"
         << "  Rate"
         << "\tAmount" << endl;
    node *temp = head;
    int total = 0;
    while (temp != NULL)
    {
        database d = temp->data;
        cout << p << "\t" << d.code << "\t" << d.product << "\t\t" << d.quantity << "\t  " << d.rate << "\t" << d.Amount << endl;
        temp = temp->next;
        p++;
        total += d.Amount;
    }
    cout << "\n\nTOTAL\t\t" << total << endl;
    cout << "\n " << endl;
    if (c == 2)
    {
        system("pause");
        system("cls");
    }
}

node *deleteOrder(node *head)
{
    string code;
    displaying(head);
    cout << endl;
    cout << "Enter product code : ";
    cin >> code;

    node *temp = head;
    if (!temp->next)
    {
        if (temp->data.code == code)
            return NULL;
        else
        {
            return head;
        }
    }
    while (temp->next && temp->next->data.code != code)
    {
        cout << temp->data.code << " ";
        temp = temp->next;
    }
    cout << temp->data.code;
    node *del = temp->next;
    cout << del->data.code << endl;
    temp->next = temp->next->next;
    delete del;
    return head;
}
int main()
{
    node *head = NULL;
    system("cls");
    struct database d[100];
    int p, val2;
    cout << "\n\t\tWELCOME\n"
         << endl;
    while (c != 5)
    {
        system("Color 7");
        cout << "\n1.Make Order" << endl;
        cout << "2.Display Orders" << endl;
        cout << "3.Delete Order" << endl;
        cout << "4.Exit" << endl;
        cout << "Enter the choice:-> ";
        cin >> c;
        switch (c)
        {
        case 1:
            head = create_data(head);
            break;

        case 2:
            displaying(head);
            break;

        case 3:
            head = deleteOrder(head);
            break;

        case 4:
            exit(0);
            break;

        default:
            cout << "Invalid Choice\n";
            break;
        }
    }
}