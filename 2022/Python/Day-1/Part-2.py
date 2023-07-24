from helper_functions import get_relative_path


def main():
    with open(get_relative_path("input.txt")) as file:
        lines = file.read().split("\n\n")
        sums = [sum(map(int, line.split("\n"))) for line in lines]
        sums.sort()
    print(sum(sums[-3:]))


if __name__ == "__main__":
    main()
