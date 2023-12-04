#include "models/abstractrepo.hpp"

#include <iostream>

AbstractRepo::AbstractRepo() {
    sqlite3_open(getenv("DBNAME"), &_db);
}

AbstractRepo::~AbstractRepo() {
    sqlite3_close(_db);
}

int AbstractRepo::executeInsert(sqlite3 *db, std::string sql) const {
    char *zErrMsg = 0;
    int rc;

    rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &zErrMsg);
    if (rc != SQLITE_OK) {
        std::cout << zErrMsg;
        sqlite3_free(zErrMsg);
        return 0;
    } else {
        return 1;
    }
}

std::vector<std::map<std::string, std::string>> AbstractRepo::executeSelect(sqlite3 *db, std::string sql) const {
    sqlite3_stmt *stmt;
    std::vector<std::map<std::string, std::string>> result;

    // Prepara consulta
    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        return result;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int colCount = sqlite3_column_count(stmt);
        std::map<std::string, std::string> line;

        for (int i = 0; i < colCount; ++i) {
            const char *colName = sqlite3_column_name(stmt, i);
            const char *colValue = reinterpret_cast<const char *>(sqlite3_column_text(stmt, i));

            // Adiciona o par coluna-valor ao mapa
            line[colName] = colValue;
        }

        // Adiciona o mapa ao vetor de resultados
        result.push_back(line);
    }

    // Libera os recursos
    sqlite3_finalize(stmt);
    return result;
}

int AbstractRepo::executeDelete(sqlite3 *db, std::string sql) const {
    char *zErrMsg = 0;
    int rc;

    rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &zErrMsg);
    if (rc != SQLITE_OK) {
        std::cout << zErrMsg;
        sqlite3_free(zErrMsg);
        return 0;
    } else {
        return 1;
    }
}