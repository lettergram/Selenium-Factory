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
 * === TODO ===
 * @brief generate::create - Creates
 *      or generates the selenium code,
 *      currently just prints it.
 */
void Generate::create(){
    while(objects->size() > 0){
        std::cout << this->pop() << std::endl;
    }
}
