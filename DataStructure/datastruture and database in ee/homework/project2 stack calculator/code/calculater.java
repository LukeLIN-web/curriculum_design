import java.util.*;
/*
 *编程对于可能含有以下运算符的表达式计算结果。

1：+、-、*、/、%：四则运算  %优先级高于 加减 ,等于乘. 已完成

2：>>、<<：移位运算 , <<  优先级低于 加减 ; 已完成
3：能够处理单目运算符，例如阶乘(!)
4：(、)：括号内优先，可嵌套 已完成
5. 能够处理小数
 */
public class calculater {
    //计算表达式的值
    public void getExpressionValue(String A){
        char[] arrayA = A.toCharArray();
        Stack<Integer> Value = new Stack<Integer>();      //存放运算数字及表达式计算结果
        Stack<Character> Operator =  new Stack<Character>();   //存放运算符
        for(int i = 0;i < A.length();i++){
            int temp = 0;
            //如果是数字
            if(arrayA[i] >= '0' && arrayA[i] <= '9'){  
                temp = arrayA[i] - '0';
                i = i + 1;
                while(i < A.length() && arrayA[i] >= '0' && arrayA[i] <= '9'){
                    temp = temp * 10 + (arrayA[i] - '0');//读数字.
                    i++;
                }
                i--;     //对应上面一句i = i+1;因为在for循环中有i++自增操作，若不执行此句，会导致i自增两次
                Value.push(temp);
            }
            //如果是运算符
            else{
            	//如果是单目运算符
            	if(arrayA[i] == '!') {
            		int tempA = Value.pop();
            		int res = addArray(tempA);
            		Value.push(res);
            	}
            	else{
            	// 如果是双目运算符
	                if(Operator.empty()){
	                   Operator.push(arrayA[i]);  //如果运算符栈是空的就直接存放操作符.
	                }
	                else{
	                    char temp1 = Operator.pop();   //进栈前，pop出运算符栈中栈顶存放字符
	                    int tempA , tempB,result;
	                    int judge = comparePriority(temp1,arrayA[i]);  //比较当前运算符与temp1栈顶运算符优先级
	                    switch (judge) {
		                    case 1:
		                    {           //当前运算符优先级小于等于栈顶运算符,  先计算栈顶两个数字.
		                        tempA = Value.pop();
		                        tempB = Value.pop();
		                        result = computeNumber(tempB,tempA,temp1);
		                        Value.push(result);
		                        Operator.push(arrayA[i]);
		                        break;
		                    }
		                    case 0:
		                    {           //当前运算符优先级大于栈顶运算符,再放回去看看之后有没有更大的.
		                        Operator.push(temp1);  //pop出来的要push回去.
		                        Operator.push(arrayA[i]); //先计算arrayA[i]
		                        break;
		                    }
		                    case 2 :
		                    {  //字符')'遇到'('  当前字符')' 栈顶字符'('
		                        System.out.println("'('刚好遇到')'");   //这种情况也应该不会出现，按照给定优先级，')'一般会先遇到+、-、*、/字符
		                        break;
		                    }
		                    case 3: 
		                    {   //此时')'刚好准备进栈
		                        while(temp1 != '('){          //')'字符要等到第一个'('出栈才能结束循环
		                            //System.out.println(temp1);
		                            tempA = Value.pop();
		                            tempB = Value.pop();
		                            result = computeNumber(tempB,tempA,temp1);
		                            Value.push(result);
		                            temp1 = Operator.pop();  
		                        }
		                        break;
		                    }
		                    case 4:
		                           tempA = Value.pop();
		                           tempB = Value.pop();
		                           result = tempB<<tempA ;
		                           Value.push(result);
		                           break ; 
		                    case 5: 
		                           tempA = Value.pop();
		                           tempB = Value.pop();
		                           result = tempB>>tempA ;
		                           Value.push(result);
		                           break ; 
		                    default:  
		                    	System.out.println("出现栈顶有')'错误！！！");// if(judge == -1){    //此时，说明当前栈顶字符为')'，这是不存在的，因为遇到')'，按要求不让进栈
		                }
	                  }
            	}
            }
        }
        
        while(!Operator.empty() && !Value.empty()){   //此时，字符栈中还存在运算符的情况
            char temp1 = Operator.pop();
            char temp2 ;
            int result = 0 ;
            int tempA = Value.pop();
            int tempB = Value.pop();
            switch(temp1){
	            case '<':
	            	temp2 = Operator.pop();
	            	if(temp2 == '<') 
	            		result = tempB<<tempA ;
	            	else 
	            		System.out.println("出现移位运算不对应错误！！！");
	            	break;
	            case '>':
	            	temp2 = Operator.pop();
	            	if(temp2 == '>') 
	            		result = tempB>>tempA ;
	            	else 
	            		System.out.println("出现移位运算不对应错误！！！");
	            	break;
	            default:
	            	result = computeNumber(tempB,tempA,temp1);
            }
            Value.push(result);
        }
        System.out.println(Value.pop());   //此时运算符栈为空，数字栈中只存在表达式计算最终结果
    }
    //计算a operator b的值，operator = {+,-,*,/,%,<<,}
    public int computeNumber(int a,int b,char operator){
        int result;
        switch(operator){
        case '+': 
            result = a+b;
            break;
        case '-':
            result = a-b;
            break;
        case '*': 
            result = a*b;
            break;
        case '/': 
            result = a/b;
            break;        
        case '%':
        	result = a%b;
        	break;
        default:  
            result = 0;
            break;
        }
        return result;
    }
    //判断运算符a和b的优先级 返回1表示 栈顶字符a优先级大于等于b当前字符.  comparePriority(temp1,arrayA[i]); 
    public int comparePriority(char a,char b){
        //使用二维数组表达运算符之间的优先级，行用字符a表示，列用字符b表示,
        int[][] Value = {
        		{1,1,0,0,0,3,0,1,1},
                {1,1,0,0,0,3,0,1,1},
                {1,1,1,1,0,3,1,1,1},  	// 第七列是 %,第八列是 <,第九列是> 
                {1,1,1,1,0,3,1,1,1},
                {0,0,0,0,0,2,0,1,1},
                {-1,-1,-1,-1,-1,-1,-1,-1,-1},//此时，说明当前栈顶字符为')'，这是不存在的，因为遇到')'，按要求不让进栈
                {1,1,1,1,0,3,1,1,1},   	// %的优先级和乘除一样
                {0,0,0,0,0,3,0,4,-1}, 	// <的优先级比目前所有都低,所以第八列第九列是1 
                {0,0,0,0,0,3,0,-1,5}		// >的优先级比目前所有都低,所以第八列第九列是1  遇到自己要特殊处理
        };
        int i = 0,j = 0;// a= +, b = * 那就是[0][2]   返回0  ,栈顶字符a也就是temp1优先级小于b当前字符arrayA[i]
        switch(a) {
        	case '+' :
        		i = 0;// a= +, b = < 那就是[0][7]   返回1  ,栈顶字符a也就是temp1优先级大于b当前字符arrayA[i]
        		break;
        	case '-' :
        		i = 1;
        		break;
        	case '*' :
        		i = 2;
        		break;
        	case '/' :
        		i = 3;
        		break;
        	case '(' :  // a= (, b = * 那就是[4][2] ,也就是0  栈顶字符a也就是temp1优先级小于b当前字符arrayA[i] ,括号优先级比较高
        		i = 4;
        		break;
        	case ')' :
        		i = 5;
        		break;
        	case '%' :
        		i = 6;
        		break;
        	case '<' :
        		i = 7;// a= <, b = * 那就是[7][2]   返回0    ,栈顶字符a也就是temp1优先级小于b当前字符arrayA[i]
        		break;
        	case '>' :
        		i = 8;// temp  = '>', 当前字符arrayA[i]  都比他大
        		break;
        }
     
        switch(b) {
    	case '+' :
    		j = 0;
    		break;
    	case '-' :
    		j = 1;
    		break;
    	case '*' :
    		j = 2;
    		break;
    	case '/' :
    		j = 3;
    		break;
    	case '(' :
    		j = 4;
    		break;
    	case ')' :
    		j = 5;
    		break;
    	case '%' :
    		j = 6;
    		break;
    	case '<' :
    		i = 7;
    		break;
    	case '>' :
    		i = 8;
    		break;
        }
        return Value[i][j];
    }
    
