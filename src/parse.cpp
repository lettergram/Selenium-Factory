/*
 * Author: Gaurav D. Kale
 * Creation Date: July 22, 2014
 *
 * Last Edit: Austin G. Walters
 * Last Modified: July 24, 2014
 * Project: Selenium Factory
 */

#include "parse.h"

/**
 * @brief parse::parse - Constrcutor for the parse class
 * @param str - file name to parse
 */
parse::parse(std::string str){
    filename = str;
}

/**
 * @brief parse::getVector - Returns a vector that contains
 *            vectors of items on each line of the csv file/
 * @return 2D vector containting the data from the CSV document
 */
std::vector<std::vector<std::string> > parse::getVector() {
    std::vector<std::vector<std::string> > output;

    std::ifstream file ( filename.c_str() );
    std::string value;

    while ( file.good() ){
         file >> value;
         output.push_back(string_split(value,","));
    }

    return output;
}

/**
 * @brief parse::createCSV - Creates a CSV file based on the
 * vector of vectors of strings
 * @param 2D vector containting the data for the CSV document
 */
void parse::createCSV(std::vector<std::vector<std::string> > vector, std::string newFile) {
    std::ofstream file ( newFile.c_str() );

    for(unsigned int i = 0; i < vector.size(); i++){
        for(unsigned int j = 0; j < vector[i].size() - 1; j++){
            file << vector[i][j] << ",";
        }
        file << vector[i][vector[i].size()-1] << "\n";
    }
}

/**
 * @brief parse::string_split - Helper Function
 *          Splits a string into a vector based on the delimiter
 * @param str - Single line contained in the CSV
 * @param delimiter - What we are looking to parse
 * @return vector, where each data element is what was parsed
 */
std::vector<std::string> parse::string_split(std::string str, std::string delimiter) {

    std::vector<std::string> output;
    char * tok = strtok((char *)str.c_str(), delimiter.c_str());

    while(tok != NULL){
        output.push_back(tok);
        tok = strtok(NULL, delimiter.c_str());
    }

    for(unsigned int i = 0; i < output.size(); i++){
        std::string element = output[i];
        char * spaceReplace = strtok((char *)element.c_str(), "-");
        std::string line = "";

        while(spaceReplace != NULL){
            line += spaceReplace;
            spaceReplace = strtok(NULL, "-");
            if(spaceReplace != NULL){ line += " "; }
        }
        output[i] = line;
        element.clear();
    }

    return output;
}
