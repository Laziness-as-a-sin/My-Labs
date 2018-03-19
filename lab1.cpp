#include <iostream>
using namespace std;
 
class Vector
{
    friend Vector operator+(const Vector& lv, const Vector& rv);
	friend Vector operator-(const Vector& lv, const Vector& rv);
private:
    int* data;
    int minI;
    int maxI;
    int lengths;
public:
    Vector(int minIndex, int maxIndex);
    Vector(int len);
    ~Vector();
    int Get(int index);
    int SetValue(int index, int value);
    void Show();
    void Div(int el);
    void Mul(int el);
};
 
Vector operator+(const Vector& lv, const Vector& rv)
{
 
    if (lv.maxI == rv.maxI && lv.minI == rv.minI)
    {
        Vector temp(lv.minI, lv.maxI);
        for (int i = 0; i < rv.lengths; ++i)
        {
            temp.data[i] = lv.data[i] + rv.data[i];
        }
		temp.Show();
        return temp;
    }
		
}

Vector operator-(const Vector& lv, const Vector& rv)
{
 
    if (lv.maxI == rv.maxI && lv.minI == rv.minI)
    {
        Vector temp(lv.minI, lv.maxI);
        for (int i = 0; i < rv.lengths; ++i)
        {
            temp.data[i] = lv.data[i] - rv.data[i];
        }
		temp.Show();
        return temp;
    }
		
}
 
Vector::Vector(int minIndex, int maxIndex):
    minI(minIndex), maxI(maxIndex)
{
    lengths = maxI + 1 - minI;
    data = new int[lengths];
 
    for (int i = 0; i < lengths; ++i)
        data[i] = 0;
}
Vector::Vector(int len):
    minI(0),maxI(len-1)
{
    data = new int[len];
    lengths = len;
    for(int i = 0; i < len; ++i)
        data[i] = 0;
}
int Vector::Get(int index)
{
    if (index < minI || index > maxI)
        return -1;
    else
        return data[index - minI];
}
int Vector::SetValue(int index, int value)
{
    if (index < minI || index > maxI)
        return -1;
    else
        data[index - minI] = value;
}
Vector::~Vector()
{
    delete[] data;
}
void Vector::Show()
{
    cout << "vector : " << endl << "Lengths = " << lengths << "\t Indexes " << minI << " to " << maxI << endl;
    for (int i = 0; i < lengths; ++i)
    {
        cout << data[i] << " ";
    }
    cout << endl;
}
void Vector::Div(int val)
{
    for (int i = 0; i < lengths; ++i)
    {
        data[i] /= val;
    }
}
 
void Vector::Mul(int val)
{
    for (int i = 0; i < lengths; ++i)
    {
        data[i] *= val;
    }
}
 
int main()
{
	char ch, name;
	int firstI, lastI;
	bool g;
	
    //system("@pause");
	    
	cout << "" << endl;
	cout << "First index of vector: " << endl;
	cin >> firstI;		
	cout << "Last index of vector: " << endl;
	cin >> lastI;
	Vector first(firstI, lastI);
	first.Show();
	
	cout << "First index of vector: " << endl;
	cin >> firstI;		
	cout << "Last index of vector: " << endl;
	cin >> lastI;
	Vector second(firstI, lastI);
	second.Show();	
	
	menu:
    cout << ">";
    ch = 0;
    cin.get(ch);
    if(ch == '1') 
    {
		first.Show();
    }
    else if(ch == '2')
    {
		second.Show();
    }
	else if(ch == '4') 
    {
		cout << "Index of element: " << endl;
		cin >> firstI;		
		cout << "Value: " << endl;
		cin >> lastI;
		second.SetValue(firstI, lastI);
    }
    else if(ch == '3')
    {
		cout << "Index of element: " << endl;
		cin >> firstI;		
		cout << "Value: " << endl;
		cin >> lastI;
		first.SetValue(firstI, lastI);
    }
	else if(ch == '5')
    {
		cout << "Factor: " << endl;
		cin >> firstI;
		first.Mul(firstI);
    }
	else if(ch == '6')
    {
		cout << "Divider: " << endl;
		cin >> firstI;
		first.Div(firstI);
    }	
	else if(ch == '7')
    {
		first + second;
    }
	else if(ch == '8')
    {
		first - second;
    }
	else if(ch == '9')
    {
		cout << "Index: " << endl;
		cin >> firstI;
		cout << first.Get(firstI) << endl;
    }
	
	

    else if(ch == '0') return 0;
    goto menu;
    return 0;
}