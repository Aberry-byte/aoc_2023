#!/usr/local/bin/python3.12
"""
day 03
"""

def turn_line_to_list(input_string: str) -> list:
    """make a line into a list but keep ints together

    Args:
        input_string (str): _description_

    Returns:
        list: _description_
    """
    output_list = []
    current_number = ""
    for c in input_string:
        if c.isnumeric():
            current_number += c
            continue
        elif c == '.':
            if len(current_number) > 0:
                output_list.append(current_number)
                current_number = ""
            output_list.append('.')
        else:
            if len(current_number) > 0:
                output_list.append(current_number)
                current_number = ""
            output_list.append(c)
    return output_list



if __name__ == "__main__":
    input_file = open("test_file.txt", 'r', encoding="ASCII")
    # Read into array
    array = []
    while True:
        line = input_file.readline()

        if not line:
            break

        array.append(list(line.strip()))
    for x in array:
        print(x)
