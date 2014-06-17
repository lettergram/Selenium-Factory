#include "generate.h"

generate::generate(){
    this->objects = new std::queue<std::string>;
}

/**
 * @brief generate::push - Push a webElement onto
 *      the objects queue.
 * @param obj - std (standard C) string -
 *          should be webElements name.
 */
void generate::push(std::string obj){
    this->objects->push(obj);
}

/**
 * @brief generate::pop - Removes an element from the
 *      top of the queue.
 * @return std (standard C) string
 */
std::string generate::pop(){
    std::string obj = this->objects->front();
    this->objects->pop();
    return obj;
}

/**
 * === TODO ===
 * @brief generate::create - Creates
 *      or generates the selenium code
 */
void generate::create(){

}
