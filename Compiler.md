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

### LL  

LL能分析的文法类型受限（只适用于LL文法），并不被流行的GNU Bison所采用  

~~LL //**L**eft-to-right **L**eftmost derivation  
LL(1) //use **1** tokens of lookahead  when parsing a sentence  
LL(1) 根据 当前的非终结符 和 1个前看符号(显然一定是终结符) 确定产生式规则 //**通过比较 前看符号和First_S集 从而确定产生式规则**      
//First_S集(针对某个产生式规则) 产生式规则 对应的 所有的推导结果中 可能出现的第1个符号(显然一定是终结符)~~  

~~//同一非终结符中 不同产生式规则的First_S集中 可能存在重复的符号 即LL(1)冲突 //存在有回溯的可能  
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


### LR 
//LR //**L**eft-to-right **R**ightmost derivation //又叫Shift-Reduce算法 //自底向上(Bottom-up)分析       
//流行的GNU Bison所采用  
 
//读入Token后尝试归约(Reduce)\[由产生式右侧到左侧\] //即自底向上分析 //最右推导的逆过程      
 
//点记号 // \<已经读入的Token **·** 剩余的输入Token\>   
//\<已经读入的Token>\ 处于栈中  
//移进(Shift) //即点记号右移 //将Token读入到栈中  
//归约(Reduce) //栈顶的若干个符号（构成某产生式的右部）弹出 压入相应的产生式的左部   

确定移

//YACC: yytranslate_  