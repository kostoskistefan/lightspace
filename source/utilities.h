#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <vector>

#define clamp(x, low, high) (((x) > (high)) ? (high) : (((x) < (low)) ? (low) : (x)))

namespace Utilities
{
    std::string trim(const std::string &string);
    std::string lowercase(const std::string &string);
    std::vector<std::string> split(const std::string &string, char delimeter);

    std::string get_filename_from_path(const std::string &path);

}

#endif // UTILITIES_H