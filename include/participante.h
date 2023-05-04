#ifndef PDS2_PARTICIPANTE_H
#define PDS2_PARTICIPANTE_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "armas.h"
#include "utensilios.h"

using namespace std;

class Participante {
    private:
        int _id;
        string _nome;
        int _idade;
        bool _vivo;
        int _distrito;
        float _energia;
        float _hidratacao;
        float _ferido;
        //os dois maps ligam a arma/o utensílio à quantidade que o jogador tem de cada uma
        vector<Arma> _armas;
        map<Utensilio, int> _utensilios;

    public:
        Participante(string nome, int idade, int distrito);
        string get_nome() const;
        int get_distrito() const;
        void morreu();
        void adicionar_arma(Arma arma);
        void adicionar_utensilio(Utensilio utensilio);

        Arma escolher_arma();
        void batalha(Participante p);

};

#endif