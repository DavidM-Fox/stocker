#include <iostream>
#include "include/stockerAPI.hpp"

int main(int, char**)
{
    stocker::quote Quote;
    Quote.set_period("2020-01-01", "2020-05-01");
    Quote.set_interval("1wk");
    Quote.print_period();

    return 0;
}
