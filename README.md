# Complier Design

## 用法

在linux直接运行start.sh即可，
在这个过程中会执行lex，yacc，以及g++编译，并且运行生成后的程序

生成后的程序为mycomp，
可以传入一个参数，表示待编译的文件名，例如“./testcode/test0.pas”；
若不传入参数，则可以在程序运行后手动输入文件路径

在start.sh中默认传入了一个测试文件名

## 说明

在编译过程中我采取了-g的debug编译模式，最后生成时可以删除掉

## 项目说明

一个小型的简化版的Pascal编译器

## 关于测试数据testcode

test0.pas是默认用于测试的
其他的还没改，有一些语法不一致，例如：
const a = 10; 而不是 const a:integer = 10;
test8.pas测试通过

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

##　关于cd_yacc_node.h的说明

### struct simple_type_decl_s;
对于RANGE_TYPE，包括      |  const_value  DOTDOT  const_value  
              			 |  MINUS  const_value  DOTDOT  const_value
                		 |  MINUS  const_value  DOTDOT  MINUS  const_value
                	     |  ID  DOTDOT  ID
可以通过判ID这个vector是否为空来判断是否是ID DOTDOT ID产生式，否则是其他三个产生式（其值存储在MIN,MAX）中

