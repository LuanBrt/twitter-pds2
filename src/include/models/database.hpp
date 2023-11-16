#include <sqlite3.h>
#include <map>
#include <string>

class Database {
public:
    /// @brief Destrutor padrao
    Database();

    /// @brief Construtor padrao
    ~Database();

    /// @brief Comando para criar o banco de dados e todas as tabelas nele
    void createDb();

    /// @brief Comando para criar uma tabela no banco de dados
    /// @param tableName Nome da tabela
    /// @param attributes mapa contendo nome do atributo e restricoes do mesmo
    void createTable(std::string tableName, std::map<std::string, std::string> attributes);
private:
    sqlite3 *_db;
};