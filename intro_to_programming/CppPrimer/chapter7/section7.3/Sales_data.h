#include <iostream>
#ifndef __SALES_DATA_H
#define __SALES_DATA_H

class Sales_data
{

    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend std::ostream &print(std::ostream &, const Sales_data &);
    friend std::istream &read(std::istream &, Sales_data &);

private:
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    double avg_price() const;

public:
    Sales_data() : Sales_data("") { std::cout << "default constructor." << std::endl; }
    Sales_data(const std::string &s) : Sales_data(s, 0, 0.0) { std::cout << "constructor accepts a string." << std::endl; }
    Sales_data(const std::string &s, unsigned n, double p)
        : bookNo(s), units_sold(n), revenue(p * n) { std::cout << "constructor accepts a string, a unsigned, a double." << std::endl; }
    Sales_data(std::istream &is)
    {
        read(is, *this);
    }

    // be inline automaticly
    std::string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);
};

// nonmember Sales_data interface function
Sales_data add(const Sales_data &, const Sales_data &);
std::ostream &print(std::ostream &, const Sales_data &);
std::istream &read(std::istream &, Sales_data &);

inline double
Sales_data::avg_price() const
{
    return revenue / units_sold;
}

// friends should be in the same file as header file which define that friendship

#endif