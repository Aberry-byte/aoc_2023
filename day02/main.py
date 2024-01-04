"""
I stopped with the cpp version cause string splitting is a pain
and too much for these fun challenges
"""


class Bag:
    def __init__(self, red_balls, green_balls, blue_balls):
        self.red = red_balls
        self.green = green_balls
        self.blue = blue_balls

    def possible_pull(self, red_pull, green_pull, blue_pull) -> bool:
        if red_pull > self.red:
            return False
        elif green_pull > self.green:
            return False
        elif blue_pull > self.blue:
            return False
        return True


def clean_line(game_line: list) -> list:
    new_line = [x.strip(',').strip(':') for x in game_line]

    return new_line


if __name__ == "__main__":
    input_file = open("test_file.txt", 'r', encoding="ASCII")
    while True:
        line = input_file.readline()
        split_line = line.split()
        split_line = clean_line(split_line)
        print(split_line)

        if not line:
            break
