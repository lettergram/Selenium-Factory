/*
 * Author: Gaurav D. Kale
 * Date: July 22, 2014
 * Project: Selenium Factory
 */

#include "parse.h"

parse::parse(std::string str){
    filename = str;
}

//returns a vector that contains vectors of items on each line of the csv file
std::vector<std::vector<std::string> > parse::getVector() {
    std::vector<std::vector<std::string> > output;

    std::ifstream file ( filename.c_str() );
    std::cout << "filename: " << filename << std::endl;
    std::cout << file.is_open() << std::endl;
    std::string value;

    //goes through the file line by line, creating vectors of every line, which themselves are vectors deliminated by commas
    while ( file.good() ){

         file >> value;
         output.push_back(string_split(value, ','));
    }

    return output;
}

//splits a string into a vector based on the delimiter
std::vector<std::string> parse::string_split(std::string str, const char delimiter) {

    size_t start = 0;
    size_t end = str.find_first_of(delimiter);

    std::vector<std::string> output;

    while (end <= std::string::npos){

        output.push_back(str.substr(start, end-start));

        if (end == std::string::npos)
            break;

        start = end + 1;
        end = str.find_first_of(delimiter, start);
    }

    return output;
}
