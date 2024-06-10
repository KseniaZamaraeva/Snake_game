#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <Windows.h>
#include <iostream>
#include <random>
#include <vector>

using namespace sf;

// Індетифікатор функцій
void Snake();
int Instructions();

int main() {
    sf::RenderWindow window(sf::VideoMode(750, 625), "Menu"); //Відкривається вікно

    sf::Font font; //Перевірка на тип шрифта тексту
    if (!font.loadFromFile("times.ttf")) {
        return 1;
    }

    sf::Font font1; //Перевірка на тип шрифта тексту
    if (!font1.loadFromFile("times.ttf")) {
        return 2;
    }

    sf::Font font2; //Перевірка на тип шрифта тексту
    if (!font2.loadFromFile("times.ttf")) {
        return 3;
    }

    sf::Font font3; //Перевірка на тип шрифта тексту
    if (!font3.loadFromFile("times.ttf")) {
        return 4;
    }

    sf::Text text; // Створюємо класс та задаємо змінну
    text.setFont(font); // Вибираємо який буде шрифту текст
    text.setString(L"Гра змійка"); // Задаємо текст  
    text.setCharacterSize(30); // Задаємо розмір
    text.setFillColor(sf::Color::Green); // Задаємо колір
    text.setPosition(320, 100); // Задаємо позицію

    sf::Text text1; // Створюємо класс та задаємо змінну
    text1.setFont(font1); // Вибираємо який буде шрифту текст
    text1.setString(L"Вихід з гри"); // Задаємо текст  
    text1.setCharacterSize(23); // Задаємо розмір
    text1.setFillColor(sf::Color::White); // Задаємо колір
    text1.setPosition(125, 370);// Задаємо позицію

    sf::Text text2; // Створюємо класс та задаємо змінну
    text2.setFont(font2); // Вибираємо який буде шрифту текст
    text2.setString(L"Гра в змійку"); // Задаємо текст  
    text2.setCharacterSize(23); // Задаємо розмір
    text2.setFillColor(sf::Color::White); // Задаємо колір
    text2.setPosition(325, 370); // Задаємо позицію

    sf::Text text3; // Створюємо класс та задаємо змінну
    text3.setFont(font3); // Вибираємо який буде шрифту текст
    text3.setString(L"Інструкція"); // Задаємо текст  
    text3.setCharacterSize(23); // Задаємо розмір
    text3.setFillColor(sf::Color::White); // Задаємо колір
    text3.setPosition(530, 370);  // Задаємо позицію

    RectangleShape rectangle2(Vector2f(120, 80)); // Додаємо змінну та задаємо розміри квадрату
    rectangle2.setOutlineThickness(8); // Товщина контура
    rectangle2.setOutlineColor(Color(80, 220, 50)); // Колір контура
    rectangle2.setPosition(125, 350); // Позиція квадрату
    rectangle2.setFillColor(Color(175, 180, 240)); // Колір квадрату

    RectangleShape rectangle(Vector2f(120, 80));  // Додаємо змінну та задаємо розміри квадрату
    rectangle.setOutlineThickness(8); // Товщина контура
    rectangle.setOutlineColor(Color(80, 220, 50));  // Колір контура
    rectangle.setPosition(325, 350); // Позиція квадрату
    rectangle.setFillColor(Color(175, 180, 240)); // Колір квадрату

    RectangleShape rectangle3(Vector2f(120, 80));   // Додаємо змінну та задаємо розміри квадрату
    rectangle3.setOutlineThickness(8); // Товщина контура
    rectangle3.setOutlineColor(Color(80, 220, 50));  // Колір контура
    rectangle3.setPosition(525, 350); // Позиція квадрату
    rectangle3.setFillColor(Color(175, 180, 240)); // Колір квадрату

    while (window.isOpen()) {

        Vector2i MousePozition = Mouse::getPosition(window); //перетворюємо координати нашої мишки в ціле число

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (Mouse::isButtonPressed(Mouse::Left)) { // Перевірка на натискання лівої кнопки миші
            if (rectangle.getGlobalBounds().contains(MousePozition.x, MousePozition.y)) { // Перевірка чи координати миші по осі Х та У є в квадраті
                window.close();
                Snake(); // Виклик функції гри
            }
        }

        if (Mouse::isButtonPressed(Mouse::Left)) { // Перевірка на натискання лівої кнопки миші
            if (rectangle2.getGlobalBounds().contains(MousePozition.x, MousePozition.y)) { // Перевірка чи координати миші по осі Х та У є в квадраті

                window.close();
            }
        }

        if (Mouse::isButtonPressed(Mouse::Left)) { // Перевірка на натискання лівої кнопки миші
            if (rectangle3.getGlobalBounds().contains(MousePozition.x, MousePozition.y)) // Перевірка чи координати миші по осі Х та У є в квадраті
            {
                window.close();
                Instructions(); // Виклик функції інтрукції
            }
        }
        window.clear(sf::Color::Yellow); //Відображення заднього фону
        window.draw(rectangle); // Відображення чотирикутника
        window.draw(rectangle2); // Відображення чотирикутника
        window.draw(rectangle3); // Відображення чотирикутника
        window.draw(text); // Відображення тексту
        window.draw(text1); // Відображення тексту
        window.draw(text2); // Відображення тексту
        window.draw(text3); // Відображення тексту
        window.display(); // Закривання вікна
    }

    return 0;
}

