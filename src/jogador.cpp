#include "../include/jogador.h"

#include <iostream>
#include <string>

using namespace std;

Jogador::Jogador(string nome, int distrito) : Participante(nome, distrito) { }

void Jogador::definir_acao(){
    string comando;
    cin >> comando;
}