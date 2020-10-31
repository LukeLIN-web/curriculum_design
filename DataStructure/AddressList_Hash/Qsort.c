void Qsort1(int a[], int low, int high)
{
    int pivot = a[low], s = low, t = s;
    int temp;
    if (low >= high) return;
    while (t <= high){
        if (a[t] <= pivot){
            Swap(a, s, t);/* 将其交换到 [s t] 之首 */
            s++;/* a[s] 划分到 “小的”部分*/

        }
        t++;
    }
    s--;
    a[low] = a[s];
    a[s] = pivot;
    Qsort1(a, low, s-1);
    Qsort1(a, s+1, high);
}



//重复下面两个过程，直到划分完毕（s = t ）
//从 t 开始由后往前搜索 ( t--)，直到找到一个小于pivot 的值a[t]，将A[t]存于A[s]；
//从 s开始由前往后搜索( s++)，直到找到一个大于pivot的A[s]，将A[s] 存于A[t]；
// 快排(左右往中间走) O(nlogn)，最差情况O(n^2)，倒序时
void Qsort2(int a[], int low, int high)
{
     int s = low, t = high, pivot = a[ s ];  //pivot 先存好a[s];
     if (low >= high) return;
     while ( s < t ) {
          while (t > s && a[ t ] >= pivot )  -- t; //找到a[t]<pivot 
          a[ s ] = a[ t ];  /* 将比key小的移到前面 */
          while ( s < t && a[ s ] <= pivot) ++ s;
          a[ t ] = a[ s ]; /*将比key大的移到后面,一次换一个*/
      }
     a[ s ] = pivot; /* 将key 保存回到数组 */
     Qsort2(a, low, s - 1); /* 递归 */
     Qsort2(a, s + 1, high); /* 递归 */
}

