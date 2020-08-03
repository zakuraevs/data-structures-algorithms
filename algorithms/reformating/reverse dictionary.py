# python

# input: dictionary with keys as strings and values as lists
# output: dictionary with reverse keys-values
# example: 
# input: d={'move': ['liikuttaa'], 'hide': ['piilottaa', 'salata'], 'six': ['kuusi'], 'fir': ['kuusi']}
# output: reverse_dictionary(d) == {'liikuttaa': ['move'], 'piilottaa': ['hide'], 'salata': ['hide'], 'kuusi': ['six', 'fir']}
# example taken from Data Analysis with Python Course by University of Helsinky:
# https://csmastersuh.github.io/data_analysis_with_python_2020/index.html
 
def reverse_dictionary(d):
    rd = {}

    for key, value in d.items():
        if len(value) == 1:
            if value[0] in rd:
                rd[value[0]].append(key)
            else:
                rd[value[0]] = [key]
        else:
            for j in value:
                rd[j] = [key]

    return rd