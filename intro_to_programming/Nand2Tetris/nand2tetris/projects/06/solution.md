### 应该有哪些类？

AsmFileProcesser, 内部与一个asm文件绑定，每次调用其processOneLine都读取一行并返回去掉空格和注释的字符串。需要对非法格式进行处理（退出程序）。

ResolutionMan,内部与一个新的hack文件绑定，每次从AsmFileProcesser获取一行就对这一行的内容进行解析，解析之后输出内容。

SymbolTable,内部是一个map<string, int>，初始化时只有预定义的常量，向外部暴露getAddress(string)方法，如果要获取地址的字符串没有存在于map中，即为变量，需要添加到map中。（变量的地址从16开始增长）。

### 类设计

AsmFileProcesser

- 类成员
  - ifstream asmFile，用于与asm文件绑定
- 类方法
  - processOneLine，从asmFile中读取有效的一行，若为空行则抛弃（包括只有注释的一行），若有效则返回，并且需要在字符串串首加上\`a  or \`c or `l。遇到语法错误的行则抛出运行时异常。如果遇到文件尾则返回空串。



ResolutionMan

- 类成员

  - ofstream hackFile, 用于绑定输出到新hack文件。
  - SymbolTable st, 用于存储符号表。

- 类方法

  - translateAInstruction, 接收一个a指令字符串，返回机器码对应的字符串。
  - translateCInstruction,接收一个c指令字符串，返回对应机器码的字符串，期间可能使用符号表成员，**只查询**。

  - resolution, 得到一个符合语法规范的字符串，判断是c指令还是a指令，传入对应的处理方法，得到结果后写入hackFile。

SymbolTable

- 类成员
  - map<string, unsigned> nameToAddress，存储符号表的数据结构。
  - unsigned counter = 16，用于给新变量指定地址，每次要加1。
- 类方法
  - findAddresss(string)，如果有就返回对应的值，否则返回-1。
  - getAddress(string)，先find,如果返回值是-1,则调用addVariable(string)。
  - addVariable(string)，将counter的值给新变量，counter++。

Scanner

- 类成员
  - SymbolTable st。
  - AsmFIleProcesser afp, 用于获取指令。
  - unsigned counter，用于计数扫描时有效行数。
- 类方法
  - getSymbolTable，返回对st的const引用。
  - scanning，使用asmFile成员对符号表进行处理。主要是将label和变量值添加到符号表中。



当前功能：

1. 将.asm文件的空行和注释行去掉，输入有效行，并以\`c \`a \`l来帮助分辨c和a指令、label. 
2. 将.asm文件中的符号存储到一个符号表中。

接下来：ResolutionMan

- 成员变量

  - Scanner scanner，进行label和变量的地址处理。
  - AsmFileProcesser* afp。
  - std::string asmFileName;
  - std::string hackFileName;
  - std::ofstream os;

- 成员方法

  - resoluting(): 调用scanner的scanning()方法。

    给afp分配空间，afp = new AsmFileProcessor(asmFileName)。

    循环调用processOneLine ()方法，直到文件尾。

  - processOneLine():从afp中获取一行，如果是无效指令，返回false 。否则：

    1. 判断是c,a,还是l,如果是l,直接返回true.
    2. a指令，如果是数字，转成16位2进制数输出到os。
    3. c指令...

- 构造函数

  - ResolutionMan(const std::string & afn, const std::string& hfn) : 用afn,hfn初始化asmFileName 和 os和scanner。



