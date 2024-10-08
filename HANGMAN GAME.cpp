#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


using namespace std;

// Function prototypes.
string getRandomWord();
int wordSize(const string& word);
bool isAlpha();
char toLower(char c);
bool isGameOver(const string& word, const string& guessedLetters);
char getGuess();
void displayHangman(int incorrectAttempts);
void displayWord(const string& word, const string& guessedLetters);

int main() {
    srand(static_cast<unsigned int>(time(0)));

    const int maxAttempts = 6;
    string word;
    word = getRandomWord();
    string guessedLetters;

    cout << "Welcome to Hangman!\n\n";

	//while loop for until word is guessed or number of lives end.
    int incorrectAttempts = 0;
    while (!isGameOver(word, guessedLetters) && incorrectAttempts < maxAttempts) {
        displayHangman(incorrectAttempts);
        displayWord(word, guessedLetters);
        
		cout << "lives remaining: " << maxAttempts - incorrectAttempts << endl;
		
        char guess = getGuess();

        // Update guessed letters
        bool isCorrectGuess = false;
        for (int i = 0; i < wordSize(word); ++i) {
            if (toLower(word[i]) == guess) {
                guessedLetters += toLower(guess);
                cout << "Correct guess!\n" << endl;
                isCorrectGuess = true;
                break;
            }
        }

        if (!isCorrectGuess) {
            cout << "Incorrect guess." << endl << endl;
            ++incorrectAttempts;
        }
    }

    // Display game result
    if (isGameOver(word, guessedLetters)) 
	{
        cout << "Congratulations! You guessed the word: " << word << endl;
    } 
	else 
	{
        cout << "NOOOOOOO!...you've been hanged. " << endl;
		cout << "The correct word was: \""  << word <<"\" "  << endl;
    }

    return 0;
}

bool isGameOver(const string& word, const string& guessedLetters) {
    for (int i = 0; i < wordSize(word); ++i) {
        bool letterGuessed = false;
        for (int j = 0; j < wordSize(guessedLetters); ++j) {
            if (toLower(word[i]) == guessedLetters[j]) {
                letterGuessed = true;
                break;
            }
        }
        if (!letterGuessed) {
            return false;
        }
    }
    return true;
}

 //returning any random word from given list of words.
string getRandomWord() {
    const string words[] = {"laptop", "sniper", "elephant", "xylophone", "jazz",
							"potatoes", "hazelnut", "chocoalate", "beans", "alphabets",
							"parrot", "cocoa", "automobile", "boxer", "sauce",
							"physics", "cliche", "guessed", "narcotics", "aluminium"};
    return words[rand() % (sizeof(words) / sizeof(words[0]))];
}


//checking if character entered is an alphabet.
bool isAlpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

//turning uppercase to lowercase using ascii code.
char toLower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 'a';
    }
    return c;
}

//takes letter and checks if it is alphabet using isAlpha function.
char getGuess() {
    char guess;
    cout << "Enter your guess: ";
    cin >> guess;

    while (!isAlpha(guess)) {
        cout << "Invalid input. Please enter a valid letter: ";
        cin >> guess;
    }

    return toLower(guess);
}

//using switch for displaying hangman if incorrect attempt.
void displayHangman(int incorrectAttempts) {
    switch (incorrectAttempts) {
        case 1:
            cout << "  O" << endl;
            break;
        case 2:
            cout << "  O" << endl;
            cout << "  |" << endl;
            break;
        case 3:
            cout << "  O" << endl;
            cout << " \\|" << endl;
            break;
        case 4:
            cout << "  O" << endl;
            cout << " \\|/" << endl;
            break;
        case 5:
            cout << "  O" << endl;
            cout << " \\|/" << endl;
            cout << " /" << endl;
            break;
        case 6:
            cout << "  O" << endl;
            cout << " \\|/" << endl;
            cout << " / \\" << endl;
            break;
        default:
            break;
    }
}

//displaying the guessed
void displayWord(const string& word, const string& guessedLetters) {
    for (int i = 0; i < wordSize(word); ++i) {
        char letter = word[i];
        bool letterGuessed = false;

        for (int j = 0; j < wordSize(guessedLetters); ++j) {
            if (toLower(letter) == guessedLetters[j]) {
                letterGuessed = true;
                break;
            }
        }

        if (letterGuessed) {
            cout << letter << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

// Count the characters in the word until a null character is encountered.
int wordSize(const string& word) {
    int size = 0;
    while (word[size] != '\0') {
        size++;
    }
    return size;
}

