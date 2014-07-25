/*
 * Author: Gaurav D. Kale
 * Creation Date: July 22, 2014
 *
 * Last Edit: Austin G. Walters
 * Last Modified: July 24, 2014
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
    void createCSV(std::vector<std::vector<std::string> >, std::string);

private:
    std::string filename;
    std::vector<std::string> string_split(std::string, std::string);
};

#endif // PARSE_H
