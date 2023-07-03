#ifndef PDS2_REGIAO_H
#define PDS2_REGIAO_H

#include <utility>
#include <map>
//#include "participante.h" Essa inclusão cria um loop de includes, e não é utilizado nesse arquivo

enum regioes{centro, floresta, deserto, pantano, campo, montanhas, ruinas, cavernas, savana};

class destino_nao_existe_e {};
class nao_da_para_mudar_para_essa_regiao_e {};

class Regiao{
    private:
    regioes _nome;
    int _x;
    int _y;
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
    Regiao(int chance_agua, int chance_comida, int chance_arma, int chance_remedio, regioes _nome, int x, int y);
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
    regioes get_nome();
    /*
     * @brief Retorna a coordenada x da região 
     */
    int get_x();
    /*
     * @brief Retorna a coordenada y da região 
     */
    int get_y();
    /*
     * @brief Testa se é possível mudar para a região com as
     *        coordenadas recebidas 
     * @param Coordenada x
     * @param Coordenada y
     */
    bool pode_mudar_de_regiao(int x, int y);
    /*
     * @brief Converte o enum para as Coordenadas das regiões
     * 
     * @param enum da região
     * 
     * @throws lança um erro se o destino não existir
     * @throws lança um erro se nao for possivel mudar para
     *         a regiao solicitada 
     */
    void muda_regiao(regioes destino);
};

#endif