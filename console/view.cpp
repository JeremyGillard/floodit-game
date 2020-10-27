#include "view.h"

View::View(FloodIt& model)
    : m_model(model)
{
    getViewDimensions();
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

unsigned View::colorQuestion() // TODO
{
    int color { -1 };
    const std::string message { "Sorry, you have to give a number between 1 and (color diff), please try again" }; // A CHANGER *****************
    do {
        try {
            std::cout << "Which color do you want to pick ? : ";
            color = nvs::lineFromKbd<int>();
        } catch (const std::exception& e) {
            std::cout << message << std::endl;
        }
        if (color < 1 || color > static_cast<int>(m_model.chosenDifficulty()))
            std::cout << message << std::endl;
    } while (color < 1 || color > static_cast<int>(m_model.chosenDifficulty()));
    return unsigned(color);
}

void View::displayBoard() const
{
    std::cout << std::endl;
    for (unsigned i = 0; i < m_model.chosenHeight(); ++i) {
        for (unsigned j = 0; j < m_model.chosenWidth(); ++j) {
            std::cout << std::setw(3) << m_model.getColorAt(i, j);
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << m_model.getNumberOfMoves() << " moves" << std::endl;
    std::cout << std::endl;
}

void View::endMessage() const
{
    displayBoard();
    std::cout << "\nCongratulation!\n"
              << std::endl;
}

void View::getViewDimensions()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    m_viewHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    m_viewWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
}
