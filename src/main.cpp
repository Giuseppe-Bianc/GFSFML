#include "Game.h"
#include "headers.h"
int main() {
    spdlog::set_pattern(R"(%^[%T] [%l] %v%$)");
    auto console = spdlog::stdout_color_mt("console");
    spdlog::set_default_logger(console);
    Game game;

    game.run();
    SYSPAUSE()
    return 0;
}
