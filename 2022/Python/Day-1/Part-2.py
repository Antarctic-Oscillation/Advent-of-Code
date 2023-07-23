from helper_functions import get_relative_path


def main():
    with open(get_relative_path("input.txt")) as file:
        lines = file.read().split("\n\n")
        sums = [sum(map(int, line.split("\n"))) for line in lines]
        sums.sort()
    print(sums[-1:][0])    # Part 1
    print(sum(sums[-3:]))  # Part 2


if __name__ == "__main__":
    main()
