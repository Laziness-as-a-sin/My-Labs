%lg(3x-1)+exp(2x-1)=0
%Локализуем наименьший корень
%exp(-x)-1/2*sinx^2
clc
eps = 0.0001;
a = -10;
b = a+0.5;
check = 0;
syms t f(t)
f(t) = exp(-1*t)-1/2*sin(t)*sin(t)
%f(t) = log(3*t-1)+exp(2*t-1);
ftt(t)= diff(f(t),2);
ft(t)= diff(f(t),1);
k = 0; %счётчик шагов

while (check == 0) %определяем границы
    fa = eval(f(a));
    fb = eval(f(b));
    if (fa*fb < 0) 
        check = 1
    else
        a = a + 0.5;
        b = b + 0.5;
    end
    if (a > 10)
        check = 1
    end
end
check = 0;

if (eval(ftt(a))*eval(f(a)) < 0) %a-неподвижный конец отрезка, b-конец с которого мы приближаемся
                                 %a-fixed end of the segment, b-the end from which we are approaching                       
    c = a;
    a = b;
    b = c;
end

%метод хорд и касательных
%method of chords and tangents
a1 = a;
b1 = b;
fa1 = eval(f(a1));
fb1 = eval(f(b1));
fta1 = eval(ft(a1));

while(abs(a1-b1) > eps)
   a2 = a1-eval(f(a1))/eval(ft(a1));
   b1 = b1 - (a1-b1)*eval(f(b1))/(eval(f(a1))-eval(f(b1)));
   a1 = a2;
   k = k + 1;
end
k %шаги/steps
k = 0;
a1 %корень/root
b1

a1 = a; %метод хорд и касательных(чуть другой)/method of chords and tangents (slightly different) http://cyclowiki.org/wiki/%D0%9A%D0%BE%D0%BC%D0%B1%D0%B8%D0%BD%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%BD%D1%8B%D0%B9_%D0%BC%D0%B5%D1%82%D0%BE%D0%B4
b1 = b;
while(abs(a1-b1) > eps)
   if(eval(f(a1))*eval(ft(a1)) < 0)
        a1 = a1 - eval(f(a1))*(a1-b1)/(eval(f(a1))-eval(f(b1)));
   else
        a1 = eval(f(a1))/eval(ft(a1));
   end
   
   if(eval(f(b1))*eval(ft(b1)) < 0)
        b1 = b1 - eval(f(b1))*(b1-a1)/(eval(f(b1))-eval(f(a1)));
   else
        b1 = eval(f(b1))/eval(ft(b1));
   end
   k = k +1;
end
k
root = (a1+b1)/2 %корень
x = 0 : 0.01 : 2;
y = eval(f(x));
plot( x , y )
