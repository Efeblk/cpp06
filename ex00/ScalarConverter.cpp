#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() : _value("0") {}

ScalarConverter::ScalarConverter(std::string const &value) : _value(value) {}

ScalarConverter::ScalarConverter(ScalarConverter const &src) : _value(src._value) {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
    if (this != &rhs)
    {
        _value = rhs._value;
    }
    return *this;
}

void ScalarConverter::convert(std::string value)
{
    switch (what_type(value))
    {
    case CHAR:
        std::cout << "char: " << value << std::endl;
        std::cout << "int: " << static_cast<int>(value[0]) << std::endl;
        std::cout << "float: " << static_cast<float>(value[0]) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(value[0]) << ".0" << std::endl;
        break;
    case INT:
        printCharWithLimits(value);
        printIntegerWithLimits(value);
        printFloatWithLimits(value, 0);
        std::cout << "double: " << value << ".0" << std::endl;
        break;
    case FLOAT:
        printCharWithLimits(value);
        printIntegerWithLimits(value);
        std::cout << "float: " << value << std::endl;
        std::cout << "double: " << std::stod(value) << "" <<std::endl;
        break;
    case DOUBLE:
        printCharWithLimits(value);
        printIntegerWithLimits(value);
        printFloatWithLimits(value, 1);
        std::cout << "double: " << value <<std::endl;
        break;
    case STRING:
    case NANN:
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        break;
    default:
        throw ImpossibleException();
    }
}

void ScalarConverter::print()
{
    std::cout << "Print" << std::endl;
}

e_type ScalarConverter::what_type(std::string const &value) 
{
    if((value.length() == 1) && (!isdigit(value[0])))
        return CHAR;
    else if((value.length() > 1) && is_digit_str(value))
        return STRING;
    else if(is_float(value))
        return FLOAT;
    else if (is_double(value))
        return DOUBLE;
    else if(is_int(value))
        return INT;
    else
        return NANN;
}

void ScalarConverter::printCharWithLimits(std::string value)
{
    if(static_cast<int>(std::stod(value)) > 32 && static_cast<int>(std::stod(value)) < 126)
        std::cout << "char: '" << static_cast<char>(std::stod(value)) << "'" << std::endl;
    else
        std::cout << "char: " << "Non displayable " << std::endl;
}

void ScalarConverter::printIntegerWithLimits(std::string value) 
{
    try {
        int num = std::stoi(value);
        if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min()) {
            std::cout << "Number is out of int range." << std::endl;
        } else {
            std::cout << "int: " << num << std::endl;
        }
    } catch (std::invalid_argument& e) {
        std::cout << "Invalid argument: " << e.what() << '\n';
    } catch (std::out_of_range& e) {
        std::cout << "Out of range: " << e.what() << '\n';
    }
}

void ScalarConverter::printFloatWithLimits(std::string value, int flag) 
{
    try {
        float num = std::stof(value);
        if (num > std::numeric_limits<float>::max() || num < std::numeric_limits<float>::lowest()) {
            std::cout << "Number is out of float range." << std::endl;
        } 
        else
        {
            if(flag == 1)
                std::cout << "float: " << num << "f" << std::endl;
            else if(flag == 0)
                std::cout << "float: " << num << ".0f" << std::endl;
        }
    } catch (std::invalid_argument& e) {
        std::cout << "Invalid argument: " << e.what() << '\n';
    } catch (std::out_of_range& e) {
        std::cout << "Out of range: " << e.what() << '\n';
    }
}

int ScalarConverter::is_digit_str(std::string value)
{
    int len = value.length();
    for(int i = 0; i <= len; i++)
    {
        if(isdigit(value[i]))
            return 0;
    }
    return 1;
}

int ScalarConverter::is_float(std::string value)
{
    int len;
    int i;
    int flag;

    flag = 0;
    len = value.length();
    i = 0;
    while(value[i] == '+' || value[i] == '-')
        i++;
    if(!isdigit(value[0]) && i == 0)
        return 0;
    while(i < (len - 1))
    {
        if(!isdigit(value[i]) && (value[i] != '+' || value[i] != '-'))
        {
            if(value[i] == '.')
                flag++;
            
            else
                return 0;
        }
        if(flag > 1)
            return 0;
        i++;
    }
    if(value[len - 1] != 'f')
        return 0;
    if(flag != 1)
        return 0;
    return 1;
}

int ScalarConverter::is_double(std::string value)
{
    int len;
    int i;
    int flag;

    flag = 0;
    len = value.length();
    i = 0;
    while(value[i] == '+' || value[i] == '-')
        i++;
    if(!isdigit(value[i]) && i == 0)
        return 0;

    while(i < len)
    {
        if(!isdigit(value[i]))
        {
            if(value[i] == '.')
                flag++;
            else
                return 0;
        }
        if(flag > 1)
            return 0;
        i++;
    }
    if(flag != 1)
        return 0;
    return 1;
    
}

int ScalarConverter::is_int(std::string value)
{
    int i;
    int len;

    i = 0;
    len = value.length();
    while(value[i] == '+' || value[i] == '-')
        i++;
    while(i < len)
    {
        if(!isdigit(value[i]))
            return 0;
        i++;
    }
    return 1;
}


const char *ScalarConverter::ImpossibleException::what() const throw()
{
    return "Impossible";
}