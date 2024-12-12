


//     [Incloc les llibreries que em faran falta per fer funcionar el programa]
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\

#include <sstream>	
#include <SFML/Graphics.hpp>	
#include <SFML/Audio.hpp>		
#include <iostream>				


//     [Declarar constants i altres variables per a tenir millor qualitat de vida al programar: ]
// ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\

	// Per no haver d'escriure sempre std:: i sf:: direm que fem servir els namespaces sf i std
		using namespace sf;
		using namespace std;
	
	//     [Declarem les constants de la pantalla (la mida que serà / fullscreen)]
	// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\
			
		const int Xmax = 1920;
		const int Ymax = 1080;
	
	//     [Declarem les constants següents: el màxim de núvols, la posició de la destral a la dreta, el mateix a l'esquerra i el total de branques que sortiran per pantalla]
	// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\
			
		const int NumMaxClouds = 3;
		const float AXE_POSITION_LEFT = 700;
		const float AXE_POSITION_RIGHT = 1075;
		const int NUM_BRANCHES = 6;

	//      [Aquest bool ens servirà per veure si quan pressionem les tecles de moviment una estona no ens accepti l'input tota la estona sinò que ho faci al prèmer però al deixar anar no]
	// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\
			
		bool acceptInput = false;

	//     [Originem una estructura anomenada CloudStructure que contindrà una part important dels núvols (si es troben actius/o no i la velocitat)]
	// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\
			
		struct CloudStructure {
		sf::Sprite dibuix;
		bool  Active;
		float Speed; };

	//     [Enumerem les possibles opcions que es poden donar al tallar amb el personatge (també ens ajudarà amb els troncs de fusta voladors)]
	// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\
		
		enum class side{LEFT, RIGHT, NONE};

	//     [Acabem d'afegir variables que farem servir per al canvi de cançons de fons]
	// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\

			// Creem la llista de cançons que sonaran mentre es juga a partir d'un Music gameMusic
			Music gameMusic;

			// Guardarem dins un vector les cançons que volem que sonin mentre es juga al joc Timber
				vector<std::string> musicFiles = {
					"Deathbrain1.ogg",
					"Deathbrain2.ogg",
					"Kanemiko1.ogg",
					"Kanemiko2.ogg" };

			// Iniciem la variable lastPlayedIndex a -1
				int lastPlayedIndex = -1; 
				
				int getRandomSongIndex(int excludeIndex) {
					int index;
					do {
						index = rand() % musicFiles.size();
						} while (index == excludeIndex); 
					return index; }	
	
	//     [Cridem la funció void perquè actualitzi les branques a cada inici de programa (per això la situem abans del main) ]
	// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\

		void updateBranches(int seed, side branca[]);

	
//     [Obrim la funció principal on buidarem tot el nostre codi]
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\

