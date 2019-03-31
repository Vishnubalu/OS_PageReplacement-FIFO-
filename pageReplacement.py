import random


def pageReplace(frame, pages, n):
    faults = 0
    hit = 0
    j = n + 1
    print("")

    for i in pages:
        if i not in frame:
            if (len(frame) < n):
                frame.append(i)
                faults = faults + 1
            else:
                if (j >= len(frame)):
                    j = 0
                frame[j] = i
                j = j + 1
                faults = faults + 1
        else:
            hit = hit + 1
    return (faults, hit)


if __name__ == '__main__':
    frame = []
    print("According to FIFO, the page which first comes in the memory will first goes out :\n")
    pages = [random.randint(0,9) for page in range(0,15)]
    #pages = [3, 2, 1, 0, 3, 2, 4, 3, 2, 1, 0, 4]
    print("\n\nPage References : ", pages)
    for i in range(1, 8):
        print("Number of frames : ", i)
        faults, hits = pageReplace(frame, pages, i)
        print("Faults : ",faults)
        print("Hits   : ", hits)
        print("\n------------------------")

