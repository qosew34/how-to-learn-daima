/*本题目要求一元二次方程ax2＋bx＋c＝0的根，结果保留2位小数。（注意：0.00会在gcc下被输出为-0.00，需要做特殊处理，输出正确的0.00。）
输入格式:

输入在一行中给出3个浮点系数a、b、c，中间用空格分开。
输出格式:

根据系数情况，输出不同结果：

1)如果方程有两个不相等的实数根，则每行输出一个根，先大后小；

2)如果方程有两个不相等复数根，则每行按照格式“实部+虚部i”输出一个根，先输出虚部为正的，后输出虚部为负的；

3)如果方程只有一个根，则直接输出此根；

4)如果系数都为0，则输出"Zero Equation"；

5)如果a和b为0，c不为0，则输出"Not An Equation"。*/
/*
#include <bits/stdc++.h>
using namespace std;
int main(){
double a,b,c;
cin>>a>>b>>c;
if (a==0&&b==0&&c==0){
cout<<"Zero Equation";
}
else if (a==0&&b==0&&c!=0){
    cout<<"Not An Equation";
}
else{
    double delta;
    delta=b*b-4*a*c;
    if(delta=0){
    if(b==0){
    cout<<"0.00";
    }
    else{
    cout<<fixed<<setprecision(2)<<-1*b/(2*a);
    }
}
    if(delta<0){
delta=sqrt(-1*delta);
cout<<fixed<<setprecision(2)<<-1*b/(2*a)<<"+"<<delta/(2*a)<<"i"<<endl<<fixed<<setprecision(2)<<-1*b/(2*a)<<"-"<<-1*delta/(2*a)<<"i";
    }
    if (delta>0){
    if(c==0){
    if(b/a<0){
    cout<<fixed<<setprecision(2)<<b/a<<0.00;
    }
    if(b/a>0){
    cout<<fixed<<setprecision(2)<<0.00<<b/a;
    }
    }
    else{
    cout<<fixed<<setprecision(2)<<-1*b/(2*a)<<"+"<<delta/(2*a)<<endl<<fixed<<setprecision(2)<<-1*b/(2*a)<<"-"<<-1*delta/(2*a);
    }
    }
}

}
不想写了
2. 特殊情况处理不完整

if (a==0&&b==0&&c==0) 和 else if (a==0&&b==0&&c!=0) 只处理了 a=b=0 的极端情况，但忽略了线性方程（a=0, b≠0）的处理。
当 a=0, b≠0 时，程序进入 else 分支，计算 delta = b² - 40c = b² > 0，然后进入 delta>0 分支，错误地当作二次方程处理（根应该是 -c/b，而不是虚构的二次根）。
错误示例：输入 0 1 -2（方程 x - 2 = 0，根 x=2），程序会输出类似 2.00 和 0.00 的错根。
正确做法：添加 else if (a == 0) { double x = -c / b; cout << x; } 来处理线性情况。

3. delta 计算后的 if 分支结构错误（无 else，造成多重执行）

三个 if 分支（delta=0, delta<0, delta>0）都是独立的，没有 else，导致：

当 delta < 0 时，先执行 <0 分支（设置 delta = sqrt(-delta) > 0），打印复根；然后因为 delta 现在 >0，又执行 >0 分支，再打印一次实根。结果输出多余内容。
当 delta == 0 时，只执行第一个分支（好）。
当 delta > 0 时，只执行最后一个（好）。


正确做法：改为 if-else if-else 结构，确保互斥。

4. delta == 0 分支：赋值误用作比较

if (delta=0) 是赋值操作（将 delta 设为 0），不是比较（应为 ==）。这会让 delta 强制变为 0，导致后续分支判断出错。
即使修复，内部 if(b==0) cout<<"0.00"; 是多余的（因为 delta=0 且 b=0 隐含 c=0，根为 0），但逻辑上可接受。
正确做法：改为 if (delta == 0)，并统一输出 -b / (2 * a)（当 b=0 时自然为 0）。

5. delta < 0 分支：复根计算和输出错误

delta = sqrt(-1*delta);：计算了虚部幅度正确（sqrt(|delta|)），但后续输出：

第一根：-b/(2a) + delta/(2a) i 基本正确（假设 a > 0）。
第二根：-b/(2a) - (-1*delta/(2a)) i，计算 - (-delta/(2a)) = + delta/(2a)，所以输出 real - (+ imag) i，但格式是 <<"-"<< -1*delta/(2*a) <<"i"，如果 a > 0，-delta/(2a) < 0，所以 "-" + (负数) 变成实部减去正虚部，但打印时会是如 "1.00- -0.50i"（双负号混乱）。


未考虑 a < 0 时虚部符号（标准公式虚部是 sqrt(-delta)/(2*|a|) 的正幅度，符号统一）。
无 endl 分隔两根（虽有 endl，但第二行有问题）。
由于无 else，后续还会执行 >0 分支。
正确做法：用 fabs(sqrt(-delta) / (2 * a)) 计算虚部幅度，统一输出 real + imag i 和 real - imag i，并用 else if 避免多执行。

6. delta > 0 分支：未取 sqrt，导致根计算完全错误

输出 -b/(2a) + delta/(2a) 和 -b/(2a) - (-delta/(2a))，但 delta 是判别式（b²-4ac），不是 sqrt(delta)！所以加减的是巨大值，不是正确的 ± sqrt(delta)/(2a)。
示例：a=1, b=0, c=-1（根 ±1），delta=4，输出 0 + 4/2=2 和 0 - (-4/2)=2，双根 2（错，应 ±1）。
第二根：- (-delta/(2a)) = + delta/(2a)，所以两个根都变成 real + |delta|/(2a)，完全相同。
正确做法：先计算 sqrt_delta = sqrt(delta)，然后根1 = (-b + sqrt_delta)/(2a)，根2 = (-b - sqrt_delta)/(2a)，并按从小到大排序输出。

7. c==0 特殊子分支：逻辑和输出格式错

当 c=0 时，根为 0 和 -b/a。
但代码：if(b/a <0) cout << b/a << 0.00; else cout << 0.00 << b/a;

符号错：应为 -b/a，不是 b/a。
输出无空格/换行：如 b/a=-2，输出 "-2.000.00"（连在一起）；b/a=2，输出 "0.002.00"。
未排序（应小根在上）。


这只在 delta>0 且 c=0 时触发，但如上所述，delta 未 sqrt 也错。
正确做法：统一用二次公式计算（c=0 时自然得 0 和 -b/a），排序后输出，每行一个，带 endl。

8. 其他小问题

未处理 a < 0 时根的排序（实根或虚部）。
输出缺少 endl 在某些地方，导致根挤一起。
浮点比较 ==0 不严谨（浮点精度），但对于输入简单可忽略；实际用 fabs(delta) < 1e-9 更好。
无 return 0;（main 隐式返回，但好习惯加）。
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    cout << fixed << setprecision(2);
    if (a == 0 && b == 0) {
        if (c == 0) {
            cout << "Zero Equation";
        } else {
            cout << "Not An Equation";
        }
    } else if (a == 0) {
        double x = -c / b;
        cout << x;
    } else {
        double delta = b * b - 4 * a * c;
        double real_part = -b / (2 * a);
        if (delta == 0) {
            cout << real_part;
        } else if (delta < 0) {
            double imag_part = fabs(sqrt(-delta) / (2 * a));
            cout << real_part << "+" << imag_part << "i" << endl
                 << real_part << "-" << imag_part << "i";
        } else {
            double sqrt_delta = sqrt(delta);
            double root1 = (-b + sqrt_delta) / (2 * a);
            double root2 = (-b - sqrt_delta) / (2 * a);
            double smaller = min(root1, root2);
            double larger = max(root1, root2);
            cout << smaller << endl << larger;
        }
    }
    return 0;
}
/* 但未处理0.00#include <bits/stdc++.h>
using namespace std;

// 辅助函数：标准化零
double normalize_zero(double x) {
    if (fabs(x) < 1e-9) {  // 如果接近零
        return 0.0;  // 强制正零
    }
    return x;
}

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    cout << fixed << setprecision(2);
    if (a == 0 && b == 0) {
        if (c == 0) {
            cout << "Zero Equation";
        } else {
            cout << "Not An Equation";
        }
    } else if (a == 0) {
        double x = normalize_zero(-c / b);  // 应用到线性根
        cout << x;
    } else {
        double delta = b * b - 4 * a * c;
        double real_part = normalize_zero(-b / (2 * a));  // 应用到实部
        if (fabs(delta) < 1e-9) {  // 用 fabs 检查 delta == 0，避免浮点误差
            cout << real_part;
        } else if (delta < 0) {
            double imag_part = fabs(sqrt(-delta) / (2 * a));  // 虚部幅度已用 fabs
            cout << real_part << "+" << imag_part << "i" << endl
                 << real_part << "-" << imag_part << "i";
        } else {
            double sqrt_delta = sqrt(delta);
            double root1 = normalize_zero((-b + sqrt_delta) / (2 * a));  // 应用到每个根
            double root2 = normalize_zero((-b - sqrt_delta) / (2 * a));
            double smaller = min(root1, root2);
            double larger = max(root1, root2);
            cout << smaller << endl << larger;
        }
    }
    return 0;
}*/