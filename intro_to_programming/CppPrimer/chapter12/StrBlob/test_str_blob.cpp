#include "StrBlob.h"
#include "StrBlobPtr.h"
#include "ConstStrBlobPtr.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
    const StrBlob blob;
    ifstream ifs("../../transactions_input_file");
    string temp;
    while (getline(ifs, temp))
    {
        blob.push_back(temp);
    }

    ConstStrBlobPtr iter = blob.begin();
    ConstStrBlobPtr end = blob.end();
    while (true)
    {
        if (iter == end)
            break;
        cout << iter.deref() << endl;
        iter.incr();
    }
    return 0;
}
