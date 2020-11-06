#include "records.h"

Records::Records(const std::string& recordsFilePath)
    : m_records_file_path(recordsFilePath)
{
    m_records_file.open(m_records_file_path, std::fstream::in);
    std::string line;
    if (m_records_file.is_open()) {
        while (std::getline(m_records_file, line)) {
            std::string delimiter = ",";
            std::string name, score;
            size_t pos = 0;
            pos = line.find(delimiter);
            name = line.substr(0, pos);
            line.erase(0, pos + delimiter.length());
            pos = line.find(delimiter);
            score = line.substr(0, pos);
            newRecord(name, std::stoi(score));
        }
        m_records_file.close();
    }
}

Records::~Records()
{
    m_records_file.open(m_records_file_path, std::fstream::out);
    if (m_records_file.is_open()) {
        for (auto it = m_names.cbegin(); it != m_names.cend(); ++it) {
            m_records_file << it->first << "," << it->second << std::endl;
        }
        m_records_file.close();
    }
}

bool Records::isPlayerAlreadyRegistered(const std::string& name)
{
    return m_names.find(name) != m_names.end();
}

unsigned Records::getPlayersRanking(const std::string& name)
{
    auto score_it = m_scores.find(m_names.at(name));
    return std::distance(m_scores.begin(), score_it) + 1;
}

void Records::newRecord(const std::string& name, const unsigned score)
{
    auto name_it = m_names.find(name);
    if (name_it != m_names.end()) {
        if (name_it->second > score) {
            m_scores.erase(name_it->second);
            m_names[name] = score;
            auto existingScore = m_scores.insert(std::pair<unsigned, std::string>(score, name));
            if (!existingScore.second) {
                m_names.erase(existingScore.first->second);
                m_scores[score] = name;
            }
        }
    } else {
        m_names[name] = score;
        auto existingScore = m_scores.insert(std::pair<unsigned, std::string>(score, name));
        if (!existingScore.second) {
            m_names.erase(existingScore.first->second);
            m_scores[score] = name;
        }
    }
}

std::map<unsigned, std::string> Records::getScores() const
{
    return m_scores;
}
