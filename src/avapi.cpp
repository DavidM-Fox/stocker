#include "avapi.h"

namespace avapi {

/**
 * @brief   Class constructor
 * @param   symbol The stock symbol of interest
 * @param   api_key The Alpha Vantage API key to use
 */
Quote::Quote(std::string symbol, std::string api_key)
    : m_symbol(symbol), m_api_key(api_key),
      m_url_base("https://www.alphavantage.co/query?function="),
      m_url_end("&symbol={symbol}&apikey={api}&datatype=csv"),
      m_urls(
          {m_url_base + "TIME_SERIES_INTRADAY&interval={interval}" + m_url_end,
           m_url_base + "TIME_SERIES_DAILY" + m_url_end,
           m_url_base + "TIME_SERIES_WEEKLY" + m_url_end,
           m_url_base + "TIME_SERIES_MONTHLY" + m_url_end}),
      m_fnames({"..\\..\\data\\intraday_{symbol}.csv",
                "..\\..\\data\\daily_{symbol}.csv",
                "..\\..\\data\\weekly_{symbol}.csv",
                "..\\..\\data\\monthly_{symbol}.csv"})
{
}

/**
 * @brief   Class Deconstructor
 */
Quote::~Quote() {}

/**
 * @brief   Returns a "func" time_series from last_n_rows;
 * @param   func The avapi::function to use
 * @param   last_n_rows Last number of rows to get - default = 0 (all)
 * @param   interval Interval for avapi::INTRADAY - default = "30min"
 * @returns An avapi::time_series with each pair.second =
 * std::vector<float>[open, high, low, close, volume]
 */
time_series Quote::getTimeSeries(const function &func,
                                 const size_t &last_n_rows,
                                 const std::string &interval)
{
    // Create url query for getting said time series
    std::string url = this->m_urls[func];
    if (func == avapi::INTRADAY) {
        stringReplace(url, "{interval}", interval);
    }
    stringReplace(url, "{symbol}", this->m_symbol);
    stringReplace(url, "{api}", this->m_api_key);

    // Create filename for time series csv
    std::string file_name = this->m_fnames[func];
    stringReplace(file_name, "{symbol}", this->m_symbol);

    // Download csv data for global quote
    std::string data = downloadCsv(url);
    return parseCsvString(data, last_n_rows);
}

/**
 * @brief   Returns an avapi::time_pair containing the latest global quote:
 * @returns latest global quote as an avapi::time_pair with pair.second =
 * std::vector<float>[open,high,low,price,volume,prevClose,change,change]
 */
time_pair Quote::getGlobalQuote()
{
    // Create url query for getting global quote
    std::string url = this->m_url_base + "GLOBAL_QUOTE" + this->m_url_end;
    stringReplace(url, "{symbol}", this->m_symbol);
    stringReplace(url, "{api}", this->m_api_key);

    // Create url query for global quote csv
    std::string file_name = "..\\..\\data\\global_quote_{symbol}.csv";
    stringReplace(file_name, "{symbol}", this->m_symbol);

    // Download csv data for global quote
    std::stringstream data(downloadCsv(url));

    rapidcsv::Document doc(data, rapidcsv::LabelParams(0, 0));
    std::vector<float> quote_row = doc.GetRow<float>(this->m_symbol);

    // Erase final data column and put at the beginning as a unix_timestamp
    quote_row.erase(quote_row.begin() + 5);
    time_pair global_quote = std::make_pair(
        toUnixTimestamp(doc.GetColumn<std::string>("latestDay")[0]), quote_row);

    // Return global quote as a avapi::time_pair
    return global_quote;
}

/**
 * @brief   Returns an avapi::time_series created from a csv file
 * @param   file_path file path of the csv file to parse
 * @param   last_n_rows last number of rows to return
 * @returns avapi::time_series
 */
time_series parseCsvFile(const std::string &file_path,
                         const size_t &last_n_rows)
{
    rapidcsv::Document doc(file_path);
    std::vector<std::string> date_col = doc.GetColumn<std::string>(0);
    size_t n_data = last_n_rows;

    if (last_n_rows > date_col.size()) {
        std::cout << "Error: Not enough data rows in in file for last_n series"
                  << '\n';
        time_series fail;
        return fail;
    }
    else if (last_n_rows == 0) {
        n_data = date_col.size();
    }

    std::vector<float> open = doc.GetColumn<float>(1);
    std::vector<float> high = doc.GetColumn<float>(2);
    std::vector<float> low = doc.GetColumn<float>(3);
    std::vector<float> close = doc.GetColumn<float>(4);
    std::vector<float> volume = doc.GetColumn<float>(5);

    time_series series;

    for (size_t i = 0; i < n_data; ++i) {

        std::vector<float> data;

        data.push_back(open[i]);
        data.push_back(high[i]);
        data.push_back(low[i]);
        data.push_back(close[i]);
        data.push_back(volume[i]);

        series.push_back(std::make_pair(toUnixTimestamp(date_col[i]), data));
    }
    std::reverse(series.begin(), series.end());
    return series;
}

/**
 * @brief   Returns an avapi::time_series created from a csv std::string
 * @param   data the csv std::string to parse
 * @param   last_n_rows last number of rows to return
 * @returns avapi::time_series
 */
time_series parseCsvString(const std::string &data, const size_t &last_n_rows)
{
    std::stringstream sstream(data);
    rapidcsv::Document doc(sstream);
    std::vector<std::string> date_col = doc.GetColumn<std::string>(0);
    size_t n_data = last_n_rows;

    if (last_n_rows > date_col.size()) {
        std::cout << "Error: Not enough data rows in in file for last_n series"
                  << '\n';
        time_series fail;
        return fail;
    }
    else if (last_n_rows == 0) {
        n_data = date_col.size();
    }

    std::vector<float> open = doc.GetColumn<float>(1);
    std::vector<float> high = doc.GetColumn<float>(2);
    std::vector<float> low = doc.GetColumn<float>(3);
    std::vector<float> close = doc.GetColumn<float>(4);
    std::vector<float> volume = doc.GetColumn<float>(5);

    time_series series;

    for (size_t i = 0; i < n_data; ++i) {

        std::vector<float> data;

        data.push_back(open[i]);
        data.push_back(high[i]);
        data.push_back(low[i]);
        data.push_back(close[i]);
        data.push_back(volume[i]);

        series.push_back(std::make_pair(toUnixTimestamp(date_col[i]), data));
    }
    std::reverse(series.begin(), series.end());
    return series;
}

/**
 * @brief   Callback function for CURLOPT_WRITEFUNCTION
 * @param   ptr The downloaded chunk members
 * @param   size Member memory size
 * @param   nmemb Number of members
 * @param   data Current running chunk for data appension
 * @returns The current running chunk's realsize
 */
size_t Quote::WriteMemoryCallback(void *ptr, size_t size, size_t nmemb,
                                  void *data)
{
    size_t realsize = size * nmemb;

    std::string *mem = reinterpret_cast<std::string *>(data);
    mem->append(static_cast<char *>(ptr), realsize);
    return realsize;
}

/**
 * @brief   Curls csv data and uses WriteMemoryCallback to store data
 * @param   t_url The url to be curled
 * @returns The csv data as an std::string
 */
std::string Quote::downloadCsv(const std::string &t_url)
{
    CURL *curl;
    CURLcode res;
    std::string data;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, t_url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
        res = curl_easy_perform(curl);

        /* always cleanup */
        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }
    return data;
}

