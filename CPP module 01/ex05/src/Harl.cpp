#include "../includes/Harl.hpp"

void Harl::debug( void ) {
    std::cout << "[DEBUG]" << std::endl;
    std::cout << "I love having extra bacon for my "
    "7XL-double-cheese-triple-pickle-special-ketchup burger. "
    "I really do!" << std::endl;
}

void Harl::info( void ) {
    std::cout << "[INFO]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. "
    "You didnt put enough bacon in my burger! "
    "If you did, I wouldnt be asking for more!" << std::endl;
}

void Harl::warning( void ) {
    std::cout << "[WARNING]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. "
    "Ive been coming for years whereas you "
    "started working here since last month." << std::endl;
}

void Harl::error( void ) {
    std::cout << "[ERROR]" << std::endl;
    std::cout << "This is unacceptable! "
    "I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level ) {
    typedef void (Harl::*level_function)();
    level_function functions[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[] = {"debug", "info", "warning", "error"};

    for (int i = 0; i < 4; i++) {
        if (level == levels[i]) {
            (this->*functions[i])();
        }
    }
}
