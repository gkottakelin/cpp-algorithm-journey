#include <iostream>
#include <vector>

using namespace std;

// 定义两个取模常量
const long long MOD = 998244353;       // 最终结果的模数
const long long MOD_PHI = 998244352;   // 根据费马小定理，指数需要取模的值 (MOD - 1)

// 为了方便操作，给二维矩阵起个别名
typedef vector<vector<long long>> Matrix;

// 1. 矩阵乘法函数 (对 MOD_PHI 取模)
Matrix multiply(Matrix A, Matrix B) {
    Matrix C(2, vector<long long>(2, 0));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                // 注意这里是对指数的模 MOD_PHI 取模
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD_PHI;
            }
        }
    }
    return C;
}

// 2. 矩阵快速幂函数 (计算矩阵 A 的 p 次方)
Matrix matrix_pow(Matrix A, long long p) {
    Matrix res = {{1, 0}, {0, 1}}; // 初始化为单位矩阵
    while (p > 0) {
        if (p % 2 == 1) res = multiply(res, A);
        A = multiply(A, A);
        p /= 2;
    }
    return res;
}

// 3. 普通数字快速幂函数 (计算 base^exp % MOD)
long long fast_pow(long long base, long long exp) {
    long long res = 1;
    base %= MOD; // 底数对 MOD 取模
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

int main() {
    // 优化输入输出速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (!(cin >> n)) return 0;

    // 构建初始状态矩阵 (用于生成斐波那契数列)
    Matrix T = {{1, 1}, 
                {1, 0}};
    
    // 计算转移矩阵的 n 次方
    Matrix Tn = matrix_pow(T, n);

    // 根据公式: Tn = [[Fn+1, Fn], [Fn, Fn-1]]
    // 获取 2 的指数 E2 = Fn
    long long E2 = Tn[0][1];
    
    // 获取 3 的指数 E3 = Fn+1 - 1
    // 注意：减 1 后可能会变成负数，因此需要 + MOD_PHI 再取模来保证是正数
    long long E3 = (Tn[0][0] - 1 + MOD_PHI) % MOD_PHI; 

    // 分别计算 2^E2 和 3^E3
    long long ans2 = fast_pow(2, E2);
    long long ans3 = fast_pow(3, E3);

    // 计算最终乘积并取模
    long long final_ans = (ans2 * ans3) % MOD;
    
    cout << final_ans << "\n";

    return 0;
}








// 获取数组中的最大值，用于确定数字的最大位数
int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > mx) {
            mx = arr[i];
        }
    }
    return mx;
}
// 基于 exp 表示的特定位进行计数排序
void countSort(int arr[], int n, int exp) {
    int* output = new int[n]; 
    int i, count[10] = { 0 };
    // 在 count[] 中存储出现的次数
    for (i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    // 更新 count 数组以存储实际位置
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    // 构建输出数组以保持稳定性
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    // 将输出复制回原数组
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }
    // 释放动态内存以防止内存泄漏
    delete[] output; 
}
// 主基数排序函数
void radixSort(int arr[], int n) {
    int m = getMax(arr, n); // 调用 getMax 函数获取最大值
    // 从最低位到最高位对每个数字进行计数排序
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
    }
}

