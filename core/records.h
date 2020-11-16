#ifndef RECORDS_H
#define RECORDS_H

#include <fstream>
#include <map>
#include <string>

class Records {
public:
    /**
     * @brief Records allows to construct a Records panel. This will be used
     * during the game to record new scores if the players wish to do so.
     * This class will also allow to retrieve information about a certain
     * scoreboard from a possible pre-existing file.
     *
     * @param recordsFilePath the name of the possible pre-existing file or the
     * file wich will register the futures scores.
     */
    Records(const std::string& recordsFilePath);

    /**
     * @brief the desctructeur of this class will save in the file indicated in
     * the constructor the last records created during the current execution
     * of the game.
     */
    ~Records();

    /**
     * @brief isPlayerAlreadyRegistered indicates if a player is already register
     * in the score panel.
     *
     * @param name the player's username.
     * @return true if the user is already register under this username.
     */
    bool isPlayerAlreadyRegistered(const std::string& name);

    /**
     * @brief getPlayersRanking returns the ranking of a given username.
     *
     * @param name the username researched.
     */
    unsigned getPlayersRanking(const std::string& name);

    /**
     * @brief newRecord allows to register a new score in the score panel.
     * If the player already exists, a check of the already existing score will
     * be done to see if the last referenced score is better.
     * If it is the case, the user's score will be replaced.
     * If another person has already indicated an identical score in the
     * scoreboard, this one will be replaced in order to create a dynamic
     * competition between the different players.
     *
     * @param name the username linked to the score entered.
     * @param score the score linked to the username entered.
     */
    void newRecord(const std::string& name, const unsigned score);

    /**
     * @brief getScores returns the hash map of the score.
     *
     * @return the hash map of the score.
     */
    std::map<unsigned, std::string> getScores() const;

private:
    std::string m_records_file_path;
    std::fstream m_records_file;
    std::map<std::string, unsigned> m_names;
    std::map<unsigned, std::string> m_scores;
};

#endif // RECORDS_H
