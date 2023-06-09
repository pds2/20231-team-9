#ifndef PDS2_REGIAO_H
#define PDS2_REGIAO_H

#include <map>
#include "participante.h"

class participante_nao_esta_aq_e{};

class Regiao{
    private:
    map<string,Participante*> _regiao;
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
    Regiao(int chance_agua, int chance_comida, int chance_arma, int chance_remedio);
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
    * @brief Retorna um map com os participantes na região
    */
    map<string,Participante*> get_participantes();
    /*
     * @brief Insere participante na regiao
     */
    void inserir_participante(Participante *fulano);
    /*
    * @brief Confere se o participante está nessa região
    */
    bool conferir_participante(string nome);
    /*
     * @brief Remove participante da regiao
     * @throws Lança uma exceção se o participante não
     *         está nessa região
     */
    void remover_participante(Participante *fulano);

};

#endif