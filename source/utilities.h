#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
#include <vector>

/**
 * @namespace Utilities
 * @brief Namespace containing various utility functions.
 */
namespace Utilities
{
    /**
     * @brief Trim leading and trailing white spaces from a string.
     * @param str The string to remove the white spaces from.
     * @return The trimmed string.
     */
    std::string trim(const std::string &str);

    /**
     * @brief Convert a string to lowercase.
     * @param str The string to convert.
     * @return The lowercase version of the string.
     */
    std::string lowercase(const std::string &str);

    /**
     * @brief Split a string into a vector of strings.
     * @param str The string to split.
     * @param delimeter The delimeter to split the string by.
     * @return A vector of strings (tokens).
     */
    std::vector<std::string> split(const std::string &str, char delimeter);
}

#endif // UTILITIES_H
