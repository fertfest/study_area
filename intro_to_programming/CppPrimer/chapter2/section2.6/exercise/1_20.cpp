#include "Sales_data.h"
#include <vector>
#include <iostream>

int main()
{
    using namespace std;
    vector<Sales_data> transactions;
    string bookNo;
    unsigned number_sold;
    double revenue;

    while (cin >> bookNo && cin >> number_sold && cin >> revenue)
    {
        Sales_data new_item;
        new_item.bookNo = bookNo;
        new_item.number_sold = number_sold;
        new_item.revenue = revenue;
        transactions.push_back(new_item);
    }

    for (Sales_data transaction : transactions)
    {
        cout << transaction.bookNo << " " << transaction.number_sold << " " << transaction.revenue << endl;
    }
    return 0;
}