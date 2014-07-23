/*
 * Author: Gaurav D. Kale
 * Date: July 22, 2014
 * Project: Selenium Factory
 */

#ifndef PARSE_H
#define PARSE_H

#include <string>
#include <vector>
#include <QString>

class parse
{
public:
    parse(std::string str);
    std::vector<std::vector<std::string> > getVector();
private:
    std::string filename;
    std::vector<std::string> string_split(std::string, char);
};

#endif // PARSE_H
