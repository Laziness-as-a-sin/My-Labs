clc
clear all;
format long

a = 0.5;
b = 1.0;
n = 2;
[I, cnt] = quad('x.^2 + log(x)', a, b) %проверка
eps = 10^-6;
h = (b-a)/n;
check = 0;
x = a:h:b;

syms t f(t)
f(t) = t.^2 + log(t);

c = [ 1/6 4/6 1/6];

In = 0;
for i = 1:1:n+1
    In = In + c(i)*eval(f(x(i)));
end
In = In*(b-a) %первое значение In

k = 2;
while(check == 0) %вычесление интеграла с точностью eps(0.000001)
    SumInk = 0;
    h = (b-a)/(k*n);
    for j = 0:1:k-1 %Ink
        Ink = 0;
        x = a+(b-a)/k*j:h:a+(b-a)/k*(j+1);
        for i = 1:1:n+1
            Ink = Ink + c(i)*eval(f(x(i)));
        end
        SumInk = SumInk + Ink*(b-a)/k
    end
    
    if(abs(In - SumInk) < eps)
        check = 1;
    else
        In = SumInk;
        k = k*2;
    end
    
    if(k == 200)
       fprintf('Too many steps');
       break;
    end
end

In %Answer

