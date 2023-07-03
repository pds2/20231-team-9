#ifndef PDS2_PARTICIPANTE_H
#define PDS2_PARTICIPANTE_H

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>

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
        Regiao _regiao_atual;
        Arma _arma;
        int qntd_agua;
        int qntd_comida;
        int qntd_remedio;

    public:
        /*
         * @brief um participante, inicializando os dados
         */
        Participante(string nome, int distrito);
        /**
         * @brief Retorna o nome do participante
        */
        string get_nome() const;
        /**
         * @brief Retorna o distrito do participante
        */
        int get_distrito() const;
        /**
         * @brief Retorna 'True' se o participante está vivo e 'False'
         *        se ele está morto
        */
        bool get_vivo() const;
        /**
         * @brief Retorna a quantidade de energia do participante
        */
        float get_energia();
        /**
         * @brief Retorna a hidratação do participante
        */
        float get_hidratacao();
        /**
         * @brief Retorna a Arma do participante
        */
        Arma get_arma();
        /**
         * @brief Adiciona uma arma para o participante
         * 
         * @param arma
        */
        void adicionar_arma(Arma arma);
        /**
         * @brief Muda a região do participante
         * 
         * @param destino
        */
        void muda_regiao(regioes destino);
        /**
         * @brief Define a ação do participante
         * 
         * @param Msm_Regiao_Q_Eu
        */
        virtual void definir_acao(set<Participante*> Msm_Regiao_Q_Eu) = 0;
        /*
         * @brief simula a batalha entre o participante corrente com um outro participante p
         */
        void batalha(Participante& p);
        /**
         * @brief Retorna a regiao atual do participante
        */
        Regiao get_Regiao_Atual();
        /**
         * @brief Imprime a quantidade de utensílios do participante
        */
        void imprime_qntd_utensilios();
        /**
         * @brief Adiciona utensílios ao participante
         * 
         * @param utelsilio
         * @param qntd
        */
        void adicionar_utensilio(std::string utensilio, int qntd);
        // void adicionar_utensilio_agua(int a_consumir);
        // void adicionar_utensilio_comida(int a_consumir);
        // void adicionar_utensilio_remedio(int a_consumir);

        /**
         * @brief Faz o participante consumir um utensilio
         * 
         * @param utensilio
         * @param qntd
        */
        void consumir_utensilio(std::string utensilio, int qntd);
        /**
         * @brief Faz o participante consumir água
         * 
         * @param a_consumir
        */
        void consumir_utensilios_agua(int a_consumir);
        /**
         * @brief Faz o participante consumir comida
         * 
         * @param a_consumir
        */
        void consumir_utensilios_comida(int a_consumir);
        /**
         * @brief Faz o participante comsumir remédio
         * 
         * @param a_consumir
        */
        void consumir_utensilios_remedio(int a_consumir);
        /**
         * @brief Efetua uma busca na região atual do participante
        */
        void buscar_na_regiao();

};

#endif