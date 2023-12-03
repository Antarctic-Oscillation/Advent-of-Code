from helper_functions import get_relative_path


outcomes = {
    "A X": 3, "B X": 0, "C X": 6,
    "A Y": 6, "B Y": 3, "C Y": 0,
    "A Z": 0, "B Z": 6, "C Z": 3,
}

scores = {'X': 1, 'Y': 2, 'Z': 3}


def main():
    score = 0
    
    with open(get_relative_path("input.txt")) as file:
        while Round := file.readline().strip():
            score += scores[Round[2]] + outcomes[Round]
            
    print(score)


if __name__ == "__main__":
    main()
