#ifndef GENERATE_H
#define GENERATE_H

#include <stdio.h>
#include <string.h>

#include <string>
#include <queue>
#include <iostream>
#include <fstream>

class Generate{

public:

    Generate();

    /* push and pull objects name in string form */
    void push(std::string);
    std::string pop();

    /* Creates script */
    void create(std::string, std::string);

private:

    std::queue<std::string> * objects;
};

#endif // GENERATE_H
