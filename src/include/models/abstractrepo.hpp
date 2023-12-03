#pragma once

#include <string>
#include <map>
#include <vector>
#include <sqlite3.h>

class AbstractRepo {
public:
    /// @brief Construtor padrao
    AbstractRepo();

    /// @brief Destrutor padrao
    ~AbstractRepo();

    /// @brief Executa um insert sql
    /// @param db Conexao com banco de dados
    /// @param sql Insert a ser executada
    /// @return Um inteiro representando sucesso ou falha na execucao do insert
    virtual int executeInsert(sqlite3 *db, std::string sql) const;

    /// @brief Executa um select sql
    /// @param db Conexao com banco de dados
    /// @param sql Select a ser executada
    /// @return Um mapa contendo as informações obtidas no select
    virtual std::vector<std::map<std::string, std::string>> executeSelect(sqlite3 *db, std::string sql) const;
protected:
    sqlite3 *_db;
};

