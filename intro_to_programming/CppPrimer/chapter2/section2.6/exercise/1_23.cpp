#include "Sales_data.h"

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
    int count = 0;

    while (cin >> bookNo && cin >> number_sold && cin >> revenue)
    {
        if (sum.bookNo.size() != 0 && bookNo != sum.bookNo)
        {
            cout << endl
                 << "Count: " << count << endl;
            cout << sum.bookNo << " " << sum.number_sold << " " << sum.revenue << endl;
            count = 0;
            sum.bookNo = "";
            sum.number_sold = 0;
            sum.revenue = 0.0;
        }
        sum.bookNo = bookNo;
        sum.number_sold += number_sold;
        sum.revenue += revenue;
        count++;
    }

    cout << endl
         << "Count: " << count << endl;
    cout << sum.bookNo << " " << sum.number_sold << " " << sum.revenue << endl;

    vector<int> result;
    return 0;
}