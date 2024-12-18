$$
F_n=\frac{1}{\sqrt 5}\left[\left(\frac{1+\sqrt 5}{2}\right)^n-\left(\frac{1-\sqrt 5}{2}\right)^n\right]
$$

因为
$$
\lim_{n \rightarrow \infty}\left(\frac{1-\sqrt 5}{2}\right)^n=0
$$
所以
$$
\lim_{n \rightarrow \infty} \frac{F_n}{\left(\frac{1+\sqrt 5}{2}\right)^n}=1
$$
由此
$$
n=\frac{\log {\sqrt 5 F_n}}{\log \frac{1+\sqrt 5}{2}}
$$

```c++
int get(const string& s) {
    return round((log(5)/2+(s.size()-1)*log(10)+
    log(stod(s.substr(0, 20).insert(1, "."))))/log((1+sqrt(5))/2));
}
```

