#include "utilities.h"
#include <sstream>
#include <algorithm>

std::string Utilities::get_filename_from_path(const std::string &path)
{
    size_t lastSlash = path.find_last_of("/");
    return path.substr(lastSlash + 1, path.back());
}

std::vector<std::string> Utilities::split(const std::string &str, char delimeter)
{
    std::istringstream ss(str);
    std::string item;
    std::vector<std::string> tokens;

    for (std::string item; std::getline(ss, item, delimeter); )
       tokens.push_back(item);

    return tokens;
}

std::string Utilities::lowercase(const std::string &str)
{
    std::string lowercaseString = str;

    std::transform(lowercaseString.begin(), lowercaseString.end(), lowercaseString.begin(), ::tolower);

    return lowercaseString;
}

std::string Utilities::trim(const std::string &str)
{
    std::string trimmedString = str;
    trimmedString.erase(trimmedString.find_last_not_of(" \n\r\t") + 1);
    trimmedString.erase(0, trimmedString.find_first_not_of(" \n\r\t"));
    return trimmedString;
}