#ifndef RECORDS_H
#define RECORDS_H

#include <fstream>
#include <map>
#include <string>

class Records {
public:
    Records(const std::string& recordsFilePath);
    ~Records();
    bool isPlayerAlreadyRegistered(const std::string& name);
    unsigned getPlayersRanking(const std::string& name);
    void newRecord(const std::string& name, const unsigned score);
    std::map<unsigned, std::string> getScores() const;

private:
    std::string m_records_file_path;
    std::fstream m_records_file;
    std::map<std::string, unsigned> m_names;
    std::map<unsigned, std::string> m_scores;
};

#endif // RECORDS_H
