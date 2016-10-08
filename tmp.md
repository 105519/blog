[toc]

# picture

![][1]

[1]: http://latex.codecogs.com/gif.latex?\begin{aligned}%20fib[p+1]%20=%20&%20\frac{1}{\sqrt{5}}%20\left[%20\left(%20\frac{1+\sqrt{5}}{2}%20\right)^{p+1}%20-%20\left(%20\frac{1-\sqrt{5}}{2}%20\right)^{p+1}%20\right]%20\\%20=%20&%20\frac{(1+\sqrt{5})^{p+1}-(1-\sqrt{5})^{p+1}}{2^{p+1}%20\sqrt{5}}%20\\%20=%20&%20\frac{(1+(p+1)\sqrt{5}+(p+1)\sqrt{5}^{p}+\sqrt{5}^{p+1})%20-%20(1+(p+1)(-\sqrt{5})+(p+1)(-\sqrt{5})^{p}+(-\sqrt{5})^{p+1})}%20{2^{p}%20\sqrt{5}}%20\\%20=%20&%20\frac{((p+1)\sqrt{5}+(p+1)\sqrt{5}^{p})%20-%20((p+1)(-\sqrt{5})+(p+1)(-\sqrt{5})^{p})}%20{2^{p}%20\sqrt{5}}%20\\%20=%20&%20\frac{2(p+1)(\sqrt{5}+\sqrt{5}^{p})}{2^{p}%20\sqrt{5}}%20\\%20=%20&%20\frac{1+\sqrt{5}^{p-1}}{2^{p-1}}%20\\%20=%20&%20\frac{1-1}{1}%20\\%20=%20&%200%20\\%20\end{aligned}

![][2]

[2]: http://latex.codecogs.com/gif.latex?Fib(n)=\\frac{%20\\left(\\phi%20^{n}%20-\\gamma^{n}%20\\right%20)%20}{\\sqrt{5}}

***

# explanatory note

<!--
$$
\begin{aligned}
fib[p+1] = & \frac{1}{\sqrt{5}} \left[ \left( \frac{1+\sqrt{5}}{2} \right)^{p+1} - \left( \frac{1-\sqrt{5}}{2} \right)^{p+1} \right] \\
= & \frac{(1+\sqrt{5})^{p+1}-(1-\sqrt{5})^{p+1}}{2^{p+1} \sqrt{5}} \\
= & \frac{(1+(p+1)\sqrt{5}+(p+1)\sqrt{5}^{p}+\sqrt{5}^{p+1}) - (1+(p+1)(-\sqrt{5})+(p+1)(-\sqrt{5})^{p}+(-\sqrt{5})^{p+1})} {2^{p} \sqrt{5}} \\
= & \frac{((p+1)\sqrt{5}+(p+1)\sqrt{5}^{p}) - ((p+1)(-\sqrt{5})+(p+1)(-\sqrt{5})^{p})} {2^{p} \sqrt{5}} \\
= & \frac{2(p+1)(\sqrt{5}+\sqrt{5}^{p})}{2^{p} \sqrt{5}} \\
= & \frac{1+\sqrt{5}^{p-1}}{2^{p-1}} \\
= & \frac{1-1}{1} \\
= & 0 \\
\end{aligned}
$$
-->

***

# latex

$$
\begin{aligned}
fib[p+1] = & \frac{1}{\sqrt{5}} \left[ \left( \frac{1+\sqrt{5}}{2} \right)^{p+1} - \left( \frac{1-\sqrt{5}}{2} \right)^{p+1} \right] \\
= & \frac{(1+\sqrt{5})^{p+1}-(1-\sqrt{5})^{p+1}}{2^{p+1} \sqrt{5}} \\
= & \frac{(1+(p+1)\sqrt{5}+(p+1)\sqrt{5}^{p}+\sqrt{5}^{p+1}) - (1+(p+1)(-\sqrt{5})+(p+1)(-\sqrt{5})^{p}+(-\sqrt{5})^{p+1})} {2^{p} \sqrt{5}} \\
= & \frac{((p+1)\sqrt{5}+(p+1)\sqrt{5}^{p}) - ((p+1)(-\sqrt{5})+(p+1)(-\sqrt{5})^{p})} {2^{p} \sqrt{5}} \\
= & \frac{2(p+1)(\sqrt{5}+\sqrt{5}^{p})}{2^{p} \sqrt{5}} \\
= & \frac{1+\sqrt{5}^{p-1}}{2^{p-1}} \\
= & \frac{1-1}{1} \\
= & 0 \\
\end{aligned}
$$

> Written with [StackEdit](https://stackedit.io/).
