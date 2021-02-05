#include <iostream>
#include "include/stockerAPI.hpp"

int main(int argc, char** argv)
{
    stocker::quote Quote("GME", "2020-01-01", "2020-05-01", "1wk");
    Quote.print_quote_info();
    Quote.download_quote_data("..\\..\\stock_data\\gme_data.csv");

}