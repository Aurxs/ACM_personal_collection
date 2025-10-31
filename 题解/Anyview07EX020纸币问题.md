### 问题分析

我们需要求解不定方程 `x + 5y + 10z = n` 的非负整数解 `(x, y, z)` 的个数，其中 `n` 是总金额。

### 推导 O(1) 解法

我们可以通过数学归纳和观察，或者使用生成函数来推导。这里我们展示一个比较直观的推导过程。

1. **固定10元纸币的数量** 假设我们用了 `k` 张10元的纸币，那么剩下的金额是 `n - 10k`。我们需要用1元和5元的纸币来凑齐这个金额。
   `x + 5y = n - 10k` 对于一个固定的 `k`，5元纸币的数量 `y` 可以从 `0` 取到 `floor((n - 10k) / 5)`。每当 `y` 确定，`x`
   的值也随之确定。所以，对于一个固定的 `k`，有 `floor((n - 10k) / 5) + 1` 种组合。

2. **累加所有可能性** 10元纸币的数量 `k` 可以从 `0` 取到 `floor(n / 10)`。所以总的支付方法数是：
   `Sum = Σ [k=0 to floor(n/10)] (floor((n - 10k) / 5) + 1)`

3. **化简求和公式** 这个求和公式虽然正确，但需要循环，时间复杂度不是 O(1)
   。我们可以通过代数变换将其化简为一个封闭形式的公式。这个过程涉及到整数除法和求和技巧，最终可以得到一个与 `n` 相关的二次多项式。

   经过推导，最终的公式为： 令 `m = floor(n / 10)`，`r = n % 10`。 支付方法的总数 =
   `(m + 1) * (floor(r / 5) + 1) + m * (m + 1) / 2 * 2` 简化后为： *
   *`Ways(n) = (m + 1) \* (floor(r / 5) + 1) + m \* (m + 1)`**

   其中：

    - `m = n / 10` (整数除法)
    - `r = n % 10` (取余)

这个公式只涉及几次整数乘除和加法运算，与 `n` 的大小无关，因此时间复杂度是 O(1)。

下面用一步一步的方式，把“求和公式”化成 O(1) 的封闭形式。全程用清晰的等式推演，便于你自己复现。

步骤 0：符号约定

- 设总方法数为 W(n)。
- 设 m = ⌊n/10⌋，r = n mod 10（即 n = 10m + r，0 ≤ r ≤ 9）。

步骤 1：列出总和
固定 10 元张数 z，则剩余金额是 n − 10z，用 1 元与 5 元的解数为 ⌊(n − 10z)/5⌋ + 1。z 的范围是 0…m。
$$
W(n)=\sum_{z=0}^{m}\left(\left\lfloor\frac{n-10z}{5}\right\rfloor+1\right)
$$

步骤 2：拆成两部分
$$
W(n)=\underbrace{\sum_{z=0}^{m}\left\lfloor\frac{n-10z}{5}\right\rfloor}_{S_1}+\underbrace{\sum_{z=0}^{m}1}_{S_2}
$$
显然
$$
S_2=m+1.
$$

步骤 3：化简 S1 的地板函数
用到性质：对任意实数 x 与整数 k，有
$$
\left\lfloor x-k\right\rfloor=\left\lfloor x\right\rfloor-k.
$$
证明很短：若 q=⌊x⌋，则 q≤x<q+1，减去整数 k 得 q−k≤x−k<q−k+1，所以 ⌊x−k⌋=q−k=⌊x⌋−k。

令 x=n/5，k=2z（因 10z/5=2z 为整数），于是
$$
\left\lfloor\frac{n-10z}{5}\right\rfloor
=\left\lfloor\frac{n}{5}-2z\right\rfloor
=\left\lfloor\frac{n}{5}\right\rfloor-2z.
$$

步骤 4：把 S1 代回并求和
$$
\begin{aligned}
S_1
&=\sum_{z=0}^{m}\Big(\left\lfloor\frac{n}{5}\right\rfloor-2z\Big)
=\sum_{z=0}^{m}\left\lfloor\frac{n}{5}\right\rfloor-\sum_{z=0}^{m}2z \\
&=(m+1)\left\lfloor\frac{n}{5}\right\rfloor-2\cdot\frac{m(m+1)}{2} \\
&=(m+1)\left\lfloor\frac{n}{5}\right\rfloor-m(m+1).
\end{aligned}
$$

步骤 5：合并 S1 与 S2
$$
\begin{aligned}
W(n)
&=S_1+S_2\\
&=(m+1)\left\lfloor\frac{n}{5}\right\rfloor-m(m+1)+(m+1) \\
&=(m+1)\Big(\left\lfloor\frac{n}{5}\right\rfloor+1\Big)-m(m+1).
\end{aligned}
$$

步骤 6：把 ⌊n/5⌋ 用 m 与 r 表示
因 n=10m+r，
$$
\left\lfloor\frac{n}{5}\right\rfloor=\left\lfloor\frac{10m+r}{5}\right\rfloor
=2m+\left\lfloor\frac{r}{5}\right\rfloor,
\qquad 0\le r\le 9.
$$

步骤 7：代回并整理为最简形
$$
\begin{aligned}
W(n)
&=(m+1)\Big(2m+\left\lfloor\frac{r}{5}\right\rfloor+1\Big)-m(m+1) \\
&=(m+1)\Big(m+\left\lfloor\frac{r}{5}\right\rfloor+1\Big) \\
&=m(m+1)+(m+1)\Big(\left\lfloor\frac{r}{5}\right\rfloor+1\Big).
\end{aligned}
$$

步骤 8：给出更直观的分段形式
因为 r∈{0,1,2,3,4,5,6,7,8,9}，有
$$
\left\lfloor\frac{r}{5}\right\rfloor=
\begin{cases}
0,&0\le r\le 4,\\[4pt]
1,&5\le r\le 9.
\end{cases}
$$
于是
$$
W(n)=
\begin{cases}
(m+1)^2,&0\le r\le 4,\\[6pt]
(m+1)(m+2),&5\le r\le 9,
\end{cases}
\qquad\text{其中 } m=\left\lfloor\frac{n}{10}\right\rfloor,\ r=n\bmod 10.
$$

这样就把原来的求和，完整地一步一步化简为了 O(1) 的封闭公式。你可以拿任意 n（如 10、13、20 等）代入这个分段式快速验证。