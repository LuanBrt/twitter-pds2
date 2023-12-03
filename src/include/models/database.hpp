#include <sqlite3.h>
#include <map>
#include <string>

class Database {
public:
    /// @brief Destrutor padrao.
    Database();

    /// @brief Construtor padrao.
    ~Database();

    /// @brief Comando para criar o banco de dados e todas as tabelas.
    void createDb();

    /// @brief Comando para criar uma tabela no banco de dados.
    /// @param tableName Nome da tabela.
    /// @param sql mapa contendo nome do atributo e restricoes do mesmo.
    void createTable(std::string tableName, std::string sql);
private:
    sqlite3 *_db;
};