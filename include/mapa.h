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
    map<string,Participante> _vivos;
    vector<string> _mortos;
    Regiao _centro;
    Regiao _floresta;
    Regiao _deserto;
    Regiao _pantano;
    Regiao _campo;
    Regiao _montanhas;
    Regiao _ruinas;

    public:
    /*
    * @brief Construtor
    */
    Mapa();
    map<string, Participante> get_map_vivos();
    Regiao get_centro();
    Regiao get_floresta();
    Regiao get_deserto();
    Regiao get_pantano();
    Regiao get_campo();
    Regiao get_montanhas();
    Regiao get_ruinas();
    /*
    * @brief retorna um vetor com o nome dos participantes vivos 
    */
    vector<string> get_vivos();
    /*
    * @brief retorna um map com os participantes no centro
    */
    map<string,Participante*> get_participantes_centro();
    /*
    * @brief retorna um map com os participantes na floresta
    */
    map<string,Participante*> get_participantes_floresta();
    /*
    * @brief retorna um map com os participantes no deserto
    */
    map<string,Participante*> get_participantes_deserto();
    /*
    * @brief retorna um map com os participantes no pantano
    */
    map<string,Participante*> get_participantes_pantano();
    /*
    * @brief retorna um map com os participantes no campo
    */
    map<string,Participante*> get_participantes_campo();
    /*
    * @brief retorna um map com os participantes nas montanhas
    */
    map<string,Participante*> get_participantes_montanhas();
    /*
    * @brief retorna um map com os participantes nas ruínas
    */
    map<string,Participante*> get_participantes_ruinas();
    /*
    * @brief Retorna um vetor com o nome dos participantes mortos
    */
    vector<string> get_mortos();
    /*
    * @brief Cria um participante recebendo nome, idade e destrito
    * @throws Lança uma excessão se a idade <= 15
    * @throws Lança uma excessão se destrito > 12
    * @throws Lança uma excessão se o participante ja existe
    */
    void criar_participante(string nome, int destrito);
    /*
    * @brief Inicia o Jogo colocando os participantes no Centro
    */
    void inicio();
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