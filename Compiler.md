## Scanner  

Scanner/Lex  
   
Regular Language //三型文法

RE(Regular Expression) // | () *  //可以参考FLex中的记法     
 ↓ Thompson's construction    
NFA(Nondeterministic Finite Automaton) //从某个状态出发，同一个字符可能对应多个不同的边（即产生不同的转移结果） //可能存在空字符对应的边(即空字符转换)，Thompson's construction会生成"空字符转换"         
 ↓ 幂集构造法(powerset construction)/子集构造法(subset construction)  //算法一定会终止 因为 设NFA的状态为n个 非空子集的个数不会超过$2^n-1$  
DFA(Deterministic Finite Automaton) //不同的终止状态对应Token的不同类型 //优化： DFA minimization    
  
DFA -> 转移表(translate table) //     

## Parser  

Parser/Syntax   

Context-Free Grammar //二型文法   
G = {N, T, P, S}  

产生式规则 //可以参考YACC中的记法

YACC约定 //Bison    
开始符号S 第一个产生式规则  
非终结符N 小写  
终结符T 大写  

BNF范式 //Coco/R  
非终结符N \<symbol\>  
终结符T $\underline{symbol}$  
  
给出结果 求推导过程(即 分析树) //可能产生不同的分析树 -> 二义性文法(比如 优先级) //文法重写 左递归文法(Expression Term Factor Atom)     
-> AST //开始符号S -> AST的根结点   

For example:  
exp-> n op n  
 n -> A  
 n -> B  
 n -> C  
 op -> E  
 op -> F  

### LL(1)  

LL能分析的文法类型受限（只适用于LL文法），并不被流行的GNU Bison所采用  

~~LL //**L**eft-to-right **L**eftmost derivation  
LL(1) //use **1** token of lookahead when parsing a sentence  
LL(1) 根据 当前的非终结符 和 1个前看符号(显然一定是终结符) 确定产生式规则 //**通过比较 前看符号和First_S集 从而确定产生式规则**      
//First_S集(针对某个产生式规则) 产生式规则 对应的 所有的推导结果中 可能出现的第1个符号(显然一定是终结符)~~  

~~//同一非终结符中 不同产生式规则的First_S集中 可能存在重复的符号 即LL(1)冲突 //存在回溯的可能  
//没有LL(1)冲突的上下文无关文法 称为LL(1)文法 //LL(1)文法 是 上下文无关文法 的特殊情形 //LL(1)的缺陷：能分析的文法类型受限制~~     

~~//一些文法改写的方式 // 尝试将非LL(1)文法转换为LL(1)文法~~      

~~//1\.<左递归消除>  
//比如 左递归文法一定不是LL(1)文法 //可以用 左递归消除 转换成LL(1)文法     
// exp -> exp + term  
// exp -> term  
// term -> term * factor //* 比 + 更高的优先级    
// term -> term  
// factor -> atom~~  

~~//左递归消除后：  
// exp -> term exp'  
// exp' -> + term  exp'
// exp' -> ε //空串  
// term -> factor term'  
// term' -> * factor term'  
// term' -> ε  
// factor -> atom~~  

~~//2\.<提取左公因子>  
//存在左公因子的文法也一定不是LL(1)文法  
// x -> A y //A为终结符    
// x -> A z~~  

~~//提取左公因子后：  
// x -> A x'  
// x' -> y  
// x' -> z~~  
  
~~//Nullable集 可能为空串的非终结符 //如果 某条产生式规则 右侧 都是Nullable  那么 左侧的非终结符号 也是Nullable  
//可以用不动点算法求出Nullable集~~      

~~//First集(针对某个非终结符) 整个上下文无法文法中 在所有的推导结果中 可能在某个非终结符中出现的第1个符号(显然一定是终结符)  
//可以用不动点算法求解 //非终结符开头 比如 n->x y 有 First(n) = First(x)\[当x不属于Nullable集\] 如果x可能为空 那么需要求出First(y)以此类推 从而复用计算结果~~   

~~//Follow集(针对某个非终结符) 整个上下文无法文法中 在所有的推导结果中 可能在某个非终结符之后出现的第1个符号(显然一定是终结符)  
//可以用不动点算法求解 //比如 n->x y z 有Follow(x)=First(y) \[当y不属于Nullable集\] 如果y可能为空 那么需要求出First(z)以此类推 从而复用计算结果~~  

~~//First_S集  
//比如 n->x y z //First_S(n->x y z) = First(x) \[当x不属于Nullable集\]  如果x可能为空 那么需要求出First(y)以此类推 如果x y z都可能为空 那么First_S(n->x y z) = Follow(n) //不需要用到不动点算法~~     


### LR(0) 
//LR //**L**eft-to-right **R**ightmost derivation //又叫Shift-Reduce算法 //自底向上(Bottom-up)分析    
LR(0) //use **0** token of lookahead when parsing a sentence  
 
