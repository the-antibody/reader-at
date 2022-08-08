#include <string>
#include <vector>
#include <stdbool.h>

class file
{
    std::string name;
    std::vector<std::string> lines;

    public:
        file(std::string name);
        std::string get_name();
        std::vector<std::string> get_lines();
        bool exists();
};