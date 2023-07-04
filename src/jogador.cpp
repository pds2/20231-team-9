#include "../include/jogador.h"

#include <iostream>
#include <string>
#include <set>

using namespace std;

Jogador::Jogador(string nome) : Participante(nome) { }

void Jogador::definir_acao(set<Participante*> Msm_Regiao_Q_Eu) {
    cout << endl << "---------------------------------------------------------------------------" << endl;
    cout << get_nome() << ", é sua vez de jogar!" << endl;
    imprime_status(Msm_Regiao_Q_Eu);
    char comando;
    string escolha;
    bool encontrou = 0;
    cin >> comando;
    switch (comando){
        case 'a': //atacar
            cin >> escolha;
            for (auto pessoa : Msm_Regiao_Q_Eu){
                if (pessoa->get_nome() == escolha) batalha(*pessoa);
                encontrou = 1;
            }
            if(encontrou == 0){
                cout << "Jogador nao encontrado" << endl;
            }
            //throw comando_invalido_e{};
            break;

        case 'm': //mover
        // !! ADICIONEI O CÓDIGO DAQUI 
            cout << "Digite o nome da região para onde você quer ir:" << endl;
            while(1) {
                cin >> escolha;
                try {
                    return muda_regiao(escolha);
                } catch (regiao_invalida_e &e) {
                    cout << "Entrada inválida! Essa região não existe. Digite novamente" << endl; 
                }

            }
        // !! ADICIONEI O CÓDIGO ATÉ AQUI
            break;

        case 'b': //buscar elementos
            buscar_na_regiao();
            break;
        case 'u': //usar utensílio
            cin >> escolha;
            if ((escolha == "agua") || (escolha == "remedio") || escolha == "comida"){
                consumir_utensilio(escolha, 1);
            } else {
                throw comando_invalido_e{};
            }
            break;

        /*┌──────────────────────┬───────────────────────┬────────────────────┐
│░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░░░░░░░░│
│░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░░░░░░░░│
│░░░░░░░░░░░░░░░░░░░░░░└┐░░░░░░░░░░░░░░░░░░░░░┌┘░░░░░░░░░░░░░░░░░░░░│
│░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░░░░░░░░░│
│░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░░░░░░░░┌┘░░░░░░░░░░░░░░░░░░░░░│
│░░░░░░░░░░░░░░░░░░░░░░░└┐░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░░░░░░░░░░│
│░░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░░░░░░┌┘░░░░░░░░░░░░░░░░░░░░░░│
│░░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░░░░░░░░░░░│
│░░░░░░░░░░░░░░░░░░░░░░░░└┐░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░░░░░░░░░░░│
│░░░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░░░░┌┘░░░░░░░░░░░░░░░░░░░░░░░│
│░░░░░░░░░░░░░░░░░░░░░░░░░├────────────────┤░░░░░░░░░░░░░░░░░░░░░░░░│
│░░░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░░░░░░░░░░░░│
├─────────────────────────┤░░░░░░░░░░░░░░░░├────────────────────────┤
│░░░░░░░░░░░░░░░░░░░░░░░░░├────────────────┤░░░░░░░░░░░░░░░░░░░░░░░░│
│░░░░░░░░░░░░░░░░░░░░░░░░┌┘░░░░░░░░░░░░░░░░└┐░░░░░░░░░░░░░░░░░░░░░░░│
│░░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░░░░░░░░░░░│
│░░░░░░░░░░░░░░░░░░░░░░░┌┘░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░░░░░░░░░░░│
│░░░░░░░░░░░░░░░░░░░░░░┌┘░░░░░░░░░░░░░░░░░░░└┐░░░░░░░░░░░░░░░░░░░░░░│
│░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░░░░░░░░░░│
│░░░░░░░░░░░░░░░░░░░░░┌┘░░░░░░░░░░░░░░░░░░░░░└┐░░░░░░░░░░░░░░░░░░░░░│
│░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░░░░░░░░░│
│░░░░░░░░░░░░░░░░░░░░┌┘░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░░░░░░░░░│
│░░░░░░░░░░░░░░░░░░░┌┘░░░░░░░░░░░░░░░░░░░░░░░░└┐░░░░░░░░░░░░░░░░░░░░│
│░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░░░░░░░░│
│░░░░░░░░░░░░░░░░░░┌┘░░░░░░░░░░░░░░░░░░░░░░░░░░└┐░░░░░░░░░░░░░░░░░░░│
│░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░░░░░░░░░░░░░░░░│░░░░░░░░░░░░░░░░░░░│
│░░░░░░░░░░░░░░░░░┌┘░░░░░░░░░░░░░░░░░░░░░░░░░░░░└┐░░░░░░░░░░░░░░░░░░│
└─────────────────┴──────────────────────────────┴──────────────────┘
*/
    }
}

void Jogador::imprime_status(set<Participante*> Msm_Regiao_Q_Eu) {
    cout << "STATUS:" << endl;
    cout << "Energia: " << get_energia() << "/100" << endl;
    cout << "Hidratação: " << get_hidratacao() << "/100" << endl;

    cout << "Você está na região " << get_Regiao_Atual().get_nome() << "." << endl << endl;
    cout << "Estão na mesma região que você:" << endl;
    for (auto i: Msm_Regiao_Q_Eu){
        cout << i->get_nome() << endl;
    }

    cout << "Seu inventário:" << endl;
    imprime_qntd_utensilios();
    cout << "Arma: " << get_arma().get_tipo() << endl << endl;

    cout << "Defina sua ação!" << endl;
    cout << "Mover: Muda para outra região." << endl;
    cout << "Atacar: Batalha com outro participante." << endl;
    cout << "Buscar: Procura por recursos na região." << endl;
    cout << "Usar: Consome um item." << endl << endl;
}