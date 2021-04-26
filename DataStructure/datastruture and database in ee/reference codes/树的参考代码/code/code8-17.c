int create_expression_tree(BiTree *tree, BiTreeNode *parent, BiTreeNodeSide side, char *p, int l) {
     // lnum记录"("的未成对个数；
     // rpst1/rpst2记录表达式中("*"、"/")/("+"、"-")的位置;
     // pn记录操作数中"."的个数,以判断输入操作数是否合法
    int i = 0, lnum = 0, rpst1 = -1, rpst2 = -1, pn = 0;
    if(l == 0)
        return 1;
    //判断表达式是否正确
    if(*p == '+' || *p == '*' || *p == '/' || *p == '.' || *p == ')') {
        printf("Wrong expression：not start with number or left bracket!\n");
        return 0;
    }
    if(!(*(p+l-1) == ')' || *(p+l-1) >= '0' && *(p+l-1) <= '9')) {
        printf("Wrong expression：not end with number or right bracket!\n");
        return 0;
    }
    if(*p == '(')
        lnum++;
    for(i = 1; i < l ; i++) {
        if(*(p+i) == '.') {
            if(!(*(p+i-1) >= '0' && *(p+i-1) <= '9')) {
                printf("Wrong expression: no number following dot(.)!\n");
                return 0;
            }
        } 
		else if(*(p+i) == '*' || *(p+i) == '/') {
            if(!(*(p+i-1) >= '0' && *(p+i-1) <= '9' || *(p+i-1) == ')')) {
                printf("Wrong expression: not number or right bracket on the left of (*)!\n");
                return 0;
            }
            if(lnum == 0)
                rpst1 = i;
        } 
		else if(*(p+i) == '(') {
            if(*(p+i-1) == '+' || *(p+i-1) == '-' || *(p+i-1) == '*' || *(p+i-1) == '/' || *(p+i-1) == '(')
                lnum++;
            else {
                printf("Wrong expression: unexpected char appears on the left of left bracket!\n");
                return 0;
            }
        } 
		else if(*(p+i) == ')') {
            if(*(p+i-1) == ')' || *(p+i-1) >= '0' && *(p+i-1) <= '9')
                lnum--;
            else {
                printf("Wrong expression: unexpected char appears on the left of right bracket!\n");
                return 0;
            }
            if(lnum < 0) {
                printf("Wrong expression: left bracket and right bracket not equal!\n");
                return 0;
            }
        } 
		else if(*(p+i) == '+' || *(p+i) == '-') {
            if(*(p+i) == '+' && !(*(p+i-1) >= '0' && *(p+i-1) <= '9' || *(p+i-1) == ')')) {
                printf("Wrong expression: unexpected char appears on the left of (+)!\n");
                return 0;
            } 
			else if(*(p+i) == '-' && !(*(p+i-1) >= '0' && *(p+i-1) <= '9' || *(p+i-1) == ')' || *(p+i-1) == '(')) {
                printf("Wrong expression: unexpected char appears on the left of (-)!\n");
                return 0;
            }
            if(lnum == 0)
                rpst2 = i;
        }
    }
    //"("、")"未能完全配对,表达式输入不合法
    if(lnum != 0) {
        printf("Wrong expression： left bracket and right bracket not equal!\n");
        return 0;
    }
    if(rpst2 > -1) {
        char *value = (char *)malloc(2*sizeof(char));
        strncpy(value, p+rpst2, 1);
        *(value + 1) = '\0';
        BiTreeNode * newNode = bitree_insert(tree, value, parent, side);
        if(create_expression_tree(tree, newNode, BITREE_NODE_LEFT, p, rpst2))
            if(create_expression_tree(tree, newNode, BITREE_NODE_RIGHT, p+rpst2+1, l-rpst2-1))
                return 1;
        return 0;
    }
    //此时表明表达式或者是一个数字，或是表达式整体被一对括弧括起来
    if(rpst1 < 0) {
        if(*p == '(') { //此时表达式整体被一对括弧括起来
            if(create_expression_tree(tree, parent, side, p+1, l-2))
                return 1;
            else
                return 0;
        } 
		else {
            if(*(p+1) != '(') {//此时表达式一定是一个数字
                for(i = 0; i < l; i++) {
                    if(*(p+i) == '.')
                        pn++;
                    if(pn > 1) {
                        printf("Wrong expression: more than one dot(.) found in a number!\n");
                        return 0;
                    }
                }
                char *value = (char *)malloc((l+1)*sizeof(char));
                strncpy(value, p, l);
                *(value+l) = '\0';
                bitree_insert(tree, value, parent, side);
                return 1;
            } 
			else {	//此时表达式首一定是操作符"-"，其余部分被一对括弧括起来
                char *value = (char *)malloc(2*sizeof(char));
                strncpy(value, p, 1);
                *(value+1) = '\0';
                BiTreeNode *newNode = bitree_insert(tree, value, parent, side);
                if(create_expression_tree(tree, newNode, BITREE_NODE_RIGHT, p+2, l-3))
                    return 1;
                else
                    return 0;
            }
        }
    } 
	else {	//此时表明表达式为几个因子相乘或相除而组成的
        char *value = (char *)malloc(2*sizeof(char));
        strncpy(value, p+rpst1, 1);
        *(value+1) = '\0';
        BiTreeNode *newNode = bitree_insert(tree, value, parent, side);
        if(create_expression_tree(tree, newNode, BITREE_NODE_LEFT, p, rpst1))
            if(create_expression_tree(tree, newNode, BITREE_NODE_RIGHT, p+rpst1+1, l-rpst1-1))
                return 1;
        return 0;
    }
}