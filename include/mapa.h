#ifndef PDS2_MAPA_H
#define PDS2_MAPA_H

#include "participante.h"
#include "regiao.h"

class participante_ja_existe_e {};
class idade_invalido_e {};
class distrito_invalido_e {};
class destino_invalido_e{};

class Mapa {
    private:
        vector <string> _td_mundo;
        vector<string> _centro;
        vector<string> _floresta;
        vector<string> _deserto;
        vector<string> _pantano;
        vector<string> _campo;
        vector<string> _montanhas;
        vector<string> _ruinas;

    public:
    /*
    * @brief Construtor
    */
    Mapa();
    /**
     * @brief retorna um vetor embaralhado com todo mundo
    */
   vector<string> get_td_mundo();
    /*
    * @brief retorna um vetor embaralhado com os participantes no centro
    */
    vector<string> get_participantes_centro();
    /*
    * @brief retorna um vetor embaralhado com os participantes na floresta
    */
    vector<string> get_participantes_floresta();
    /*
    * @brief retorna um vetor embaralhado com os participantes no deserto
    */
    vector<string> get_participantes_deserto();
    /*
    * @brief retorna um vetor embaralhado com os participantes no pantano
    */
    vector<string> get_participantes_pantano();
    /*
    * @brief retorna um vetor embaralhado com os participantes no campo
    */
    vector<string> get_participantes_campo();
    /*
    * @brief retorna um vetor embaralhado com os participantes nas montanhas
    */
    vector<string> get_participantes_montanhas();
    /*
    * @brief retorna um vetor embaralhado com os participantes nas ruínas
    */
    vector<string> get_participantes_ruinas();
    /*
    * @brief Inicia o Jogo colocando os participantes no Centro
    */
    void inicio(map<string,Participante&> vivos);
    /*
    * @brief Remove o participante do map de vivos e insere ele
             no vetor com os nomes dos mortos
    */
    void morrer(Participante* fulano);
    /*
    * @brief Move um participante para o Centro
    * @throws Lança uma excessão se o destino for invalido
    */
    void mover_do_centro(regioes destino, Participante* fulano);
    /*
    * @brief move um participante para a Floresta
    * @throws Lança uma excessão se o destino for invalido
    */
    void mover_da_floresta(regioes destino, Participante* fulano);
    /*
    * @brief move um participante para o Deserto
    * @throws Lança uma excessão se o destino for invalido
    */
    void mover_do_deserto(regioes destino, Participante* fulano);
    /*
    * @brief move um participante para o Pantano
    * @throws Lança uma excessão se o destino for invalido
    */
    void mover_do_pantano(regioes destino, Participante* fulano);
    /*
    * @brief move um participante para o Campo
    * @throws Lança uma excessão se o destino for invalido
    */
    void mover_do_campo(regioes destino, Participante* fulano);
    /*
    * @brief move um participante para as Montanhas
    * @throws Lança uma excessão se o destino for invalido
    */
    void mover_das_montanhas(regioes destino, Participante* fulano);
    /*
    * @brief move um participante para as Ruínas
    * @throws Lança uma excessão se o destino for invalido
    */
    void mover_das_ruinas(regioes destino, Participante* fulano);
};

#endif