/**
 * @brief   Replaces a substring within a given string
 * @param   str The given string
 * @param   from The substring being replaced by "to"
 * @param   to The substring replacing "from"
 * @returns Success bool
 */
bool stringReplace(std::string &str, const std::string &from,
                   const std::string &to)
{
    size_t start = str.find(from);
    if (start == std::string::npos) {
        return false;
    }
    str.replace(start, from.length(), to);
    return true;
}

/**
 * @brief   Reads the first line from a given file
 * @param   file_path File to be read's path
 * @returns first line as an std::string
 */
std::string readFirstLineFromFile(const std::string &file_path)
{
    std::string api_key;
    std::ifstream file(file_path);
    if (file.is_open()) {
        std::getline(file, api_key);
        file.close();
    }
    else {
        std::cout << "Unable to open file: " << file_path;
    }
    return api_key;
}

/**
 * @brief   Converts date + time string "%Y-%m-%d %H:%M:%S" to Unix Timestamp
 * (seconds since unic epoch)
 * @param   input The input string to be converted
 * @returns std::time_t timestamp
 */
std::time_t toUnixTimestamp(const std::string &input)
{
    std::tm t{};
    std::istringstream ss(input);
    std::string format = "%Y-%m-%d %H:%M:%S";
    ss >> std::get_time(&t, format.c_str());
    return mktime(&t);
}

/**
 * @brief   Prints an avapi::time_series' data to console
 * @param   series The avapi::time_series to be printed
 */
void printSeries(const time_series &series)
{
    for (auto &pair : series) {
        std::cout << pair.first << ':';
        for (auto &val : pair.second) {
            std::cout << ' ' << val;
        }
        std::cout << '\n';
    }
}

/**
 * @brief   Prints an avapi::time_pair's data to console
 * @param   pair The avapi::time_pair to be printed
 */
void printPair(const time_pair &pair)
{
    std::cout << pair.first << ':';
    for (auto &val : pair.second) {
        std::cout << ' ' << val;
    }
    std::cout << '\n';
}
} // namespace avapi