    public static void main(String[] args){
        calculater test = new calculater(); 
       // Scanner in = new Scanner(System.in);
      //  System.out.println("请输入一个算法表达式：");
       // String A = in.nextLine();
        String A  = "1-2*((2+3)*2-(2+3))";
        String B = "1%2-2*((2+3)*2-(2+3))";
        String c = "1%2-2+3*(4-5)";
        String d =  "1<<3+2";
        String e =  "4!+3";
        String f = "-1.1+2*3=";
        test.getExpressionValue(e);
        Calculator calc = new Calculator();
        Double result;
            // 计算处理
            result = calc.prepareParam(f);
            if (result != null) {
                // 处理结果并打印
                System.out.println(
                        MyUtils.formatResult(String.format("%." + MyUtils.RESULT_DECIMAL_MAX_LENGTH + "f", result)));
            }
    }
    
    public static int addArray(int num){//数组添加计算阶乘
    	int[]arr = new int[21];//创建数组
    	arr[0] = 1;
    	int last = 0;
    	if(num >= arr.length){
    		throw new IllegalArgumentException("传入的值太大");//抛出传入的数太大
    	}
    	if(num < 0)
    		throw new IllegalArgumentException("必须为正整数!");//抛出不合理参数异常
    	while(last < num){//建立满足小于传入数的while循环
    		arr[last+1] = arr[last]*(last+1);//进行运算
    		last++;//last先进行运算，再将last的值加1
    	}
    	return arr[num];
   }
}