//读入Token后尝试归约(Reduce)\[由产生式右侧到左侧\] //即自底向上分析 //最右推导的逆过程      
 
//点记号 // \<已经读入的Token **·** 剩余的输入Token\>   
//\<已经读入的Token>\ 处于栈中  

确定移进/归约的时机 //以 项目集 为状态的 DPDA（Deterministic Pushdown Automaton）    

//读入下一个Token //根据当前的状态（即栈顶的状态）和读入的Token（显然一定是终结符）——即<状态,非终结符>——查表 //查表的结果决定移进或归约（或提示语法错误）    
//移进(Shift)  //查表的结果得到转移后的状态 //将Token和转移后的状态都压入到栈中 //进行状态转移（当前状态即栈顶的状态） 点记号右移 //栈中同时有符号和状态   
//归约(Reduce) //得到产生式的右部（即 项目集 中 存在 点记号在最右侧 的项）时 查表的结果会得到用于归约的产生式 //弹出构成该产生式右部的符号和对应状态（状态和符号都在栈中） 压入相应的产生式的左部（显然一定是非终结符） //根据当前的状态（即栈顶的状态）和压入的左部——即<状态,非终结符>（注意，之前的二元组是<状态,终结符>）——再次进行查表 进行状态转移（即移进）或归约（和查表） //归约会不断进行，直到不能再归约为止（体现为，查表的结果为状态转移（即移进）而非归约） 整个过程不需要读入Token      

//构造项目集  
~~//对项目集中的每一条产生式 //对每一个符号（包括终结符和非终结符）进行测试 //点记号右移 //可以接受同一符号的产生式被归入新生成的同一个项目集~~   
//**点记号右侧为非终结符时 以该非终结符为左侧的产生式也会加入到项目集** //即closure运算      

//移进归约冲突 
//在某个项目集中 一部分产生式 点记号在最右侧（表明归约） 而一部分产生式 点记号不在最右侧（表明移进）   
//GNU Bison [Shift/Reduce Conflicts](https://www.gnu.org/software/bison/manual/html_node/Shift_002fReduce.html)    

缺点：
只要得到产生式的右部 就会进行归约（和查表） 且归约会不断进行，直到不能再归约为止 //会延迟错误发现的时机  //用前向符号解决 //比如LR(1)  
与LL一样 存在冲突的可能 //即存在回溯的可能   


LR分析表  //YACC: yytranslate_  

### SLR  
SLR //Simple LR    
在LR(0)基础上 在得到产生式的右部（即 项目集 中 存在 点记号在最右侧 的项）时 只对Follow集中的终结符进行归约 其它终结符查表提示错误  
//Follow集 还可以解决某些移进归约冲突  

### LR(1)  
LR(1) //use **1** token of lookahead when parsing a sentence  

LR(0) 项目集 中的 项 为 产生式  
LR(1) 项目集 中的 项 为 二元组\<产生式,终结符构成集合\> //终结符集合 比 产生式 左侧的Follow集更精确   

与LR(0)的区别在于closure运算  
比如 有\<\[x -\> A **.** y B\],\[{C,D}\]\> //点记号右侧为非终结符(即y)    
\<\[y -\> **.** E\],First_S(B(C|D))>会加入到项目集  

//构造s‘->s\$ //\$代表EOF  
//初始的二元组为\<\[s‘-\>s\$\],\[\$\]\>  

在分析时  
比如 有\<\[x -\> A **.** y B\],\[{C,D}\]\>  
将前看符号与First_S(B(C|D))比较作进一部判断  

### LALR(1)  
//流行的GNU Bison所采用  

在LR(1)的基础上，将相似的项目集合并 //负面影响：降低精确性    

### 移进归约冲突  
//GNU Bison [Shift/Reduce Conflicts](https://www.gnu.org/software/bison/manual/html_node/Shift_002fReduce.html)    

//比如：exp -> exp + exp //结合性（实际上属于二义性文法）      

//注意：点记号右侧为非终结符（即exp）时 以该非终结符（即exp）为左侧的产生式（即exp -> exp + exp）也会加入到项目集  

//\[exp -> exp **.** + exp\] -+-> \[exp -> exp + **.** exp\] -exp-> \[exp -> exp + exp **.** \] //表明归约  //发生移进归约冲突！     
\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\-\[exp -> **.** exp + exp\] -exp-> \[exp -> exp **.** + exp \] //表明移进    

//使用bison的-r state -r solved选项 在生成的*.output文件开头： State XXX conflicts: XXX shift/reduce //找到相应的State 进行进一步分析即可  

//YACC中 支持 %left '+' 解决结合性冲突  

//优先级、悬空的ELSE 也会产生类似的冲突  

//在实际中，LALR(1)的移进归约冲突大多是由**二义性文法**导致的   
//可以通过**消除二义性文法**来解决移进归约冲突   