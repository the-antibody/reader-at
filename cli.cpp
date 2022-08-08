#include "cli.hpp"

#include <cstring>

/**
 * @brief Construct a new cli::cli object
 * 
 * @param lines 
 */
cli::cli(std::vector<std::string> lines)
{
    this->lines = lines;
}

/**
 * @brief Get the window
 * 
 * @return WINDOW*
 */
WINDOW* cli::get_window()
{
    return this->window;
}

/**
 * @brief Get the lines
 * 
 * @return std::vector<std::string> 
 */
std::vector<std::string> cli::get_lines()
{
    return this->lines;
}

/**
 * @brief Enter the CLI
 */
void cli::enter()
{
    // init ncurses
    initscr();
    noecho();

    // set cursor
    curs_set(0);

    // create window
    this->window = newwin(0, 0, 0, 0);
}

/**
 * @brief Set the values of the dimensions array
 */
void cli::set_dimensions()
{
    // get dimensions
    getmaxyx(stdscr, this->dimensions[0], this->dimensions[1]);
}

/**
 * @brief Create the box
 */
void cli::create_box(std::string filename)
{
    // create box
    box(this->get_window(), 0, 0);
    wattron(this->get_window(), A_STANDOUT);
    mvwprintw(this->get_window(), 0, 2, "rat (reader-at)");
    wattroff(this->get_window(), A_STANDOUT);
    wattron(this->get_window(), A_BOLD);
    mvwprintw(this->get_window(), 0, 18, "(1.0.0)");
    mvwprintw(this->get_window(), 0, this->dimensions[1] - 18, "Exit (Ctrl + C)");

    // print file name at the top    ------ this bit is so that the text is centered -------            
    mvwprintw(this->get_window(), 0, (this->dimensions[1] / 2) - (filename.length() / 2) - 3, filename.c_str());
    wattroff(this->get_window(), A_BOLD);
}

/**
 * @brief Fix overflowing lines in vector
 */
void cli::fix_overflows()
{
    for (int i = 0; i < this->lines.size(); i++)
    {
        // get line & length
        const char *line = this->lines.at(i).c_str();

        if (strlen(line) >= this->dimensions[1] - 2)
        {
            // create old ad new line strings
            std::string old_line(line);
            std::string new_line = "";

            // loop through every overflowing character
            for (auto j = this->dimensions[1] - 2; j < old_line.length(); j++)
            {
                // append to new line
                new_line = new_line + old_line[j];

                // erase from old line
                this->lines.at(i)[j] = '\0';
            }

            // insert into lines map
            this->lines.insert((this->lines.begin() + i) + 1, new_line);
        }
    }
}

/**
 * @brief Print the lines to the CLI
 */
void cli::print_lines()
{
    // fix overflows
    this->fix_overflows();

    // create line index variable
    int index = 0;

    // loop through every line
    for (auto line : this->get_lines())
    {
        // print line and update index
        mvwprintw(this->get_window(), index + 1, 1, line.c_str());
        index++;
    }

    // await entry
    wgetch(this->get_window());

    // end window
    endwin();
}