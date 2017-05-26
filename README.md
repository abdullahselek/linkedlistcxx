# linkedlistcxx

[![Build Status](https://travis-ci.org/abdullahselek/linkedlistcxx.svg?branch=master)](https://travis-ci.org/abdullahselek/linkedlistcxx)
[![Build status](https://ci.appveyor.com/api/projects/status/5ku2a2q2kjcvlr1u?svg=true)](https://ci.appveyor.com/project/abdullahselek/linkedlistcxx)

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
LinkedList<std::string> *linkedList = new LinkedList<std::string>();
```

Initiation of Node

```
std::string strNext("next");
std::string strNode("node");

Node<std::string> *next = new Node<std::string>(strNext, nullptr);
Node<std::string> *node = new Node<std::string>(strNode, next);
```

Adding first node

```
std::string strFirst("first");
Node<std::string> *first = new Node<std::string>(strFirst, nullptr);
linkedList->addFirst(first);
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
std::string strLast("last");
Node<std::string> *last = new Node<std::string>(strLast, nullptr);
```

Adding data as node

```
std::string last("last");
std::string head("head");
linkedList->add(nullptr, head);
linkedList->add(linkedList->getHead(), last);
```

Clear LinkedList

```
linkedList->clear();
```

Searching for node data

```
std::string mid("mid");
Node<std::string> *foundNode = linkedList->searchNode(mid);
```

Delete node

```
std::string mid("mid");
Node<std::string> *node = linkedList->searchNode(mid);
bool isDeleted = linkedList->deleteNode(node);
```
