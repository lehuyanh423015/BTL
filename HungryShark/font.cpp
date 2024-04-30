#include "font.h"
using namespace std;

void Font::renderText(int x, int y, Graphics& graphics) {
    font = graphics.loadFont(FONT, font_size);
    color = {0, 0, 0, 255};
    Text = graphics.renderText(font_text, font, color);

    graphics.renderTexture(Text, x, y);
}
