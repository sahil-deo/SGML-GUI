#include "includes.h"
#include "GuiLib.h"
#include <iostream>
int main() {
	sf::RenderWindow window(sf::VideoMode(500, 500), "GUI Example", sf::Style::Close);

	sf::Text _usernameLabel;
	sf::Text _passwordLabel;

	Button b("x");
	Button b2("s");
	TextBox tb;
	TextBox tb2;

	//Styling
	{
		b.setBoxSize(20, 24);
		b.setPadding(4, -4);
		b.setTextSize(24);
		b.setBoxColor(sf::Color(61, 61, 61));
		b.setBoxDownColor(sf::Color(43, 43, 43));
		b.setFillColor(sf::Color::Red);
		b.setBoxOutline(1, sf::Color::White);
		b.setPosition(10, 10);

		b2.setBoxSize(20, 24);
		b2.setPadding(4, -4);
		b2.setTextSize(24);
		b2.setBoxColor(sf::Color(61, 61, 61));
		b2.setBoxDownColor(sf::Color(43, 43, 43));
		b2.setFillColor(sf::Color::Red);
		b2.setBoxOutline(1, sf::Color::White);
		b2.setPosition(10, 50);
		 
		tb.setBoxColor(sf::Color(61, 61, 61));
		tb.setBoxOutline(1, sf::Color::White);
		tb.setFillColor(sf::Color::White);
		tb.setPosition(40, 10);
		tb.setBoxSize(400, 24);
		tb.setPadding(4, 0);

		tb2.setBoxColor(sf::Color(61, 61, 61));
		tb2.setBoxOutline(1, sf::Color::White);
		tb2.setFillColor(sf::Color::White);
		tb2.setBoxSize(400, 24);
		tb2.setPosition(40, 50);
		tb2.setPadding(4, 0);
	}

	GuiHandler handler;

	handler.addToHandler(&b);
	handler.addToHandler(&b2);
	handler.addToHandler(&tb);
	handler.addToHandler(&tb2);
	sf::Event event;

	while (true) {
		
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			handler.HandleGuiEvent(&window, &event);
		}
		
		if (b.getState()) {
			tb.clearString();
		}
		if (b2.isReleased()) {
			tb2.setPasswordField(!tb2.getPasswordField());
		}
		
		window.clear(sf::Color(43, 43, 43));
	
		handler.HandleGuiRender(&window);

		window.display();

	}
}