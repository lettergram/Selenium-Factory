#include "generate.h"

generate::generate(){

    this->objects = new std::queue<std::string>;
}

void generate::push(std::string obj){
    this->objects->push(obj);
}

// class::function definition
std::string generate::pull(){
    std::string obj = this->objects->front();
    this->objects->pop();
    return obj;
}

void generate::create(){

}
