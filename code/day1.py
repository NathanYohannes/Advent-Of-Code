global max
max = 0
global sum
sum = 0 

def main():
    steel = [0,0,0]
    sum = 0
    with open('../puzzleInput/day1.txt', 'r') as anishtext:
        while True:
            
            line = anishtext.readline()
            print(line)
            if not line:
                print("goodbye, MAX: ", steel)
                printListSum(steel)
                break
            if(line == '\n'):
                print("empty")
                if(sum > steel[2]):
                    steel[2] = sum
                    steel = listManager(steel)
                sum = 0
            else:
                
                sum = sum+int(line)


        
        print(line)

def listManager(steel):
    for i in range(2):
        if(steel[2-i] > steel[1-i]):
            steel = swapPositions(steel,(2-i),(1-i))
    return steel

def swapPositions(list, pos1, pos2):
     
    list[pos1], list[pos2] = list[pos2], list[pos1]
    return list

def printListSum(myList):
    sum = 0
    for i in myList:
        sum += i
    print("The List Sum is",sum)
main()