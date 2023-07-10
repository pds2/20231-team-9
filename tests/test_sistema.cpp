#include "../third_party/doctest.h"
#include "../include/sistema.h"

#include <exception>

TEST_CASE("Testa se Sistema cria um Jogador") {
    Sistema cobaia;
    Regiao Centro(2,2,"centro",0,0,9,3);
    cobaia.criar_jogador("Clara", &Centro);
    cobaia.criar_jogador("Cecília", &Centro);
    cobaia.criar_jogador("Lucas", &Centro);
    cobaia.criar_jogador("Felipe", &Centro);
    cobaia.criar_jogador("Arthur", &Centro);

    CHECK_THROWS_AS(cobaia.criar_jogador("Clara", &Centro), participante_ja_existe_e);

    CHECK(cobaia.get_participantes().size() == 5);
}

TEST_CASE("Testa quando há a morte de participantes") {
    Sistema jogo;
    Regiao Centro(2,2,"centro",0,0,9,3);

    jogo.criar_jogador("Maria", &Centro);
    jogo.criar_jogador("Pedro", &Centro);

    Arma _nova_arma = Arma(armas::espada);
    Arma _nova_arma2 = Arma(armas::faca);
    Participante *p1;
    Participante *p2;

    std::map<std::string, Participante *> map_part = jogo.get_participantes();

    auto pair = map_part.begin();

    while(pair != map_part.end()) {
        if(pair->first == "Maria") {
            pair->second->adicionar_arma(_nova_arma);
            p1 = pair->second;
        } else if(pair->first == "Pedro") {
            pair->second->adicionar_arma(_nova_arma2);
            p2 = pair->second;
        }
        pair = next(pair);
    }


    p1->batalha(*p2);

    CHECK_EQ(p2->get_vivo(), false);
    CHECK_EQ(p1->get_energia(), 60);
}