class MyUtils {
    public static final int FORMAT_MAX_LENGTH = 500;// 表达式最大长度限制
    public static final int RESULT_DECIMAL_MAX_LENGTH = 8;// 结果小数点最大长度限制
    public static final Map<Character, Integer> symLvMap = new HashMap<Character, Integer>();// 符号优先级map
    static {
        symLvMap.put('=', 0);
        symLvMap.put('-', 1);
        symLvMap.put('+', 1);
        symLvMap.put('*', 2);
        symLvMap.put('/', 2);
        symLvMap.put('(', 3);
        symLvMap.put(')', 1);
    }
    /**
     * 
     * @Title: change2StandardFormat
     * @Desc: 处理表达式格式为标准格式，如2(-1+2)(3+4)改为2*(0-1+2)*(3+4)
     *
     * @param str
     * @return 标准表达式
     *
     */
    public static String change2StandardFormat(String str) {
        StringBuilder sb = new StringBuilder();
        char c;
        for (int i = 0; i < str.length(); i++) {
            c = str.charAt(i);
            if (i != 0 && c == '(' && (isCharNum(str.charAt(i - 1)) || str.charAt(i - 1) == ')')) {
                sb.append("*(");
                continue;
            }
            if (c == '-' && str.charAt(i - 1) == '(') {
                sb.append("0-");
                continue;
            }
            sb.append(c);
        }
        return sb.toString();
    }

    /**
     * 
     * @Title: isBracketCouple
     * @Desc: 校验括号是否配对
     * @param str
     * @return 参数
     *
     */
    public static boolean isBracketCouple(String str) {
        LinkedList<Character> stack = new LinkedList<>();
        for (char c : str.toCharArray()) {
            if (c == '(') {
                stack.add(c);
            } else if (c == ')') {
                if (stack.isEmpty()) {
                    return false;
                }
                stack.removeLast();
            }
        }
        if (stack.isEmpty()) {
            return true;
        } else {
            return false;
        }

    }

