#include <iostream>
#include <utils/console.hh>

int main(int argc, char *argv[])
{
    std::string name, colored_name = "";

    std::cout << "Hey, what's your name?" << std::endl;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    colored_name = utils::console::colorize(
        name,
        utils::console::ForegroundColor::Green,
        utils::console::BackgroundColor::DarkGray,
        utils::console::FormatAttribute::Bold,
        utils::console::ResetFormatAttribute::All);

    std::cout << "Hello, " << colored_name << "!" << std::endl;

    return EXIT_SUCCESS;
}
