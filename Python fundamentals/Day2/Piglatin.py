
def to_piglatin(string):
    first = string[0]
    if first in 'aeiou':
        return "{a}-ay".format(a=string)
    else:
        return "{a}-{b}ay".format(a=string[1:], b=string[0])

def from_piglatin(string):
    string = string.strip()
    index = string.index("-")
    if len(string[index:]) == 3:    # Word begins with a vowel
        return "{a}".format(a=string[0:index])
    else:                           # Word begins with a consonant
        return "{a}{b}".format(a=string[index+1], b=string[0:index])


if __name__ == "__main__":
    print(from_piglatin(to_piglatin("egg")))
    print(from_piglatin(to_piglatin("happy")))
