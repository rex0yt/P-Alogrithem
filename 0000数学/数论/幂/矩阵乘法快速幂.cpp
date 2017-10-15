/*
*	矩阵乘法 以及 矩阵快速幂
*	定义矩阵结构体以及乘法运算
*	二位数组下标从 1 开始
*
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int matN = 100;
const int matn = 4;

struct Matrix
{
    int mat[matN][matN];
};

void inputMat(Matrix &a)
{
    for(int i = 1; i <= matn; i ++)
        for(int j = 1; j <= matn; j ++)
            cin >> a.mat[i][j];
    return ;
}
void outputMat(Matrix &a)
{
    for(int i = 1; i <= matn; i ++)
    {
        for(int j = 1; j <= matn; j ++)
        {
            printf("%5d", a.mat[i][j]);
        }
        printf("\n");
    }
}
Matrix operator * (Matrix &a, Matrix &b)
{
    Matrix c;
    for(int i = 1; i <= matn; i ++)
    {
        for(int j = 1; j <= matn; j ++)
        {
            c.mat[i][j] = 0;
            for(int k = 1; k <= matn; k ++)
                c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
        }
    }
    return c;
}
Matrix operator ^ (Matrix &a, int k)
{
    Matrix c;
    for(int i = 1; i <= matn; i ++)
        for(int j = 1; j <= matn; j ++)
            c.mat[i][j] = (i == j);		//初始化为单位矩阵
    for(; k; k >>= 1)
    {
        if(k & 1) c = a * c;
        a = a * a;
    }
    return c;
}

int main()
{
    Matrix a;
    inputMat(a);
    Matrix b = a ^ 8;
    outputMat(b);

    return 0;
}
