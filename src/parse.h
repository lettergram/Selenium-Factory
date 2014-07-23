/*
 * Author: Gaurav D. Kale
 * Date: July 22, 2014
 * Project: Selenium Factory
 */

#ifndef PARSE_H
#define PARSE_H

#include <string>
#include <string.h>
#include <vector>
#include <iostream>
#include <fstream>

class parse
{
public:
    parse(std::string);
    std::vector<std::vector<std::string> > getVector();

private:
    std::string filename;
    std::vector<std::string> string_split(std::string, std::string);
};

#endif // PARSE_H
