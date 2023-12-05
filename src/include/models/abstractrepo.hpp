#pragma once

#include <string>
#include <map>
#include <vector>
#include <sqlite3.h>

namespace repo {
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

        /// @brief Executa uma operação SELECT no banco de dados
        /// @param db Conexão com o banco de dados
        /// @param sql Comando SELECT a ser executado
        /// @return Retorna um vetor com o resultado da busca
        virtual std::vector<std::map<std::string, std::string>> executeSelect(sqlite3 *db, std::string sql) const;

        /// @brief Executa uma operação DELETE no banco de dados
        /// @param db Conexão com o banco de dados
        /// @param sql Comando DELETE a ser executado
        /// @return Retorna 1 se a operação DELETE foi bem-sucedida, caso contrário, retorna 0
        int executeDelete(sqlite3 *db, std::string sql) const;
    protected:
        sqlite3 *_db;
    };
}

