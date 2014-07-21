#include "generate.h"

Generate::Generate(){
    objects = new std::queue<std::string>;
}

/**
 * @brief generate::push - Push a webElement onto
 *      the objects queue.
 * @param obj - std (standard C) string -
 *          should be webElements name.
 */
void Generate::push(std::string obj){
    std::cout << "Size: " << objects->size() << std::endl;
    std::cout << "Pushing:\n" << obj << std::endl;
    objects->push(obj);
}

/**
 * @brief generate::pop - Removes an element from the
 *      top of the queue.
 * @return std (standard C) string
 */
std::string Generate::pop(){
    std::string obj = objects->front();
    objects->pop();
    return obj;
}

/**
 * NOT FULLY FUNCTIONAL
 * @brief generate::create - Genereates .csv
 *          file containing the characteristics of user selected
 *          web elements. Then it runs the script designated by fileName
 *          in the directory dir, which should genereate selenium code
 *          based off the the .csv.
 */
void Generate::create(std::string dir, std::string fileName){

    std::cout << "Creating CSV Document\n" << std::endl;

    std::cout << dir + "/" + fileName << "\n" << std::endl;

    std::fstream file;
    std::string name = dir + "/webElement.csv";
    file.open(name.c_str(), std::ios_base::out);

    if(file.is_open())
        std::cout << "Successfully Opened File!\n" << std::endl;
    else
        std::cout << "Failed to Open File!\n" << std::endl;

    std::cout << "creating!\n---------------------\n\n" << std::endl;
    while(objects->size() > 0){
         std::string webElement = this->pop();

         file << webElement << std::endl;
         std::cout << webElement << std::endl;
    }

    file.close();
}
