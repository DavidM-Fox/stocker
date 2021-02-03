#pragma once
#include <string.h>
#include <curl/curl.h>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <vector>
#include <stdio.h>


namespace stocker
{
    //Array of date pairs [YYYY-MM-DD, Unix Timestamp]
    typedef std::vector<std::vector<std::string>> period;

    class quote
    {
        public:
            quote();
            void set_interval(std::string t_interval);
            void set_period(std::string t_period_start, std::string t_period_end);
            void set_symbol(std::string t_symbol);
            
            stocker::period get_period();

            void print_period();

            ~quote();
    
        private:
            /* data */
            std::string m_url;
            std::string m_symbol;
            std::vector<std::string> m_date_start; 
            std::vector<std::string> m_date_end; 
            std::string m_interval;
    };
    
    quote::quote(/* args */) :
    m_url("https://query1.finance.yahoo.com/v7/finance/download/{symbol}?period1={period_start}&period2={period_end}&interval={interval}&events=history"),
    m_symbol("---"),
    m_date_start(2, ""),
    m_date_end(2, "") { }

    /*
    *
    * Sets the interval of historical stock data: "1d", "1wk", "1mo"
    *
    */
    void quote::set_interval(std::string t_interval)
    {
        this->m_interval = t_interval;
    }
    
    /*
    *
    * Takes an end and start date in the format YYYY-MM-DD, converting both strings to unix timestamps.
    * Sets m_date_start & m_date_end vectors to ["YYYY-MM-DD", "Unix Timestamp"]
    *
    */
    void quote::set_period(std::string t_date_start, std::string t_date_end)
    {

        struct std::tm start_time = {0,0,0,0,0,0,0,0,0};
        struct std::tm end_time   = {0,0,0,0,0,0,0,0,0};
        std::time_t epoch;

        std::istringstream iss(t_date_start + ' ' + t_date_end);
        
        iss >> std::get_time(&start_time, "%Y-%m-%d"); 
        if(iss.fail())
        {
            std::cerr  << "ERROR: Cannot parse starting date (" << t_date_start <<"); required format YYYY-MM-DD" << std::endl;
            exit(1);
        }
        
        iss >> std::get_time(&end_time, "%Y-%m-%d");
        if(iss.fail())
        {
            std::cerr  << "ERROR: Cannot parse ending date (" << t_date_end <<"); required format YYYY-MM-DD" << std::endl;
            exit(1);
        }
        
        start_time.tm_hour = 0;
        start_time.tm_min  = 0;
        start_time.tm_sec  = 0;
        epoch = std::mktime(&start_time);
        this->m_date_start[0] = t_date_start;
        this->m_date_start[1] = std::to_string(epoch);
        
        end_time.tm_hour = 0;
        end_time.tm_min  = 0;
        end_time.tm_sec  = 0;
        epoch = std::mktime(&end_time);
        this->m_date_end[0] = t_date_end;
        this->m_date_end[1] = std::to_string(epoch);
    }

    stocker::period quote::get_period()
    {
        stocker::period this_period{this->m_date_start, this->m_date_end};
        return this_period;
    }
    
    /*
    *
    * std::cout << Time Period of this Quote
    * 
    */
    void quote::print_period()
    {
        std::cout << "START: " << this->m_date_start[0] << " -- (" << this->m_date_start[1] << ")" << '\n';
        std::cout << "END--: " << this->m_date_end[0]   << " -- (" << this->m_date_end[1]   << ")" << '\n';
    }
    
    void quote::set_symbol(std::string t_symbol)
    {

    }
    
    quote::~quote()
    {
    
    }
    
    //
}