#ifndef GENERATE_H
#define GENERATE_H

#include <string>
#include <queue>

class generate{

public:

    generate();

    /* push and pull objects name in string form */
    void push(std::string);
    std::string pull();

    /* Creates script */
    void create();

private:

    /* TODO: make queue */
    std::queue<std::string> * objects;
};

#endif // GENERATE_H
