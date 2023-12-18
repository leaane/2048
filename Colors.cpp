#include "Colors.h"

sf::Color Colors::getColor(ColorsEnum color) {
    switch(color) {
        case BOARD: return {191,178,158};
        case BLANK: return {202, 193, 181};
        case C2: return {236, 228, 219};
        case C4: return {236, 225, 204};
        case C8: return {233, 181, 130};
        case C16: return {233,154,109};
        case C32: return {231,132,104};
        case C64: return {246, 94, 59};
        case C128: return {232,209,128};
        case C256: return {237,204,97};
        case C512: return {237,200,80};
        case C1024: return {237,197,63};
        case C2048: return {237,194,46};
    }
}

sf::Color Colors::getColor(int num) {
    switch(num) {
        case 2: return {236, 228, 219};
        case 4: return {236, 225, 204};
        case 8: return {233, 181, 130};
        case 16: return {233,154,109};
        case 32: return {231,132,104};
        case 64: return {246, 94, 59};
        case 128: return {232,209,128};
        case 256: return {237,204,97};
        case 512: return {237,200,80};
        case 1024: return {237,197,63};
        case 2048: return {237,194,46};
    }
}

