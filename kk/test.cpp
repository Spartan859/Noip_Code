#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 100000;                   // 最大运算位数
struct bign
{
	int len, s[maxn];                  //len记录数字的位数，s存储数字s[0]，s[1],s[2]。分别是个位十位百位（以此类推）
	bign() { memset(s, 0, sizeof(s)); len = 1; }
	bign operator=(const char * num)   //将字符串赋值给大数类型
	{
		len = strlen(num);

		for (int i = 0; i < len; i++)
			s[i] = num[len - i - 1] - '0';
		int i = len - 1;
		while (i > 0 && s[i] == 0) i--;  // 验证数字的真正大小，避免“0000010”的这样情况
		len = i + 1;
		return *this;
	}
	bign operator=(int num)           //将int类型赋值给大数类型
	{
		char s[maxn];
		sprintf(s, "%d", num);
		*this = s;
		return *this;
	}
	bign operator=(const bign & b)   //大数类型的互相赋值
	{
		len = b.len;
		for (int i = 0; i < len; i++)
			s[i] = b.s[i];

		return *this;
	}
	bign(int num) { *this = num; }   //将int转换为大数类型
	bign(const char * num) { *this = num; }  //同上
	string str() const               //将大数类型（副本）转换为string
	{
		string res = "";
		for (int i = 0; i < len; i++)
			res = (char)(s[i] + '0') + res;
		if (res == "")
			res == "0";
		return res;
	}

	bign operator+(const bign & b) const
	{
		bign c;
		c.len = 0;
		for (int i = 0, g = 0; g || i < max(len, b.len); i++)
		{
			int x = g;
			if (i < len)
				x += s[i];
			if (i < b.len)
				x += b.s[i];
			c.s[c.len++] = x % 10;
			g = x / 10;
		}
		return c;

	}
	bign operator-(const bign & b) const
	{
		bign c;
		bign temp;
		temp = *this;
		c.len = 0;
		for (int i = 0; i < max(temp.len, b.len); i++)
		{
			int x = 0;
			if (i < temp.len)
				x += temp.s[i];
			if (i < b.len)
				x -= b.s[i];
			if (x >= 0)
				c.s[c.len++] = x;
			else
			{
				c.s[c.len++] = x + 10;
				temp.s[i + 1]--;
			}
		}
		int i = c.len - 1;
		while (i > 0 && c.s[i] == 0) i--;       //确定数字的真正位数
		c.len = i + 1;
		return c;

	}
	bign operator*(const bign & b) const
	{
		bign c;
		for (int i = 0; i < len; i++)
		{

			for (int j = 0; j < b.len; j++)
			{
				c.s[i + j] += s[i] * b.s[j];

			}
		}
		for (int i = 0; i < len + b.len - 1; i++)
		{
			c.s[i + 1] += c.s[i] / 10;
			c.s[i] = c.s[i] % 10;
		}
		for (int i = len + b.len + 2; i > 0; i--)
			if (c.s[i] != 0)
			{
				c.len = i + 1;
				break;
			}
		return c;
	}
	//定义逻辑运算符
	bool operator<(const bign & b) const
	{

		if (len != b.len)
			return len < b.len;
		for (int i = len; i > 0; i--)
			if (s[i] != b.s[i])
				return s[i] < b.s[i];
	}
	bool operator>(const bign & b) const
	{
		return b < *this;
	}
	bool operator<=(const bign & b) const
	{
		return !(b < *this);
	}
	bool operator>=(const bign & b) const
	{
		return !(*this < b);
	}
	bool operator==(const bign & b) const
	{
		if (*this < b)
			return false;
		else if (*this > b)
			return false;
		else
			return true;
	}
	bool operator!=(const bign & b) const
	{
		return !(*this == b);
	}
	//除法（整除）
	bign operator/(const bign & b) const
	{
		bign temp, result;
		temp = *this;
		result = 0;
		while (temp > b)
		{
			temp = temp - b;
			result = result + 1;

		}
		return result;
	}
	//取余数
	bign operator%(const bign & b) const
	{
		bign result;
		result = *this;
		while (result > b)
			result = result - b;
		return result;
	}
};
istream & operator>>(istream & in, bign & x)
{
	string s;
	in >> s;
	x = s.c_str();
	return in;
}
ostream & operator<<(ostream & out, const bign & x)
{
	out << x.str();
	return out;
}

int main() {
	ll num;
	cin >> num;
	ll flag[100] = { 0 };
	ll k = 2;
	int i = 0;
	while (num >= k) {
		//从2开始分解，依次分解为2，3，4，5...连续的元素
		flag[i++] = k;
		num = num-k;
		k=k+1;
	}
	if (num > 0) {
		//说明有剩余的
		if (num == flag[i - 1]) {
			//说明这时候剩余的数正好比已有的元素个数多1，所以要先给最后一个元素加1
			flag[i - 1]= flag[i - 1]+1;
			num=num-1;
		}
		for (int j = i - 1; j >= 0 && num>0; j--) {
			flag[j]= flag[j]+1;
			num=num-1;
		}
	}
	bign result = 1;
	for (int j = 0; j<i; j++) {
		result = result*flag[j];
	}
	cout << result << endl;
	return 0;
}
