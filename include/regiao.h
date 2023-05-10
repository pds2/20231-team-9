#ifndef PDS2_REGIAO_H
#define PDS2_REGIAO_H

#include <map>
#include "participante.h"


class Regiao{
    private:
    map<string,Participante*> _regiao;
    int _chance_agua;
    int _chance_comida;
    int _chance_arma;

    public:
    /*
    * @brief Construtor Padrao
    */
    Regiao();
    /*
    * @brief Construtor
    */
    Regiao(int chance_agua, int chance_comida, int chance_arma);
    /*
    * @brief Retorna chance de agua
    */
    int get_chance_agua();
    /*
    * @brief Retorna chance de comida
    */
    int get_chance_comida();
    /*
    * @brief Retorna chance de arma
    */
    int get_chance_arma();
    /*
    * @brief Insere participante na regiao
    */
    void inserir_participante(Participante *fulano);
    /*
    * @brief Remove participante da regiao
    */
    void remover_participante(Participante *fulano);

};

#endif