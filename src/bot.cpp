#include "../include/bot.h"
#include <cstdlib>
//#include <random>

Bot::Bot(string nome) : Jogador(nome) {}

void Bot::definir_acao(set<Participante*> Msm_Regiao_Q_Eu){
    if (get_energia() <= 0){
        morrer();
        std::cout << get_nome() << " morreu de fome." << endl;
        return;
    }
    if (get_hidratacao() <= 0){
        morrer();
        std::cout << get_nome() << " morreu de sede." << endl;
        return;
    }

    if (get_hidratacao() < 60){
        try{
            consumir_utensilio("agua",1);
        } catch (quantidade_agua_invalida_e){
            buscar_na_regiao();
        }
    } 
    else if (get_energia() < 60){
        try{
            consumir_utensilio("comida",1);
        } catch (quantidade_comida_invalida_e){
            buscar_na_regiao();
        }
    } else{    
        int rng = rand() % 10 + 1;
        if (rng <= 4){
            buscar_na_regiao();
        }
        else if (rng <= 8){
            if(get_Regiao_Atual().get_nome() != centro){
                muda_regiao("centro");
            } else{
                int destino = rand() % 7 + 1;
                muda_regiao(regioes(destino));
            }
        }
        else {
            int escolhido = rand() % Msm_Regiao_Q_Eu.size();
            auto adversario = Msm_Regiao_Q_Eu.begin();
            for (int i=0; i < escolhido ; i++){
                adversario++;
            }
            batalha(**adversario);
        }

    }
}