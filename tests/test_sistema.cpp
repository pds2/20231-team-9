#include "../third_party/doctest.h"
#include "../include/sistema.h"

#include <exception>

TEST_CASE("Testa se Sistema cria um Jogador") {
    Sistema cobaia;
    bool v = false;
    cobaia.criar_jogador("Clara",10);
    auto pair = cobaia.get_vivos().begin();
    while(pair != cobaia.get_vivos().end()) {
        if(pair->first == "Clara") {
            v == true;
        }
    }
    CHECK(v == true);
}