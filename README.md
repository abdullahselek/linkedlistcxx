# linkedlistcxx

LinkedList implementation with C++ as shared library.

## Building Repository

To build the repository you need CMake. You can download from [here](https://cmake.org/download/).
You can create a shortcut ```cmake``` command for macOS as below

```
sudo mkdir -p /usr/local/bin
sudo /Applications/CMake.app/Contents/bin/cmake-gui --install=/usr/local/bin
```

After cloning repository to your own local machine go to project root folder and run

```
cmake .
```

and then

```
cmake --build .
```

to run unit tests for UNIX machines

```
cd test
./tests --gtest_color=yes
```

and for Windows machines

```
cd test/Debug/
tests.exe --gtest_color=yes
```

## Sample Usage

Initiate linkedlist as below

```
LinkedList *linkedList = new LinkedList();
```

Initiation of Node

```
Node *next = new Node("next", nullptr);
Node *head = new Node("node", next);
```

Adding first node

```
linkedList->addFirst(head);
```

Getting first node's data

```
std::string data = linkedList->getFirst();
```

Removing head from LinkedList

```
std::string headData = linkedList->removeFirst()
```

Adding last node

```
Node *last = new Node("last", nullptr);
linkedList->addLast(last);
```

Adding data as node

```
std::string last = "last";
std::string head = "head";
linkedList->add(nullptr, head);
linkedList->add(linkedList->getHead(), last);
```

Clear LinkedList

```
linkedList->clear();
```

Searching for node data

```
Node *foundNode = linkedList->searchNode("mid");
```

Delete node

```
Node *node = linkedList->searchNode("mid");
bool isDeleted = linkedList->deleteNode(node);
```
