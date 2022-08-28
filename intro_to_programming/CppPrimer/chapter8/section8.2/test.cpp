#include "Sales_data.h"
#include <fstream>

int main(int argc, char const *argv[])
{
    std::ifstream ifs("../../transactions_input_file");
    std::ofstream out;
    out.open(argv[1], std::ios_base::app | std::ofstream::out);
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
            print(out, sum) << " " << count << std::endl;
            count = 1;
            sum = temp;
        }
    }

    print(out, sum) << " " << count << std::endl;
    return 0;
}
