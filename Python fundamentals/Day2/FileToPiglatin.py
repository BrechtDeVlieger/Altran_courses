import Piglatin as pig

with open("input.txt", "r") as input, open("output.txt", "w") as output:
    for word in input:
        word = word.strip()
        output.write("{a}\n".format(a=(pig.to_piglatin(word))))
