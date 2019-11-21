#include <cassert>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <vector>

#include "functions.h"

using namespace std;

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while(stop != std::string::npos) {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}

void print_ip(std::vector<std::vector<int>> ip_pool)
{
    for(auto ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip) {
        for(auto ip_part = ip->cbegin(); ip_part != ip->cend(); ++ip_part) {
            if (ip_part != ip->cbegin()) {
                std::cout << ".";
            }
            std::cout << *ip_part;
        }
        std::cout << std::endl;
    }
}

int main(int argc, char const *argv[])
{
    try
    {
        std::vector<std::vector<int>> ip_pool;

        for(std::string line; std::getline(std::cin, line);) {
            std::vector<std::string> v = split(line, '\t');
            auto ipString = split(v.at(0), '.');
            std::vector<int> ipInt;
            std::for_each ( ipString.begin(), ipString.end(), [&ipInt](auto ipStr) {
                ipInt.push_back( std::stoi( ipStr ) );
            });

            ip_pool.push_back(ipInt);
        }

        // TODO reverse lexicographically sort
        std::sort( ip_pool.begin(), ip_pool.end(), greater<vector<int>>() );
        print_ip(ip_pool);

        // 222.173.235.246
        // 222.130.177.64
        // 222.82.198.61
        // ...
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first byte and output
        auto filter = [ip_pool](const auto&... values) {
            decltype (ip_pool) result;
            std::for_each( ip_pool.begin(), ip_pool.end(), [&result, ip_pool, values...](auto ip) {
                auto compareArray = getVector( ip, values... );
                auto equal = std::equal(compareArray.begin(), compareArray.end(), ip.begin());
                if(equal) {
                    result.push_back( ip );
                }
            } );
            return result;
        };

        auto ip = filter( 1 );
        print_ip( ip );

        // 1.231.69.33
        // 1.87.203.225
        // 1.70.44.170
        // 1.29.168.152
        // 1.1.234.8

        // TODO filter by first and second bytes and output
         ip = filter(46, 70);
         print_ip( ip );

        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76

        // TODO filter by any byte and output
         auto filter_any = [ip_pool](const auto& value) {
             decltype(ip_pool) result;
             for_each( ip_pool.begin(), ip_pool.end(), [&result, value](const auto& ip){
                 if ( std::any_of( ip.begin(), ip.end(), [value](auto i){ return i == value;} ) )
                     result.push_back(ip);
             } );
             return result;
         };

         ip = filter_any(46);
         print_ip( ip );

        // 186.204.34.46
        // 186.46.222.194
        // 185.46.87.231
        // 185.46.86.132
        // 185.46.86.131
        // 185.46.86.131
        // 185.46.86.22
        // 185.46.85.204
        // 185.46.85.78
        // 68.46.218.208
        // 46.251.197.23
        // 46.223.254.56
        // 46.223.254.56
        // 46.182.19.219
        // 46.161.63.66
        // 46.161.61.51
        // 46.161.60.92
        // 46.161.60.35
        // 46.161.58.202
        // 46.161.56.241
        // 46.161.56.203
        // 46.161.56.174
        // 46.161.56.106
        // 46.161.56.106
        // 46.101.163.119
        // 46.101.127.145
        // 46.70.225.39
        // 46.70.147.26
        // 46.70.113.73
        // 46.70.29.76
        // 46.55.46.98
        // 46.49.43.85
        // 39.46.86.85
        // 5.189.203.46
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
