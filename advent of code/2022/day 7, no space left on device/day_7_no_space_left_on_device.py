class MyNode:

    def __init__(self, name, parent = None):

        self.name = name
        self.parent = parent
        self.localDirectorySize = 0
        self.accumulatedSubdirectoriesSize = 0
        self.files = {}
        self.parent = parent
        self.children = []


class NoSpaceLeftOnDevice:

    def __init__(self, input):

        self.root = MyNode("/")
        self.sum_sizes_at_most_100000 = 0
        self.foundSize = 0

        self.__initializeTree(input)

        self.__calculateDirectoriesSizes()
        self.__findDirectorySizeToRemove()

        self.printOutput()


    def __initializeTree(self, input):

        currentNode = self.root

        for line in input:
            lineItems = line.split()
            command = lineItems[0] == "$"

            if command:
                currentNode = self.__handleCommand(lineItems, currentNode)
            else:
                currentNode = self.__handleLsCommandOutput(lineItems, currentNode)


    def __handleCommand(self, lineItems, currentNode):

        commandKey = lineItems[1]

        if commandKey == "cd":
            directoryName = lineItems[2]

            if directoryName != "..":
                if directoryName != "/":
                    for node in currentNode.children:
                        if node.name == directoryName:
                            currentNode = node
                            break
                else:
                    currentNode = self.root

            elif currentNode.name != "/":
                currentNode = currentNode.parent

        elif commandKey == "ls":
            pass

        return currentNode


    def __handleLsCommandOutput(self, lineItems, currentNode):

        field1, field2 = lineItems

        if field1 == "dir":
            directoriesNames = [node.name for node in currentNode.children]

            if not field2 in directoriesNames:
                node = MyNode(field2, parent = currentNode)
                currentNode.children.append(node)
        
        else:
            size, name = int(field1), field2

            if not name in currentNode.files:
                currentNode.files.update({name: size})
                currentNode.localDirectorySize += size

        return currentNode
                        

    def __calculateDirectoriesSizes(self, node = None):

        if not node:
            node = self.root

        node.accumulatedSubdirectoriesSize = node.localDirectorySize

        for child in node.children:
            self.__calculateDirectoriesSizes(child)
            node.accumulatedSubdirectoriesSize += child.accumulatedSubdirectoriesSize

        if node.accumulatedSubdirectoriesSize <= 100000:
            self.sum_sizes_at_most_100000 += node.accumulatedSubdirectoriesSize


    def __findDirectorySizeToRemove(self, node = None):

        spaceToUpdate = 30000000
        totalSpace = 70000000
        freeSpace = totalSpace - self.root.accumulatedSubdirectoriesSize
        self.requireSpaceToFree = spaceToUpdate - freeSpace
        self.foundSize = self.root.accumulatedSubdirectoriesSize
        
        self.__findDirectorySize()


    def __findDirectorySize(self, node = None):

        if not node:
            node = self.root

        for child in node.children:
            self.__findDirectorySize(child)

        if node.accumulatedSubdirectoriesSize >= self.requireSpaceToFree and node.accumulatedSubdirectoriesSize <= self.foundSize:
            self.foundSize = node.accumulatedSubdirectoriesSize


    def printOutput(self):
        print(self.sum_sizes_at_most_100000)
        print(self.foundSize)


def main():
    with open("input.txt") as f:
        input = f.readlines()
    noSpaceLeftOnDevice = NoSpaceLeftOnDevice(input)


if __name__ == "__main__":
    main()
