#include "../third_party/doctest.h"
#include "../include/jogador.h"

TEST_CASE("Testa se os atributos de Participante foram corretamente inicializados") {
    Jogador p = Jogador("Maria");
    CHECK_EQ(p.get_Regiao_Atual().get_nome(), regioes::centro);
    CHECK_EQ(p.get_energia(), 100.0);
    CHECK_EQ(p.get_hidratacao(), 100.0);
    //delete p;
}

TEST_CASE("Testa se o personagem está na região correta") {
    Jogador p = Jogador("Maria");
    Regiao _floresta(8,7,2,0,regioes::floresta,2,1);
    p.muda_regiao(regioes::floresta);
    CHECK_EQ(p.get_Regiao_Atual().get_nome(), regioes::floresta);
}

TEST_CASE("Testa se a mudança de arma está ocorrendo corretamente") {
    Jogador p = Jogador("Maria");
    Arma _nova_arma = Arma(armas::espada);
    p.adicionar_arma(_nova_arma);
    CHECK_EQ(p.get_arma().get_tipo(), armas::espada);
}

TEST_CASE("Testa a função batalha") {
    Jogador p = Jogador("Maria");
    Arma _nova_arma = Arma(armas::espada);
    p.adicionar_arma(_nova_arma);

    Jogador p2 = Jogador("Pedro");
    Arma _nova_arma2 = Arma(armas::faca);
    p2.adicionar_arma(_nova_arma2);
    p.batalha(p2);
    CHECK_EQ(p2.get_vivo(), false);
    CHECK_EQ(p.get_energia(), 60);
}