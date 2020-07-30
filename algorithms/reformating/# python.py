# python

# input: list of unsorted integers
# output: sorted list where pairs are used for all the detected intervals

def detect_ranges(L):

    sorted_copy = sorted(L)

    ranges = []
    range_to_add = [sorted_copy[0]]
    sorted_copy.pop(0)

    for current in sorted_copy:
        if range_to_add[-1] + 1 == current:
            if len(range_to_add) == 1:
                range_to_add.append(current)
            else:
                range_to_add.pop(-1)
                range_to_add.append(current)
        else:
            if len(range_to_add) == 1:
                ranges.append(range_to_add[0])
                range_to_add.pop(0)
                range_to_add.append(current)
            else:
                ranges.append((range_to_add[0], range_to_add[1] + 1))
                range_to_add = [current]

    if len(range_to_add) > 1:
        ranges.append((range_to_add[0], range_to_add[1] + 1))
    elif len(range_to_add) == 1:
        ranges.append(range_to_add[0])

    return ranges