#include <iostream>						//We always use it
#include <string>						//Necessary for strings
#include <stdlib.h>						//Necessary for clearing the console 
#include <Windows.h>					//Necessary for the Sleep() function 
//In this program we'll defy the needed variables/strings/etc and then we'll call them inside the main function
using namespace std;					//Be able to write couts and cins without having to write std::
const int NUM_WORDS = 10;				//Defy a constant variable

char startStory(const string& prompt) { //Start the story 
	char respostaa;						//Create a variable character
	while (true) {						//Create a bool where if the player wants to play he will and if he doesn't want it let him think about it
		cout << prompt;					//Print the value inside of prompt
		cin >> respostaa;				//Save a value inside the char variable 'respostaa'
		respostaa = toupper(respostaa); //Turn characters into their uppercase form 
		if (respostaa == 'Y' || respostaa == 'N') {
			break;						//Skip the while and continue with the code
		}
		cout << "Thou should try again, for the entry is wrong" << endl;
		// If anything else is entered prompt the user to try again 
	}
	return respostaa; 					//Function ends :( 
}

void saveWords(string words[NUM_WORDS]) {	//This function will save and collect the words from the user 
	//Every single sleep in this program is going to add mini-pauses to the program after printing any of the cout info
	cout << "Fill the gaps on the following text with the words asked next:" << endl << endl;;
	cout << "#1: Chose a body part:" << endl;
	Sleep(1000);
	cout << "#2: Chose a color ending with -ish" << endl;
	Sleep(900);
	cout << "#3: Chose a place" << endl;
	Sleep(800);
	cout << "#4: Chose a verb" << endl;
	Sleep(700);
	cout << "#5: Chese an adjective" << endl;
	Sleep(600);
	cout << "#6: Chose an object" << endl;
	Sleep(500);
	cout << "#7: Chose a noun" << endl;
	Sleep(400);
	cout << "#8: Chose another adjective" << endl;
	Sleep(300);
	cout << "#9: Chose a noun related to time" << endl;
	Sleep(200);
	cout << "#10: Chose a random name" << endl << endl;
	Sleep(100);


	for (int i = 0; i < NUM_WORDS; i++) {						//Collect the inputs recieved from the user 
		cout << "Write a word #" << i + 1 << ": ";				//Print the needed place where the user is going to print the words
		cin >> words[i];										//Save every input entered by the user in a variable ranging from 0 to 9 (i=0 < 10)
	}
}

void printMyStory(const string words[NUM_WORDS]) {	//Display the story to be completed and fill the gaps with the words entered earlier in the saveWords function 
	cout << "\n--- crazy story ---\n";
	cout << "So, it was a dark night near Arrowstreet Inc, Boston’s streets were empty dry but not enough, there was a couple walking by holding *" << words[0] << "* gently." << endl;
	Sleep(4000);
	cout << "When the man told her it was his time to leave, she smiled shyly and waved him saying goodbye. She fades 50 meters away in a " << words[1] << " fog." << endl;
	Sleep(4000);
	cout << "The man walked through the city alone, he helped her girlfriend get home so he could do it too. Benjamin was a people of goodwill, he loved helping others and talking a lot but soon he would find out that maybe he shouldn’t have talked to that man. When he was arriving " << words[2] << ", " << endl;
	Sleep(6000);
	cout << "he saw someone by the door with his eyes staring deep at his soul, when he asked him to move, he simply did not answer and proceeded to " << words[3] << " him by the arms, trying to immobilize him. " << endl;
	Sleep(5000);
	cout << "Benjamin fought back but the man was stronger than him and ended up *" << words[4] << "* " << endl;
	Sleep(6000);
	cout << "with just one strike to the nose. Days passed until Benjamin woke up, he had been sleeping in a small room alongside some sheep. It took him seven minutes to realize he was unable to move since he had " << words[5] << " on his arms and the sheep were slowly eating his robes away from him." << endl;
	Sleep(6000);
	cout << "Later that day, someone made his way into the room and gave him some homemade cheese, a loaf of bread and a glass of water. He told him that he would be participating forcefully in a secret military " << words[6] << " that wouldn’t be possible to do in legal terms." << endl;
	Sleep(6000);
	cout << "Benjamin was told to remain calm and follow the orders of not screaming, eating his meals three times a day and behaving like a sheep. He felt a shiver all over his spine, he knew something was wrong but couldn’t understand it, were those people really " << words[7] << " or they were just part of a cult?" << endl;
	Sleep(6000);
	cout << "Days passed and he started dissociating from himself, something was off, and he felt it, was he growing white hair all over his body?? What the fuck had he been eating all this time? This wicked individual showed off a " << words[8] << " later and told him that he would be set free near a place called" << words[9];
	cout << " Farm, he followed by saying that he must behave like a sheep for a year or else he would’ve been brought to a slaughtering house.Deep down in a spiral of dissociation and stress he completely lost his whole identity." << endl;
	Sleep(1000);												//Let some time pass between lines with  sleep
}

int main() {												//Main function (ºvº)/ 
	if (startStory("Dost thou want to repeat the story ? (Y/N):") == 'Y') {
		string words[NUM_WORDS];							//Ask if the user wants to repeat the story again in a medieval way
		saveWords(words);									//Save the constant variable NUM_WORDS entered earlier (the number of words needed to print basically)
		printMyStory(words);								//Add the words saved into the story
	}

	while (startStory("\n\nDost thou want to repeat the story again? (Y/N): ") == 'Y') {
		//When the user wishes to repeat the story again clear the console and return to the start
		system("cls");						//Clear the console 
		main();
	}

	cout << "Shall we meet again some time..." << endl;		//Say goodbye to the user in a medieval way
	return 0;
}
