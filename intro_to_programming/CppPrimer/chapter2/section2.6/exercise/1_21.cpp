#include "Sales_data.h"
#include <vector>
#include <iostream>

int main()
{
    using namespace std;
    Sales_data sum;
    sum.bookNo = "";
    sum.number_sold = 0;
    sum.revenue = 0.0;
    string bookNo;
    unsigned number_sold;
    double revenue;

    while (cin >> bookNo && cin >> number_sold && cin >> revenue)
    {
        if (sum.bookNo.size() != 0 && bookNo != sum.bookNo)
        {
            cout << endl
                 << "Got different ISBN, finish input!" << endl;
            break;
        }
        sum.bookNo = bookNo;
        sum.number_sold += number_sold;
        sum.revenue += revenue;
    }

    cout << sum.bookNo << " " << sum.number_sold << " " << sum.revenue << endl;
    return 0;
}