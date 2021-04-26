int main(void) {
    char exp3[] = "-2+3/1.5-(10*3)+40";
    char exp4[] = "-(3+4*5)+1*2.5";
    double rst = 0;
    do_expression_calculate(exp3, &rst);
    printf(" = %.1f\n", rst);
    do_expression_calculate(exp4, &rst);
    printf(" = %.1f\n",rst);
    return 0;
}

int do_expression_calculate(char *exp, double *rst) {
    int l = strlen(exp);
    BiTree *tree = bitree_new();
    create_expression_tree(tree, tree->rootnode, BITREE_NODE_LEFT, exp, l);
    in_order_print(tree->rootnode);
    calculate(tree->rootnode, rst);
    post_order_free(tree->rootnode);
    bitree_free(tree);
}