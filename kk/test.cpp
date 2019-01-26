#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 100000;                   // �������λ��
struct bign
{
	int len, s[maxn];                  //len��¼���ֵ�λ����s�洢����s[0]��s[1],s[2]���ֱ��Ǹ�λʮλ��λ���Դ����ƣ�
	bign() { memset(s, 0, sizeof(s)); len = 1; }
	bign operator=(const char * num)   //���ַ�����ֵ����������
	{
		len = strlen(num);

		for (int i = 0; i < len; i++)
			s[i] = num[len - i - 1] - '0';
		int i = len - 1;
		while (i > 0 && s[i] == 0) i--;  // ��֤���ֵ�������С�����⡰0000010�����������
		len = i + 1;
		return *this;
	}
	bign operator=(int num)           //��int���͸�ֵ����������
	{
		char s[maxn];
		sprintf(s, "%d", num);
		*this = s;
		return *this;
	}
	bign operator=(const bign & b)   //�������͵Ļ��ำֵ
	{
		len = b.len;
		for (int i = 0; i < len; i++)
			s[i] = b.s[i];

		return *this;
	}
	bign(int num) { *this = num; }   //��intת��Ϊ��������
	bign(const char * num) { *this = num; }  //ͬ��
	string str() const               //���������ͣ�������ת��Ϊstring
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
		while (i > 0 && c.s[i] == 0) i--;       //ȷ�����ֵ�����λ��
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
	//�����߼������
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
	//������������
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
	//ȡ����
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
		//��2��ʼ�ֽ⣬���ηֽ�Ϊ2��3��4��5...������Ԫ��
		flag[i++] = k;
		num = num-k;
		k=k+1;
	}
	if (num > 0) {
		//˵����ʣ���
		if (num == flag[i - 1]) {
			//˵����ʱ��ʣ��������ñ����е�Ԫ�ظ�����1������Ҫ�ȸ����һ��Ԫ�ؼ�1
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
