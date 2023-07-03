#include "../include/jogador.h"

#include <iostream>
#include <string>
#include <set>

using namespace std;

Jogador::Jogador(string nome, int distrito) : Participante(nome, distrito) { }

void Jogador::definir_acao(set<Participante*> Msm_Regiao_Q_Eu) {
    cout << endl << "---------------------------------------------------------------------------" << endl;
    cout << get_nome() << ", é sua vez de jogar!" << endl;
    imprime_status();
    char comando;
    string escolha;
    cin >> comando;
    switch (comando){
        case 'a': //atacar
            cin >> escolha;

            break;
        case 'm': //mover
            //muda_regiao_atual(destino);
            break;

        case 'b': //buscar elementos
            buscar_na_regiao();
            break;
        case 'u': //usar utensílio
            cin >> escolha;
            consumir_utensilio(escolha, 1);
            break;
    }
}

void Jogador::imprime_status() {
    cout << "STATUS:" << endl;
    cout << "Energia: " << get_energia() << "/100" << endl;
    cout << "Hidratação: " << get_hidratacao() << "/100" << endl;

    cout << "Você está na região " << get_atual().get_nome() << "." << endl << endl;

    cout << "Seu inventário:" << endl;
    imprime_qntd_utensilios();
    cout << "Arma: " << get_arma().get_tipo() << endl << endl;

    cout << "Defina sua ação!" << endl;
    cout << "Mover: Muda para outra região." << endl;
    cout << "Atacar: Batalha com outro participante." << endl;
    cout << "Buscar: Procura por recursos na região." << endl;
    cout << "Usar: Consome um item." << endl << endl;
    cout << "Comando: ";
}