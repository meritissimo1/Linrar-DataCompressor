
# 42Compress

  

This project consists of developing a data analysis and compression application. This application will use the Huffman compression algorithm and will be able to receive multiple data, where once compressed it should be decompressed and collect relevant information for the analysis of the process and data.

For this, we need to create two programs `encoder` and `decoder`  that will communicate using *shared memory operations*

### Huffman Algorithm
The Huffman algorithm is a lossless data compression algorithm. It works by creating a binary tree of nodes, where each leaf node represents a character from the input string, and each non-leaf node represents a combination of two characters. The compressed data is then generated by traversing the tree and representing each character with a unique binary code based on the path from the root to the leaf node representing that character. This code is usually shorter for characters that appear more frequently in the input string, resulting in a efficient compression.

### Shared Memory
Shared memory is a method of inter-process communication (IPC) in which multiple processes can access a common region of memory. This allows the processes to share data and synchronize their execution without the need for explicit message passing.

In this project a file ``Fabin.42`` will be used to share memory between the two processes.
 

## 🚀 Starting

  

These instructions will allow you to obtain a copy of the project running on your local machine for development and testing purposes.

  

### 📋 Prerequisite

Before getting started, you will need to have the following tools installed on your machine: gcc, [Git](https://git-scm.com), C libraries.

  

```

$ sudo apt update

$ sudo apt install build-essential

```

  

### 🔧 Installing

  

# Clone this repository

```

$ git clone <https://github.com/meritissimo1/Linrar-DataCompressor.git>

```

  

# Run the application
```
$ make
```
Create a file
```
$ echo "testing" > file.txt  
```
Run
```
$ ./encoder file.txt
```
### 🚩 Flags

-t: Enables the option to compress a text as a parameter, example:
```
$ ./encoder -t "TEXT"
```

### Decoder
``` 
$ ./decoder
```
  

### 🛠 Technologies

  

The following tools were used in building the project:

* [Makefile](https://makefile.site/)

* [C](https://www.cprogramming.com/)


## Contributors

Thanks goes to these people and and everyone who helped in the chats.
<table>
  <tbody>
    <tr>
      <td align="center"><a href="https://github.com/fnacarellidev"><img src="https://avatars.githubusercontent.com/u/97247063?v=4" width="100px;" alt="Fabin"/><br /><sub><b>Fabin</b>
         <td align="center"><a href="https://github.com/renanguillen?tab=following"><img src="https://avatars.githubusercontent.com/u/87039111?v=4" width="100px;" alt="Renan"/><br /><sub><b>Renan</b>
            <td align="center"><a href="https://github.com/Guiribei"><img src="https://avatars.githubusercontent.com/u/85483589?v=4" width="100px;" alt="Guilherme"/><br /><sub><b>Guilherme</b> 
           <td align="center"><a href="https://github.com/erick-medeiros"><img src="https://avatars.githubusercontent.com/u/49819787?v=4" width="100px;" alt="Erick"/><br /><sub><b>Erick</b> 
           <td align="center"><a href="https://github.com/willianportilho"><img src="https://avatars.githubusercontent.com/u/76135314?v=4" width="100px;" alt="Willian"/><br /><sub><b>Willian</b> 
           <td align="center"><a href="https://github.com/rgenge"><img src="https://avatars.githubusercontent.com/u/82456124?v=4" width="100px;" alt="Atila"/><br /><sub><b>Atila</b>      
   </tr>
  </tbody>
  <tfoot>
    
  </tfoot>
</table>
