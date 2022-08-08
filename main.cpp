#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>

/**
 * FORMAT:
 * rat <filename>
 */

#include "exceptions.hpp"
#include "file.hpp"
#include "cli.hpp"

/**
 * @brief Main function
 * 
 * @param argc - argument count
 * @param argv - argument variable
 * @return int 
 */
int main(int argc, char *argv[])
{
    // check argument length
    if (argc != 2)
    {
        // create exception
        exception exception("Correct Usage: rat <filename>", INCORRECT_USAGE);
        exception.throw_exception();
        exit(0);
    }

    // get filename
    std::string filename(argv[1]);

    // create file object
    file file(filename);

    // check if file exists
    if (!file.exists())
    {
        // exception message
        std::string message = "File by name \"" + filename + "\" not found.";

        // create exception
        exception exception(message, INCORRECT_USAGE);
        exception.throw_exception();
        exit(0);
    }

    // open file & create string buffer
    std::ifstream __file(filename);
    std::string buffer;

    // lines vector
    std::vector<std::string> lines(file.get_lines());
    
    // push every line into vector
    while (getline(__file, buffer))
        lines.push_back(buffer);

    // create cli object
    cli cli(lines);

    // enter CLI
    cli.enter();

    // setup window
    cli.set_dimensions();
    cli.create_box(filename);

    // print lines
    cli.print_lines();
}