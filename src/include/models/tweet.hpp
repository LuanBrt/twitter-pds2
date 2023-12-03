#pragma once
#include <string>
#include <vector>
#include "models/user.hpp"

class Tweet {
public:
    /// @brief Construtor padrão
    /// @param authorId Identificador único do autor do tweet.
    /// @param description Descrição do tweet.
    /// @param timestamp Tempo de publicação do tweet.
    /// @param likes Quantidade de likes do tweet.
    Tweet(int authorId, std::string description, std::string timestamp, int likes): 
        _authorId(authorId), _description(description), _timestamp(timestamp), _likes(likes) {};

    /// @brief Construtor padrão
    /// @param id Id do tweet.
    /// @param authorId Identificador único do autor do tweet.
    /// @param description Descrição do tweet.
    /// @param timestamp Tempo de publicação do tweet.
    /// @param likes Quantidade de likes do tweet.
    Tweet(int id, int authorId, std::string description, std::string timestamp, int likes):
        _id(id), _authorId(authorId), _description(description), _timestamp(timestamp), _likes(likes) {};

    /// @brief Retorna o identificador único associado ao tweet.
    /// @return Retorna o identificador único associado ao tweet.
    int id();

    /// @brief Retorna o autor do tweet. Cria uma instância de User consultando o repositório de usuários (UserRepo) com base no identificador do autor (_authorId).
    /// @return Retorna o autor do tweet.
    User author();

    /// @brief Retorna a descrição do tweet.
    /// @return Retorna a descrição do tweet.
    std::string description();

    /// @brief Retorna o carimbo de data/hora associado ao tweet.
    /// @return Retorna o carimbo de data/hora associado ao tweet.
    std::string timestamp();

    /// @brief Retorna a quantidade de curtidas que o tweet recebeu.
    /// @return Retorna a quantidade de curtidas que o tweet recebeu.
    int likes();

    /// @brief Função para recuperar um tweet específico por seu identificador a partir de um vetor de tweets.
    /// @param id Identificador do tweet desejado.
    /// @param tweets Vetor de tweets no qual a busca será realizada.
    /// @return 'Tweet' Retorna o tweet correspondente ao identificador fornecido ou um tweet "vazio" (com atributos não garantidos) caso não seja encontrado.
    Tweet getTweetById(int id, std::vector<Tweet> tweets);

private:
    int _id;
    int _authorId;
    std::string _description;
    std::string _timestamp;
    int _likes;
};
