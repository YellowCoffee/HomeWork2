#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <algorithm>
#include <type_traits>

using namespace std;

template<typename Vector, typename T>
typename enable_if< is_same<typename Vector::value_type, T>::value, Vector>::type
getVector(Vector vector, const T& t)
{
    Vector result;
    result.reserve(1);
    result.push_back(t);
    return result;
}

template<typename Vector, typename T, typename ...V>
typename enable_if< is_same<typename Vector::value_type, T>::value, Vector>::type
getVector(Vector vector, const T& t, const V& ...v)
{
    Vector result;
    auto size = sizeof... (v) + 1;
    result.reserve( size );
    auto gV = getVector(vector, v...);
    std::copy( gV.begin(), gV.end(), back_inserter(result));
    result.insert(result.begin(), t);
    return result;
}

#endif // FUNCTIONS_H

