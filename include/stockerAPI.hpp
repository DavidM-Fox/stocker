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

    class quote
    {
        public:
            quote
            (
                std::string t_symbol     = "---", 
                std::string t_date_start = "YYYY-MM-DD", 
                std::string t_date_end   = "YYYY-MM-DD", 
                std::string t_interval   = "1wk"
            );

            void set_symbol(std::string t_symbol);
            void set_period(std::string t_date_start, std::string t_date_end);
            void set_interval(std::string t_interval);


            std::string get_symbol();
            
            void download_quote_data(std::string filename);
            
            void print_quote_info();

            ~quote();
    
        private:
            std::string unix_timestamp(std::string t_date);
            bool string_replace(std::string& str, const std::string from, const std::string to);
            void build_url();
            
            std::string m_symbol;
            std::string m_date_start; 
            std::string m_date_end; 
            std::string m_interval;
            std::string m_data_col;
            std::string m_url;
    };
    

    // quote constructor: m_symbol, m_date_start, m_date_end, m_interval, m_url set to default
    quote::quote(std::string t_symbol, std::string t_date_start, std::string t_date_end, std::string t_interval) :
    m_symbol(t_symbol),
    m_date_start(t_date_start),
    m_date_end(t_date_end),
    m_interval(t_interval),
    m_url("https://query1.finance.yahoo.com/v7/finance/download/{symbol}?period1={date_start}&period2={date_end}&interval={interval}&events=history")
    {
        build_url();
    }
    
    // quote deconstructor
    quote::~quote() { }
    
    // Sets the quote symbol ex: "GME"
    void quote::set_symbol(std::string t_symbol)
    {
        this->m_symbol = t_symbol;
    }
    
    // Sets the quote period from a start and end date "YYYY-MM-DD"
    void quote::set_period(std::string t_date_start, std::string t_date_end)
    {
        this->m_date_start = t_date_start;
        this->m_date_end = t_date_end;

    }
    
    // Sets the quote period interval: ["1d", "1wk", "1mo"]
    void quote::set_interval(std::string t_interval)
    {
        this->m_interval = t_interval;
    }
    
    std::string quote::get_symbol() 
    {
        return this->m_symbol;
    }

    // Downloads historical stock data for quote
    void quote::download_quote_data(std::string filename)
    {
        CURL *curl;
        FILE *fp;
        CURLcode res;
        curl = curl_easy_init();
        if (curl)
        {
            fp = fopen(filename.c_str(), "wb");
            curl_easy_setopt(curl, CURLOPT_URL, this->m_url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
            res = curl_easy_perform(curl);

            /* always cleanup */
            curl_easy_cleanup(curl);
            fclose(fp);
        }

    }
    
    // Prints all quote information 
    void quote::print_quote_info()
    {
        std::cout << "Quote Symbol      : " << this->m_symbol << '\n';
        std::cout << "Quote Date (Start): " << this->m_date_start << ", " << unix_timestamp(this->m_date_start) << '\n';
        std::cout << "Quote Date (End)  : " << this->m_date_end   << ", " << unix_timestamp(this->m_date_end)   << '\n';
        std::cout << "Quote Interval    : " << this->m_interval << '\n';
        std::cout << "Download URL      : " << this->m_url << '\n';

    }
    
    // Takes a date in the format YYYY-MM-DD and returns a unix timestamp.
    std::string quote::unix_timestamp(std::string t_date)
    {
        std::istringstream iss(t_date);
        
        struct std::tm time = {0,0,0,0,0,0,0,0,0};
        iss >> std::get_time(&time, "%Y-%m-%d"); 
        if(iss.fail())
        {
            std::cerr  << "ERROR: Cannot parse date (" << t_date <<"); required format YYYY-MM-DD" << std::endl;
            exit(1);
        }
        
        time.tm_hour = 0;
        time.tm_min  = 0;
        time.tm_sec  = 0;
        std::time_t epoch = std::mktime(&time);
        return std::to_string(epoch);
    }

    // Replaces string "{from}" to "{to}"
    bool quote::string_replace(std::string& str, const std::string from, const std::string to)
    {
        size_t start = str.find(from);
        if(start == std::string::npos)
        {
            return false;
        }
        str.replace(start, from.length(), to);
        return true;
    }
    
    // Builds download url from quote information. Requires symbol, start_date, end_date, interval
    void quote::build_url()
    {
        std::string url = this->m_url;
        string_replace(url, "{symbol}"        , this->m_symbol);
        string_replace(url, "{date_start}"    , unix_timestamp(this->m_date_start));
        string_replace(url, "{date_end}"      , unix_timestamp(this->m_date_end));
        string_replace(url, "{interval}"      , this->m_interval);
        this->m_url = url;
    }

    size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream)
    {
        size_t written;
        written = fwrite(ptr, size, nmemb, stream);
        return written;
    }
    
}