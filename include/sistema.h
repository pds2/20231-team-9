#ifndef PDS2_SISTEMA_H
#define PDS2_SISTEMA_H

#include "participante.h"
#include "mapa.h"

class participante_ja_existe_e {};
class distrito_invalido_e {};

class Sistema{
    private:
    Mapa _mapa;
    map<string,Participante> _vivos;
    vector<string> _mortos;

    public:
    /*
     * @brief Cria um participante recebendo nome, idade e destrito
     * @throws Lança uma excessão se destrito > 12
     * @throws Lança uma excessão se o participante ja existe
     */
    void criar_participante(string nome, int distrito);
    /*
     * @brief Remove o participante do map de vivos e insere ele
             no vetor com os nomes dos mortos
     */
    void morrer(Participante &fulano);
    /*
     * @brief retorna o mapa com os participantes vivos
     */
    map<string,Participante> get_vivos();
};

#endif