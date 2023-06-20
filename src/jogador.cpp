#include "../include/jogador.h"

#include <iostream>
#include <string>

using namespace std;

Jogador::Jogador(string nome, int distrito) : Participante(nome, distrito) { }

void Jogador::definir_acao() {
    char comando;
    cin >> comando;
    switch (comando){
        case 'a': //atacar
        
            break;
        case 'm': //mover
            //muda_regiao_atual(destino);
            break;

        case 'b': //buscar elementos
            buscar_na_regiao();
            break;
        case 'u': //usar utensílio
            
            break;
    }
}