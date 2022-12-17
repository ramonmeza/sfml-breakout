#include <string>

namespace utils::console
{
    enum class FormatAttribute
    {
        Default = 0,
        Bold = 1,
        Dim = 2,
        Italics = 3,
        Underlined = 4,
        Blink = 5,
        Revers = 7,
        Hidden = 8
    };

    enum class ForegroundColor
    {
        Default = 39,
        Black = 30,
        Red = 31,
        Green = 32,
        Yellow = 33,
        Blue = 34,
        Magenta = 35,
        Cyan = 36,
        LightGray = 37,
        DarkGray = 90,
        LightRed = 91,
        LightGreen = 92,
        LightYellow = 93,
        LightBlue = 94,
        LightMagenta = 95,
        LightCyan = 96,
        White = 9
    };

    enum class BackgroundColor
    {
        Default = 49,
        Black = 40,
        Red = 41,
        Green = 42,
        Yellow = 43,
        Blue = 44,
        Megenta = 45,
        Cyan = 46,
        LightGray = 47,
        DarkGray = 100,
        LightRed = 101,
        LightGreen = 102,
        LightYellow = 103,
        LightBlue = 104,
        LightMagenta = 105,
        LightCyan = 106,
        White = 107
    };

    enum class ResetFormatAttribute
    {
        All = 0,
        Bold = 21,
        Dim = 22,
        Underlined = 24,
        Blink = 25,
        Reverse = 27,
        Hidden = 28
    };

    std::string colorize(
        const std::string &text,
        ForegroundColor foreground = ForegroundColor::Default,
        BackgroundColor background = BackgroundColor::Default,
        FormatAttribute format_attr = FormatAttribute::Default,
        ResetFormatAttribute reset_attr = ResetFormatAttribute::All);
}