int Instructions()
{
    sf::RenderWindow window(sf::VideoMode(750, 625), "Instructions");

    sf::Font font;  //Перевірка на тип шрифта тексту
    if (!font.loadFromFile("times.ttf")) {
        return 5;
    }

    sf::Font font2;  //Перевірка на тип шрифта тексту
    if (!font2.loadFromFile("times.ttf")) {
        return 5;
    }

    sf::Font font3;  //Перевірка на тип шрифта тексту
    if (!font3.loadFromFile("times.ttf")) {
        return 5;
    }

    sf::Text text;  // Створюємо класс та задаємо змінну
    text.setFont(font);  // Вибираємо який буде шрифту текст
    text.setString(L"Інструкція");  // Задаємо текст  
    text.setCharacterSize(30);  // Задаємо розмір
    text.setFillColor(sf::Color::Green); // Задаємо колір
    text.setPosition(320, 100);  // Задаємо позицію

    sf::Text text2; // Створюємо класс та задаємо змінну
    text2.setFont(font2);  // Вибираємо який буде шрифту текст
    text2.setString(L"Після вибору першого пункту в меню «Почати гру» гра Після\nвибору першого пункту в меню «Почати гру» гра починається.\nЗмійка розташовується випадковим чином на полі. На полі\nтакож випадково розташовується їжа. Змійка рухається\nпо полю,виконуючи команди користувача введені з клавіатури,\nзмінює напрямок руху відповідно до введення і рухається\nу вибраному напрямку. Якщо змійка зіткнеться зі стіною або\nз собою, гра закінчується. При поїданні їжі змійка\nзбільшується, і на полі з'являється нова їжа. Кожен раз, коли\nзмійка з'їдає їжу, рахунок користувача збільшується. Кінцем\nгри може бути зіткнення змійки з стінкою або самою собою\n(тілом). Після цього користувач повертається до меню і має\nвибір варіанту меню.");  // Задаємо текст  
    text2.setCharacterSize(18); // Задаємо колір
    text2.setFillColor(sf::Color::White); // Задаємо колір
    text2.setPosition(145, 180);  // Задаємо позицію

    sf::Text text3;  // Створюємо класс та задаємо змінну
    text3.setFont(font3);  // Вибираємо який буде шрифту текст
    text3.setString(L"Повернутись\nдо меню.");  // Задаємо текст  
    text3.setCharacterSize(16); // Задаємо колір
    text3.setFillColor(sf::Color::White); // Задаємо колір
    text3.setPosition(30, 28);  // Задаємо позицію

    RectangleShape rectangle3(Vector2f(500, 300));  // Додаємо змінну та задаємо розміри квадрату
    rectangle3.setOutlineThickness(8); // Товщина контура
    rectangle3.setOutlineColor(Color(80, 220, 50));  // Колір контура
    rectangle3.setPosition(140, 175); // Позиція квадрату
    rectangle3.setFillColor(Color(175, 180, 240)); // Колір квадрату

    RectangleShape rectangle4(Vector2f(100, 50)); // Додаємо змінну та задаємо розміри квадрату
    rectangle4.setOutlineThickness(8); // Товщина контура
    rectangle4.setOutlineColor(Color(80, 220, 50));  // Колір контура
    rectangle4.setPosition(25, 25); // Позиція квадрату
    rectangle4.setFillColor(Color(175, 180, 240)); // Колір квадрату

    while (window.isOpen()) {

        Vector2i MousePozition = Mouse::getPosition(window); //перетворюємо координати нашої мишки в ціле число

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (Mouse::isButtonPressed(Mouse::Left)) { // Перевірка на натискання лівої кнопки миші
            if (rectangle4.getGlobalBounds().contains(MousePozition.x, MousePozition.y)) // Перевірка чи координати миші по осі Х та У є в квадраті
            {
                window.close();
                main(); // Виклик функції меню
            }
        }

        window.clear(sf::Color::Yellow);  //Відображення заднього фону
        window.draw(text); // Відображення тексту
        window.draw(rectangle3); // Відображення чотирикутника
        window.draw(rectangle4); // Відображення чотирикутника
        window.draw(text2);  // Відображення тексту
        window.draw(text3);  // Відображення тексту
        window.display(); // Закривання вікна
    }
    return 6;
}

