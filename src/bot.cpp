#include "../include/bot.h"
#include <cstdlib>

Bot::Bot(string nome, int distrito) : Jogador(nome,distrito) {}

// void Bot::definir_acao(set<Participante*> Msm_Regiao_Q_Eu){
//     if (get_hidratacao() < 60){
//         //consumir_utensilios();
//         //A função deve ser específica para cada utensílio,
//         //o bot não faz cin.
//     } 
//     else if (get_energia() < 60){
//         //consumir_utensilios();
//     } else{    
//         int rng = rand() % 10 + 1;
//         if (rng <= 4){
//             buscar_na_regiao();
//         }
//         else if (rng <= 8){
//             //mover
//         }
//         else {
//             //atacar
//         }
//     }
// }