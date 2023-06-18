#include "../third_party/doctest.h"
#include "../include/jogador.h"

TEST_CASE("Testa se o personagem está na região correta") {
    Participante& p = Jogador("Maria", 8);
    CHECK(p.get_atual().get_nome() == regioes::centro);
    CHECK(p.get_distrito() == 8);
    CHECK(p.get_energia() == 100.0);
    CHECK(p.get_hidratacao() == 100.0);

    Regiao _floresta(8,7,2,0,regioes::floresta);
    p.muda_regiao_atual(_floresta);
    CHECK(p.get_atual().get_nome() == regioes::floresta);

    Arma _nova_arma = Arma(armas::espada, 3);
    p.adicionar_arma(_nova_arma);
    CHECK(p.get_arma().get_tipo() == armas::espada);

    Participante& p2 = Jogador("Pedro", 2);
    Arma _nova_arma2 = Arma(armas::faca, 1);
    p2.adicionar_arma(_nova_arma2);
    p.batalha(p2);
    CHECK(p2.get_vivo() == false);
    CHECK(p.get_energia() == p.get_energia() * p2.get_arma().get_poder() * 0.9);

    
}