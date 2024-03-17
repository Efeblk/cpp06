#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

enum e_type
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    STRING,
    NANN
};

class ScalarConverter
{
private:
    std::string _value;
public:
    ScalarConverter();
    ScalarConverter(std::string const &value);
    ScalarConverter(ScalarConverter const &src);
    ~ScalarConverter();

    ScalarConverter &operator=(ScalarConverter const &rhs);

    static void convert(std::string value);
    static void print();

    static e_type what_type(std::string const &value);
    
    static int is_digit_str(std::string str);
    static int is_float(std::string str);
    static int is_int(std::string str);
    static int is_char(std::string str);
    static int is_double(std::string str);

    static void printFloatWithLimits(std::string value, int flag);
    static void printIntegerWithLimits(std::string value);
    static void printCharWithLimits(std::string value);
    class ImpossibleException : public std::exception
    {
        virtual const char *what() const throw();
    };


};

#endif