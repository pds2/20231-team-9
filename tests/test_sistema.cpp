#include "doctest.h"
#include "sistema.h"

#include <exception>

TEST_CASE("Testa se Sistema cria um personagem") {
    Sistema cobaia;
    bool v;
    cobaia.criar_participante("Clara",10);
    auto pair = cobaia.get_vivos().begin();
    while(pair != cobaia.get_vivos().end()) {
        if(pair->first == "Clara") {
            v == true;
        }
    }
    CHECK(v == true);
}