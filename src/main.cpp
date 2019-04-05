#include <iostream>
#include <deque>
#include <vector>
#include <iterator>
#include <algorithm>
#include <experimental/string_view>

#include "ip_filter.h"

int main()
{
    using namespace std;
    using std::experimental::string_view;

    try
    {
        vector<ip_address_t> ips;

        // read ips
        std::vector<string_view> line_parts;
        line_parts.reserve(3);
        for(std::string line; std::getline(std::cin, line);)
            ips.push_back(ip_read(line));
        
        // reverse sort of ips
        sort(begin(ips), end(ips), greater<ip_address_t>());
        copy(begin(ips), end(ips), ostream_iterator<ip_address_t>(cout, "\n"));
        // filter by first byte (equals 1)
        ip_filter(begin(ips), end(ips), ostream_iterator<ip_address_t>(cout, "\n"), 1);
        // filter by first and second bytes (equal 46 anf 70)
        ip_filter(begin(ips), end(ips), ostream_iterator<ip_address_t>(cout, "\n"), 46, 70);
        // filter by any byte (46)
        ip_filter_any(begin(ips), end(ips), ostream_iterator<ip_address_t>(cout, "\n"), 46);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}