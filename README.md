# Complier Design

## 项目说明

一个小型的简化版的Pascal编译器

## 用法

在linux直接运行start.sh即可，
在这个过程中会执行lex，yacc，以及g++编译，并且运行生成后的程序

生成后的程序为mycomp，
可以传入一个参数，表示待编译的文件名，例如“./testcode/test0.pas”；
若不传入参数，则可以在程序运行后手动输入文件路径

在start.sh中默认传入了一个测试文件名

## 说明&注意

在编译过程中我采取了-g的debug编译模式，最后生成时可以删除掉

在vector<xxx>的使用中，例如compound_stmt中，实际顺序应该是vector的逆序，
这和next的实际链表转换成vector的过程有关，为了方便就不改了，实际过程中，要注意一下

label是数字类型，即0001和001的label是一致的。

cd_yacc_node.h中struct simple_type_decl_s;
对于RANGE_TYPE，包括      |  const_value  DOTDOT  const_value  
              			 |  MINUS  const_value  DOTDOT  const_value
                		 |  MINUS  const_value  DOTDOT  MINUS  const_value
                	     |  ID  DOTDOT  ID
可以通过判ID这个vector是否为空来判断是否是ID DOTDOT ID产生式，否则是其他三个产生式（其值存储在MIN,MAX）中

case语句中label和case前面的int可能产生歧义？不会


## 关于测试数据testcode

test0.pas是默认用于测试的
其他的还没改，有一些语法不一致，例如：

1. const a = 10; 而不是 const a:integer = 10;

2. 函数或过程若没有参数则不参数列表的括号

3. for函数体begin .. end;不能省略（即使是一条语句）

4. if,else,while内的语句体也不能省略begin...end，
但是没有分号，在每一条语句后面才有分号

测试通过:

1. test8.pas

2. test7.pas

3. test1.pas

## 吐槽区

他这个文法设计的并不是很好，
例如ID，ID.ID，ID[expression]明明应该作为一个非终止符的产生式，但是却分开了
可见assgin_stmt和factor，有大量重复。

## TODO

以下内容不保证yacc实现完全。
SYS_PROC: "write", "writeln" 
SYS_FUNCT: "abs","chr","odd","ord","pred","sqr","sqrt","succ"
SYS_CON: "false", "maxint", "true"
SYS_TYPE: "integer", "real", "boolean", "char"

const_value 中的 STRING是不是不要实现了。

Yacc中要实现个UpperClass，对于一些公用的标识符，统一转换成大写。