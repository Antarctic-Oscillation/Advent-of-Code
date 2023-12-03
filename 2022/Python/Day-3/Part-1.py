from helper_functions import get_relative_path


def calculate_priority_sum(line):
    mid = len(line) // 2
    prefix = set(line[:mid])
    suffix = set(line[mid:])
    common = list(prefix.intersection(suffix))[0]
    return (ord(common) - 38) if common.isupper() else (ord(common) - 96)



def main():
    priority_sum = 0

    with open(get_relative_path("input.txt")) as file:
        while line := file.readline().strip():
                priority_sum += calculate_priority_sum(line)
                
    print(priority_sum)


if __name__ == "__main__":
    main()
