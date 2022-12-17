#include <gtest/gtest.h>
#include <utils/console.hh>

namespace
{
    TEST(console, colorize)
    {
        auto result = utils::console::colorize(
            "Hello, world!",
            utils::console::ForegroundColor::Green,
            utils::console::BackgroundColor::DarkGray,
            utils::console::FormatAttribute::Bold,
            utils::console::ResetFormatAttribute::All);
        auto expected = "\033[1;32;100mHello, world!\033[0m";

        EXPECT_EQ(result, expected);
    };
}
