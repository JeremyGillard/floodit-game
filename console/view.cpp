#include "view.h"

View::View(FloodIt& model)
    : m_model(model)
{
}

void View::welcomeMessage()
{
    std::cout << "Welcome to Flood It game !!!\n"
              << std::endl;
    std::cout << std::setw(25) << "[Press Enter to launch]" << std::endl;
}

bool View::squareOrRectangularBoardQuestion()
{
    std::cin.ignore();
    std::cout << "Do you want to play on a rectangular board ? (y/n) : ";
    char response;
    std::cin >> response;
    while (std::tolower(response) != 'y' && std::tolower(response) != 'n') {
        std::cout << "This answear is not correct. Please try again (Y/y or N/n) : ";
        std::cin >> response;
    }
    std::cin.ignore();
    return response == 'y';
}

unsigned View::sizeBoardQuestion(const std::string& concernedDimension)
{
    int sizeBoard { -1 };
    const std::string message { "Sorry, you have to give a number between 6 and 26, please try again" };
    do {
        try {
            std::cout << "What size do you want for the " << concernedDimension << " of your board ? : ";
            sizeBoard = nvs::lineFromKbd<int>();
        } catch (const std::exception& e) {
            std::cout << message << std::endl;
        }
        if (sizeBoard < 6 || sizeBoard > 26)
            std::cout << message << std::endl;
    } while (sizeBoard < 6 || sizeBoard > 26);
    return unsigned(sizeBoard);
}

unsigned View::difficultyQuestion()
{
    int difficulty { -1 };
    const std::string message { "Sorry, you have to give a number between 3 and 8, please try again" };
    do {
        try {
            std::cout << "Which difficulty do you want to choose ?\nIn other words, how many different colors would you like to have on the board (3-8) ? : ";
            difficulty = nvs::lineFromKbd<int>();
        } catch (const std::exception& e) {
            std::cout << message << std::endl;
        }
        if (difficulty < 3 || difficulty > 8)
            std::cout << message << std::endl;
    } while (difficulty < 3 || difficulty > 8);
    return unsigned(difficulty);
}
