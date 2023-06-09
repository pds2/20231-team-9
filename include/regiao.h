#ifndef PDS2_REGIAO_H
#define PDS2_REGIAO_H

#include <map>
#include "participante.h"

enum regioes{centro, floresta, deserto, pantano, campo, montanhas, ruinas};

class Regiao{
    private:
    regioes _nome;
    int _chance_agua;
    int _chance_comida;
    int _chance_arma;
    int _chance_remedio;

    public:
    /*
     * @brief Construtor Padrao
     */
    Regiao();
    /*
     * @brief Construtor
     */
    Regiao(int chance_agua, int chance_comida, int chance_arma, int chance_remedio, regioes _nome);
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
    * @brief Retorna chance de remedio
    */
    int get_chance_remedio();
    /*
     * @brief Retorna o enum com o nome da regiao
     */
    regioes Regiao::get_nome();

};

#endif