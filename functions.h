#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> split(const std::string &str, char d);

template<class T>
T filter(int N);

#endif // FUNCTIONS_H
