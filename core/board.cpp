#include "board.h"

Board::Board(unsigned height, unsigned width, unsigned initializationNumber)
    : m_height { height }
    , m_width { width }
    , m_floodOrigin { 0, 0 }
{

    m_board.reserve(m_height);
    for (unsigned i = 0; i < m_height; ++i) {
        m_board.push_back(std::vector<unsigned>(m_width, initializationNumber));
    }
}

void Board::setDifficulty(unsigned numberOfColor)
{
    std::default_random_engine generator;
    std::uniform_int_distribution<unsigned> distribution(1, numberOfColor);
    m_difficultyLevel = numberOfColor;
    for (unsigned i = 0; i < m_height; ++i) {
        for (unsigned j = 0; j < m_width; ++j) {
            m_board.at(i).at(j) = distribution(generator);
        }
    }
}

unsigned Board::height() const
{
    return m_height;
}

unsigned Board::width() const
{
    return m_width;
}

bool Board::operator==(const Board& board) const
{
    if (board.height() != m_height || board.width() != m_width)
        return false;
    for (unsigned i = 0; i < board.height(); ++i) {
        for (unsigned j = 0; j < board.width(); ++j) {
            if (m_board.at(i).at(j) != board.m_board.at(i).at(j))
                return false;
        }
    }
    return true;
}

unsigned Board::getCurrentColor()
{
    return getColorAt(m_floodOrigin.first, m_floodOrigin.second);
}

unsigned Board::getColorAt(unsigned row, unsigned col) const
{
    return m_board.at(row).at(col);
}

bool Board::pickColor(unsigned newColor)
{
    std::stack<std::pair<unsigned, unsigned>> job;
    job.push(m_floodOrigin);
    unsigned oldColor = m_board.at(m_floodOrigin.first).at(m_floodOrigin.second);
    if (oldColor == newColor)
        return false;
    flood(job, oldColor, newColor);
    return true;
}

void Board::flood(std::stack<std::pair<unsigned, unsigned>>& job, unsigned oldColor, unsigned newColor)
{
    std::stack<std::pair<unsigned, unsigned>> newJob;
    while (job.size() > 0) {
        auto [x, y] = job.top();
        job.pop();

        if (oldColor != m_board.at(x).at(y))
            continue;

        m_board.at(x).at(y) = newColor;

        if (x < m_height - 1 && m_board.at(x + 1).at(y) == oldColor)
            newJob.push(std::make_pair(x + 1, y));

        if (y < m_width - 1 && m_board.at(x).at(y + 1) == oldColor)
            newJob.push(std::make_pair(x, y + 1));

        if (x > 0 && m_board.at(x - 1).at(y) == oldColor)
            newJob.push(std::make_pair(x - 1, y));

        if (y > 0 && m_board.at(x).at(y - 1) == oldColor)
            newJob.push(std::make_pair(x, y - 1));
    }
    if (newJob.size() > 0)
        flood(newJob, oldColor, newColor);
}

unsigned Board::difficultyLevel()
{
    return m_difficultyLevel;
}
