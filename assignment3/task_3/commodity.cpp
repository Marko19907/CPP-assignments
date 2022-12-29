#include <string>
#include <iostream>
#include <utility>
#include "commodity.hpp"

using namespace std;


Commodity::Commodity(std::string name, int id, double price) : name(std::move(name)), id(id), price(price) {};

string Commodity::get_name() const {
    return name;
}

int Commodity::get_id() const {
    return id;
}

double Commodity::get_price() const {
    return price;
}

double Commodity::get_price(double quantity) const {
    return quantity * price;
}

void Commodity::set_price(double newPrice) {
    price = newPrice;
}

double Commodity::get_price_with_sales_tax() const {
    return get_price() * TAX_MULTIPLIER;
}

double Commodity::get_price_with_sales_tax(double quantity) const {
    return get_price_with_sales_tax() * quantity;
}

int main() {
    const double quantity = 2.5;
    Commodity commodity("Norvegia", 123, 73.50);

    cout << "Varenavn: " << commodity.get_name() << ", varenr: " << commodity.get_id() << " Pris pr enhet: " << commodity.get_price() << endl;

    cout << "Kilopris: " << commodity.get_price() << endl;
    cout << "Prisen for " << quantity << " kg er " << commodity.get_price(quantity) << " uten moms" << endl;
    cout << "Prisen for " << quantity << " kg er " << commodity.get_price_with_sales_tax(quantity) << " med moms" << endl;

    commodity.set_price(79.60);
    cout << "Ny kilopris: " << commodity.get_price() << endl;
    cout << "Prisen for " << quantity << " kg er " << commodity.get_price(quantity) << " uten moms" << endl;
    cout << "Prisen for " << quantity << " kg er " << commodity.get_price_with_sales_tax(quantity) << " med moms" << endl;

    return 0;
}

/* Correct printout:
Varenavn: Norvegia, varenr: 123 Pris pr enhet: 73.5
Kilopris: 73.5
Prisen for 2.5 kg er 183.75 uten moms
Prisen for 2.5 kg er 229.688 med moms
Ny kilopris: 79.6
Prisen for 2.5 kg er 199 uten moms
Prisen for 2.5 kg er 248.75 med moms
*/
