/*
 * @?: *********************************************************************
 * @Author: Weidows
 * @Date: 2021-10-19 23:13:19
 * @LastEditors: Weidows
 * @LastEditTime: 2021-10-19 23:14:33
 * @FilePath: \C++\src\demos\sort\QuickSort.cpp
 * @Description:
 * @!: *********************************************************************
 */
#include "stdio.h"
#define LEN 10
int count; //全局变量，记录次数
void Printarr(int a[])
{
  if (count == 0)
  {
    printf(" 数组元素的初始值是：");
    count++;
  }
  else
  {
    printf("确定第%d个元素的结果：", count++);
  }
  for (int n = 0; n < LEN; n++)
  {
    printf("%d\t", a[n]);
  }
  printf("\n");
}
void Swap(int *x, int *y)
{
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}
int Partition(int a[], int p, int r)
{
  int i = p, j = r + 1;
  int x = a[p];
  while (true)
  {
    while (a[++i] < x && i < r)
      ;
    while (a[--j] > x)
      ;
    if (i >= j)
    {
      break;
    }
    Swap(&a[i], &a[j]);
  }
  a[p] = a[j];
  a[j] = x;
  printf("\n确定第%d个元素的值是：%d %d\n", count, j, a[j]);
  return j;
}
void QuickSort(int a[], int p, int r)
{
  if (p < r)
  {
    int q = Partition(a, p, r);
    Printarr(a);
    QuickSort(a, p, q - 1); //对左半段排序
    QuickSort(a, q + 1, r); //对右半段排序
  }
}
int main(int argc, char *argv[])
{
  int a[LEN] = {49, 38, 65, 97, 76, 13, 27, 49, 8, 10};
  Printarr(a); //打印初始值
  QuickSort(a, 0, LEN - 1);
  return 0;
}
