#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>




int getBoat(int posX, int posY, int cell[][10]){

	if(posY != 0){
		if(cell[posX][posY - 1] == 0){

			return 1;
		}
		else{
			return 0;
				}
	}
	else if (posY == 0 ){
		if(cell[posX][posY + 1] == 0){

			return 2;
		}
	}
		else{
			return 0;
				}
	}

int getCell(int posX, int posY, int cell[][10]){

	if(posY > 0 && posY < 9){
		if(cell[posX][posY - 1] == 0 && cell[posX][posY + 1] == 0){

			return 1;
		}
		else{
			return 0;
				}
	}
	else if (posY == 0){
		if(cell[posX ][posY  + 1] == 0 && cell[posX ][posY+2] == 0){

			return 2;
		}
		
		else{
			return 0;
				}
	}
	
	else if(posX == 9){
		if(cell[posX][posY - 1] == 0 && cell[posX][posY - 2] == 0){

			return 3;
		}
		else{
			return 0;
		}
	}
	
}


int getPlane(int posX, int posY, int cell[][10]){

	if(posX >= 3 && posX <= 7){
		if(cell[posX - 1][posY] == 0 && cell[posX +1][posY] == 0 && cell[posX +2][posY] == 0){

			return 1;
		}
		else{
			return 0;
				}
	}
	else if (posX < 3 ){
		if(cell[posX + 1][posY] == 0 && cell[posX +2][posY] == 0 && cell[posX + 3][posY] == 0){

			return 2;
		}
		else{
			return 0;
		}
	}
	else if(posX > 7){
		if(cell[posX - 1][posY] == 0 && cell[posX -2][posY] == 0 && cell[posX - 3][posY] == 0){

			return 3;
		}
		else{
			return 0;
		}
	}	
		
		else{
			return 0;
				}
	}
	
	int getBig(int posX, int posY, int cell[][10]){

	if(posX >= 4 && posX <= 6){
		if(cell[posX - 1][posY] == 0 && cell[posX +1][posY] == 0 && cell[posX +2][posY] == 0 && cell[posX - 2][posY] == 0){

			return 1;
		}
		else{
			return 0;
				}
	}
	else if (posX < 4 ){
		if(cell[posX + 1][posY] == 0 && cell[posX +2][posY] == 0 && cell[posX + 3][posY] == 0 && cell[posX + 4][posY] == 0){

			return 2;
		}
		else{
			return 0;
		}
	}
	else if(posX > 6){
		if(cell[posX - 1][posY] == 0 && cell[posX -2][posY] == 0 && cell[posX - 3][posY] == 0 && cell[posX - 4][posY] == 0){

			return 3;
		}
		else{
			return 0;
		}
	}	
		
		else{
			return 0;
				}
	}

	sf::RectangleShape criaRetangulo(int x, int y, int width, int height) {

	sf::RectangleShape rectangle(sf::Vector2f(width, height));

	rectangle.setFillColor(sf::Color::Transparent);

	rectangle.setOutlineColor(sf::Color::White);

	rectangle.setOutlineThickness(1.0f);

	rectangle.setPosition(x, y);

	return rectangle;

	}
	

	int check(int posicao, int mapa[][10]){
		int i, j, cont=0;

		for ( i=0; i<10; i++ )
  			for ( j=0; j<10; j++ )
  			{
				if(posicao == mapa[i][j]){
					cont = cont + 1;
				}
  		}
		if(cont == 1){
			return 1;
		}else{
			return 0;
		}
	}

	int function(int mapa [][10]){

		int i, j, cont=0;

		for ( i=0; i<10; i++ )
  			for ( j=0; j<10; j++ )
  			{
				if(mapa[i][j] == 0){
					cont++;
				}
  		}
		if(cont == 100){
			return 1;
		}else{
			return 0;
		} 
	}

	sf::Vector2i getInitialPos(sf::RectangleShape object) {
    sf::Vector2i pos(object.getPosition().x - object.getOrigin().x * object.getScale().x, object.getPosition().y - object.getOrigin().y * object.getScale().y);
    return pos;
}

sf::Vector2i getFinalPos(sf::RectangleShape object) {
    sf::Vector2i pos(object.getPosition().x - object.getOrigin().x * object.getScale().x + object.getLocalBounds().width * object.getScale().x, object.getPosition().y - object.getOrigin().y * object.getScale().y + object.getLocalBounds().height * object.getScale().y);
    return pos;
}

