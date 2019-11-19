#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

std::vector<std::string> split(const std::string &str, char d);

template<typename V, typename T>
V filter(const V& vector, const T& value ) {
    V result;
    std::for_each( vector.begin(), vector.end(), [&result, value](auto ip) {
        if ( ip.at(0) == value ) {
            result.push_back( ip );
        }
    } );
    return result;
}

template<typename V, typename ...T>
V filter(const V &vector, const T& ... values) {
    V result;
    std::for_each( vector.begin(), vector.end(), [&](auto ip, auto ... values) {
        auto v = getVector(values...);
        if( std::equal(v.begin(), v.end(), vector.begin()) ) {
            result.push_back( ip );
        }
    });
    return result;
}

template<typename Vector, typename T>
typename enable_if< is_same<typename Vector::value_type, T>::value, Vector>::type
//typename enable_if< true, Vector>::type
getVector(Vector vector, const T& value) //, const T& ... values) {
{
    return vector;
}



#endif // FUNCTIONS_H

