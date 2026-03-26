#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cctype>

int main_hangman() {
    std::vector<std::string> words = {
        "adventure", "bicycle", "candle", "dolphin", "envelope",
        "fireplace", "giraffe", "helicopter", "internet", "jacket",
        "keyboard", "lantern", "magazine", "necklace", "octopus",
        "parrot", "question", "rainbow", "scissors", "tomato",
        "umbrella", "volcano", "waterfall", "xylophone", "yogurt",
        "zigzag", "airplane", "butterfly", "chocolate", "diamond",
        "elevator", "festival", "guitar", "hospital", "icecream",
        "jigsaw", "kangaroo", "library", "mountain", "notebook",
        "ostrich", "penguin", "quilt", "rainforest", "sandwich",
        "triangle", "uniform", "violet", "whale", "xylophone",
        "yacht", "zipper", "balloon", "cactus", "donut", "falcon",
        "grapes", "honeybee", "igloo", "jellyfish", "kiwi"
    };

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, words.size() - 1);

    std::string userEntry;

	std::cout << "============== HANGMAN WORD GAME ==============\n";

    do {
        // game logic
        const std::string guessWord = words[distrib(gen)];
        std::string tiles(guessWord.size(), '_');

        std::cout << "  0  \n";
        std::cout << " /|  \n";
        std::cout << "   \ \n";
        std::cout << "  |  \n";
        std::cout << " /   \n";
        std::cout << "   \ \n";

        std::cout << "============== " << tiles << " ==============\n";

        // play again or quit
        std::cout << "Do you wish to play again? y or n: \n";
        std::cin >> userEntry;

        if (userEntry == "y" || userEntry == "Y") {
            continue;
        }

        break;
    } while (true);

    return 0;
}