bool isClickBetween(sf::Vector2i click, sf:: RectangleShape object) {
   sf:: Vector2i iniPos = getInitialPos(object);
   sf:: Vector2i finalPos = getFinalPos(object);
    if (click.x >= iniPos.x && click.y >= iniPos.y && click.x <= finalPos.x && click.y <= finalPos.y) {
        return true;
    }
    return false;
}


int main()
{
	srand(time(NULL));
	setbuf(stdout, NULL);

	sf::RenderWindow window(sf::VideoMode(500, 600), "BATALHA NAVAL",
			sf::Style::Close | sf::Style::Titlebar);
	// Opções de abertura da janela: sf::Style::Close + sf::Style::Titlebar + sf::Style::Resize

	//declara os sons

     sf::Music music;
    if (!music.openFromFile("sonic.wav"))
        return -1;
    music.play();
	music.setLoop(true);
	music.setVolume(20.f);

     sf::Music water;
    if (!water.openFromFile("water.wav"))
            return -1;
	water.setVolume(50.f);

	 sf::Music bomb;
    if (!bomb.openFromFile("bomb.wav"))
            return -1;
	bomb.setVolume(50.f);

		sf::Music explosion;
    if(!explosion.openFromFile("explosion.wav"))
            return -1;
	explosion.setVolume(10.f); 

	sf::Music error;
    if (!error.openFromFile("error.wav"))
            return -1;
	error.setVolume(50.f);

	sf::Music hue;
    if (!hue.openFromFile("hue.wav"))
            return -1;
	hue.setVolume(50.f);

	
	//Declara variávieis para SFML
	sf::Texture textureFundo;
	sf::Sprite fundoImage1;
	sf::Sprite fundoImage2;
	
	sf::Texture textureBarco5;
	sf::Sprite barco5;

	sf::Texture textureBarco2;
	sf::Sprite barco21;
	sf::Sprite barco22;
	sf::Sprite barco23;
	sf::Sprite barco24;

	sf::Texture textureBarco3;
	sf::Sprite barco31;
	sf::Sprite barco32;
	sf::Sprite barco33;

	sf::Texture textureBarco4;
	sf::Sprite barco41;
	sf::Sprite barco42;

	sf::Texture textureBomba;
	sf::Sprite bomba;
	sf::Sprite bombaTeste;

	sf::Texture textureEnd;
	sf::Sprite end;

	sf::Image image = sf::Image { };
	
	image.loadFromFile("icone.png");

	window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());

	sf::Font font;
	font.loadFromFile("poxel-font.ttf");

	sf::Text text("02", font);
	text.setCharacterSize(40);
	text.setFillColor(sf::Color::Red);
	text.setPosition(420, 545);

	sf::Text gameOver;
	text.setCharacterSize(40);
	text.setFillColor(sf::Color::Red);
	text.setPosition(420, 545);

	sf::Text endText("60", font);
	text.setCharacterSize(40);
	text.setFillColor(sf::Color::Red);
	text.setPosition(420, 545);

	textureFundo.loadFromFile("fundo.jpeg");
	textureBarco5.loadFromFile("barco5.png");
	textureBarco2.loadFromFile("barco2.png");
	textureBarco3.loadFromFile("barco3.png");
	textureBarco4.loadFromFile("barco4.png");
	textureBomba.loadFromFile("bomb.png");


	fundoImage1.setTexture(textureFundo);
	fundoImage1.setPosition(1.f, 1.f);
	fundoImage2.setTexture(textureFundo);
	fundoImage2.setPosition(1.f, 142.5);

	barco21.setTexture(textureBarco2);
	barco22.setTexture(textureBarco2);
	barco23.setTexture(textureBarco2);
	barco24.setTexture(textureBarco2);
	barco31.setTexture(textureBarco3);
	barco32.setTexture(textureBarco3);
	barco33.setTexture(textureBarco3);
	barco41.setTexture(textureBarco4);
	barco42.setTexture(textureBarco4);
	barco5.setTexture(textureBarco5);


	barco21.scale(0.25f, 0.22f);
	barco22.scale(0.25f, 0.22f);
	barco23.scale(0.25f, 0.22f);
	barco24.scale(0.25f, 0.22f);
	barco31.scale(0.45f, 0.20f);
	barco32.scale(0.45f, 0.20f);
	barco33.scale(0.45f, 0.20f);
	barco41.scale(0.48f, 0.15f);
	barco42.scale(0.48f, 0.15f);
	barco5.scale(1.2f, 0.3f);
	bomba.scale(0.2f,0.2f);
	
	bomba.setTexture(textureBomba);
	bomba.setPosition(345,520);

	end.setTexture(textureEnd);
	end.setScale(1.f, 1.f);
	

	barco41.setRotation(270.f);
	barco42.setRotation(270.f);
	barco5.setRotation(270.f);
	
	sf::Text textasso;
	sf::Text textassonao;

	unsigned seed = time(0);

	srand(seed);

			int map [10][10] ;

			int x=0, y=0, boat=0, i=1 , sub = 0, plane = 0, big = 0,dim=50,bombs=2,l,c,fim = 0;
			sf::RectangleShape boxes[10][10];
			sf::RectangleShape butao ;
			sf::RectangleShape butaonao ;

			bool out = true;
			
				for(x=0; x < 10; x++){
						for(y=0; y < 10; y++){

							map[x][y] = 0;
						}
					}
				printf("Barcos de 2: \n");	
			
				while (sub != 4){


				out = true;

				while(out == true){

					x = rand()%9+1;
					y = rand()%10;

					
		
								
								if(map[x][y] != 0 ){
								
									out = true;
								}
								else{

									if(getBoat(x, y, map) == 1){

										map[x][y] = i;
										map[x][y - 1] = i;
										i++;
										sub++;
										out = false;
										printf("%d\t%d\n", x,y);
										if(sub==1){
										
										barco21.setPosition(x*dim-62,y*dim-66);
			
										}else if(sub==2){

										barco22.setPosition(x*dim-62,y*dim-66);	
										}else if(sub==3){
										barco23.setPosition(x*dim-62,y*dim-66);
										}else{
										barco24.setPosition(x*dim-62,y*dim-66);
										}
										

										}
									else if ((getBoat(x, y, map) == 2)){
										
										map[x][y] = i;
										map[x][y + 1] = i;
										sub++;
										i++;
										out = false;
										printf("%d\t%d\n", x,y);
										if(sub==1){
										
										barco21.setPosition(x*dim-62,y*dim-66);
			
										}else if(sub==2){

										barco22.setPosition(x*dim-62,y*dim-66);	
										}else if(sub==3){
										barco23.setPosition(x*dim-62,y*dim-66);
										}else{
										barco24.setPosition(x*dim-62,y*dim-66);
										}
										}
									else{

										out = true;


									}
								}

							
				}
			}
		

				i = 5;
			
				printf("Barcos de 3: \n");

				while (boat != 3){

				out = true;

				while(out == true){

					x = rand()%8-3;
					y = rand()%10;

								
								if(map[x][y] != 0){
								
									out = true;
								}
								else{


									if(getCell(x, y, map) == 1){

										map[x][y] = i;
										map[x][y - 1] = i;
										map[x][y + 1] = i;
										boat++;
										i++;
										out = false;
										printf("%d\t%d\n", x,y);
										if(boat==1){
										
										barco31.setPosition(x*dim-20,y*dim-35);
			
										}else if(boat==2){

										barco32.setPosition(x*dim-20,y*dim-35);	
										}else{
										barco33.setPosition(x*dim-20,y*dim-35);
										}
				

										}
									else if ((getCell(x, y, map) == 2)){
										
										map[x][y] = i;
										map[x][y+1] = i;
										map[x][y+2] = i;
										boat++;
										i++;
										out = false;
										printf("%d\t%d\n", x,y);
										if(boat==1){
										
										barco31.setPosition(x*dim-20,y*dim-35);
			
										}else if(boat==2){

										barco32.setPosition(x*dim-20,y*dim-35);	
										}else{
										barco33.setPosition(x*dim-20,y*dim-35);
										}

										}
									else if ((getCell(x, y, map) == 3)){
										
										map[x][y] = i;
										map[x][y - 1 ] = i;
										map[x][y-2] = i;
										boat++;
										i++;
										out = false;
										printf("%d\t%d\n", x,y);
										if(boat==1){
										
										barco31.setPosition(x*dim-20,y*dim-35);
			
										}else if(boat==2){

										barco32.setPosition(x*dim-20,y*dim-35);	
										}else{
										barco33.setPosition(x*dim-20,y*dim-35);
										}

										}	
									else{

										out = true;

									}
								}

				}

			}
				i=8;
				printf("Barcos de 4: \n");
			
				while (plane != 2){

				out = true;

				while(out == true){

					x = rand()%9-1;
					y = rand()%15+8;
		
								
								if(map[x][y] != 0){
								
									out = true;
								}
								else{

									if(getPlane(x, y, map) == 1){

										map[x][y] = i;
										map[x-1][y] = i;
										map[x+1][y] = i;
										map[x+2][y] = i;
										plane++;
										i++;
										out = false;
										printf("%d\t%d\n", x,y);
										if(plane==1){
										barco41.setPosition(x*dim+42,y*dim-30);
										}else{
										barco42.setPosition(x*dim+42,y*dim-30);
										}
										}
									else if ((getPlane(x, y, map) == 2)){
										
										map[x][y] = i;
										map[x+1][y] = i;
										map[x+2][y] = i;
										map[x+3][y] = i;
										i++;
										plane++;
										out = false;
										printf("%d\t%d\n", x,y);
										if(plane==1){
										barco41.setPosition(x*dim+42,y*dim-30);
										}else{
										barco42.setPosition(x*dim+42,y*dim-30);
										}
										}
									else if ((getPlane(x, y, map) == 3)){
										
										map[x][y] = i;
										map[x-1][y] = i;
										map[x-2][y] = i;
										map[x-3][y] = i;
										plane++;
										i++;
										out = false;
										printf("%d\t%d\n", x,y);
										if(plane==1){
										barco41.setPosition(x*dim+42,y*dim-30);
										}else{
										barco42.setPosition(x*dim+42,y*dim-30);
										}
										}	
									else{

										out = true;

									}
								}


				}

			}
				i = 10;
				printf("Barcos de 5: \n");
			
				while (big != 1){

				out = true;

				while(out == true){

					x = rand()%10-2;
					y = rand()%6+16;

								
								if(map[x][y] != 0){
								
									out = true;
								}
								else{

									if(getBig(x, y, map) == 1){

										map[x][y] = i;
										map[x-1][y] = i;
										map[x+1][y] = i;
										map[x+2][y] = i;
										map[x-2][y] = i;
										big++;
										out = false;
										printf("%d\t%d\n", x,y);
										barco5.setPosition(x*dim+40,y*dim);

										}
									else if ((getBig(x, y, map) == 2)){
										
										map[x][y] = i;
										map[x+1][y] = i;
										map[x+2][y] = i;
										map[x+3][y] = i;
										map[x+4][y] = i;
										big++;
										out = false;
										printf("%d\t%d\n", x,y);
										barco5.setPosition(x*dim+40,y*dim);

										}
									else if ((getBig(x, y, map) == 3)){
										
										map[x][y] = i;
										map[x-1][y] = i;
										map[x-2][y] = i;
										map[x-3][y] = i;
										map[x-4][y] = i;
										big++;
										out = false;
										printf("%d\t%d\n", x,y);
										barco5.setPosition(x*dim+40,y*dim);

										}	
									else{

										out = true;

									}
								}

				}

			}
			
			i=0;
			

			
			while (window.isOpen())
			{
			sf::Event event;
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						window.close();
						

				if (event.type == sf::Event::MouseButtonPressed) {
				
				//esta parte do código no qual é pego a posição do mouse, foi utilizado uma parte do código que o senhor disponibilizou para gente, já que eu tentei pensar como fazer e não consegui chegar em uma conclusão. O link para o código que possui a parte que foi utilizada neste código é este: https://gpjecc.blogspot.com/2023/03/sfml-matriz-na-tela-eventos-do-mouse.html  

				int linha = sf::Mouse::getPosition(window).x / dim;

				int coluna = sf::Mouse::getPosition(window).y / dim;

				//a linha 648 e 650 foram as que eu utilizei de seu código, novamente disponível em: https://gpjecc.blogspot.com/2023/03/sfml-matriz-na-tela-eventos-do-mouse.html
				
				int number=0;

				number = map[linha][coluna];

				int val=check(number, map);

				if(map[linha][coluna] != 0){			
						
				if(val == 1){
					explosion.play();
				}
				if(val != 1){
					bomb.play();
				}
				}else{
						water.play();
				}
				
				map[linha][coluna]=0;
				
				bombs--;
				char str[6];
				sprintf(str, "%d", bombs);
				text.setString(str);
				
				}

			fim = function(map);

				if(bombs==0 || fim == 1){

					if(bombs == 0){
						error.play();
					}
				if(fim == 1){
						hue.play();
					}
				

				music.stop();
				window.clear(sf::Color(255,255,255));
				
				gameOver.setFont(font);
				gameOver.setString(L"GAME OVER");
				gameOver.setCharacterSize(70); 
				gameOver.setFillColor(sf::Color::Red);
				gameOver.setPosition(50,0);

				endText.setFont(font);
				endText.setString(L"DESEJA JOGAR NOVAMENTE?");
				endText.setCharacterSize(34); 
				endText.setFillColor(sf::Color(255,32,0));
				endText.setPosition(0,210);

				butao = criaRetangulo(10, 300, 200, 100);
				butao.setFillColor(sf::Color(105,44,8));
				textasso.setFont(font);
				textasso.setString(L"SIM");
				textasso.setCharacterSize(34); 
				textasso.setFillColor(sf::Color:: White);
				textasso.setPosition(85,330);

				
				butaonao = criaRetangulo(290, 300, 200, 100);
				butaonao.setFillColor(sf::Color(105,44,8));
				textassonao.setFont(font);
				textassonao.setString(L"NAO");
				textassonao.setCharacterSize(34); 
				textassonao.setFillColor(sf::Color:: White);
				textassonao.setPosition(360,330);

				if (isClickBetween(sf::Mouse::getPosition(window), butao)) {
				
				music.play();
				music.setLoop(true);
				music.setVolume(20.f);

				x=0; 
				y=0; 
				boat=0; 
				i=1 ;
				sub = 0; 
			 	plane = 0;
				big = 0;
				dim=50;
				bombs=2;
				fim = 0;
					for(x=0; x < 10; x++){
						for(y=0; y < 10; y++){

							map[x][y] = 0;
						}
					}

				printf("Barcos de 2: \n");	
			
				while (sub != 4){


				out = true;

				while(out == true){

					x = rand()%9+1;
					y = rand()%10;
								
								if(map[x][y] != 0 ){
								
									out = true;
								}
								else{

									if(getBoat(x, y, map) == 1){

										map[x][y] = i;
										map[x][y - 1] = i;
										i++;
										sub++;
										out = false;
										printf("%d\t%d\n", x,y);
										if(sub==1){
										
										barco21.setPosition(x*dim-62,y*dim-66);
			
										}else if(sub==2){

										barco22.setPosition(x*dim-62,y*dim-66);	
										}else if(sub==3){
										barco23.setPosition(x*dim-62,y*dim-66);
										}else{
										barco24.setPosition(x*dim-62,y*dim-66);
										}
										

										}
									else if ((getBoat(x, y, map) == 2)){
										
										map[x][y] = i;
										map[x][y + 1] = i;
										sub++;
										i++;
										out = false;
										printf("%d\t%d\n", x,y);
										if(sub==1){
										
										barco21.setPosition(x*dim-62,y*dim-66);
			
										}else if(sub==2){

										barco22.setPosition(x*dim-62,y*dim-66);	
										}else if(sub==3){
										barco23.setPosition(x*dim-62,y*dim-66);
										}else{
										barco24.setPosition(x*dim-62,y*dim-66);
										}
										}
									else{

										out = true;


									}
								}

				}
			}
		

				i = 5;
			
				printf("Barcos de 3: \n");

				while (boat != 3){

				out = true;

				while(out == true){

					x = rand()%8-3;
					y = rand()%10;
								
								if(map[x][y] != 0){
								
									out = true;
								}
								else{


									if(getCell(x, y, map) == 1){

										map[x][y] = i;
										map[x][y - 1] = i;
										map[x][y + 1] = i;
										boat++;
										i++;
										out = false;
										printf("%d\t%d\n", x,y);
										if(boat==1){
										
										barco31.setPosition(x*dim-20,y*dim-35);
			
										}else if(boat==2){

										barco32.setPosition(x*dim-20,y*dim-35);	
										}else{
										barco33.setPosition(x*dim-20,y*dim-35);
										}
				

										}
									else if ((getCell(x, y, map) == 2)){
										
										map[x][y] = i;
										map[x][y+1] = i;
										map[x][y+2] = i;
										boat++;
										i++;
										out = false;
										printf("%d\t%d\n", x,y);
										if(boat==1){
										
										barco31.setPosition(x*dim-20,y*dim-35);
			
										}else if(boat==2){

										barco32.setPosition(x*dim-20,y*dim-35);	
										}else{
										barco33.setPosition(x*dim-20,y*dim-35);
										}

										}
									else if ((getCell(x, y, map) == 3)){
										
										map[x][y] = i;
										map[x][y - 1 ] = i;
										map[x][y-2] = i;
										boat++;
										i++;
										out = false;
										printf("%d\t%d\n", x,y);
										if(boat==1){
										
										barco31.setPosition(x*dim-20,y*dim-35);
			
										}else if(boat==2){

										barco32.setPosition(x*dim-20,y*dim-35);	
										}else{
										barco33.setPosition(x*dim-20,y*dim-35);
										}

										}	
									else{

										out = true;

									}
								}

				}

			}
				i=8;
				printf("Barcos de 4: \n");
			
				while (plane != 2){

				out = true;

				while(out == true){

					x = rand()%9-1;
					y = rand()%15+8;
					
								
								if(map[x][y] != 0){
								
									out = true;
								}
								else{

									if(getPlane(x, y, map) == 1){

										map[x][y] = i;
										map[x-1][y] = i;
										map[x+1][y] = i;
										map[x+2][y] = i;
										plane++;
										i++;
										out = false;
										printf("%d\t%d\n", x,y);
										if(plane==1){
										barco41.setPosition(x*dim+42,y*dim-30);
										}else{
										barco42.setPosition(x*dim+42,y*dim-30);
										}
										}
									else if ((getPlane(x, y, map) == 2)){
										
										map[x][y] = i;
										map[x+1][y] = i;
										map[x+2][y] = i;
										map[x+3][y] = i;
										i++;
										plane++;
										out = false;
										printf("%d\t%d\n", x,y);
										if(plane==1){
										barco41.setPosition(x*dim+42,y*dim-30);
										}else{
										barco42.setPosition(x*dim+42,y*dim-30);
										}
										}
									else if ((getPlane(x, y, map) == 3)){
										
										map[x][y] = i;
										map[x-1][y] = i;
										map[x-2][y] = i;
										map[x-3][y] = i;
										plane++;
										i++;
										out = false;
										printf("%d\t%d\n", x,y);
										if(plane==1){
										barco41.setPosition(x*dim+42,y*dim-30);
										}else{
										barco42.setPosition(x*dim+42,y*dim-30);
										}
										}	
									else{

										out = true;

									}
								}
				}

			}
				i = 10;
				printf("Barcos de 5: \n");
			
				while (big != 1){

				out = true;

				while(out == true){

					x = rand()%10-2;
					y = rand()%6+16;
								
								if(map[x][y] != 0){
								
									out = true;
								}
								else{

									if(getBig(x, y, map) == 1){

										map[x][y] = i;
										map[x-1][y] = i;
										map[x+1][y] = i;
										map[x+2][y] = i;
										map[x-2][y] = i;
										big++;
										out = false;
										printf("%d\t%d\n", x,y);
										barco5.setPosition(x*dim+40,y*dim);

										}
									else if ((getBig(x, y, map) == 2)){
										
										map[x][y] = i;
										map[x+1][y] = i;
										map[x+2][y] = i;
										map[x+3][y] = i;
										map[x+4][y] = i;
										big++;
										out = false;
										printf("%d\t%d\n", x,y);
										barco5.setPosition(x*dim+40,y*dim);

										}
									else if ((getBig(x, y, map) == 3)){
										
										map[x][y] = i;
										map[x-1][y] = i;
										map[x-2][y] = i;
										map[x-3][y] = i;
										map[x-4][y] = i;
										big++;
										out = false;
										printf("%d\t%d\n", x,y);
										barco5.setPosition(x*dim+40,y*dim);

										}	
									else{

										out = true;

									}
								}
				}

			}
			
			i=0;

}
		
			
	
				if (isClickBetween(sf::Mouse::getPosition(window), butaonao)) {
				
				window.close();
}
				
				
			}
		
				

			}


		window.clear(sf::Color(255,255,255));

			if(bombs > 0){
			
			window.draw(fundoImage1);
			window.draw(fundoImage2);
			window.draw(barco21);
			window.draw(barco22);
			window.draw(barco23);
			window.draw(barco24);
			window.draw(barco31);
			window.draw(barco32);
			window.draw(barco33);
			window.draw(barco41);
			window.draw(barco42);
			window.draw(barco5);
			window.draw(bomba);
			window.draw(text);
			for (int l = 0; l < 10; l++) {

				for (int c = 0; c < 10; c++) {

					boxes[l][c] = criaRetangulo(l * dim, c * dim, dim, dim);

					window.draw(boxes[l][c]);
				}
			}
		}
		if(bombs == 0){
			window.draw(gameOver);
			window.draw(endText);
			window.draw(butao);
			window.draw(butaonao);
			window.draw(textasso);
			window.draw(textassonao);
			
		}

			
			window.display();
			}	
				
	return 0;
 }
	

