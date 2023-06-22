#include "../third_party/doctest.h"
#include "../include/jogador.h"

TEST_CASE("Testa se os atributos de Participante foram corretamente inicializados") {
    Participante *p = new Jogador("Maria", 8);
    CHECK(p->get_atual().get_nome() == regioes::centro);
    CHECK(p->get_distrito() == 8);
    CHECK(p->get_energia() == 100.0);
    CHECK(p->get_hidratacao() == 100.0);
    delete p;
}

TEST_CASE("Testa se o personagem está na região correta") {
    Participante *p = new Jogador("Maria", 8);

    Regiao _floresta(8,7,2,0,regioes::floresta);
    p->muda_regiao_atual(_floresta);
    CHECK(p->get_atual().get_nome() == regioes::floresta);

    delete p;
}

TEST_CASE("Testa se a mudança de arma está ocorrendo corretamente") {
    Participante *p = new Jogador("Maria", 8);
    Arma _nova_arma = Arma(armas::espada);
    p->adicionar_arma(_nova_arma);
    CHECK(p->get_arma().get_tipo() == armas::espada);
    delete p;
}

TEST_CASE("Testa a função batalha") {
    Participante *p = new Jogador("Maria", 8);
    Arma _nova_arma = Arma(armas::espada);
    p->adicionar_arma(_nova_arma);

    Participante *p2 = new Jogador("Pedro", 2);
    Arma _nova_arma2 = Arma(armas::faca);
    p2->adicionar_arma(_nova_arma2);
    p->batalha(*p2);
    CHECK(p2->get_vivo() == false);
    CHECK(p->get_energia() == p->get_energia() * p2->get_arma().get_poder() * 0.9);

    delete p;
    delete p2;
}