void Snake() {
    const int SIZE = 25; // Розмір клітинки
    const int WIDTH = 30; // Ширина ігрового поля
    const int HEIGHT = 25; // Висота ігрового поля

    RenderWindow window(VideoMode(WIDTH * SIZE, HEIGHT * SIZE), "Snake Game"); // Створення вікна з розмірами із назвою "Snake Game"

    RectangleShape cells[WIDTH][HEIGHT]; // Створення масиву квадратиків для відображення клітинок ігрового поля

    // Створення ігрового поля з темно-зеленими і світло-зеленими квадратиками
    for (int i = 0; i < WIDTH; ++i) {
        for (int j = 0; j < HEIGHT; ++j) {
            cells[i][j].setSize(Vector2f(SIZE, SIZE)); // Встановлення розміру клітинки
            cells[i][j].setPosition(i * SIZE, j * SIZE); // Встановлення позиції клітинки
            if ((i + j) % 2 == 0)
                cells[i][j].setFillColor(Color(109, 185, 102)); // Встановлення темно-зеленого кольору для парних клітинок

            else
                cells[i][j].setFillColor(Color(158, 207, 141)); // Встановлення світло-зеленого кольору для непарних клітинок

            window.draw(cells[i][j]); // Відображення клітинок ігрового поля
        }
    }

    // Створення генератора випадкових чисел для встановлення випадкової позиції їжі
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribX(0, WIDTH - 1); /*визначає розподіл рівномірно розподілених цілих чисел в заданому діапазоні.
                                                               У цьому випадку, діапазон від 0 до WIDTH - 1, тобто від 0 до ширини ігрового поля*/
    std::uniform_int_distribution<int> distribY(0, HEIGHT - 1);

    // Генерація випадкових координат для розміщення їжі на ігровому полі
    int foodX = distribX(gen);
    int foodY = distribY(gen);

    CircleShape food(SIZE / 2); // Малювання кругу (це буде яблуко)
    food.setFillColor(Color::Red); // Червний колір для їжі
    food.setOrigin(food.getRadius(), food.getRadius()); // Встановлення точки центру кола як точки початку координат
    food.setPosition((foodX + 0.5) * SIZE, (foodY + 0.5) * SIZE); // Їжа встановлюється у центрі випадкової клітинки

    int snakeX = WIDTH / 2; // Початкові координати змійки (по центру поля)
    int snakeY = HEIGHT / 2;
    int snakeLength = 1; // Початкова довжина змійки

    std::vector<Vector2i> snakeSegments; // Зберігання змійки як векторне ціле число
    snakeSegments.push_back(Vector2i(snakeX, snakeY)); // Функція яка буде додавати хвіст змійки

    int dx = 1; // Напрямок руху змійки по осі X (1 - вправо, -1 - вліво)
    int dy = 0; // Напрямок руху змійки по осі Y (1 - вниз, -1 - вгору)

    Clock clock;
    float timer = 0.0f;
    float delay = 0.1f;

    // Головний цикл гри
    while (window.isOpen()) {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        // Керування змійкою за допомогою клавіатури
        if (Keyboard::isKeyPressed(Keyboard::Left) && dx == 0) /*Якщо натиснута клавіша вліво і змійка рухається горизонтально (dx == 0),
                                                   то змінна dx стає -1, що вказує на рух уліво, а dy залишається нульовим, оскільки не відбувається рух по вертикалі.*/
        {
            dx = -1;
            dy = 0;
        }
        if (Keyboard::isKeyPressed(Keyboard::Right) && dx == 0) {
            dx = 1;
            dy = 0;


            /*Аналогічно для натискання клавіші вправо, вгору і вниз: якщо змійка не рухається вже у відповідному напрямку, встановлюється новий напрямок руху.*/
        }
        if (Keyboard::isKeyPressed(Keyboard::Up) && dy == 0) {
            dx = 0;
            dy = -1;
        }
        if (Keyboard::isKeyPressed(Keyboard::Down) && dy == 0) {
            dx = 0;
            dy = 1;
        }

        // Рух змійки
        if (timer >= delay) {
            timer = 0;

            snakeX += dx;
            snakeY += dy;

            //// Перевірка з'їдання їжі
            if (snakeX == foodX && snakeY == foodY) {
                snakeLength++;
                foodX = distribX(gen);
                foodY = distribY(gen);
                food.setPosition((foodX + 0.5) * SIZE, (foodY + 0.5) * SIZE);
            }

            // Оновлення розміру змійки коли вона з'їдає яблуко 
            snakeSegments.push_back(Vector2i(snakeX, snakeY));
            if (snakeSegments.size() > snakeLength) {
                snakeSegments.erase(snakeSegments.begin());
            }

        }

        window.clear();

        for (int i = 0; i < WIDTH; ++i) {
            for (int j = 0; j < HEIGHT; ++j) {
                window.draw(cells[i][j]);
            }
        }
        //// Малювання змійки
        for (const auto& segment : snakeSegments) { // Цикл який перевіряє розмір змійки як вона з'їсть їжу. 
            RectangleShape snakeSegment(Vector2f(SIZE, SIZE));
            snakeSegment.setFillColor(Color::Green);
            snakeSegment.setPosition(segment.x * SIZE, segment.y * SIZE); // Додає хвіст змійки по осі x та у після того як з'їла яблуко
            window.draw(snakeSegment);
        }

        window.draw(food);

        window.display();

        // Перевірка на зіткнення змійки з межами поля
        if (snakeX < 0 || snakeX >= WIDTH || snakeY < 0 || snakeY >= HEIGHT) {
            window.close();
            main();
        }
        window.clear();
    }
}
