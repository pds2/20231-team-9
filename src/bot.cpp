#include "../include/bot.h"
#include <cstdlib>
//#include <random>

Bot::Bot(string nome, Regiao* ponto_partida) : Jogador(nome, ponto_partida) {}

void Bot::definir_acao(set<Participante*> Msm_Regiao_Q_Eu, map<string,Regiao*>* map_regioes){
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
            try{
                consumir_utensilio("remedio",1);
            } catch (quantidade_remedio_invalida_e){
                buscar_na_regiao();
            }
        }
    } 
    else if (get_energia() < 60){
        try{
            consumir_utensilio("comida",1);
        } catch (quantidade_comida_invalida_e){
            try{
                consumir_utensilio("remedio",1);
            } catch (quantidade_remedio_invalida_e){
                buscar_na_regiao();
            }
        }
    } else{    
        std::vector<std::string> regioes = {"centro", "floresta", "deserto", "pantano", "campo", "montanhas", "ruinas", "cavernas", "savana"};

        int rng = rand() % 10 + 1;
        if (rng <= 4){
            buscar_na_regiao();
        }
        else if (rng <= 8){
            if(get_Regiao_Atual()->get_nome_string() != "centro"){
                muda_regiao("centro", map_regioes);
            } else{


                int destino = rand() % 7 + 1;
                muda_regiao(regioes[destino],map_regioes);
            }
        }
        else {
            if (Msm_Regiao_Q_Eu.size()!=0){
                int escolhido = rand() % Msm_Regiao_Q_Eu.size();
                auto adversario = Msm_Regiao_Q_Eu.begin();
                for (int i=0; i < escolhido ; i++){
                    adversario++;
                }
                batalha(**adversario);
            }else buscar_na_regiao();
        }

    }
}