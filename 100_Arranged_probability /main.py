

if __name__ == '__main__':
    v = 7e11
    v_string = list(str(int(v)))
    for i in range(len(v_string) - 1):
        #
        for j in range(9, -1, -1):
            v_string[i + 1] = str(j)
            v_int = int(''.join(v_string))
            d = (v_int / 1e12) * ((v_int - 1) / (1e12 - 1))
            print(v_int, d)

            if d == 0.5:
                print(d)
                break
            elif d < 0.5:
                break
        # if (v / 10e12) * (v - 1) / (10e12 - 1) == 0.5:
        #    print(v_int)
