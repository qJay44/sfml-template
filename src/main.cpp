#include <vector>

int main() {
  sf::RenderWindow window;
  sf::Font font;
  std::vector<sf::RectangleShape> grid;

  // Setup main window
  window.create(sf::VideoMode(WIDTH, HEIGHT), "Template text", sf::Style::Close);
  window.setFramerateLimit(90);

  // Font for some test text
  font.loadFromFile("../../src/fonts/Minecraft rus.ttf");

  grid.resize(ROWS * COLUMNS);
  grid.reserve(ROWS * COLUMNS);

  int scale = 255 / ROWS;
  for (int x = 0; x < COLUMNS; x++) {
    for (int y = 0; y < ROWS; y++) {
      sf::RectangleShape& rect = grid[x + y * COLUMNS];
      rect.setPosition(sf::Vector2f{sf::Vector2i{x * CELL_SIZE, y * CELL_SIZE}});
      rect.setSize({CELL_SIZE, CELL_SIZE});
      rect.setFillColor(sf::Color(255, 255, 255, scale * y));
    }
  }

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();

      if (event.type == sf::Event::KeyReleased)
        switch (event.key.code) {
          case sf::Keyboard::Q:
            window.close();
            break;
          default:
            break;
        }
    }

    window.clear();
    for (const sf::RectangleShape& rect : grid) window.draw(rect);
    window.display();
  }

	return 0;
}

