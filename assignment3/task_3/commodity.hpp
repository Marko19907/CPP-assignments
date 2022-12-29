#pragma once

#include <string>

using namespace std;

/**
 * 25% tax.
 */
const double TAX_MULTIPLIER = 1.25;

class Commodity {
private:
    string name;
    int id;
    double price;
public:
    Commodity(string name, int id, double price);

    string get_name() const;

    int get_id() const;

    double get_price() const;

    double get_price(double quantity) const;

    void set_price(double price);

    double get_price_with_sales_tax() const;

    double get_price_with_sales_tax(double quantity) const;
};
