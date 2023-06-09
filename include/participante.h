#ifndef PDS2_PARTICIPANTE_H
#define PDS2_PARTICIPANTE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "armas.h"
#include "utensilios.h"
#include "regiao.h"

using namespace std;

enum regioes{centro, floresta, deserto, pantano, campo, montanhas, ruinas};

class Participante {
    private:
        int _id;
        string _nome;
        bool _vivo;
        int _distrito;
        float _energia;
        float _hidratacao;
        float _ferido;
        Regiao _atual;
        //os dois maps ligam a arma/o utensílio à quantidade que o jogador tem de cada uma
        vector<Arma> _armas;
        map<Utensilio, int> _utensilios;

        Regiao _regiao;

    public:
        /*
         * @brief um participante, inicializando os dados
         */
        Participante();
        Participante(string nome, int distrito);

        /*
         * @brief retornam o nome e o distrito, respectivamente, do participante
         */
        string get_nome() const;
        int get_distrito() const;
        Regiao get_atual();
        float get_energia();
        float get_hidratacao();
        float get_ferido();
        void adicionar_arma(Arma arma);
        void adicionar_utensilio(Utensilio utensilio);
        void muda_regiao_atual(int chance_agua, int chance_comida, int chance_arma, int chance_remedio);

        /*
         * @brief retorna uma arma do vector _armas
         */
        Arma escolher_arma();

        /*
         * @brief simula a batalha entre o participante corrente com um outro participante p
         */
        void batalha(Participante p);

        /*
         * @brief retorna o enum com o nome da sua regiao atual 
         */
        regioes get_regiao_atual();


};

#endif