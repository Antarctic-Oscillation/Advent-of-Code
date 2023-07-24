from helper_functions import get_relative_path


def main():
    outcomes = {
    "A X": 3, "B X": 0, "C X": 6,
    "A Y": 6, "B Y": 3, "C Y": 0,
    "A Z": 0, "B Z": 6, "C Z": 3,
    }
    
    scores = {'X': 1, 'Y': 2, 'Z': 3}
    
    with open(get_relative_path("input.txt")) as file:
        Rounds = file.read().split('\n')
        print(sum(scores[Round[2]] + outcomes[Round] for Round in Rounds))


if __name__ == "__main__":
    main()
