#include "../third_party/doctest.h"
#include "../include/jogador.h"

TEST_CASE("Testa a saída quando a ação de um jogador é chamada"){
    cout << "------------------------------------------------------------------" << endl;
    cout << "Saída de imprime_status" << endl;

    Jogador p = Jogador("Maria");
    p.imprime_status();
    cout << "------------------------------------------------------------------" << endl;

    Regiao _floresta(10,10,0,10,regioes::floresta,2,1);
    p.muda_regiao(regioes::floresta);

    Arma _nova_arma = Arma(armas::espada);
    p.adicionar_arma(_nova_arma);

    p.buscar_na_regiao();
    p.buscar_na_regiao();
    p.buscar_na_regiao();

    p.imprime_status();

    cout << "------------------------------------------------------------------" << endl;
}