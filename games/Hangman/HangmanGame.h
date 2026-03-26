#include <vector>
#include <array>
#include <string>
#include <cctype>

class HangmanGame {
public:
	HangmanGame();

	void Run();

private:
	void DisplayGraphics();

    std::string text =
        "Line one\n"
        "Line two\n"
        "Line three\n"
        "And so on...";

    std::vector<std::string> words {
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

  /*  std::array<std::string, 6> hangman{
        {
            "  |  \n",
            "  0  \n",
            "     \n",
            "     \n",
            "=   =\n",
        },
        {
            "  |  \n",
            "  0  \n",
            "  |  \n",
            "     \n",
            "=   =\n",
        },
        {
            "  |  \n",
            "  0  \n",
            " /|  \n",
            "     \n",
            "=   =\n",
        },
        {
            "  |  \n",
            "  0  \n",
            " /|\ \n",
            "     \n",
        },
        {
            "  |  \n",
            "  0  \n",
            " /|\ \n",
            " /   \n",
            "=   =\n",
        },
        {
            "  |  \n",
            "  0  \n",
            " /|\ \n",
            " / \ \n",
            "=   =\n",
        },
    };*/
};