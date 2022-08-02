#include "utilities.h"
#include <algorithm>

double fastPow(double a, double b)
{
    union
    {
        double d;
        int x[2];
    } u = {a};

    u.x[1] = (int)(b * (u.x[1] - 1072632447) + 1072632447);
    u.x[0] = 0;

    return u.d;
}

void trim_left(Glib::ustring &s)
{
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch)
                                    { return !std::isspace(ch); }));
}

void trim_right(Glib::ustring &s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch)
                         { return !std::isspace(ch); })
                .base(),
            s.end());
}

void trim(Glib::ustring &s)
{
    trim_left(s);
    trim_right(s);
}

std::vector<Glib::ustring> split(Glib::ustring &str, char delimeter)
{
    std::stringstream ss(str);
    std::string item;
    std::vector<Glib::ustring> tokens;

    while (std::getline(ss, item, delimeter))
       tokens.push_back(item);

    return tokens;
}

double string_to_double(const Glib::ustring &str)
{
    double value;

    try
    {
        value = std::stod(str);
    }

    catch (std::exception &e)
    {
        value = 0;
        fprintf(stderr, "%s\n", e.what());
    }

    return value;
}

bool string_to_bool(const Glib::ustring &str)
{
    bool value = false;

    if (str == "True")
        value = true;

    else if (str == "False")
        value = false;

    else 
        fprintf(stderr, "Cannot convert the string: '%s' to bool", str);

    return value;
}