int main() {
	
	// Definim el generador aleatori que farem servir per canviar les cançons i un historial per treure la opció a que surti la mateixa cançó dues vegades seguides
		srand(static_cast<unsigned>(time(0))); 
		int currentSongIndex = getRandomSongIndex(-1); 
	
	//En cas que no es trobi el fitxer,avisa per la consola abans de començar el programa i acaba'l amb un return -1
		if (!gameMusic.openFromFile("sound/"+musicFiles[currentSongIndex])) {
			cout << "No s'ha pogut carregar la música" << endl;
			return -1;
		} 

	// No permetis començar un bucle i comença a reproduïr la música
		gameMusic.setLoop(false);
		gameMusic.play();

//     [Creem les branques]
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\

	// Creem un sprite amb la constant de branques que voldrem que apareixin per pantalla
	// I les situarem en posicions aleatòries (de 1 a 6 posicions diferents)
		Sprite branches[NUM_BRANCHES];
		side branchPositions[NUM_BRANCHES];

//     [Generem la pantalla]
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\

	// Crea un objecte de vídeo del tamany de les constants Xmax i Ymax (mida pantalla completa) i obrim la finestra com a "Timber!!!"
		VideoMode vm(Xmax, Ymax);
		RenderWindow window(vm, "Timber!!!", Style::Fullscreen);

//     [Creem el fons de pantalla]
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\

	// Crea les textures pel fons de pantalla que sortirà a la finestra i busca'n la imatge a la carpeta graphics
	// Crea'n també un sprite i afegeix-li les textures que li hem posat abans
	// Finalment li donem una posició (en el nostre cas 0,0 perquè al ser una pantalla de mida 1920x1080 treballarem amb aquella mida)
		Texture textureBackground;
		textureBackground.loadFromFile("graphics/background.png");
		Sprite spriteBackground;
		spriteBackground.setTexture(textureBackground);
		spriteBackground.setPosition(0, 0);

//     [Creem els arbres ]
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\

	// Creem les textures de l'arbre que sortirà per la finestra, busca l'imatge a la carpeta graphics
	// Crea un sprite i afegeix-li les textures d'abans i situa l'arbre a la posició 810, 0 (mes o menys el mig de la pantalla)
	// No només creem un arbre sinò que en creem un total de 3 per millorar el fons i donar la sensació que som dins un bosc
	
		// Arbre 1
			Texture textureTree;
			textureTree.loadFromFile("graphics/tree.png");
			Sprite spriteTree;
			spriteTree.setTexture(textureTree);
			spriteTree.setPosition(810, 0);
	
		// Arbre 2
			Texture textureTree2;
			Sprite spriteTree2;
			spriteTree2.setTexture(textureTree);
			spriteTree2.setPosition(1310, 0);
	
		// Arbre 3
			Texture textureTree3;
			Sprite spriteTree3;
			spriteTree3.setTexture(textureTree);
			spriteTree3.setPosition(210, 0);

//     [Creem a Taylor i el Lorax]
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\
	// Afegim un altre sprite a la finestra i busquem la seva imatge a la carpeta graphics
	// Ajuntem el nostre sprite amb la texture i només ens falta situar-lo a (1560,510)!
	// Semblarà com si aquest sprite fos a sobre un tros de soca d'arbre
		Texture textureTayLorax;
		Sprite spriteTayLorax;
		textureTayLorax.loadFromFile("graphics/taylorax.png");
		spriteTayLorax.setTexture(textureTayLorax);
		spriteTayLorax.setPosition(1560, 510);
	
//     [Creem el sol d'Astora]
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\
	// Crea una textura, un sprite i ajunta la textura amb el sprite
	// Seguidament situa'l a (1670, 0)
		Texture textureSun;
		Sprite spriteSun;
		textureSun.loadFromFile("graphics/sun.png");
		spriteSun.setTexture(textureSun);
		spriteSun.setPosition(1670, 0);

//     [Creem l'abella]
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\
	// Preparem l'abella creant la seva textura, el seu sprite i busca'n la textura a la carpeta graphics
	// Tot seguit ajunta la textura amb el sprite i situa'l a la posició inicial (0, 800)
		Texture textureBee;
		textureBee.loadFromFile("graphics/bee.png");
		Sprite spriteBee;
		spriteBee.setTexture(textureBee);
		spriteBee.setPosition(0, 800);
			
			// S'està movent l'abella al principi del programa 
			// (SI/No [però igualment fem que no es mogui fins que començi de veritat el programa / pressionant Enter])
			// Definim la velocitat de l'abella
				bool beeActive = false;
				float beeSpeed = 0.0f;

//     [Creem els núvols]
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\
	// Preparem la textura dels núvols i la busquem a la carpeta graphics
	// Tot seguit amb un for generem els tres núvols amb la variable constant NumMaxClouds (que és igual a 3)
		Texture textureCloud;
		textureCloud.loadFromFile("graphics/cloud.png");
		CloudStructure spriteCloud[NumMaxClouds];

		// I els donem posicions diferents
		for (int i = 0; i < NumMaxClouds; i++)	{
		spriteCloud[i].dibuix.setTexture(textureCloud);
		spriteCloud[i].dibuix.setPosition(0, i * 250);
		spriteCloud[i].Active = false;
		spriteCloud[i].Speed = 0.0f; }

//     [Creem els rellotges i la barra de temps]
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\

		// Fem els rellotges que ens faran falta per poder canviar els vestits i el comptador de fotogrames per segon (FPS)
		// La variable constant serà el cooldown de canviar de vestit del gat (timberman)
			Clock clock;
			Clock skinClockCd;				
			const float skinCLockCd = 3.0f; 

			// Preparem la barra del temps, triem el seu gruix i llargada i la posicionem a la part central baixa de la pantalla 
				RectangleShape timeBar;
				float timeBarStartWidth = 400;
				float timeBarHeight = 80;
				timeBar.setSize(Vector2f(timeBarStartWidth, timeBarHeight));

				// La pintem de color vermell i li definim el temps total de joc (6 segons)
					timeBar.setFillColor(Color::Red);
					timeBar.setPosition((1920 / 2) - timeBarStartWidth / 2, 980);
					Time gameTimeTotal;
					float timeRemaining = 6.0f;

				// Com més temps passi més curta serà la barra del temps
					float timeBarWidthPerSecond = timeBarStartWidth / timeRemaining;

//     [Creem el text]
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\

			// Si el programa es troba en funcionament (si no es troba pausat)
				bool paused = true;
		
			// Seguidament defineix les variables de text que farem servir per escriure
				int score = 0;
				Text messageText;
				Text scoreText;

				// Triem la font de la lletra que sortirà per pantalla, en el nostre cas serà IMFePIit28P.ttf (es a dir, que farem servir IM Fell DW Pica)
					Font font;
					font.loadFromFile("fonts/IMFePIit28P.ttf");

//     [Creem el menú inicial i el comptador de fps]
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\

		// Preparem el rellotge i el comptador de fps
			int frameCount = 0;
			float elapsedTime = 0.0f;
			
			// Li afegim també la mateixa font d'abans (IM Fell DW Pica), li posem una mida de 24, de color blanc i la situem a les coordenades (20, 150)
			Text fpsText;
			fpsText.setFont(font);
			fpsText.setCharacterSize(24);
			fpsText.setFillColor(Color::White);
			fpsText.setPosition(20, 150);
			
			// Generem el rellotge dels fps
			Clock fpsClock;
			float fps = 0;
	
		// Calcula els FPS a cada input
		fps = 1.0f / fpsClock.restart().asSeconds();
		fpsText.setString("FPS: " + to_string(static_cast<int>(fps)));
		// Variables per calcular el FPS
		
//     [Assignem la font als missatges anteriors i escrivim que volem veure]
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\

		// Assigna la font IM Fell DW Pica al text del comptador de fps
			messageText.setFont(font);
			scoreText.setFont(font);
	
		// Escrivim què és el que volem que apareixi per la pantalla al començar el joc
			messageText.setString("Press Enter to start!!!");
			scoreText.setString("Score=0");

			// Ens assegurem que el tamany de les lletres es gran 
				messageText.setCharacterSize(75);
				scoreText.setCharacterSize(100);

			// Fem que siguin del mateix color (blanc)
				messageText.setFillColor(Color::White);
				scoreText.setFillColor(Color::White);
	
				// Posicionem el text als llocs que volem
				// El primer text apareixerà al mig de la pantalla perquè n'hem buscat la posició
				// El segon text el posarem a (20, 20)
					FloatRect textRect = messageText.getLocalBounds();
					messageText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
					messageText.setPosition(Xmax / 2.0f, Ymax / 2.0f);
					scoreText.setPosition(20, 20);
	
//     [Creem les branques]
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\
	// Preparem les branques creant primer la seva textura i buscant-la a la carpeta graphics
		Texture textureBranch;
		textureBranch.loadFromFile("graphics/branch.png");
			// Assigna a cada sprite branch una textura i una posició per a cada una
				for (int i = 0; i < NUM_BRANCHES; i++) {
					branches[i].setTexture(textureBranch);
					branches[i].setPosition(-2000, -2000);
					branches[i].setOrigin(220, 20); }
	
//     [Creem el jugador i els seus vestits]				
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\
	// Crea les textures del jugador
	// En total tindrà tres vestits / skins
	// Busquem els vestits a la carpeta graphics.
		Texture texturePlayer;
		Texture texturePlayer2;
		Texture texturePlayer3;
		texturePlayer.loadFromFile("graphics/player.png");
		texturePlayer2.loadFromFile("graphics/player2.png");
		texturePlayer3.loadFromFile("graphics/player3.png");
			
			// Creem un sprite player amb un vestit inicial 0
				Sprite spritePlayer;
				int currentSkin = 0;

				// Dins un array guardem el total de vestits que tindrà el jugador
				vector<Texture*> playerOutfits = { &texturePlayer, &texturePlayer2, &texturePlayer3};
				
				// Posem una textura inicial al jugador i el posicionem a (580,720)
				spritePlayer.setTexture(texturePlayer);
				spritePlayer.setPosition(580, 720);

				// Al començar el programa el situarem a l'esquerra i no sortirà cap branca al iniciar el programa
					side playerSide = side::LEFT;
					branchPositions[3] = side::NONE;

//     [Creem la làpida]
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\
	// Per fer la làpida del gat (player) crearem una textura i la buscarem a graphics
	// Fusionarem el sprite amb la textura i el situarem a (580,720)
		Texture textureGravestone;
		textureGravestone.loadFromFile("graphics/rip.png");
		Sprite spriteGravestone;
		spriteGravestone.setTexture(textureGravestone);
		spriteGravestone.setPosition(580,720);
	
//     [Creem la destral]
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\
	// Com amb tots els altres objectes que surten per pantalla li afegim una textura des de la carpeta graphics
		Texture textureAxe;
		textureAxe.loadFromFile("graphics/axe.png");
		Sprite spriteAxe;
		spriteAxe.setTexture(textureAxe);
		spriteAxe.setPosition(580, 720);
	
//     [Creem el tros de fusta volador]
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\
	// Com amb tots els altres objectes que surten per pantalla li afegim una textura des de la carpeta graphics
		Texture textureLog;
		textureLog.loadFromFile("graphics/log.png");
		Sprite spriteLog;
		spriteLog.setTexture(textureLog);
		spriteLog.setPosition(580, 720);

	// Variables útils per a fer lliscar el tros de fusta
		bool logActive = false;
		float logSpeedX = 1000;
		float logSpeedY = -1500;
		bool acceptInput = false;

//     [Prepara els sons]
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\
	// Crea els buffers per fer sonar els sons i busca'ls a la carpeta sound
	
		// So 1: el tallar l'arbre amb la destral
			SoundBuffer chopBuffer;
			chopBuffer.loadFromFile("sound/chop.wav");
			Sound chop;
			chop.setBuffer(chopBuffer);

		// So 2: morir al ser aplastat per una branca
			SoundBuffer deathBuffer;
			deathBuffer.loadFromFile("sound/death.wav");
			Sound death;
			death.setBuffer(deathBuffer);

		// So 3: s'acaba el temps de joc
			SoundBuffer out_of_timeBuffer;
			out_of_timeBuffer.loadFromFile("sound/out_of_time.wav");
			Sound out_of_time;
			out_of_time.setBuffer(out_of_timeBuffer);
	
//     [Fem que la música soni]	
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\
	// Comprovem que no es facin bucles no desitjats amb les cançons (que no començin infinitament)
	gameMusic.setLoop(false);
	gameMusic.play();

		// Creem una variable aleatòria
		srand((int)time(0) * 10);
	
//     [El bucle principal]
// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\

	while (window.isOpen()) {
		
		/*
		****************************************
		Handle the players input
		****************************************
		*/

	//     [Pressionar les tecles]
	// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\
		// Assegurar-se que no hi hagin problemes al mantenir premudes les tecles de moviment
			Event event;
			while (window.pollEvent(event)) {
				if (event.type == Event::KeyReleased && !paused) {
					
					// Escolta les tecles
					acceptInput = true;
					
					// Amaga la destral
					spriteAxe.setPosition(2000, spriteAxe.getPosition().y);
				}
			}

	//     [Tecla Escape/Delete]
	// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\
		// Si es pressiona la pantalla es tanca
			if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
		}

	//     [Tecla Return/Intro]		
	// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\
		// Comença el joc perquè és la tecla que es demana pressionar
			if (Keyboard::isKeyPressed(Keyboard::Return)) {
				paused = false;

				//Inicia la música del joc
					if (gameMusic.getStatus() != SoundSource::Playing) {
					gameMusic.play();
					}

				// Amaga les branques al iniciar el joc
					for (int i = 1; i < NUM_BRANCHES; i++) {
						branchPositions[i] = side::NONE;
					}

				// Make sure the gravestone is hidden
					spriteGravestone.setPosition(675, 2000);
				// Move the player into position
					spritePlayer.setPosition(580, 720);
					acceptInput = true;
				// Reset the time and the score
					score = 0;
					timeRemaining = 6;
					for (int i = 1; i < NUM_BRANCHES; i++) {
						branchPositions[i] = side::NONE;
					}
			}

	//     [Moviment personatge]
	// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\
		// Només si acceptem inputs
		if (acceptInput) {
		
			//     [Fletxa Dreta]
			// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\

			if (Keyboard::isKeyPressed(Keyboard::Right)) {
				// Assegurar-se que el jugaor es troba a l'esquerra
					playerSide = side::RIGHT;
					score++;

				// Afegeix 0.15 segons al comptador i canvia la destral de posició
					timeRemaining += (2 / score) + .15;
					spriteAxe.setPosition(AXE_POSITION_RIGHT, spriteAxe.getPosition().y);
					spriteAxe.setRotation(180);
					spritePlayer.setPosition(1200, 720);

					// Actualitza les branques per tal que vagin baixant
						updateBranches(score, branchPositions);

					// Envia el tros de fusta volant cap a l'esquerra
						spriteLog.setPosition(810, 720);
						logSpeedX = -5000;
						logActive = true;
						acceptInput = false;
						chop.play(); }
			
			//     [Fletxa Esquerra]
			// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\
			
			if (Keyboard::isKeyPressed(Keyboard::Left)) {
				// Assegurar-se que el jugador es troba a la dreta
					playerSide = side::LEFT;
					score++;

				// Afegeix 0.15 segons al comptador i canvia la destral de posició
					timeRemaining += (2 / score) + .15;
					spriteAxe.setPosition(AXE_POSITION_LEFT, spriteAxe.getPosition().y);
					spriteAxe.setRotation(0);
					spritePlayer.setPosition(500, 720);

					// Actualitza les branques per tal que vagin baixant
						updateBranches(score, branchPositions);

					// set the log flying to the RIGHT
						spriteLog.setPosition(1200, 720);
						logSpeedX = 5000;
						logActive = true;
						acceptInput = false;
						chop.play(); }
			
			//     [Fletxa Amunt]
			// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\

			if (Keyboard::isKeyPressed(Keyboard::Up)) {
				currentSkin = (currentSkin + 1)%playerOutfits.size();
				// Canviar el vestit del gat pel següent vestit (1 -> 2 -> 3 -> 1 -> ...)
					spritePlayer.setTexture(*playerOutfits[currentSkin]);
					// Afegeix una petita pausa al canviar de vestit
						sleep(milliseconds(200));
			}
		}

		/*
		****************************************
		Update the scene
		****************************************
		*/
		
		//    [Que passa quan es troba tot pausat]
		// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\
		
		if (!paused) {
			
			// Reinicia el rellotge del temps que fem servir pel contador
				Time dt = clock.restart();
			
			// Comença a restar el temps
				timeRemaining -= dt.asSeconds();

			// Re-escala la barra del temps
				timeBar.setSize(Vector2f(timeBarWidthPerSecond * timeRemaining, timeBarHeight));
			
			//     [Que passa quan s'acaba el temps]
			// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\

			if (timeRemaining <= 0.0f) {
				//Pause the game
					paused = true;
				
				//Change the message shown to the player
					messageText.setString("Out of time!!");
				
				//Reposition the text based on its new size
					FloatRect textRect = messageText.getLocalBounds();
					messageText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
					messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);
				
				// Play the out of time sound
					out_of_time.play();
					gameMusic.pause();
			}

			//     [Que passa quan l'abella està activa]
			// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\

			if (!beeActive)
			{
				// La velocitat de l'abella
					beeSpeed = (rand() % 200) + 200;
				
				// Com d'alta es situa l'abella
					float height = (rand() % 500) + 500;
					spriteBee.setPosition(2000, height);
					beeActive = true;
			}
			
			else
			{
				spriteBee.setPosition(spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()), spriteBee.getPosition().y);
				// Ha sortir de la pantalla l'abella?
					
					if (spriteBee.getPosition().x < -100) {
					// Reactiva l'abella 
						beeActive = false;
					}
			}
		
			//     [Fem que els núvols es moguin]
			// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\

			for (int i = 0; i < NumMaxClouds; i++)
			{
				if (!spriteCloud[i].Active)
				{
					spriteCloud[i].Speed = (rand() % 200);
					spriteCloud[i].dibuix.setPosition(-200, (rand() % 500));
					spriteCloud[i].Active = true;
				}
				else
				{
					spriteCloud[i].dibuix.setPosition(spriteCloud[i].dibuix.getPosition().x + (spriteCloud[i].Speed * dt.asSeconds()),
						spriteCloud[i].dibuix.getPosition().y);
					if (spriteCloud[i].dibuix.getPosition().x > Xmax)
					{
						spriteCloud[i].Active = false;
					}
				}
			}
			
			//     [Actualitzem la puntuació]
			// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\

			stringstream ss;
			ss << "Score = " << score;
			scoreText.setString(ss.str());

			//     [Generem branques aleatòriament amb tres possibles opcions]
			// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\

			for (int i = 0; i < NUM_BRANCHES;
				i++)
			{
				float height = i * 150;
				if (branchPositions[i] == side::LEFT)
				{
					// Canviem el personatge de costat
						branches[i].setPosition(760, height);
					// Fem que miri a un altre costat
						branches[i].setRotation(360);
				}
				else if (branchPositions[i] == side::RIGHT)
				{
					// Canviem el personatge de costat
						branches[i].setPosition(1200, height);
					// Fem que miri a un altre costat
						branches[i].setRotation(0);
				}
				else
				{
					// Amaguem les branques
					branches[i].setPosition(3000, height);
				}
			}
			
			//     [Aleatorietat de cançons]
			// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\

			if (gameMusic.getStatus() == SoundSource::Stopped) {
				lastPlayedIndex = currentSongIndex;
				currentSongIndex = getRandomSongIndex(lastPlayedIndex);
				gameMusic.play();
			}

			//     [Fer lliscar els troncs voladors]
			// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\
	
			if (logActive) {
				spriteLog.setPosition(
					spriteLog.getPosition().x + (logSpeedX * dt.asSeconds()),
					spriteLog.getPosition().y + (logSpeedY * dt.asSeconds())
				);
			}	
			// Si el tronc volador ha sortit per la pantalla fa aixo
			if (spriteLog.getPosition().x < -100 || spriteLog.getPosition().x > 2000) {
				logActive = false;
				spriteLog.setPosition(810,720);
		}

			//     [Ha mort el jugador?]
			// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\

			if (branchPositions[5] == playerSide) {
				// Ha mort
					paused = true;
					acceptInput = false;
				
					// Fes aparèixer una làpida
					spriteGravestone.setPosition(525, 760);
				
					// Amaga el jugador
					spritePlayer.setPosition(2000, 660);
				
					// Actualitza el text del missatge antic (enter per començar el joc)
					messageText.setString("SQUISHED!!!");
				
					// Centrar el text
						FloatRect textRect = messageText.getLocalBounds();
						messageText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
						messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);
					// Fes sonar el so de morir (Kendrick u scream)
						death.play();
			}
			

		// End if(!paused)
		}

		//     [Rellotge i comptador de FPS]
		// ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\

			Time dt = clock.restart();
			frameCount++; 
			elapsedTime += dt.asSeconds(); 

		// Cada 100 fotogrames, actualitza el valor del FPS
			if (elapsedTime >= 1.0f) {
				// Actualitzar el FPS
					float fps = frameCount / elapsedTime;
					stringstream ss;
					ss << "FPS: " << int(fps);
					fpsText.setString(ss.str());
				// Restablir comptadors
					frameCount = 0;
					elapsedTime = 0.0f;
			}

	 /*
	 ****************************************
	 Draw the scene
	 ****************************************
	 */

 //     [Administra la pantalla]
 // ------------------------------------------------------------------------------------------------------------------------------------------------------------------------\\

		window.clear();

		// Fes sortir per la pantalla el fons
			window.draw(spriteBackground);

		// Fes sortir per la pantalla els núvols
			for (int i = 0; i < NumMaxClouds; i++) {
				window.draw(spriteCloud[i].dibuix);
			}


		// Fes sortir per la pantalla les branques
			for (int i = 0; i < NUM_BRANCHES; i++) {
				window.draw(branches[i]);
			}
		
		// Fes sortir per la pantalla els arbres
			window.draw(spriteTree);
			window.draw(spriteTree2);
			window.draw(spriteTree3);

		// Fes sortir per la pantalla el jugador
			window.draw(spritePlayer);

		// Fes sortir per la pantalla la destral
			window.draw(spriteAxe);
	
		// Fes sortir per la pantalla el tronc volador
			window.draw(spriteLog);
		
		// Fes sortir per la pantalla la làpida
			window.draw(spriteGravestone);

		// Fes sortir per la pantalla a la Taylor i el Lorax
			window.draw(spriteTayLorax);

		// Fes sortir per la pantalla el Sol
			window.draw(spriteSun);
		
		// Fes sortir per la pantalla l'abella
			window.draw(spriteBee);

		// Fes sortir per la pantalla la puntuació
			window.draw(scoreText);
			if (paused) {
				window.draw(messageText);
			}
		// Fes sortir per la pantalla la barra del temps
			window.draw(timeBar);


		// Fes sortir per la pantalla el nostre missatge
			window.draw(fpsText);
			window.setFramerateLimit(60);

		// Fes sortir per la pantalla tots els sprites i missatges anteriors
			window.display();

	}
	return 0;
}

// Actualitza les branques al baixar i generar-se

void updateBranches(int seed, side branca[])
{
	// Mou les branques una posició
		for (int j = NUM_BRANCHES - 1; j > 0; j--) {
			branca[j] = branca[j - 1];
		}
	// Genera una nova branca a les tres possibles posicions (<-, None i ->)
		srand((int)time(0) + seed);
		int r = (rand() % 5);
		switch (r) {
		case 0:
			branca[0] = side::LEFT;
			break;
		case 1:
			branca[0] = side::RIGHT;
			break;
		default:
			branca[0] = side::NONE;
			break;
		}
	}