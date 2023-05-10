#ifndef PDS2_PARTICIPANTE_H
#define PDS2_PARTICIPANTE_H

#include <string>
#include <vector>
#include <map>

#include "armas.h"
#include "utensilios.h"

using namespace std;

enum regioes{centro, floresta, deserto, pantano, campo, montanhas, ruinas};

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
        regioes _atual;
        //os dois maps ligam a arma/o utensílio à quantidade que o jogador tem de cada uma
        map<Arma, int> _armas;
        map<Utensilio, int> _utensilios;

    public:
        Participante(string nome, int idade, int distrito);
        string get_nome() const;
        int get_distrito() const;
        regioes get_atual();
        void muda_regiao_atual(regioes destino);
        void adicionar_arma(Arma arma);
        void adicionar_utensilio(Utensilio utensilio);

};

#endif