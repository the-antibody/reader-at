#include <ncurses.h>
#include <vector>
#include <string>

class cli
{
    WINDOW *window;
    std::vector<std::string> lines;
    int dimensions[2];

    public:
        cli(std::vector<std::string> lines);
        WINDOW* get_window();
        std::vector<std::string> get_lines();
        void enter();
        void set_dimensions();
        void create_box(std::string filename);
        void fix_overflows();
        void print_lines();
};