#include <iostream>     
#include <string> 
#include <cstdlib>																//Necessary for clearing the console 
#include <Windows.h>															//Necessary for the Sleep() function 
#include <algorithm>															//For transform 
using namespace std;
const int NUM_WORDS = 10;

char startStory(const string& prompt) { //Start the story 
	char respostaa;
	while (true) {
		cout << prompt;
		cin >> respostaa;
		respostaa = toupper(respostaa);											//Turn characters into their uppercase form 
		if (respostaa == 'Y' || respostaa == 'N') {
			break;
		}
		std::cout << "Thou should try again, for the entry is wrong" << endl;	// If anything else is entered prompt the user to try again 
	}
	return respostaa; 	//Function ends :( 
}



void saveWords(string words[NUM_WORDS]) {										//This function will save and collect the words from the user 
	std::cout << "Fill the gaps on the following text with the words asked next:" << endl << endl;;
	const string prompts[NUM_WORDS] = {
	"#1: Chose a body part:",
	"#2: Chose a color ending with -ish",
	"#3: Chose a place",
	"#4: Chose a verb",
	"#5: Chese an adjective",
	"#6: Chose an object",
	"#7: Chose a noun",
	"#8: Chose another adjective",
	"#9: Chose a noun related to time",
	"#10: Chose a random name"
	};

	for (int i = 0; i < NUM_WORDS; i++) {										//Collect the inputs recieved from the user 
		std::cout << "Write a word #" << i + 1 << ": ";
		std::cin >> words[i];
	}
}

void printMyStory(const string words[NUM_WORDS]) {								//Display the story to be completed and fill the gaps with the words entered earlier in the saveWords function 
	std::cout << "\n--- crazy story ---\n";
	std::cout << "So, it was a dark night near Arrowstreet Inc, Boston’s streets were empty dry but not enough, there was a couple walking by holding *" << words[0] << "* gently." << endl;
	Sleep(4000);
	std::cout << "When the man told her it was his time to leave, she smiled shyly and waved him saying goodbye. She fades 50 meters away in a " << words[1] << " fog." << endl;
	Sleep(4000);
	std::cout << "The man walked through the city alone, he helped her girlfriend get home so he could do it too. Benjamin was a people of goodwill, he loved helping others and talking a lot but soon he would find out that maybe he shouldn’t have talked to that man. When he was arriving " << words[2] << ", " << endl;
	Sleep(6000);
	std::cout << "he saw someone by the door with his eyes staring deep at his soul, when he asked him to move, he simply did not answer and proceeded to " << words[3] << " him by the arms, trying to immobilize him. " << endl;
	Sleep(5000);
	std::cout << "Benjamin fought back but the man was stronger than him and ended up " << words[4] << endl;
	Sleep(6000);
	std::cout << "with just one strike to the nose. Days passed until Benjamin woke up, he had been sleeping in a small room alongside some sheep. It took him seven minutes to realize he was unable to move since he had " << words[5] << " on his arms and the sheep were slowly eating his robes away from him." << endl;
	Sleep(6000);
	std::cout << "Later that day, someone made his way into the room and gave him some homemade cheese, a loaf of bread and a glass of water. He told him that he would be participating forcefully in a secret military " << words[6] << " that wouldn’t be possible to do in legal terms." << endl;
	Sleep(6000);
	std::cout << "Benjamin was told to remain calm and follow the orders of not screaming, eating his meals three times a day and behaving like a sheep. He felt a shiver all over his spine, he knew something was wrong but couldn’t understand it, were those people really " << words[7] << " or they were just part of a cult?" << endl;
	Sleep(6000);
	std::cout << "Days passed and he started dissociating from himself, something was off, and he felt it, was he growing white hair all over his body?? What the fuck had he been eating all this time? This wicked individual showed off a " << words[8] << " later and told him that he would be set free near a place called" << words[9] << " Farm, he followed by saying that he must behave like a sheep for a year or else he would’ve been brought to a slaughtering house.Deep down in a spiral of dissociation and stress he completely lost his whole identity." << endl;
	Sleep(1000);
}







int main() {																	//Main function (ºvº)/ 
	if (startStory("Dost thou want to repeat the story again ? (Y/N):") == 'Y') {
		string words[NUM_WORDS];
		saveWords(words);
		printMyStory(words);
	}
	while (startStory("\n\nDost thou want to repeat the story again? (Y/N): ") == 'Y') {
		system("cls");															//Clear the console? 
		main();
	}
	std::cout << "Shall we meet again some time..." << endl;
	return 0;
}