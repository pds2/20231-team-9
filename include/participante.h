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

// Classes dos erros
class quantidade_agua_invalida_e {};
class quantidade_comida_invalida_e {};
class quantidade_remedio_invalida_e {};
class utensilio_invalido_e {};

class Participante {
    private:
        int _id;
        string _nome;
        bool _vivo;
        int _distrito;
        float _energia;
        float _hidratacao;
        Regiao _atual;
        Arma _arma;
        int qntd_agua;
        int qntd_comida;
        int qntd_remedio;

    public:
        /*
         * @brief um participante, inicializando os dados
         */
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

        void imprime_qntd_utensilios();

        void adicionar_utensilio(std::string utensilio, int qntd);
        // void adicionar_utensilio_agua(int a_consumir);
        // void adicionar_utensilio_comida(int a_consumir);
        // void adicionar_utensilio_remedio(int a_consumir);

        void consumir_utensilio(std::string utensilio, int qntd);
        void consumir_utensilios_agua(int a_consumir);
        void consumir_utensilios_comida(int a_consumir);
        void consumir_utensilios_remedio(int a_consumir);

        void buscar_na_regiao();

};

#endif