#include "ip_filter.h"

#include <string>
#include <experimental/string_view>
#include <vector>

using std::experimental::string_view;

ip_address_t ip_read(string_view ip) {
    using namespace std;

    vector<string_view> ip_splitted;
    ip_splitted.reserve(4);
    split(ip, '.', back_inserter(ip_splitted));
    return make_ip(
        stoi(string(ip_splitted.at(0))),
        stoi(string(ip_splitted.at(1))),
        stoi(string(ip_splitted.at(2))),
        stoi(string(ip_splitted.at(3))));
}