    /**
     * 
     * @Title: formatResult
     * @Desc: 处理计算结果的显示
     *
     * @param str计算结果
     * @return 规范的计算结果
     *
     */
    public static String formatResult(String str) {
        String[] ss = str.split("\\.");
        if (Integer.parseInt(ss[1]) == 0) {
            return ss[0];// 整数
        }
        String s1 = new StringBuilder(ss[1]).reverse().toString();
        int start = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1.charAt(i) != '0') {
                start = i;
                break;
            }
        }
        return ss[0] + "." + new StringBuilder(s1.substring(start, s1.length())).reverse();
    }

    /**
     * 
     * @Title: isCorrectChar
     * @Desc: 校验字符是否合法
     *
     * @param c
     * @return 参数
     *
     */
    public static boolean isCorrectChar(Character c) {
        if (('0' <= c && c <= '9') || c == '-' || c == '+' || c == '*' || c == '/' || c == '(' || c == ')'
                || c == '.') {
            return true;
        }
        return false;
    }

    public static boolean isCharNum(Character c) {
        if (c >= '0' && c <= '9') 
            return true;
        else
        return false;
    }
    public static double plus(double num1, double num2) {
        return num1 + num2;
    }
    public static double reduce(double num1, double num2) {
        return num1 - num2;
    }
    public static double multiply(double num1, double num2) {
        return num1 * num2;
    }
    public static double divide(double num1, double num2) {
        return num1 / num2;
    }
}
class Calculator {
    /**
     * 
     * @Title: PrepareParam
     * @Desc: 准备计算的数据，符号
     *
     * @param str计算式
     * @return 计算结果
     *
     */
    public Double prepareParam(String str) {
        // 空值校验
        if (null == str || "".equals(str)) {
            return null;
        }
        // 长度校验
        if (str.length() > MyUtils.FORMAT_MAX_LENGTH) {
            System.out.println("表达式过长！");
            return null;
        }
        // 预处理
        str = str.replaceAll(" ", "");// 去空格
        if ('-' == str.charAt(0)) {// 开头为负数，如-1，改为0-1
            str = 0 + str;
        }
        // 处理表达式，改为标准表达式
        str = MyUtils.change2StandardFormat(str);
        // 拆分字符和数字
        String[] nums = str.split("[^.0-9]");
        List<Double> numLst = new ArrayList();
        for (int i = 0; i < nums.length; i++) {
            if (!"".equals(nums[i])) {
                numLst.add(Double.parseDouble(nums[i]));
            }
        }
        String symStr = str.replaceAll("[.0-9]", "");
        return doCalculate(symStr, numLst);
    }

    /**
     * 
     * @Title: doCalculate
     * @Desc: 计算
     *
     * @param symStr符号串
     * @param numLst数字集合
     * @return 计算结果
     *
     */
    public Double doCalculate(String symStr, List<Double> numLst) {
        LinkedList<Character> symStack = new LinkedList<>();// 符号栈
        LinkedList<Double> numStack = new LinkedList<>();// 数字栈
        int i = 0;// numLst的标志位
        int j = 0;// symStr的标志位
        char sym;// 符号
        double num1, num2;// 符号前后两个数
        while (symStack.isEmpty() || !(symStack.getLast() == '=' && symStr.charAt(j) == '=')) {
            if (symStack.isEmpty()) {
                symStack.add('=');
                numStack.add(numLst.get(i++));
            }
            if (MyUtils.symLvMap.get(symStr.charAt(j)) > MyUtils.symLvMap.get(symStack.getLast())) {// 比较符号优先级，若当前符号优先级大于前一个则压栈
                if (symStr.charAt(j) == '(') {
                    symStack.add(symStr.charAt(j++));
                    continue;
                }
                numStack.add(numLst.get(i++));
                symStack.add(symStr.charAt(j++));
            } else {// 当前符号优先级小于等于前一个 符号的优先级
                if (symStr.charAt(j) == ')' && symStack.getLast() == '(') {// 若（）之间没有符号，则“（”出栈
                    j++;
                    symStack.removeLast();
                    continue;
                }
                if (symStack.getLast() == '(') {// “（”直接压栈
                    numStack.add(numLst.get(i++));
                    symStack.add(symStr.charAt(j++));
                    continue;
                }
                num2 = numStack.removeLast();
                num1 = numStack.removeLast();
                sym = symStack.removeLast();
                switch (sym) {
                case '+':
                    numStack.add(MyUtils.plus(num1, num2));
                    break;
                case '-':
                    numStack.add(MyUtils.reduce(num1, num2));
                    break;
                case '*':
                    numStack.add(MyUtils.multiply(num1, num2));
                    break;
                case '/':
                    if (num2 == 0) {// 除数为0
                        System.out.println("存在除数为0");
                        return null;
                    }
                    numStack.add(MyUtils.divide(num1, num2));
                    break;
                }
            }
        }
        return numStack.removeLast();
    }
}