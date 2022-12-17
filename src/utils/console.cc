#include <utils/console.hh>

std::string utils::console::colorize(
    const std::string &text,
    ForegroundColor foreground,
    BackgroundColor background,
    FormatAttribute format_attr,
    ResetFormatAttribute reset_attr)
{
    //"\033[{FORMAT_ATTRIBUTE};{FORGROUND_COLOR};{BACKGROUND_COLOR}m{TEXT}\033[{RESET_FORMAT_ATTRIBUTE}m"
    return "\033[" + std::to_string((int)format_attr) + ";" + std::to_string((int)foreground) + ";" + std::to_string((int)background) + "m" + text + "\033[" + std::to_string((int)reset_attr) + "m";
}
