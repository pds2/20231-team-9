#ifndef PDS2_PARTICIPANTE_H
#define PDS2_PARTICIPANTE_H

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

#include "armas.h"
// #include "utensilios.h"
#include "regiao.h"

using namespace std;

// class utensilio_nao_listado_e {};
class Participante {
    private:
        int _id;
        string _nome;
        bool _vivo;
        int _distrito;
        float _energia;
        float _hidratacao;
        Regiao _atual;
        //os dois maps ligam a arma/o utensílio à quantidade que o jogador tem de cada uma
        // vector<Arma> _armas;
        Arma *_arma;
        int qntd_agua;
        int qntd_comida;
        int qntd_remedio;
        // map<Utensilio, int> _utensilios;

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
        bool get_vivo() const;
        Regiao get_atual();
        float get_energia();
        float get_hidratacao();
        Arma get_arma();
        void adicionar_arma(Arma arma);
        void adicionar_utensilio();
        // void adicionar_utensilio(Utensilio utensilio);
        void muda_regiao_atual(Regiao destino);

        
        virtual void definir_acao() = 0;
        /*
         * @brief simula a batalha entre o participante corrente com um outro participante p
         */
        void batalha(Participante& p);

        /*
         * @brief retorna o enum com o nome da sua regiao atual 
         */
        regioes get_regiao_atual();

        void consumir_utensilios();

        void buscar_na_regiao();

};

#endif