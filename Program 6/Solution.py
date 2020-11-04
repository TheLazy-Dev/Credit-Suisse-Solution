import math
# You may change this function parameters
def encrypt(words):
    # Participants code will be here
    words = ''.join(words.split(" "))
    l = len(words)
    row, col = math.floor(math.sqrt(l)), math.ceil(math.sqrt(l))
    if row*col < l:
        row += 1
    
    result = ""
    for i in range(col):
        for j in range(row):
            if (i+j*col) >= l: 
                break
            else: 
                result += words[i+j*col]
        result += " "
    return result[:-1]


def main():
    words = input()

    answer = encrypt(words)

    # Please do not remove the below line.
    print(answer)
    # Do not print anything after this line

if __name__ == '__main__':
    main()
