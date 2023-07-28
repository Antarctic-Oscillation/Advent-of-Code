from helper_functions import get_relative_path


def calculate_priority_sum(line1, line2, line3):
    common = list(line1.intersection(line2, line3))[0]
    return (ord(common) - 38) if common.isupper() else (ord(common) - 96)


def main():
    priority_sum = 0

    with open(get_relative_path("input.txt")) as file:
        while line1 := set(file.readline().strip()):
            line2 = set(file.readline().strip())
            line3 = set(file.readline().strip())

            priority_sum += calculate_priority_sum(line1, line2, line3)

    print(priority_sum)


if __name__ == "__main__":
    main()
