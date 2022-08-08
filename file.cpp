#include "file.hpp"

#include <string>
#include <vector>
#include <sys/stat.h>

/**
 * @brief Construct a new file::file object
 * 
 * @param name - the name of the file
 */
file::file(std::string name)
{
    this->name = name;
}

/**
 * @brief Get the file name
 * 
 * @return std::string 
 */
std::string file::get_name()
{
    return this->name;
}

/**
 * @brief Get the lines from the file
 * 
 * @return std::vector<std::string> 
 */
std::vector<std::string> file::get_lines()
{
    return this->lines;
}

/**
 * @brief Check if file exists
 * 
 * @return true 
 * @return false 
 */
bool file::exists()
{
    // get stat
    struct stat buffer;
    return stat(this->get_name().c_str(), &buffer) == 0;
}