#ifndef PDS2_PARTICIPANTE_H
#define PDS2_PARTICIPANTE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "armas.h"
#include "utensilios.h"
#include "regiao.h"
#include "mapa.h"

using namespace std;

enum regioes{centro, floresta, deserto, pantano, campo, montanhas, ruinas};

class Participante {
    private:
        int _id;
        string _nome;
        int _idade;
        int _distrito;
        float _energia;
        float _hidratacao;
        float _ferido;
        regioes _atual;
        //os dois maps ligam a arma/o utensílio à quantidade que o jogador tem de cada uma
        vector<Arma> _armas;
        map<Utensilio, int> _utensilios;

        Regiao _regiao;

    public:
        /*
         * @brief um participante, inicializando os dados
         */
        Participante(string nome, int idade, int distrito);

        /*
         * @brief retornam o nome e o distrito, respectivamente, do participante
         */
        string get_nome() const;
        int get_distrito() const;
        regioes get_atual();
        void adicionar_arma(Arma arma);
        void adicionar_utensilio(Utensilio utensilio);
        void muda_regiao_atual(regioes destino);

        /*
         * @brief retorna uma arma do vector _armas
         */
        Arma escolher_arma();

        /*
         * @brief simula a batalha entre o participante corrente com um outro participante p
         */
        void batalha(Participante p);


};

#endif