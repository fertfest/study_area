#include "Sales_data.h"
#include <fstream>

int main(int argc, char const *argv[])
{
    std::ifstream ifs("../../../transactions_input_file");
    Sales_data sum;
    Sales_data temp;
    int count = 0;
    while (read(ifs, temp))
    {
        if (sum.isbn().size() == 0)
        {
            count++;
            sum = temp;
        }
        else if (temp.isbn() == sum.isbn())
        {
            count++;
            sum.combine(temp);
        }
        else
        {
            print(std::cout, sum) << " " << count << std::endl;
            count = 1;
            sum = temp;
        }
    }

    print(std::cout, sum) << " " << count << std::endl;
    return 0;
}
