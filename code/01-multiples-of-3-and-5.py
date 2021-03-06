# https://rigobertocanseco.github.io/project-euler-problems/01-multiples-of-3-and-5.html

if __name__ == '__main__':
    s = 0
    for i in range(1000):
        if i % 3 == 0 or i % 5 == 0:
            s += i
    print(s)
