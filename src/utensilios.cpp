#include "../include/utensilios.h"

Utensilio::Utensilio(utensilios utensilio) {
    _utensilio = utensilio;
}

utensilios Utensilio::get_tipo() const{
    return _utensilio;
}